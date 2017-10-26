//
//  test.cpp
//  448-BreakThrough
//
//  Created by Liuyi Shi on 10/25/17.
//  Copyright © 2017 Liuyi Shi. All rights reserved.
//

#include <stdio.h>
#include "GameBoard.hpp"
#include "Player.hpp"
#include "Heuristic.hpp"

int main(int argc, char **argv){
    printf("Test!\n");
    board::GameBoard gb;
    board::GameBoard gb_new;
    heu::Heuristic h;
    player::Player p0( &gb, player::Player0, h);
    player::Player p1( &gb, player::Player1, h);
    player::ChoiceSet c;
    
    p0.GetChoiceSet(c);

    
    while(c.size()>1){
        p0.Move(c[1].first, c[1].second);
        p0.GetChoiceSet(c);
    }
     p1.GetChoiceSet(c);
    while(c.size()>1){
        p1.Move(c[1].first, c[1].second);
        p1.GetChoiceSet(c);
    }
    
    gb.PrintBoard();
    
    return 0;
}
