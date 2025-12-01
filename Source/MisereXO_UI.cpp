// MisereXO_UI.cpp
#include <iostream>
#include "InputValidation.h"
#include "MisereXO_UI.h"
using namespace std;

MisereXO_UI::MisereXO_UI() : UI<char>("Welcome to Our FCAI Misere X-O Game\n", 3)
{
    cout << "This is a Misere Tic Tac Toe Game played by two players.\n";
    cout << "The Rules are as following:\n";
    cout << "A player loses if they complete a line of three of their own marks.\n";
    cout << "If the board is filled with no player achieving three in a row, the game is a draw.\n";
    cout << "The objective is to force your opponent to get three-in-a-row\n";
    cout << "And to avoid placing three of your marks in a row, column, or diagonal.\n\n";


    srand(static_cast<unsigned int>(time(NULL)));
}

Player<char>* MisereXO_UI::create_player(string& name, char symbol, PlayerType type)
{
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer") << " player: " << name << " (" << symbol << ")\n";

    // return new Player<int>(name, type, status);
    return new Player<char>(name, symbol, type);
}

Move<char>* MisereXO_UI::get_move(Player<char>* player)
{
    int x, y;

    if (player->get_type() == PlayerType::HUMAN)
    {
        cout << "\nPlease enter your move square position in the form of x-axis and y-axis (0 to 2): ";
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

Player<char>** MisereXO_UI::setup_players()
{
    Player<char>** players = new Player<char>*[2];
    vector<string> type_options = { "Human", "Computer" };
    
    string labelX = "Player X";
    string labelO = "Player O";
    
    char symbolX = 'X';
    char symbolO = 'O';

    // Player 1
    string name1 = get_player_name(labelX);
    PlayerType type1 = get_player_type_choice(labelX, type_options);
    players[0] = create_player(name1, symbolX, type1);

    // Player 2
    string name2 = get_player_name(labelO);
    PlayerType type2 = get_player_type_choice(labelO, type_options);
    players[1] = create_player(name2, symbolO, type2);

    return players;
}
