#include "NumXO_Board.h"

NumXO_Board::NumXO_Board() : Board(3,3)
{
    for (auto& row : board)
    {
        for(auto& cell : row) cell = defaultValue;
    }
}

bool NumXO_Board::is_cell_empty(int cell)
{
    return cell == defaultValue;
}

bool NumXO_Board::update_board(Move<int>* move)
{
    int x = move->get_x();
    int y = move->get_y();
    int symbol = move->get_symbol();

    if ((x >= 0 && x <= rows) && (y >= 0 && y <= columns) && is_cell_empty(board[x][y]))
    {
        // Apply move
        n_moves++;
        board[x][y] = symbol;
        return true;
    }

    return false;
}

bool NumXO_Board::is_win(Player<int>* player)
{
    int winValue = 15;

    for (int i = 0; i < rows; i++)
    {
        if (board[i][0] + board[i][1] + board[i][2] == winValue
            || board[0][i] + board[1][i] + board[2][i] == winValue) return true;
    }

    if (board[0][0] + board[1][1] + board[2][2] == winValue
        || board[0][2] + board[1][1] + board[2][0] == winValue) return true;

    return false;
}

bool NumXO_Board::is_draw(Player<int>* player)
{
    if (n_moves == 9 && !is_win(player)) return true;

    return false;
}

bool NumXO_Board::game_is_over(Player<int>* player)
{
    return(is_win(player) || is_draw(player));
}
