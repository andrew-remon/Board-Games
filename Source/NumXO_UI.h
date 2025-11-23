// NumXO_UI.h
#pragma once
#include "BoardGame_Classes.h"
#include "NumXO_Player.h"

class NumXO_UI : public UI<int>
{
public:
    NumXO_UI();

    ~NumXO_UI() {};

    Player<int>* create_player(string& name, int symbol, PlayerType type) override;

    Move<int>* get_move(Player<int>* player) override;

    Player<int>** setup_players() override;

    PlayerStatus get_player_status_choice(string player_label, const vector<string>& options);

};
