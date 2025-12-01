#include <iostream>
#include "BoardGame_Classes.h"
#include "MisereXO_Board.h"
#include "MisereXO_UI.h"
#include "NumXO_Board.h"
#include "NumXO_UI.h"
#include "SuS_TTT_Board.h"
#include "SuS_TTT_UI.h"
#include "4X4board.h"
#include "4X4UI.h"
#include "5x5XO_Classes.h"
#include "Infinity_XO_Classes.h"
#include "Word_XO_Classes.h"
#include "Connect_4.h"
#include "InputValidation.h"

using namespace std;

// ======= Game Runners =======

void RunConnect4()
{
    UI<char>* game_ui = new connect_4_UI();
    Board<char>* xo_board = new connect_4_Board();
    Player<char>** players = game_ui->setup_players();
    GameManager<char> x_o_game(xo_board, players, game_ui);
    x_o_game.run();
    // --- Cleanup ---
    delete xo_board;
    delete game_ui;
    delete players[0];
    delete players[1];
    delete[] players;
}

void RunWordXO()
{
    UI<char>* game_ui = new word_XO_UI();

    Board<char>* xo_board = new word_X_O_Board();

    Player<char>** players = game_ui->setup_players();

    GameManager<char> x_o_game(xo_board, players, game_ui);

    x_o_game.run();

    // --- Cleanup ---
    delete xo_board;

    delete game_ui;

    delete players[0];
    delete players[1];

    delete[] players;
}

void RunInfinityXO()
{
    UI<char>* game_ui = new inf_XO_UI();

    Board<char>* xo_board = new inf_X_O_Board();

    Player<char>** players = game_ui->setup_players();

    GameManager<char> x_o_game(xo_board, players, game_ui);

    x_o_game.run();

    // --- Cleanup ---
    delete xo_board;

    delete game_ui;

    delete players[0];
    delete players[1];

    delete[] players;

}

void Run5x5XO()
{
    UI<char>* game_ui = new _5X5_XO_UI();

    Board<char>* xo_board = new _5X5_X_O_Board();

    Player<char>** players = game_ui->setup_players();

    GameManager<char> x_o_game(xo_board, players, game_ui);

    x_o_game.run();

    // --- Cleanup ---
    delete xo_board;

    delete game_ui;

    delete players[0];
    delete players[1];

    delete[] players;
}

void RunMisereXO() {
    Board<char>* board = new MisereXO_Board();
    UI<char>* ui = new MisereXO_UI();
    Player<char>** players = ui->setup_players();
    GameManager<char> manager(board, players, ui);
    manager.run();

    // Clean up
    delete board;
    delete ui;
    delete players[0];
    delete players[1];
    delete[] players;
}

void RunNumXO() {
    Board<int>* board = new NumXO_Board();
    UI<int>* ui = new NumXO_UI();
    Player<int>** players = ui->setup_players();
    GameManager<int> manager(board, players, ui);
    manager.run();

    // Clean up
    delete board;
    delete ui;
    delete players[0];
    delete players[1];
    delete[] players;
}

void RunSuSXO() {
    UI<char>* ui = new SuS_TTT_UI();
    Board<char>* board = new SuS_TTT_Board();
    Player<char>** players = ui->setup_players();
    GameManager<char> susGame(board, players, ui);
    susGame.run();

    // Clean up
    delete board;
    delete ui;
    delete players[0];
    delete players[1];
    delete[] players;
}

void Run4X4Game() {
    Board<char>* board = new Board4X4();
    UI<char>* ui = new UI4X4();
    Player<char>** players = ui->setup_players();
    GameManager<char> manager(board, players, ui);
    manager.run();

    //Clean up
    delete board;
    delete ui;
    delete players[0];
    delete players[1];
    delete[] players;
}

// ======= Main Menu =======

int main()
{

    srand(static_cast<unsigned int>(time(NULL)));

    cout << "Choose a Game To Play\n";
    cout << "[1] MisereXO\n";
    cout << "[2] NumXO\n";
    cout << "[3] SusXO\n";
    cout << "[4] 4x4 XO\n";
    cout << "[5] 5x5 XO\n";
    cout << "[6] Infinity XO\n";
    cout << "[7] Word XO\n";
    cout << "[8] Connect 4\n";

    int x = InputValidation::readIntNumberBetween(1, 8, "Invalid Input, Please Enter a number from 1 to 8");
    // cin >> x;

	// will use enum later for better readability
    switch (x) {
    case 1:
        RunMisereXO();
        break;
    case 2:
        RunNumXO();
        break;
    case 3:
        RunSuSXO();
        break;
    case 4:
        Run4X4Game();
        break;
    case 5:
        Run5x5XO();
        break;
    case 6:
        RunInfinityXO();
        break;
    case 7:
        RunWordXO();
		break;
	case 8:
		RunConnect4();
		break;
    default:
        cout << "Invalid Choice.\n";
        break;
    }

    return 0;
}
