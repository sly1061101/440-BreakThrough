//
//  test.cpp
//  448-BreakThrough
//
//  Created by Liuyi Shi on 10/25/17.
//  Copyright © 2017 Liuyi Shi. All rights reserved.
//

#include <stdio.h>
#include "GameBoard.hpp"

int main_t(int argc, char **argv){
    printf("Test!\n");
    board::GameBoard gb;
    gb.PrintBoard();
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            printf("%d ",gb.GetStatus(gb.CoorToId(i, j)));
            if(j==7)
                printf("\n");
        }
    }
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            gb.SetStatus(gb.CoorToId(i, j), board::Player1);
        }
    }
    gb.PrintBoard();
    return 0;
}
