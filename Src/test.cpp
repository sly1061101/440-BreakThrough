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
#include "Heuristic_Test.hpp"

int main(int argc, char **argv){
    
    int num_total = 0;
    int num_0_win = 0;
    int num_1_win = 0;
    
    while( num_total < 20 ){
        
        srand( (unsigned) time(NULL) );
        time_t t;
        
        board::GameBoard gb(8,8);
        heu::Heuristic *h0;
        heu::Heuristic *h1;
        
        heu::Heuristic_Offensive1 h_o1;
        heu::Heuristic_Defensive1 h_d1;
        heu::Heuristic_Test h_t;
        
        h0 = &h_o1;
        h1 = &h_o1;
        
        player::Player p0( &gb, player::Player0, h0, 0, 3);
        player::Player p1( &gb, player::Player1, h1, 1, 3);
        
        gb.PrintBoard();
        
        while(1){
            printf("Player0's turn.\n");
            t = clock();
            p0.play();
            printf("time cost:%dms\n",(clock() - t)/(CLOCKS_PER_SEC/1000));
            gb.PrintBoard();
            if( player::Player::DetectWinner(gb) == player::Player0 ){
                printf("Game End. Winner is:%d\n",player::Player::DetectWinner(gb));
                num_0_win++;
                break;
            }
            
            printf("Player1's turn.\n");
            t = clock();
            p1.play();
            printf("time cost:%ds\n",(clock() - t)/CLOCKS_PER_SEC);
            gb.PrintBoard();
            if( player::Player::DetectWinner(gb) == player::Player1 ){
                printf("Game End. Winner is:%d\n",player::Player::DetectWinner(gb));
                num_1_win++;
                break;
            }
        }
        num_total++;
    }
    
    printf("total:%d 0win:%d 1win:%d\n", num_total, num_0_win, num_1_win);
 
    return 0;
}
