#include "Ultimate_X_O.h"
#include "inputValidation.h"
#include <map>



//map<string, pair<bool, bool>> alreadyWon = {
//	{"TopLeft",   std::make_pair(false, false)},
//	{"TopMid",    std::make_pair(false, false)},
//	{"TopRight",  std::make_pair(false, false)},
//	{"MidLeft",   std::make_pair(false, false)},
//	{"MidMid",    std::make_pair(false, false)},
//	{"MidRight",  std::make_pair(false, false)},
//	{"BotLeft",   std::make_pair(false, false)},
//	{"BotMid",    std::make_pair(false, false)},
//	{"BotRight",  std::make_pair(false, false)}
//};

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

    // ======== update board ========
    for (auto& entry : smallBoards) {
        if (entry.x_won || entry.o_won) continue;

        if (move->get_symbol() == 'X') {
            checksmallWin('X', entry.name, entry.x_won);
        }
        else {
            checksmallWin('O', entry.name, entry.o_won);
        }
    }
    
    return true;
}

bool Ultimate_X_O_Board::check_win(int Xstart, int Xend,int Ystart  ,int Yend  ,char symbol, bool& winFlag) {
	// ====== horizontal check =======
	for (int i = Xstart; i <= Xend; i++) {
		if (board[i][Ystart] == symbol && board[i][Ystart + 1] == symbol && board[i][Ystart + 2] == symbol) {
			winFlag = true;
			return winFlag;
		}
	}
	// ====== vertical check =========
	for (int i = Ystart; i <= Yend; i++) {
		if (board[Xstart][i] == symbol && board[Xstart + 1][i] == symbol && board[Xstart + 2][i] == symbol) {
			winFlag = true;
			return winFlag;
		}
	}
	// ====== diagonal check ========
	if (board[Xstart][Ystart] == symbol && board[Xstart + 1][Ystart + 1] == symbol && board[Xstart + 2][Ystart + 2] == symbol) {
		winFlag = true;
		return winFlag;
	}
	else if (board[Xstart][Yend] == symbol && board[Xstart + 1][Yend - 1] == symbol && board[Xstart + 2][Yend - 2] == symbol) {
		winFlag = true;
		return winFlag;
	}
	return false;
}

void Ultimate_X_O_Board::loopBoardAndFillBlanks(int xstart, int xend, int ystart, int yend, char symbol = '#') {
	
	for (int i = xstart; i <= xend ; ++i) {
		for (int j = ystart; j <= yend ; ++j) {
			if (board[i][j] == ' ') {
				board[i][j] = symbol;
			}
		}
	}
}

// 3v3 win
void Ultimate_X_O_Board::checksmallWin(char symbol, string& s, bool& b) {
	string debugger;
	if (s == "TopLeft")
	{
		if (check_win(0, 2, 0, 2, symbol, b)) {
			debugger = (symbol == 'X') ? "X won" : "O Won";
			cout << debugger << ' ' << s << endl;
			b = true;
			loopBoardAndFillBlanks(0, 2, 0, 2);
		}
	}
	else if (s == "TopMid")
	{
		if (check_win(0, 2, 3, 5, symbol, b)) {
			debugger = (symbol == 'X') ? "X won" : "O Won";
			cout << debugger << ' ' << s << endl;
			b = true;
			loopBoardAndFillBlanks(0, 2, 3, 5);
		}
	}
	else if (s == "TopRight")
	{
		if(check_win(0, 2, 6, 8, symbol, b)) {
			debugger = (symbol == 'X') ? "X won" : "O Won";
			cout << debugger << ' ' << s << endl;
			b = true;
			loopBoardAndFillBlanks(0, 2, 6, 8);
		}
	}
	else if (s == "MidLeft")
	{
		if (check_win(3, 5, 0, 2, symbol, b)) {
			debugger = (symbol == 'X') ? "X won" : "O Won";
			cout << debugger << ' ' << s << endl;
			b = true;
			loopBoardAndFillBlanks(3, 5, 0, 2);
		}
	}
	else if (s == "MidMid")
	{	
		if (check_win(3, 5, 3, 5, symbol, b)) {
			debugger = (symbol == 'X') ? "X won" : "O Won";
			cout << debugger << ' ' << s << endl;
			b = true;
			loopBoardAndFillBlanks(3, 5, 3, 5);
		}
	}
	else if (s == "MidRight")
	{
		if (check_win(3, 5, 6, 8, symbol, b)) {
			debugger = (symbol == 'X') ? "X won" : "O Won";
			cout << debugger << ' ' << s << endl;
			b = true;
			loopBoardAndFillBlanks(3, 5, 6, 8);
		}
	}
	else if (s == "BotLeft")
	{
		if (check_win(6, 8, 0, 2, symbol, b)) {
			debugger = (symbol == 'X') ? "X won" : "O Won";
			cout << debugger << ' ' << s << endl;
			b = true;
			loopBoardAndFillBlanks(6, 8, 0, 2);
		}
	}
	else if (s == "BotMid")
	{
		if (check_win(6, 8, 3, 5, symbol, b)) {
			debugger = (symbol == 'X') ? "X won" : "O Won";
			cout << debugger << ' ' << s << endl;
			b = true;
			loopBoardAndFillBlanks(6, 8, 3, 5);
		}
	}
	else if (s == "BotRight")
	{
		if (check_win(6, 8, 6, 8, symbol, b)) {
			debugger = (symbol == 'X') ? "X won" : "O Won";
			cout << debugger << ' ' << s << endl;
			b = true;
			loopBoardAndFillBlanks(6, 8, 6, 8);
		}
	}
}

// 9v9 win
void Ultimate_X_O_Board::checkoverallwin() {

	
}
bool Ultimate_X_O_Board::is_win(Player<char>* player) {

	auto has_won = [&](int index) {
		if (player->get_symbol()=='X') return smallBoards[index].x_won;
		return smallBoards[index].o_won;
	};

	// ========= Horizontal check ==============
	if (has_won(0) && has_won(1) && has_won(2)) return true;
	if (has_won(3) && has_won(4) && has_won(5)) return true;
	if (has_won(6) && has_won(7) && has_won(8)) return true;

	// ========= Vertical Check ================
	if (has_won(0) && has_won(3) && has_won(6)) return true;
	if (has_won(1) && has_won(4) && has_won(7)) return true;
	if (has_won(2) && has_won(5) && has_won(8)) return true;

	//========= Diagonals check ================
	if (has_won(0) && has_won(4) && has_won(8)) return true;
	if (has_won(2) && has_won(4) && has_won(6)) return true;

	return false;

}
bool Ultimate_X_O_Board::is_draw(Player<char>* player) {
	if (is_win(player)) return false; // if player won return 

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (board[i][j] == ' ') {
				return false; 
			}
		}
	}
	return true;
}
bool Ultimate_X_O_Board::game_is_over(Player<char>* player) {
	return is_win(player) || is_draw(player);
}


Ultimate_X_O_UI::Ultimate_X_O_UI() {};

Player<char>* Ultimate_X_O_UI::create_player(string& name, char symbol, PlayerType type) {
	return new Player<char>(name, symbol, type);
}
Move<char>* Ultimate_X_O_UI::get_move(Player<char>* player) {
	int x, y;

	if (player->get_type() == PlayerType::HUMAN)
	{
		cout << "\nPlease enter your move x and y (0 to 2): ";
		cin >> x >> y;
		return new Move<char>(x, y, player->get_symbol());
	}
	else
	{
		int x = rand() % 9;
		int y = rand() % 9;
		return new Move<char>(x, y, player->get_symbol());
	}
}

