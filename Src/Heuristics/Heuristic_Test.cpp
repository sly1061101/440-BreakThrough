//
//  Heuristic_Test.cpp
//  448-BreakThrough
//
//  Created by Liuyi Shi on 10/27/17.
//  Copyright © 2017 Liuyi Shi. All rights reserved.
//

#include "Heuristic_Test.hpp"

float heu::Heuristic_Test::operator()(board::GameBoard board, player::PlayerSide side){
    float evaluation = 0;
    if(side == player::Player0){
        evaluation = 2 * ( 1 ) + ( rand() / double(RAND_MAX) );
    }
    else if(side == player::Player1){
        evaluation = 2 * ( 1 ) + ( rand() / double(RAND_MAX) );
    }
    return evaluation;
}
