//
//  Heuristic_Test.cpp
//  448-BreakThrough
//
//  Created by Liuyi Shi on 10/27/17.
//  Copyright © 2017 Liuyi Shi. All rights reserved.
//

#include "Heuristic_Test.hpp"

float heu::Heuristic_Test::operator()(board::GameBoard board, player::PlayerSide side){
    float Player0Score = 0;
    float Player1Score = 0;
    
    Player0Score = 2 * ( board.GetStatusNum(board::Player0) );
    Player1Score = 2 * ( board.GetStatusNum(board::Player1) );
    
    float evaluation = 0;
    
    if(side == player::Player0){
        evaluation = Player0Score + (60 - Player1Score) + ( rand() / double(RAND_MAX) );
    }
    else if(side == player::Player1){
        evaluation = Player1Score + (60 - Player0Score) + ( rand() / double(RAND_MAX) );
    }
    
    return evaluation;
}
