//
//  GameBoard.hpp
//  448-BreakThrough
//
//  Created by Liuyi Shi on 10/25/17.
//  Copyright © 2017 Liuyi Shi. All rights reserved.
//

#ifndef GameBoard_hpp
#define GameBoard_hpp

#include <stdio.h>
#include <vector>

namespace board {
    enum cellstatus {Empty, Player0, Player1};
    typedef enum cellstatus CellStatus;
    typedef std::pair<unsigned int, unsigned int> Coor;
    
    typedef struct cell{
        unsigned int row;
        unsigned int col;
        CellStatus Status;
        
    }Cell;
    
    class GameBoard{
    private:
        unsigned int row_size;
        unsigned int col_size;
        std::vector<Cell> CellList;
        
    public:
        GameBoard(unsigned int row = 8, unsigned int col = 8);
        
        unsigned int CoorToId(unsigned row, unsigned col){
            return (row * col_size + col);
        }
        
        Coor IdToCoor(unsigned int Id);
        
        void SetStatus(unsigned Id, CellStatus status);
        CellStatus GetStatus(unsigned Id);
        
        void PrintBoard();
    };
}


#endif /* GameBoard_hpp */
