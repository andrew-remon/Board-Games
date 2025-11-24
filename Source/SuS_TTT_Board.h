#pragma once
#include <iostream>
#include "BoardGame_Classes.h"
using namespace std;

class SuS_TTT_Board : public Board<char>
{
private:
    char defaultValue = '.';


public:
    SuS_TTT_Board();

    bool is_cell_empty(char cell);

    bool update_board(Move<char>* move) override;

    bool is_win(Player<char>* player) override;

    bool is_lose(Player<char>* player) { return false; };

    bool is_draw(Player<char>* player) override;

    bool game_is_over(Player<char>* player) override;
};