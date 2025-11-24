// main.cpp
// Include other game files here later (SUS, Four-in-a-row, etc.)
#include <iostream>
#include "BoardGame_Classes.h"
#include "MisereXO_Board.h"
#include "MisereXO_UI.h"
#include "NumXO_Board.h"
#include "NumXO_UI.h"
#include "SuS_TTT_Board.h"
#include "SuS_TTT_UI.h"
using namespace std;


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

    // ============= SuS Init ================

    UI<char>* ui = new SuS_TTT_UI();
    Board<char>* board = new SuS_TTT_Board();
    Player<char>** players = ui->setup_players();
    GameManager<char> susGame(board, players, ui);
    

    // ==== SuS Game Manager Run Function ====
    
    susGame.run();

    // ============= clean up ================
    delete board;
    delete ui;
    for (int i = 0; i < 2; ++i)
        delete players[i];
    delete[] players;
}


void main() {
    cout << "Choose a Game To Play\n";
    cout << "[1] MisereXO \n";
    cout << "[2] NumXO \n";
    cout << "[3] SusXO \n";
    
    // will convert to enum later
    int x;
    cin >> x;
    switch(x)
    {
    case 1:
        RunMisereXO();
        break;
    case 2:
        RunNumXO();
        break;
    case 3:
        RunSuSXO();
        break;
    }
}