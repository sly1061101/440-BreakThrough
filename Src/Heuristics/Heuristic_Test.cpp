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
    
    unsigned int Player0Left;
    unsigned int Player1Left;
    
    Player0Left = board.GetStatusNum(board::Player0);
    Player1Left = board.GetStatusNum(board::Player1);
    
    unsigned int Player0MostFrontDistance = 0 ;
    unsigned int Player1MostFrontDistance = 0 ;
    
    float Player0AverageDistanceFromHome = 0 ;
    float Player1AverageDistanceFromHome = 0 ;
    
    bool GotFrontValue = false;
    for(int i = 0; i < board.GetColSize(); ++i ){
        for(int j = 0; j < board.GetRowSize(); ++j ){
            if( board.GetStatus( board.CoorToId(i, j) ) == board::Player0 ){
                if( !GotFrontValue ){
                    Player0MostFrontDistance = board.GetColSize() - i - 1;
                    GotFrontValue = true;
                }
                Player0AverageDistanceFromHome += i;
            }
        }
    }
    Player0AverageDistanceFromHome /= Player0Left;
    
    GotFrontValue = false;
    for(int i = board.GetColSize() - 1; i >= 0; --i ){
        for(int j = 0; j < board.GetRowSize(); ++j ){
            if( board.GetStatus( board.CoorToId(i, j) ) == board::Player1 ){
                if( !GotFrontValue ){
                    Player1MostFrontDistance = i;
                    GotFrontValue = true;
                }
                Player1AverageDistanceFromHome += i;
            }
        }
    }
    Player1AverageDistanceFromHome /= Player1Left;
    
    if( Player0MostFrontDistance != 7 && Player1Left != 0)
        Player0Score = Player0Left + 2 * Player0MostFrontDistance + 2 * Player0AverageDistanceFromHome;
    else
        Player0Score = 99999999;
    
    if( Player1MostFrontDistance != 7 && Player0Left != 0)
        Player0Score = Player1Left + 2 * Player1MostFrontDistance + 2 * Player1AverageDistanceFromHome;
    else
        Player1Score = 99999999;
    
    float evaluation = 0;
    if(side == player::Player0){
        evaluation = ( 0 * Player0Left + 2 * Player0MostFrontDistance + 3 * Player0AverageDistanceFromHome )
        -( 2 * Player1Left + 5 * Player1MostFrontDistance + 1 * Player1AverageDistanceFromHome )
        + ( rand() / double(RAND_MAX) );
    }
    else if(side == player::Player1){
        evaluation = ( 0 * Player1Left + 2 * Player1MostFrontDistance + 3 * Player1AverageDistanceFromHome )
        -( 2 * Player0Left + 5 * Player0MostFrontDistance + 2 * Player0AverageDistanceFromHome )
        + ( rand() / double(RAND_MAX) );
    }
    return evaluation;
}
