#include "SuS_TTT_Board.h"

SuS_TTT_Board::SuS_TTT_Board() : Board(3, 3) {
    for (auto& row : board)
    {
        for (auto& cell : row) cell = this->defaultValue;
    }

}

bool SuS_TTT_Board::is_cell_empty(char cell)
{
    return cell == this->defaultValue;
}

bool SuS_TTT_Board::update_board(Move<char>* move)
{
    int x = move->get_x();
    int y = move->get_y();
    char symbol = move->get_symbol();

    if ((x >= 0 && x < rows) && (y >= 0 && y < columns) && is_cell_empty(board[x][y]))
    {
        // Apply move
        n_moves++;
        board[x][y] = symbol;
        return true;
    }

    return false;
}

bool SuS_TTT_Board::is_win(Player<char>* player)
{
    for (int i = 0; i < rows; i++) {
        //Diagonal Checks
        if (    (board[0][0] == 's' && board[1][1] == 'u' && board[2][2] == 's')
            ||  (board[0][2] == 's' && board[1][1] == 'u' && board[2][0] == 's'))
        {
            cout << "Diagonal Win" << endl;
            return true;}
        //Horizontal Checks
        if (   (board[0][0] == 's' && board[0][1] == 'u' && board[0][2] == 's')
            || (board[1][0] == 's' && board[1][1] == 'u' && board[1][2] == 's')
            || (board[2][0] == 's' && board[2][1] == 'u' && board[2][2] == 's'))
        {
            cout << "Horizontal Win" << endl;
            return true;
        }
        
        //Vertical Checks
        if (   (board[0][0] == 's' && board[1][0] == 'u' && board[2][0] == 's')
            || (board[0][1] == 's' && board[1][1] == 'u' && board[2][1] == 's')
            || (board[0][2] == 's' && board[1][2] == 'u' && board[2][2] == 's'))
        {
            cout << "Vertical Win" << endl; 
            return true;
        }
            
    }    
    return false;
}


bool SuS_TTT_Board::is_draw(Player<char>* player)
{
    if (n_moves == 9 && !is_win(player)) return true;

    return false;
}

bool SuS_TTT_Board::game_is_over(Player<char>* player)
{
    return(is_win(player) || is_draw(player));
}