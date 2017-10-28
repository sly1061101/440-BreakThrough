//
//  main.cpp
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
#include "Heuristic_WinningStatus.hpp"
#include "Heuristic_Test.hpp"

#define HUMAN_PLAYER 0

int main(int argc, char **argv){
    
    srand( (unsigned) time(NULL) );
    
    int num_total = 0;
    int num_0_win = 0;
    int num_1_win = 0;
    
    while( num_total < 100 ){
        
        unsigned int NumOfNodeP0 = 0;
        unsigned int NumOfNodeP1 = 0;
        
        time_t t;
        float t_P0 = 0;
        float t_P1 = 0;
        
        unsigned int NumStepP0 = 0;
        unsigned int NumStepP1 = 0;
        
        board::GameBoard gb(8,8);
        heu::Heuristic *h0;
        heu::Heuristic *h1;
        
        heu::Heuristic_Offensive1 h_o1;
        heu::Heuristic_Defensive1 h_d1;
        heu::Heuristic_WinningStatus h_w;
        heu::Heuristic_Test h_t;
        
        h0 = &h_w;
        h1 = &h_o1;
        
        player::Player p0( &gb, player::Player0, h0, 0, 3);
        player::Player p1( &gb, player::Player1, h1, 1, 3);
        
        gb.PrintBoard();
        
        
        while(1){

            
            printf("Player0's turn.\n");
            t = clock();
            
            if(!HUMAN_PLAYER){
                NumOfNodeP0 += p0.play();
            }
            else{
                int r, c;
                char d;
                
                printf("Input Row and Col of worker and Direction to move:\n");
                printf("For example: 6 0 U\n");
                scanf("%d %d %c", &r, &c, &d);
                player::Action a;
                bool IsDirectionValid = true;
                if(d == 'L')
                    a = player::LeftUp;
                else if(d == 'U')
                    a = player::Up;
                else if(d == 'R')
                    a = player::RightUp;
                else
                    IsDirectionValid = false;
                while( (IsDirectionValid==false) || (p0.IsLegalMove(gb.CoorToId(r, c), a) == false) ){
                    printf("Illegal input, try again!\n");
                    scanf("%d %d %c", &r, &c, &d);
                    IsDirectionValid = true;
                    if(d == 'L')
                        a = player::LeftUp;
                    else if(d == 'U')
                        a = player::Up;
                    else if(d == 'R')
                        a = player::RightUp;
                    else
                        IsDirectionValid = false;
                }
                p0.Move(gb.CoorToId(r, c), a);
            }
            
            t_P0 += (clock() - t)/(float)(CLOCKS_PER_SEC);
            NumStepP0++;
            
            gb.PrintBoard();
            if( player::Player::DetectWinner(gb, false) == player::Player0 ){
                num_0_win++;
                break;
            }
            
            printf("Player1's turn.\n");
            
            t = clock();
            NumOfNodeP1 += p1.play();
            t_P1 += (clock() - t)/(float)(CLOCKS_PER_SEC);
            NumStepP1++;
            
            gb.PrintBoard();
            if( player::Player::DetectWinner(gb, false) == player::Player1 ){
                num_1_win++;
                break;
            }
        }
        printf("Game End. Winner is:%d\n\n",player::Player::DetectWinner(gb));
        printf("Steps: P0: %d, P1: %d\n", NumStepP0, NumStepP1);
        printf("Total Time: P0: %f s, P1: %f s\n", t_P0, t_P1);
        printf("NumOfNodes: P0: %d, P1: %d\n", NumOfNodeP0, NumOfNodeP1);
        num_total++;
        break;
    }
    
    printf("\nTotal:%d Player0:%d Player1:%d\n\n", num_total, num_0_win, num_1_win);
 
    return 0;
}
