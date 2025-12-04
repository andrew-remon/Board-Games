// OsbtacleXO_Board.cpp
#include "ObstacleXO_Board.h"

ObstacleXO_Board::ObstacleXO_Board() : Board<char>(6, 6)
{
    n_moves = 0;
    for (auto& row : board)
    {
        for (auto& cell : row) cell = ' ';
    }
}

bool ObstacleXO_Board::update_board(Move<char>* move)
{
    int x = move->get_x();
    int y = move->get_y();
    char symbol = move->get_symbol();

    if (x >= 0 && x < this->rows && y >= 0 && y < this->columns && (this -> board[x][y] == ' '))
    {
        // Apply move
        this -> n_moves++;
        this -> board[x][y] = symbol;
        if (n_moves % 2 == 0)
        {
            int obstacles_placed = 0;
            while (obstacles_placed < 2 && (this->n_moves + obstacles_placed < 36))
            {
                int r_x = rand() % this->rows;
                int r_y = rand() % this->columns;

                if (this->board[r_x][r_y] == ' ')
                {
                    this->board[r_x][r_y] = '#';
                    obstacles_placed++;
                }
            }
        }
        return true;
    }
    return false;
}

bool ObstacleXO_Board::is_win(Player<char>* player)
{
    char s = player->get_symbol(); // s for symbol
    for (int i = 0; i < 6; i++)
    {
        for(int j =0 ; j < 3;j++)
        {
            if(board[i][0 + j] == s && board[i][1 + j] == s
            && board[i][2 + j] == s && board[i][3 + j] == s){ return true;}
        }
    }

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3;j++)
        {
            if (board[0 + j][i] == s && board[1 + j][i] == s
             && board[2 + j][i] == s && board[3 + j][i] == s){ return true;}
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == s && board[i + 1][j + 1] == s &&
                board[i + 2][j + 2] == s && board[i + 3][j + 3] == s)
            {
                return true;
            }
        }
    }

    for (int i = 3; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == s && board[i - 1][j + 1] == s &&
                board[i - 2][j + 2] == s && board[i - 3][j + 3] == s)
            {
                return true;
            }
        }
    }
    return false;
}

bool ObstacleXO_Board::is_lose(Player<char>* player)
{
    return false;
}

bool ObstacleXO_Board::is_draw(Player<char>* player)
{
    return (this->n_moves >= 18) && !is_win(player);
}

bool ObstacleXO_Board::game_is_over(Player<char>* player)
{
    return(is_win(player) || is_draw(player));
}
