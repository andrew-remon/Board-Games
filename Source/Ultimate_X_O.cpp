#include "Ultimate_X_O.h"
#include "inputValidation.h"

Ultimate_X_O_Board::Ultimate_X_O_Board() : Board<char>(9,9) {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			board[i][j] = ' ';
		}
	}
}
Ultimate_X_O_Board::~Ultimate_X_O_Board() {}


bool Ultimate_X_O_Board::update_board(Move<char>* move) {
	int x = move->get_x();
	int y = move->get_y();

	// ======== validate input ========
	if (x < 0 || x >= rows || y < 0 || y >= columns) {
		return false; 
	}
	if (board[x][y] != ' ') {
		return false; 
	}
	// ======== make move ========
	board[x][y] = move->get_symbol();
	n_moves++; 
	return true;
}
bool Ultimate_X_O_Board::is_win(Player<char>* player) {


	
	return false;
}
bool Ultimate_X_O_Board::is_draw(Player<char>* player) {
	return n_moves == 81;
}
bool Ultimate_X_O_Board::game_is_over(Player<char>* player) {
	return is_win(player) || is_draw(player);
}


Ultimate_X_O_UI::Ultimate_X_O_UI() {};

Player<char>* Ultimate_X_O_UI::create_player(string& name, char symbol, PlayerType type) {
	return new Player<char>(name, symbol, type);
}
Move<char>* Ultimate_X_O_UI::get_move(Player<char>* player) {
	if (player->get_type() == PlayerType::HUMAN) {
		int x = InputValidation::readIntNumberBetween(0, 8, player->get_name() + ", enter row (0-8): ");
		int y = InputValidation::readIntNumberBetween(0, 8, player->get_name() + ", enter column (0-8): ");
		return new Move<char>(x, y, player->get_symbol());
	}
	else
	{
		int x = rand() % 9;
		int y = rand() % 9;
		return new Move<char>(x, y, player->get_symbol());
	}
}

