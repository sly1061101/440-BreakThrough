//
//  Heuristic_Offensive1.hpp
//  448-BreakThrough
//
//  Created by Liuyi Shi on 10/26/17.
//  Copyright © 2017 Liuyi Shi. All rights reserved.
//

#ifndef Heuristic_Offensive1_hpp
#define Heuristic_Offensive1_hpp

#include <stdio.h>
#include "Heuristic.hpp"
#include "Player.hpp"
#include "GameBoard.hpp"

namespace heu{
    class Heuristic_Offensive1: public Heuristic{
    public:
        float operator()(board::GameBoard board, player::PlayerSide side);
    };
}

#endif /* Heuristic_Offensive1_hpp */
