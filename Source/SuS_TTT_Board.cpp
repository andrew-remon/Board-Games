#include "SuS_TTT_Board.h"
#include "SuS_TTT_Player.h"
#include <map>
#include <string>
#include <iostream>

map<string, bool> alreadyWon = {
    {"vertLeft"     , false},
    {"vertMid"      , false},
    {"vertRight"    , false},
    {"horzTop"      , false},
    {"horzMid"      , false},
    {"horzBot"      , false},
    {"diagOne"      , false},
    {"diagTwo"      , false}
};
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
        checkLatestBoard(alreadyWon);
        cout << "Score: P1:" << player1Sequences << " - P2:" << player2Sequences << endl;
        return true;
    }

    return false;
}

void SuS_TTT_Board::checkLatestBoard(map<string, bool>& winCondition ) {
    for (auto& it : winCondition) {
        const string& condition = it.first;
        bool& itsBool = it.second;

        if (!itsBool) {
                 if (condition == "vertLeft"    && (board[0][0] == 's' && board[1][0] == 'u' && board[2][0] == 's')) { (isFirst) ? player1Sequences++:player2Sequences++ ; itsBool = true; }
            else if (condition == "vertMid"     && (board[0][1] == 's' && board[1][1] == 'u' && board[2][1] == 's')) { (isFirst) ? player1Sequences++:player2Sequences++ ; itsBool = true; }
            else if (condition == "vertRight"   && (board[0][2] == 's' && board[1][2] == 'u' && board[2][2] == 's')) { (isFirst) ? player1Sequences++:player2Sequences++ ; itsBool = true; }
            else if (condition == "horzTop"     && (board[0][0] == 's' && board[0][1] == 'u' && board[0][2] == 's')) { (isFirst) ? player1Sequences++:player2Sequences++ ; itsBool = true; }
            else if (condition == "horzMid"     && (board[1][0] == 's' && board[1][1] == 'u' && board[1][2] == 's')) { (isFirst) ? player1Sequences++:player2Sequences++ ; itsBool = true; }
            else if (condition == "horzBot"     && (board[2][0] == 's' && board[2][1] == 'u' && board[2][2] == 's')) { (isFirst) ? player1Sequences++:player2Sequences++ ; itsBool = true; }
            else if (condition == "diagOne"     && (board[0][0] == 's' && board[1][1] == 'u' && board[2][2] == 's')) { (isFirst) ? player1Sequences++:player2Sequences++ ; itsBool = true; }
            else if (condition == "diagTwo"     && (board[0][2] == 's' && board[1][1] == 'u' && board[2][0] == 's')) { (isFirst) ? player1Sequences++:player2Sequences++ ; itsBool = true; }
        }
    }
}

bool SuS_TTT_Board::is_win(Player<char>* player)
{
    
    if (n_moves == 9) {
        return (isFirst) ? player1Sequences > player2Sequences : player2Sequences > player1Sequences;
    }
    return false;        
}
bool SuS_TTT_Board::is_lose(Player<char>* player)
{
    
    if (n_moves == 9) {
        return (isFirst) ? player1Sequences < player2Sequences : player2Sequences < player1Sequences;
    }
    return false;        
}


bool SuS_TTT_Board::is_draw(Player<char>* player)
{
    if (n_moves == 9 ) return player1Sequences == player2Sequences;
    isFirst = !isFirst;
    return false;
}

bool SuS_TTT_Board::game_is_over(Player<char>* player)
{
    return(is_win(player) || is_draw(player));
}