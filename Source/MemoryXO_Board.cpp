// MemoryXO_Board.cpp
#include "MemoryXO_Board.h"

MemoryXO_Board::MemoryXO_Board() : Board<char>(3, 3)
{
    n_moves = 0;
    for (auto& row : board)
    {
        for (auto& cell : row) cell = ' ';
    }
}

bool MemoryXO_Board::update_board(Move<char>* move)
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

bool MemoryXO_Board::is_win(Player<char>* player)
{
    char s = player->get_symbol(); // s for symbol
    for(int i = 0; i < 3; i++)
    {
        if (board[i][0] == s && board[i][1] == s && board[i][2] == s) { return true; }
    }
    for(int i = 0; i < 3; i++)
    {
        if (board[0][i] == s && board[1][i] == s && board[2][i] == s) { return true; }
    }

    if((board[0][0] == s && board[1][1] == s && board[2][2] == s) ||
    (board[2][0] == s && board[1][1] == s && board[0][2] == s)) {return true; }
    return false;
}

bool MemoryXO_Board::is_lose(Player<char>* player)
{
    return false;
}

bool MemoryXO_Board::is_draw(Player<char>* player)
{
    return (this->n_moves >= 9) && !is_win(player);
}

bool MemoryXO_Board::game_is_over(Player<char>* player)
{
    return(is_win(player) || is_draw(player));
}
