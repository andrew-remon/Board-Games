// NumXO_UI.cpp
#include "MisereXO_Board.h"

MisereXO_Board::MisereXO_Board() : Board<char>(3, 3)
{
    n_moves = 0;
    for (auto& row : board)
    {
        for (auto& cell : row) cell = ' ';
    }
}

bool MisereXO_Board::update_board(Move<char>* move)
{
    int x = move->get_x();
    int y = move->get_y();
    char symbol = move->get_symbol();

    if ((x >= 0 && x < rows) && (y >= 0 && y < columns) && (board[x][y] == ' '))
    {
        // Apply move
        n_moves++;
        board[x][y] = symbol;
        return true;
    }

    return false;
}

bool MisereXO_Board::is_win(Player<char>* player)
{
    return false;
}

bool MisereXO_Board::is_lose(Player<char>* player)
{
    char s = player->get_symbol();

    for (int i = 0; i < rows; i++)
    {
        if ((board[i][0] == s && board[i][1] == s && board[i][2] == s)

            ||

            (board[0][i] == s && board[1][i] == s && board[2][i] == s))
        {
            return true;
        }
    }

    if ((board[0][0] == s && board[1][1] == s && board[2][2] == s)
    
        ||

        (board[0][2] == s && board[1][1] == s && board[2][0] == s))
    {
        return true;
    }

    return false;
}

bool MisereXO_Board::is_draw(Player<char>* player)
{
    if (n_moves == 9 && !is_win(player) && !is_lose(player)) return true;

    return false;
}

bool MisereXO_Board::game_is_over(Player<char>* player)
{
    return(is_win(player) || is_draw(player) || is_lose(player));
}
