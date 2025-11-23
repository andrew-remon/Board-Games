// MisereXO_Board.h
#pragma once
#include <iostream>
#include "BoardGame_Classes.h"
using namespace std;

class MisereXO_Board : public Board<char>
{
private:

public:
    MisereXO_Board();

    // why no deconstructor ??

    bool update_board(Move<char>* move) override;

    bool is_win(Player<char>* player) override;

    bool is_lose(Player<char>* player) override;

    bool is_draw(Player<char>* player) override;

    bool game_is_over(Player<char>* player) override;
};
