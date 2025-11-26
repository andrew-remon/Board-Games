#pragma once
#include "BoardGame_Classes.h"
#include "4X4move.h"  

class Board4X4 : public Board<char> {
public:
    Board4X4();
    bool update_board(Move<char>* move) override;
    bool is_win(Player<char>* player) override;
    bool is_draw(Player<char>* player) override;
    bool game_is_over(Player<char>* player) override;
    bool is_lose(Player<char>* player) override;
};
