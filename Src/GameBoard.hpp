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
    enum cellstatus {Player0, Player1, Empty};
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
        GameBoard(unsigned int col_size = 8, unsigned int row_size = 8);
        
        unsigned int CoorToId(unsigned row, unsigned col){ return (row * row_size + col); }
        Coor IdToCoor(unsigned int Id);
        
        void SetStatus(unsigned Id, CellStatus status);
        CellStatus GetStatus(unsigned Id);
        
        unsigned int GetRowSize(){ return row_size; }
        unsigned int GetColSize(){ return col_size; }
        
        unsigned int GetStatusNum(CellStatus status);
        
        void PrintBoard();
    };
}


#endif /* GameBoard_hpp */
