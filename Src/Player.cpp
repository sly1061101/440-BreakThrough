//
//  Player.cpp
//  448-BreakThrough
//
//  Created by Liuyi Shi on 10/25/17.
//  Copyright © 2017 Liuyi Shi. All rights reserved.
//

#include "Player.hpp"

void player::Player::Move(unsigned int Id, Action a){
    unsigned row = (*board).IdToCoor(Id).first;
    unsigned col = (*board).IdToCoor(Id).second;
    
    if(side == Player0){
        if( (*board).GetStatus(Id) == board::Player0 ){
            if(a == Stay){
                
            }
            else if(a == LeftUp){
                if( (row > 0) && (col > 0) && ( (*board).GetStatus( (*board).CoorToId(row - 1, col - 1) ) != board::Player0 ) ){
                    (*board).SetStatus( (*board).CoorToId(row, col) , board::Empty);
                    (*board).SetStatus( (*board).CoorToId(row - 1, col - 1) , board::Player0);
                }
                else
                    printf("Error in Player0 move LeftUp.\n");
            }
            else if(a == Up){
                if( (row > 0) && ( (*board).GetStatus( (*board).CoorToId(row - 1, col) ) == board::Empty ) ){
                    (*board).SetStatus( (*board).CoorToId(row, col) , board::Empty);
                    (*board).SetStatus( (*board).CoorToId(row - 1, col) , board::Player0);
                }
                else
                    printf("Error in Player0 move UP.\n");
            }
            else if(a == RightUp){
                if( (row > 0) && (col < ((*board).GetRowSize() - 1)) && ( (*board).GetStatus( (*board).CoorToId(row - 1, col + 1) ) != board::Player0 ) ){
                    (*board).SetStatus( (*board).CoorToId(row, col) , board::Empty);
                    (*board).SetStatus( (*board).CoorToId(row - 1, col + 1) , board::Player0);
                }
                else
                    printf("Error in Player0 move RightUp.\n");
            }
        }
        else
            printf("Error in player::Player::Move(), the cell does not has the worker of Player0 side.\n");
    }
    else if(side == Player1){
        if( (*board).GetStatus(Id) == board::Player1 ){
            if(a == Stay){
                
            }
            else if(a == LeftUp){
                if( (row < ((*board).GetColSize() - 1)) && (col < ((*board).GetRowSize() - 1)) && ( (*board).GetStatus( (*board).CoorToId(row + 1, col + 1) ) != board::Player1 ) ){
                    (*board).SetStatus( (*board).CoorToId(row, col) , board::Empty);
                    (*board).SetStatus( (*board).CoorToId(row + 1, col + 1) , board::Player1);
                }
                else
                    printf("Error in Player1 move LeftUp.\n");
            }
            else if(a == Up){
                if( (row < ((*board).GetColSize() - 1))  && ( (*board).GetStatus( (*board).CoorToId(row + 1, col) ) == board::Empty ) ){
                    (*board).SetStatus( (*board).CoorToId(row, col) , board::Empty);
                    (*board).SetStatus( (*board).CoorToId(row + 1, col) , board::Player1);
                }
                else
                    printf("Error in Player1 move Up.\n");
                
            }
            else if(a == RightUp){
                if( (row < ((*board).GetColSize() - 1)) && (col > 0) && ( (*board).GetStatus( (*board).CoorToId(row + 1, col - 1) ) != board::Player1 ) ){
                    (*board).SetStatus( (*board).CoorToId(row, col) , board::Empty);
                    (*board).SetStatus( (*board).CoorToId(row + 1, col - 1) , board::Player1);
                }
                else
                    printf("Error in Player1 move RightUp.\n");
            }
        }
        else
            printf("Error in player::Player::Move(), the cell does not has the worker of this playerside.\n");
    }
}
