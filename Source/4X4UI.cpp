#include "4X4UI.h"
#include <iostream>

using namespace std;


UI4X4::UI4X4(int cell_width) : UI<char>("Welcome to 4x4 Tic-Tac-Toe!", cell_width) {
}

Player<char>* UI4X4::create_player(string& name, char symbol, PlayerType type) {
    return new Player<char>(name, symbol, type);
}

Move<char>* UI4X4::get_move(Player<char>* player) {
    int from_r, from_c, to_r, to_c;

    cout << "\n" << player->get_name() << " (" << player->get_symbol() << ") turn.\n";


    cout << "Select the piece you want to move (Row Col): ";
    cin >> from_r >> from_c;

    cout << "Select the destination (Row Col): ";
    cin >> to_r >> to_c;

    return new Move4X4(from_r, from_c, to_r, to_c, player->get_symbol());
}