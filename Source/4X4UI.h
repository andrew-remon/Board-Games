#pragma once
#include "BoardGame_Classes.h"
#include "4X4move.h" 

class UI4X4 : public UI<char> {
public:
    UI4X4(int cell_width = 3);
    Move<char>* get_move(Player<char>* player) override;
    Player<char>* create_player(string& name, char symbol, PlayerType type) override;
};