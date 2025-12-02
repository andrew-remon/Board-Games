#pragma once

#ifndef ULTIMATE_X_O_H
#define ULTIMATE_X_O_H

#include "BoardGame_Classes.h"
using namespace std;

class Ultimate_X_O_Board : public Board<char> {
public:
	Ultimate_X_O_Board();
	~Ultimate_X_O_Board();

	bool update_board(Move<char>* move) override;
	bool is_win(Player<char>* player) override;
	bool is_draw(Player<char>* player) override;
	bool is_lose(Player<char>* player) {return false;};
	bool game_is_over(Player<char>* player) override;
};
class Ultimate_X_O_UI : public UI<char> {
public:
	Ultimate_X_O_UI();
	~Ultimate_X_O_UI() {};

	Player<char>* create_player(string& name, char symbol, PlayerType type);
	Move<char>* get_move(Player<char>* player);
};

#endif // ULTIMATE_X_O_H