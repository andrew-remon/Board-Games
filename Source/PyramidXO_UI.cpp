// PyramidXO_UI.cpp
#include <iostream>
#include <cmath>
#include "InputValidation.h"
#include "PyramidXO_UI.h"
using namespace std;

bool PyramidXO_UI::is_in_pyramid(int i, int j) const
{
    return ( i >= 0 && i < 3 && j >= 0 && j < 5) && (abs(j - 2) <= i);
}

PyramidXO_UI::PyramidXO_UI() : UI<char>("\nWelcome to Our FCAI Pyramid X-O Game\n", 3)
{
    cout << "This is a Pyramid Tic Tac Toe Game played by two players.\n";
    cout << "The Rules are as following:\n";
    cout << "Players take turns placing their 'X' or 'O' marks in empty squares.\n";
    cout << "The first player to align three of their marks horizontally, vertically, or diagonally wins.\n\n";
}

Player<char>* PyramidXO_UI::create_player(string& name, char symbol, PlayerType type)
{
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer") << " player: " << name << " (" << symbol << ")\n";

    // return new Player<int>(name, type, status);
    return new Player<char>(name, symbol, type);
}

Move<char>* PyramidXO_UI::get_move(Player<char>* player)
{
    int x, y;

    if (player->get_type() == PlayerType::HUMAN)
    {
        cout << "\nPlease enter your move square position in the form of x-axis (0 to 4) and y-axis (0 to 2): ";
        cin >> x >> y;
    }
    else if (player->get_type() == PlayerType::COMPUTER)
    {
        int rows = player->get_board_ptr()->get_rows();
        int columns = player->get_board_ptr()->get_columns();
        bool valid_move_found = false;

        while(!valid_move_found)
        {
            x = rand() % rows;
            y = rand() % columns;

            Board<char>* boardPtr = player->get_board_ptr();
            char cell_content = boardPtr->get_cell(x, y);
            if (cell_content == ' ' && is_in_pyramid(x, y))
            {
                valid_move_found = true;
            }
        }
        cout << player->get_name() << " chose position (" << x << ", " << y << ")\n";
    }

    // update symbol
    return new Move<char>(x, y, player->get_symbol());
}

Player<char>** PyramidXO_UI::setup_players()
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

void PyramidXO_UI::display_board_matrix(const vector<vector<char>>& matrix) const
{
    if (matrix.empty() || matrix[0].empty()) return;

    int rows = matrix.size();
    int cols = matrix[0].size();
    int cell_width = this->cell_width;

    cout << "\n    ";
    for (int j = 0; j < cols; j++)
    {
        cout << setw(cell_width) << j << "  ";
    }
    cout << "\n";

    cout << "   " << string((cell_width + 2) * cols, '-') << "\n";
    for (int i = 0; i < rows; i++)
    {
        cout << setw(2) << i << " |";

        for (int j = 0; j < cols; j++)
        {
            if (is_in_pyramid(i, j))
            {
                cout << setw(cell_width) << matrix[i][j] << " |";
            }
            else
            {
                cout << setw(cell_width) << '#' << " |";
            }
        }
        cout << "\n";

        cout << "   " << string((cell_width + 2) * cols, '-') << "\n";
    }
    cout << endl;
}