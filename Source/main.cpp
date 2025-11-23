// main.cpp
// Include other game files here later (SUS, Four-in-a-row, etc.)
#include <iostream>
#include "BoardGame_Classes.h"
#include "MisereXO_Board.h"
#include "MisereXO_UI.h"
#include "NumXO_Board.h"
#include "NumXO_UI.h"
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

int main() {
    cout << "Choose a Game To Play\n";
    cout << "[1] MisereXO \n";
    cout << "[2] NumXO \n";
    
    // will convert to enum later
    int x;
    cin >> x;
    if (x == 1)
    {
        RunMisereXO();
    }
    if(x == 2)
    {
        RunNumXO();
    }
    return 0;
}