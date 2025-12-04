// OsbtacleXO_UI.cpp
#include <iostream>
#include <cmath>
#include "InputValidation.h"
#include "ObstacleXO_UI.h"
using namespace std;

ObstacleXO_UI::ObstacleXO_UI() : UI<char>("\nWelcome to Our FCAI Obstacle X-O Game\n", 3)
{
    cout << "This is a Osbtacle Tic Tac Toe Game played by two players.\n";
    cout << "The Rules are as following:\n";
    cout << "After every round (one turn for each player), two new obstacle cells are randomly added to the \n";
    cout << "board. These cells cannot be used by either player.\n";
    cout << "The first player to align four of their marks in a row(horizontally, vertically, or \n";
    cout << "diagonally) wins.The game is a draw if the board fills without a winner.\n\n";
}

Player<char>* ObstacleXO_UI::create_player(string& name, char symbol, PlayerType type)
{
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer") << " player: " << name << " (" << symbol << ")\n";

    // return new Player<int>(name, type, status);
    return new Player<char>(name, symbol, type);
}

Move<char>* ObstacleXO_UI::get_move(Player<char>* player)
{
    int x, y;

    if (player->get_type() == PlayerType::HUMAN)
    {
        cout << "\nPlease enter your move square position in the form of x-axis and y-axis (0 to 5): ";
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

Player<char>** ObstacleXO_UI::setup_players()
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

void ObstacleXO_UI::display_board_matrix(const vector<vector<char>>& matrix) const
{
    if (matrix.empty() || matrix[0].empty()) return;

    int rows = matrix.size();
    int cols = matrix[0].size();
    int cell_width = this->cell_width;

    cout << "\n    ";

    for (int j = 0; j < cols; ++j)
    {
        cout << setw(cell_width) << j << "  ";
    }

    cout << "\n";
    cout << "   " << string((cell_width + 2) * cols + 1, '-') << "\n";

    for (int i = 0; i < rows; ++i)
    {
        cout << setw(2) << i << " |";
        
        for (int j = 0; j < cols; ++j)
        {
            cout << setw(cell_width) << matrix[i][j] << " |";
        }

        cout << "\n";
        cout << "   " << string((cell_width + 2) * cols + 1, '-') << "\n";
    }
    cout << endl;
}