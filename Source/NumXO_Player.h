#pragma once
#include <iostream>
#include <set>
#include "BoardGame_Classes.h"
using namespace std;

enum class PlayerStatus
{
    ODD,
    Even
};

class NumXO_Player : public Player<int>
{
private:
    PlayerStatus status;
    set<int> available_values;
    // set <int> even_values = {2, 4, 6, 8};
    // set<int> odd_values = {1, 3, 5, 7, 9};

public:
    NumXO_Player(string n, int s, PlayerType t, PlayerStatus st);

    void set_symbol();

    // PlayerStatus get_status() { return status; };


    // void set_status(PlayerStatus newStatus) { status = newStatus; };

    bool is_input_symbol_validated(int InputSymbol);

    // const set<int>& get_available_values() const { return available_values; }
};
