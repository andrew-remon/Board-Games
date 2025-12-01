// Num_UI.cpp
#include <iostream>
#include "InputValidation.h"
#include "NumXO_UI.h"
using namespace std;

NumXO_UI::NumXO_UI() : UI<int>("Welcome to Our FCAI Numerical X-O Game\n", 3)
{
    cout << "This is a Numerical Tic Tac Toe Game played by two players.\n";
    cout << "The Rules are as following:\n";
    cout << "[1] One Player should play only with Odd Numbers while the other with Even Ones\n";
    cout << "[2] Odd & Even Numbers are less than 10 and only used once during the game\n";
    cout << "[3] The player who completes one row, column or diagonal with cells sum equal to '15' wins.\n\n";

    srand(static_cast<unsigned int>(time(NULL)));
}

Player<int>* NumXO_UI::create_player(string& name, int symbol, PlayerType type)
{
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer")  << " player: " << name << " (" << symbol << ")\n";

    // return new Player<int>(name, type, status);
    return new Player<int>(name, symbol, type);
}

Move<int>* NumXO_UI::get_move(Player<int>* player)
{
    // call NumXO_Player-specific functions
    NumXO_Player* numPlayer = dynamic_cast<NumXO_Player*>(player);

    if (numPlayer) {
        numPlayer->set_symbol();
    }

    int x, y;

    if (player->get_type() == PlayerType::HUMAN)
    {
        cout << "\nPlease enter your move x and y (0 to 2): ";
        cin >> x >> y;
    }
    else if (player->get_type() == PlayerType::COMPUTER)
    {
        x = rand() % player->get_board_ptr()->get_rows();
        y = rand() % player->get_board_ptr()->get_columns();
        cout << player->get_name() << " chose position (" << x << ", " << y << ")\n";
    }

    // update symbol
    return new Move<int>(x, y, player->get_symbol());
}

// Player<int>** NumXO_UI::setup_players()
// {
//     Player<int>** players = new Player<int>*[2];
//     vector<string> type_options = { "Human", "Computer" };
//     vector<string> status_options = { "Odd", "Even" };
//
//     string name1 = get_player_name("Player 1");
//     PlayerType type1 = get_player_type_choice("Player 1", type_options);
//     PlayerStatus status1 = get_player_status_choice("Player 1", status_options);
//
//     int symbol = (status1 == PlayerStatus::ODD) ? 1 : 2;
//
//     players[0] = create_player(name1, symbol, type1);
//
//
//     string name2 = get_player_name("Player 2");
//     PlayerType type2 = get_player_type_choice("Player 2", type_options);
//
//     if (symbol == 1) symbol = 2;
//     else symbol = 1;
//     players[1] = create_player(name2,symbol,type2);
//
//     return players;
// }

Player<int>** NumXO_UI::setup_players()
{
    Player<int>** players = new Player<int>*[2];
    vector<string> type_options = { "Human", "Computer" };
    vector<string> status_options = { "Odd", "Even" };

    // Player 1
    string name1 = get_player_name("Player 1");
    PlayerType type1 = get_player_type_choice("Player 1", type_options);
    PlayerStatus status1 = get_player_status_choice("Player 1", status_options);

    int initial_symbol = (status1 == PlayerStatus::ODD) ? 1 : 2;
    players[0] = new NumXO_Player(name1, initial_symbol, type1, status1);

    // Player 2 gets opposite status
    string name2 = get_player_name("Player 2");
    PlayerType type2 = get_player_type_choice("Player 2", type_options);
    PlayerStatus status2 = (status1 == PlayerStatus::ODD) ? PlayerStatus::Even : PlayerStatus::ODD;

    int initial_symbol2 = (status2 == PlayerStatus::ODD) ? 1 : 2;
    players[1] = new NumXO_Player(name2, initial_symbol2, type2, status2);

    return players;
}

PlayerStatus NumXO_UI::get_player_status_choice(string player_label, const vector<string>& options)
{
    cout << "\nChoose " << player_label << " type:\n";

    for (size_t i = 0; i < options.size(); ++i)
        cout << i + 1 << ". " << options[i] << "\n";

    int choice = InputValidation::readIntNumberBetween(1, 2, "Invalid Choice, Please enter 1 or 2: ");

    return (choice == 2) ? PlayerStatus::Even : PlayerStatus::ODD;
}
