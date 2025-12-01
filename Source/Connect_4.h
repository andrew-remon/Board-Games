#pragma once

#ifndef CONNECT_4_H
#define CONNECT_4_H

#include "BoardGame_Classes.h"
using namespace std;


class connect_4_Board : public Board<char> {
private:
    char blank_symbol = '.'; 
    

public:
    connect_4_Board();
    ~ connect_4_Board();

   
    bool update_board(Move<char>* move) override;

    bool is_win(Player<char>* player) override;

 
    bool is_lose(Player<char>* player) { return false; };

    bool is_draw(Player<char>* player) override;

    bool game_is_over(Player<char>* player) override;

};

class connect_4_UI : public UI<char>
{

public:
    connect_4_UI();

    ~connect_4_UI() {};

   
    Player<char>* create_player(string& name, char symbol, PlayerType type);

    virtual Move<char>* get_move(Player<char>* player);
};

#endif // CONNECT_4_H
