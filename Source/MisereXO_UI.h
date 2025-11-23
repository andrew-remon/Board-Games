// MisereXO_UI.h
#pragma once
#include "BoardGame_Classes.h"

class MisereXO_UI : public UI<char>
{
public:
    MisereXO_UI();

    ~MisereXO_UI() {};

    Player<char>* create_player(string& name, char symbol, PlayerType type) override;

    Move<char>* get_move(Player<char>* player) override;

    Player<char>** setup_players() override;

};
