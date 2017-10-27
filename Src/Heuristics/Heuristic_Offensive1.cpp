//
//  Heuristic_Offensive1.cpp
//  448-BreakThrough
//
//  Created by Liuyi Shi on 10/26/17.
//  Copyright © 2017 Liuyi Shi. All rights reserved.
//

#include "Heuristic_Offensive1.hpp"

float heu::Heuristic_Offensive1::operator()(board::GameBoard board, player::PlayerSide side){
    float evaluation = 0;
    if(side == player::Player0){
        evaluation = 2 * ( 30 - board.GetStatusNum(board::Player1) ) + ( rand() / double(RAND_MAX) );
    }
    else if(side == player::Player1){
        evaluation = 2 * ( 30 - board.GetStatusNum(board::Player0) ) + ( rand() / double(RAND_MAX) );
    }
    return evaluation;
}
