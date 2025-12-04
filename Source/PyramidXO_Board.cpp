// PyramidXO_Board.cpp
#include "PyramidXO_Board.h"

PyramidXO_Board::PyramidXO_Board() : Board<char>(3, 5)
{
    n_moves = 0;
    for (auto& row : board)
    {
        for (auto& cell : row) cell = ' ';
    }
}

bool PyramidXO_Board::update_board(Move<char>* move)
{
    int x = move->get_x();
    int y = move->get_y();
    char symbol = move->get_symbol();

    if (x >= 0 && x < this->rows && y >= 0 && y < this->columns && (this -> board[x][y] == ' '))
    {
        // Apply move
        this -> n_moves++;
        this -> board[x][y] = symbol;
        return true;
    }
    return false;
}

bool PyramidXO_Board::is_win(Player<char>* player)
{
    char s = player->get_symbol(); // s for symbol
    
    // Vertical Win
    if (board[0][2] == s && board[1][2] == s && board[2][2] == s) return true;

    // Row 1
    if (board[1][1] == s && board[1][2] == s && board[1][3] == s) return true;

    // Row 2
    if (board[2][0] == s && board[2][1] == s && board[2][2] == s) return true;
    if (board[2][1] == s && board[2][2] == s && board[2][3] == s) return true;
    if (board[2][2] == s && board[2][3] == s && board[2][4] == s) return true;

    // Left Diagonal
    if (board[0][2] == s && board[1][1] == s && board[2][0] == s) return true;

    // Right Diagonal
    if (board[0][2] == s && board[1][3] == s && board[2][4] == s) return true; 
    return false;
}

bool PyramidXO_Board::is_lose(Player<char>* player)
{
    return false;
}

bool PyramidXO_Board::is_draw(Player<char>* player)
{
    return (this->n_moves >= 9) && !is_win(player);
}

bool PyramidXO_Board::game_is_over(Player<char>* player)
{
    return(is_win(player) || is_draw(player));
}

static bool is_in_pyramid(int i, int j)
{
    return (j >= 0 && j < 5 && i >= 0 && i < 3) && (abs(j - 2) <= i);
}
