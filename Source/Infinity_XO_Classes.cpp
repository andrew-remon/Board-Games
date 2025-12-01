//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <iomanip>
#include <cctype>  // for toupper()
#include "Infinity_XO_Classes.h"

using namespace std;

//--------------------------------------- X_O_Board Implementation

inf_X_O_Board::inf_X_O_Board() : Board(3, 3)
{
    // Initialize all cells with blank_symbol
    for (auto& row : board)
        for (auto& cell : row)
            cell = blank_symbol;
}

bool inf_X_O_Board::update_board(Move<char>* move)
{
    int x = move->get_x();
    int y = move->get_y();
    char mark = move->get_symbol();

    // Validate move and apply if valid
    if (!(x < 0 || x >= rows || y < 0 || y >= columns) && (board[x][y] == blank_symbol || mark == 0))
    {
        if (mark == 0)
        { // Undo move
            n_moves--;
            board[x][y] = blank_symbol;
        }
        else
        {
            // Apply move
            n_moves++;
            board[x][y] = toupper(mark);
            q_moves.push({x,y}); // to save moves by order
        }

        if (n_moves % 3 == 0)
        {
            // save old coordinates;
            int oldest_move_x = q_moves.front().first;
            int oldest_move_y = q_moves.front().second;

            // remove it from the queue
            q_moves.pop();

            // return it to blank symbol
            board[oldest_move_x][oldest_move_y] = blank_symbol;
        }
        return true;
    }
    return false;
}

bool inf_X_O_Board::is_win(Player<char>* player)
{
    const char sym = player->get_symbol();

    auto all_equal = [&](char a, char b, char c)
    {
        return a == b && b == c && a != blank_symbol;
    };

    // Check rows and columns
    for (int i = 0; i < rows; ++i)
    {
        if ((all_equal(board[i][0], board[i][1], board[i][2]) && board[i][0] == sym) ||
            (all_equal(board[0][i], board[1][i], board[2][i]) && board[0][i] == sym))
            return true;
    }

    // Check diagonals
    if ((all_equal(board[0][0], board[1][1], board[2][2]) && board[1][1] == sym) ||
        (all_equal(board[0][2], board[1][1], board[2][0]) && board[1][1] == sym))
        return true;

    return false;
}

bool inf_X_O_Board::is_draw(Player<char>* player) {
    return false;
}

bool inf_X_O_Board::game_is_over(Player<char>* player) {
    return is_win(player) || is_draw(player);
}

//------------------- XO_UI Implementation --------------------

inf_XO_UI::inf_XO_UI() : UI<char>("Welcome to Our FCAI Infinity X-O Game\n", 3)
{
    cout << "This is a regular 3x3 Tic Tac Toe Game note that:\n";
    cout << "[1] After every three moves, the oldest mark on the board disappears.\n";
    cout << "[2] The first player to align three marks in a row before any of those marks vanish wins the game\n\n";

    srand(static_cast<unsigned int>(time(NULL)));
}

Player<char>* inf_XO_UI::create_player(string& name, char symbol, PlayerType type)
{
    // Create player based on type
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer")
        << " player: " << name << " (" << symbol << ")\n\n";

    return new Player<char>(name, symbol, type);
}

Move<char>* inf_XO_UI::get_move(Player<char>* player)
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
    }

    return new Move<char>(x, y, player->get_symbol());
}
