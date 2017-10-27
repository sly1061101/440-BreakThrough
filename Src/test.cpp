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
#include "Heuristic_Offensive1.hpp"
#include "Heuristic_Defensive1.hpp"

int main(int argc, char **argv){
    
    srand( (unsigned) time(NULL) );
    
    board::GameBoard gb(8,8);
    heu::Heuristic *h0;
    heu::Heuristic *h1;
    heu::Heuristic_Offensive1 h_o1;
    heu::Heuristic_Defensive1 h_d1;
    h0 = &h_o1;
    h1 = &h_d1;
    
    player::Player p0( &gb, player::Player0, h0, 0);
    player::Player p1( &gb, player::Player1, h1, 0);
    
    gb.PrintBoard();
    
    while(1){
        printf("Player0's turn.\n");
        p0.play();
        gb.PrintBoard();
        if( player::Player::DetectWinner(gb) == player::Player0 ){
            printf("Game End. Winner is:%d\n",player::Player::DetectWinner(gb));
            break;
        }
        
        printf("Player1's turn.\n");
        p1.play();
        gb.PrintBoard();
        if( player::Player::DetectWinner(gb) == player::Player1 ){
            printf("Game End. Winner is:%d\n",player::Player::DetectWinner(gb));
            break;
        }
    }
 
    return 0;
}
