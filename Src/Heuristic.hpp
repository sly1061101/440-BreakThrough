//
//  Heuristic.h
//  448-BreakThrough
//
//  Created by Liuyi Shi on 10/25/17.
//  Copyright © 2017 Liuyi Shi. All rights reserved.
//

#ifndef Heuristic_hpp
#define Heuristic_hpp

#include "Header.h"
#include "GameBoard.hpp"

namespace heu{
    class Heuristic{
    public:
        virtual float operator()(board::GameBoard board, player::PlayerSide side) = 0;
    };
}

#endif /* Heuristic_h */
