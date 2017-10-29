//
//  Heuristic_Defensive2.hpp
//  448-BreakThrough
//
//  Created by Liuyi Shi on 10/28/17.
//  Copyright © 2017 Liuyi Shi. All rights reserved.
//

#ifndef Heuristic_Defensive2_hpp
#define Heuristic_Defensive2_hpp

#include <stdio.h>
#include "Heuristic.hpp"
#include "Player.hpp"
#include "GameBoard.hpp"

namespace heu{
    class Heuristic_Defensive2: public Heuristic{
    public:
        float operator()(board::GameBoard board, player::PlayerSide side);
    };
}
#endif /* Heuristic_Defensive2_hpp */
