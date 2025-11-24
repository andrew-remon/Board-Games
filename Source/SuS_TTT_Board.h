#pragma once
#include <iostream>
#include <map>
#include "BoardGame_Classes.h"
using namespace std;



class SuS_TTT_Board : public Board<char>
{
private:
    char defaultValue = '.';
    bool isFirst = true;

public:
    //======= Variables =======
    int player1Sequences = 0;
    int player2Sequences = 0;
    
    //=======  Methods  =======
    SuS_TTT_Board();

    void checkLatestBoard(map<string, bool>& x );
    bool is_cell_empty(char cell);

    bool update_board(Move<char>* move) override;

    bool is_win(Player<char>* player) override ;
    //bool is_win(SuS_TTT_Player<char>* player) ;


    //bool is_draw(SuS_TTT_Player<char>* player) ;
    
    bool is_draw(Player<char>* player) override ;

    //bool game_is_over(SuS_TTT_Player<char>* player) ;
    
    bool game_is_over(Player<char>* player) override ;
    
    
    
    
    
    bool is_lose(Player<char>* player) /* { return false; }*/;
};