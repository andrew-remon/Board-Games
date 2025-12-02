#include "Connect_4.h"
#include <time.h>
using namespace std;

connect_4_Board::connect_4_Board() : Board(6, 7)
{
	for (auto& row : board)
		for (auto& cell : row)
			cell = blank_symbol;
}
connect_4_Board::~connect_4_Board() {}

bool connect_4_Board::update_board(Move<char>* move)
{
	int col = move->get_y();
	for (int row = rows - 1; row >= 0; --row) {
		if (board[row][col] == blank_symbol) {
			board[row][col] = move->get_symbol();
			n_moves++;
			return true;
		}
	}
	return false; 
}

bool connect_4_Board::is_win(Player<char>* player)
{
	char sym = player->get_symbol();

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			if (board[i][j] == sym) {
				// ======== Horizontal Check =======
				if (j + 3 < columns && board[i][j + 1] == sym && board[i][j + 2] == sym && board[i][j + 3] == sym)
					return true;
				// ======== Vertical Check =======

				if (i + 3 < rows && board[i + 1][j] == sym && board[i + 2][j] == sym && board[i + 3][j] == sym)
					return true;
				// ======== Diagonal Right Check =======
				if (i + 3 < rows && j + 3 < columns && board[i + 1][j + 1] == sym && board[i + 2][j + 2] == sym && board[i + 3][j + 3] == sym)
					return true; 
				// ======== Diagonal Left Check ======= 
				if (i + 3 < rows && j - 3 >= 0 && board[i + 1][j - 1] == sym && board[i + 2][j - 2] == sym && board[i + 3][j - 3] == sym)
					return true;
			}
		}
	}
	return false;
}
bool connect_4_Board::is_draw(Player<char>* player)
{
	return n_moves == 42;
}

bool connect_4_Board::game_is_over(Player<char>* player)
{
	return is_win(player) || is_draw(player);
}


connect_4_UI::connect_4_UI() : UI() {}


Player<char>* connect_4_UI::create_player(string& name, char symbol, PlayerType type)
{
	return new Player<char>(name, symbol , type);
}

Move<char>* connect_4_UI::get_move(Player<char>* player)
{
	if (player->get_type() == PlayerType::HUMAN) {
		int col;
		cout << player->get_name() << " (" << player->get_symbol() << "), enter column (0-6): ";
		cin >> col;
		return new Move<char>(0, col, player->get_symbol());
	}
	else {
		int col;
		col = rand() % 7;
		cout << player->get_name() << " (" << player->get_symbol() << ") chooses column " << col << "\n";
		return new Move<char>(0, col, player->get_symbol());
	}
}