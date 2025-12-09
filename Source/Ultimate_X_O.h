#pragma once

#ifndef ULTIMATE_X_O_H
#define ULTIMATE_X_O_H

#include "BoardGame_Classes.h"
using namespace std;

class Ultimate_X_O_Board : public Board<char> {
public:

	struct smallboardIdentity {
		string name;
		bool x_won;
		bool o_won;
	};

	vector <smallboardIdentity> smallBoards = {
		{"TopLeft",   false, false},
		{"TopMid",    false, false},
		{"TopRight",  false, false},
		{"MidLeft",   false, false},
		{"MidMid",    false, false},
		{"MidRight",  false, false},
		{"BotLeft",   false, false},
		{"BotMid",    false, false},
		{"BotRight",  false, false}
	};

	Ultimate_X_O_Board();
	~Ultimate_X_O_Board();

	bool check_win(int Xstart, int Xend, int Ystart, int Yend, char symbol, bool& winFlag);

	void loopBoardAndFillBlanks(int xstart , int ystart , int xend ,int yend ,char symbol);

	void checksmallWin(char symbol, string& s , bool& b);

	void checkoverallwin();
	bool update_board(Move<char>* move) override;
	bool is_win(Player<char>* player) override;
	bool is_draw(Player<char>* player) override;
	bool is_lose(Player<char>* player) {return false;};
	bool game_is_over(Player<char>* player) override;
};
class Ultimate_X_O_UI : public UI<char> {
public:
	struct smallboardIdentity {
		string name;
		bool x_won;
		bool o_won;
	};

	vector <smallboardIdentity> smallBoards = {
		{"TopLeft",   false, false},
		{"TopMid",    false, false},
		{"TopRight",  false, false},
		{"MidLeft",   false, false},
		{"MidMid",    false, false},
		{"MidRight",  false, false},
		{"BotLeft",   false, false},
		{"BotMid",    false, false},
		{"BotRight",  false, false}
	};
	Ultimate_X_O_UI();
	~Ultimate_X_O_UI() {};

	Player<char>* create_player(string& name, char symbol, PlayerType type);
	Move<char>* get_move(Player<char>* player);
};

#endif // ULTIMATE_X_O_H