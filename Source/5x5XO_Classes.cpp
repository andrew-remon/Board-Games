//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <iomanip>
#include <cctype>  // for toupper()
#include "5x5XO_Classes.h"

using namespace std;

//--------------------------------------- X_O_Board Implementation

_5X5_X_O_Board::_5X5_X_O_Board() : Board(5, 5)
{
    // Initialize all cells with blank_symbol
    for (auto& row : board)
        for (auto& cell : row)
            cell = blank_symbol;
}

bool _5X5_X_O_Board::update_board(Move<char>* move)
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
        }
        return true;
    }
    return false;
}

bool _5X5_X_O_Board::is_win(Player<char> * player)
{
    if (n_moves == 24)
    {
        countSequences('X');
        countSequences('O');

        const char sym = player->get_symbol();
        cout << "X_sequences: " << getPlayerXSequences() << "\n";
        cout << "O-sequences: " << getPlayerOSequences() << "\n\n";

        if (sym == 'X')
        {
            if (getPlayerXSequences() > getPlayerOSequences())
                return true;
        }

        if (sym == 'O')
        {
            if (getPlayerOSequences() > getPlayerXSequences())
                return true;
        }
    }

    return false;
}

bool _5X5_X_O_Board::is_lose(Player<char> * player)
{
    if (n_moves == 24)
    {

        const char sym = player->get_symbol();
        if (sym == 'X')
        {
            if (getPlayerXSequences() < getPlayerOSequences())
                return true;
        }

        if (sym == 'O')
        {
            if (getPlayerOSequences() < getPlayerXSequences())
                return true;
        }
    }

    return false;
}

bool _5X5_X_O_Board::is_draw(Player<char> * player)
{
    return (n_moves == 24 && playerOSequences == playerXSequences);
}

bool _5X5_X_O_Board::game_is_over(Player<char> * player)
{
    return (n_moves == 24 && (is_win(player) || is_draw(player)));
}

void _5X5_X_O_Board::countSequences(char sym)
{
    auto all_equal = [&](char a, char b, char c)
    {
        return a == b && b == c && a != blank_symbol;
    };

    if (n_moves == 24)
    {
        // ---------- HORIZONTAL ----------
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= columns - 3; j++)
        {
            if (all_equal(board[i][j], board[i][j+1], board[i][j+2]) &&
                board[i][j] == sym)
            {
                if (sym == 'X') incrementPlayerXSequences();
                else incrementPlayerOSequences();
            }
        }
    }

    // ---------- VERTICAL ----------
    for (int i = 0; i <= rows - 3; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (all_equal(board[i][j], board[i+1][j], board[i+2][j]) &&
                board[i][j] == sym)
            {
                if (sym == 'X') incrementPlayerXSequences();
                else incrementPlayerOSequences();
            }
        }
    }

    // ---------- DIAGONALS (↘) ----------
    for (int i = 0; i <= rows - 3; i++)
    {
        for (int j = 0; j <= columns - 3; j++)
        {
            if (all_equal(board[i][j], board[i+1][j+1], board[i+2][j+2]) &&
                board[i][j] == sym)
            {
                if (sym == 'X') incrementPlayerXSequences();
                else incrementPlayerOSequences();
            }
        }
    }

    // ---------- DIAGONALS (↙) ----------
    for (int i = 0; i <= rows - 3; i++)
    {
        for (int j = 2; j < columns; j++)
        {
            if (all_equal(board[i][j], board[i+1][j-1], board[i+2][j-2]) &&
                board[i][j] == sym)
            {
                if (sym == 'X') incrementPlayerXSequences();
                else incrementPlayerOSequences();
            }
        }
    }
    }
}

//------------------- XO_UI Implementation --------------------

_5X5_XO_UI::_5X5_XO_UI() : UI<char>("Welcome to OUr 5x5 FCAI X-O Game\n", 5)
{
    cout << "This is just like the regular X-O Game Except that:\n";
    cout << "[1] It's 5x5 table, so each player has only 12 moves with one square empty at the end of the game\n";
    cout << "[2] each player try to have the most three-in-a-row sequence to win\n\n";


    srand(static_cast<unsigned int>(time(NULL)));
}

Player<char>* _5X5_XO_UI::create_player(string& name, char symbol, PlayerType type)
{
    // Create player based on type
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer")
        << " player: " << name << " (" << symbol << ")\n";

    return new Player<char>(name, symbol, type);
}

Move<char>* _5X5_XO_UI::get_move(Player<char>* player)
{
    int x, y;

    if (player->get_type() == PlayerType::HUMAN)
    {
        cout << "\nPlease enter your move x and y (0 to 4): ";
        cin >> x >> y;
    }

    else if (player->get_type() == PlayerType::COMPUTER)
    {
        x = rand() % player->get_board_ptr()->get_rows();
        y = rand() % player->get_board_ptr()->get_columns();
    }

    return new Move<char>(x, y, player->get_symbol());
}
