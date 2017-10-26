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
    heu::Heuristic h;
    player::Player p0( &gb, player::Player0, h);
    player::Player p1( &gb, player::Player1, h);
    
    gb.PrintBoard();
    printf("\n");
    p0.Move( gb.CoorToId(6, 0), player::RightUp);
    gb.PrintBoard();
    printf("\n");
    p1.Move( gb.CoorToId(1, 7), player::RightUp);
    gb.PrintBoard();
    printf("\n");
    p1.Move( gb.CoorToId(2, 6), player::RightUp);
    gb.PrintBoard();
    printf("\n");
    p1.Move( gb.CoorToId(3, 5), player::RightUp);
    gb.PrintBoard();
    printf("\n");
    p1.Move( gb.CoorToId(4, 4), player::RightUp);
    gb.PrintBoard();
    printf("\n");
    p1.Move( gb.CoorToId(5, 3), player::RightUp);
    gb.PrintBoard();
    printf("\n");
    p0.Move( gb.CoorToId(7, 1), player::RightUp);
    gb.PrintBoard();
    printf("\n");
    return 0;
}
