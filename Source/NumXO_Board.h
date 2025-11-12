#pragma once
#include <iostream>
#include "BoardGame_Classes.h"
using namespace std;

class NumXO_Board : public Board<int>
{
private:
    int defaultValue = 0;

public:
    NumXO_Board();

    bool is_cell_empty(int cell);

    bool update_board(Move<int>* move) override;

    bool is_win(Player<int>* player) override;

    bool is_lose(Player<int>* player) { return false; };

    bool is_draw(Player<int>* player) override;

    bool game_is_over(Player<int>* player) override;
};
