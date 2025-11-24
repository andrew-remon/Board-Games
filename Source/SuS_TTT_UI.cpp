#include <iostream>
#include "InputValidation.h"
#include "SuS_TTT_UI.h"
using namespace std;

SuS_TTT_UI::SuS_TTT_UI() : UI<char>("Welcome to Our FCAI SuS X-O Game\n", 3)
{
    cout << "This is a SuS Tic Tac Toe Game played by two players.\n";
    cout << "The Rules are as following:\n";
    /*cout << "[1] One Player should play only with Odd Numbers while the other with Even Ones\n";
    cout << "[2] Odd & Even Numbers are less than 10 and only used once during the game\n";
    cout << "[3] The player who completes one row, column or diagonal with cells sum equal to '15' wins.\n\n";*/
}

Player<char>* SuS_TTT_UI::create_player(string& name, char symbol, PlayerType type)
{
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer") << " player: " << name << " (" << symbol << ")\n";

    // return new Player<int>(name, type, status);
    return new Player<char>(name, symbol, type);
}

Move<char>* SuS_TTT_UI::get_move(Player<char>* player)
{
    //Player* susPlayer = dynamic_cast<Player*>(player);


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
    return new Move<char>(x, y, player->get_symbol());
}



Player<char>** SuS_TTT_UI::setup_players()
{
    Player<char>** players = new Player<char>*[2];
    vector<string> type_options = { "Human", "Computer" };
    //vector<string> status_options = { "Odd", "Even" };

    // Player 1
    string name1 = get_player_name("Player 1");
    PlayerType type1 = get_player_type_choice("Player 1", type_options);
    
    players[0] = create_player(name1, 's', type1);

    string name2 = get_player_name("Player 2");
    PlayerType type2 = get_player_type_choice("Player 2", type_options);
 
    players[1] = create_player(name2, 'u', type2);

    return players;
}


