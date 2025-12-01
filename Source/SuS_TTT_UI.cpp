#include <iostream>
#include "InputValidation.h"
#include "SuS_TTT_UI.h"
using namespace std;

SuS_TTT_UI::SuS_TTT_UI() : UI<char>("Welcome to Our FCAI SuS X-O Game\n", 3)
{
    cout << "This is a SuS Tic Tac Toe Game played by two players.\n";
    cout << "The Rules are as following:\n";
    cout << "Players take turns placing either an \"S\" or a \"U\" in an empty square.\n";
    cout << "A player must use the same letter each turn.\n";

    srand(static_cast<unsigned int>(time(NULL)));
}

Player<char>* SuS_TTT_UI::create_player(string& name, char symbol, PlayerType type)
{
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer") << " player: " << name << " (" << symbol << ")\n";

    
    return new Player<char>(name, symbol, type);
}

Move<char>* SuS_TTT_UI::get_move(Player<char>* player)
{
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

    return new Move<char>(x, y, player->get_symbol());
}



Player<char>** SuS_TTT_UI::setup_players()
{
    Player<char>** players = new Player<char>*[2];
    vector<string> type_options = { "Human", "Computer" };
    

    // Player 1
    string name = get_player_name("Player S");
    PlayerType type = get_player_type_choice("Player 1", type_options);
    players[0] = create_player(name, 's', type);
    
    // Player 2
    name = get_player_name("Player U");
    type = get_player_type_choice("Player 2", type_options);
    players[1] = create_player(name, 'u', type);
 
    return players;
}


