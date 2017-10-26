//
//  Player.hpp
//  448-BreakThrough
//
//  Created by Liuyi Shi on 10/25/17.
//  Copyright © 2017 Liuyi Shi. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "Heuristic.hpp"
#include "GameBoard.hpp"

namespace player{
    enum playerside {Player0, Player1};
    typedef enum playerside PlayerSide;
    
    enum action {Stay, LeftUp, Up, RightUp};
    typedef enum action Action;
    
    class Player{
    private:
        board::GameBoard *board;
        PlayerSide side;
        heu::Heuristic heuristic; // evaluation function used to evaluate a game status
        int strategy; //0:MiniMax 1:AlphaBeta
        
    public:
        Player(board::GameBoard *b, PlayerSide s, heu::Heuristic h, int stra = 0):board(b), side(s),
                                                                                heuristic(h),strategy(stra){};
        void SetGameBoard(board::GameBoard *b){
            board = b;
        }
        
        void SetHeuristic(heu::Heuristic h){
            heuristic = h;
        }
        
        void SetStrategy(int stra){
            strategy = stra;
        }
        
        void Move(unsigned int Id, Action a);
        
    };
}
#endif /* Player_hpp */
