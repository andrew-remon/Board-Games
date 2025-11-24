#pragma once
#include "BoardGame_Classes.h"

class SuS_TTT_UI : public UI<char>
{
public:
    SuS_TTT_UI();

    ~SuS_TTT_UI() {};

    Player<char>* create_player(string& name, char symbol, PlayerType type) override;

    Move<char>* get_move(Player<char>* player) override;

    Player<char>** setup_players() override;


};
