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
#include "Heuristic_Offensive2.hpp"
#include "Heuristic_Defensive2.hpp"
#include "Heuristic_Test.hpp"

#define Three_Worker false
#define row_size 8
#define col_size 8
#define DEPTH 5
#define HUMAN_PLAYER 0
#define REPEAT_PLAY 1
#define ROUNDS 200
#define PRINT_BOARD (!REPEAT_PLAY)

int main(int argc, char **argv){
    
    srand( (unsigned) time(NULL) );
    
    int num_total = 0;
    int num_0_win = 0;
    int num_1_win = 0;
    
    while( num_total < ROUNDS ){
        
        unsigned int NumOfNodeP0 = 0;
        unsigned int NumOfNodeP1 = 0;
        
        time_t t;
        float t_P0 = 0;
        float t_P1 = 0;
        
        unsigned int NumStepP0 = 0;
        unsigned int NumStepP1 = 0;
        
        board::GameBoard gb(row_size,col_size);
        heu::Heuristic *h0;
        heu::Heuristic *h1;
        
        heu::Heuristic_Offensive1 h_o1;
        heu::Heuristic_Defensive1 h_d1;
        heu::Heuristic_Offensive2 h_o2;
        heu::Heuristic_Defensive2 h_d2;
        heu::Heuristic_Test h_t;
    
        h0 = &h_o2;
        h1 = &h_d2;
        
        player::Player p0( &gb, player::Player0, h0, 1, DEPTH);
        player::Player p1( &gb, player::Player1, h1, 1, DEPTH);
        
        if(PRINT_BOARD)
            gb.PrintBoard();
        
        while(1){
            if(PRINT_BOARD)
                printf("Player0's turn.\n");
            t = clock();
            
            if(!HUMAN_PLAYER){
                NumOfNodeP0 += p0.play();
            }
            else{
                int r, c;
                char d;
                
                printf("Input Row and Col of worker and Direction to move:\n");
                printf("For example: 6 1 U\n");
                scanf("%d %d %c", &r, &c, &d);
                r--;
                c--;
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
                    r--;
                    c--;
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
            if(PRINT_BOARD)
                printf("Player0 Step Time:%f",(clock() - t)/(float)(CLOCKS_PER_SEC));
            t_P0 += (clock() - t)/(float)(CLOCKS_PER_SEC);
            NumStepP0++;
            if(PRINT_BOARD)
                gb.PrintBoard();
            if( player::Player::DetectWinner(gb, Three_Worker) == player::Player0 ){
                num_0_win++;
                break;
            }
            if(PRINT_BOARD)
                printf("Player1's turn.\n");
            
            t = clock();
            NumOfNodeP1 += p1.play();
            if(PRINT_BOARD)
                printf("Player1 Step Time:%f",(clock() - t)/(float)(CLOCKS_PER_SEC));
            t_P1 += (clock() - t)/(float)(CLOCKS_PER_SEC);
            NumStepP1++;
            if(PRINT_BOARD)
                gb.PrintBoard();
            if( player::Player::DetectWinner(gb, Three_Worker) == player::Player1 ){
                num_1_win++;
                break;
            }
        }
        if(!PRINT_BOARD)
            gb.PrintBoard();
        num_total++;
        printf("%d's round End. Winner is:%d\n\n", num_total, player::Player::DetectWinner(gb, Three_Worker));
        printf("TotalRounds: %d Player0Win: %d Player1Win: %d\n\n", num_total, num_0_win, num_1_win);
        printf("Steps: P0: %d, P1: %d\n", NumStepP0, NumStepP1);
        printf("Total Time: P0: %f s, P1: %f s\n", t_P0, t_P1);
        printf("NumOfNodes: P0: %d, P1: %d\n", NumOfNodeP0, NumOfNodeP1);
        if(!REPEAT_PLAY)
            break;
    }
    
    printf("\nTotalRounds: %d Player0Win: %d Player1Win: %d\n\n", num_total, num_0_win, num_1_win);
 
    return 0;
}
