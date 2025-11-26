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

using namespace std;

// ======= Game Runners =======

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
    for (int i = 0; i < 2; ++i)
        delete players[i];
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

int main() {
    cout << "Choose a Game To Play\n";
    cout << "[1] MisereXO \n";
    cout << "[2] NumXO \n";
    cout << "[3] SusXO \n";
    cout << "[4] 4x4 Tic-Tac-Toe \n";

    int x;
    cin >> x;

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
    default:
        cout << "Invalid Choice.\n";
        break;
    }

    return 0;
}