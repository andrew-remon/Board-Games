#include "4X4board.h"
#include <cmath> 


Board4X4::Board4X4() : Board<char>(4, 4) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            board[i][j] = ' ';
        }
    }

    board[0][0] = 'O'; board[0][1] = 'X'; board[0][2] = 'O'; board[0][3] = 'X';

    board[3][0] = 'X'; board[3][1] = 'O'; board[3][2] = 'X'; board[3][3] = 'O';
}


bool Board4X4::update_board(Move<char>* move) {
    
    Move4X4* m = (Move4X4*)move;

    
    int fx = m->get_from_x();
    int fy = m->get_from_y();
    int tx = m->get_x();     
    int ty = m->get_y();
    char symbol = m->get_symbol();

	// ===== Rule Checks =====

    if (fx < 0 || fx >= rows || fy < 0 || fy >= columns) return false;
    if (tx < 0 || tx >= rows || ty < 0 || ty >= columns) return false;
    if (board[tx][ty] != ' ')                            return false;
    if (board[fx][fy] != symbol)                         return false;
    if (abs(tx - fx) + abs(ty - fy) != 1)                return false;

    board[tx][ty] = symbol; 
    board[fx][fy] = ' ';    
    n_moves++;
    return true;
}

bool Board4X4::is_win(Player<char>* player) {
    char s = player->get_symbol();

    for (int i = 0; i < 4; i++) {
		// ==== Horizontal Checks =====
        if ((board[i][0] == s && board[i][1] == s && board[i][2] == s) ||
            (board[i][1] == s && board[i][2] == s && board[i][3] == s)) return true;

		// ==== Vertical Checks =====

        if ((board[0][i] == s && board[1][i] == s && board[2][i] == s) ||
            (board[1][i] == s && board[2][i] == s && board[3][i] == s)) return true;
    }

	// ==== Diagonal Checks =====
    if (board[0][0] == s && board[1][1] == s && board[2][2] == s) return true;
    if (board[1][1] == s && board[2][2] == s && board[3][3] == s) return true;
    if (board[0][1] == s && board[1][2] == s && board[2][3] == s) return true;
    if (board[1][0] == s && board[2][1] == s && board[3][2] == s) return true;

    if (board[0][3] == s && board[1][2] == s && board[2][1] == s) return true;
    if (board[1][2] == s && board[2][1] == s && board[3][0] == s) return true;
    if (board[0][2] == s && board[1][1] == s && board[2][0] == s) return true;
    if (board[1][3] == s && board[2][2] == s && board[3][1] == s) return true;

    return false;
}

bool Board4X4::is_draw(Player<char>* player) {
    return false;
}

bool Board4X4::game_is_over(Player<char>* player) {
    return is_win(player);
}

bool Board4X4::is_lose(Player<char>* player) {
    return false;
}