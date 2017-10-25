//
//  GameBoard.cpp
//  448-BreakThrough
//
//  Created by Liuyi Shi on 10/25/17.
//  Copyright © 2017 Liuyi Shi. All rights reserved.
//

#include "GameBoard.hpp"

board::GameBoard::GameBoard(unsigned int row, unsigned int col): row_size(row), col_size(col){
    CellList.resize(row_size * col_size);
    
    Cell c;
    
    for(int i = 0; i < row_size; ++i){
        for(int j = 0; j < col_size; ++j){
            c.row = i;
            c.col = j;
            if( i<2 )
                c.Status = Player1;
            else if ( i >= (row_size-2) )
                c.Status = Player0;
            else
                c.Status = Empty;
            CellList[ CoorToId(i, j) ] = c;
        }
    }
    
}

board::Coor  board::GameBoard::IdToCoor(unsigned int Id){
    Coor coor;
    coor.first = Id / col_size;
    coor.second = Id % col_size;
    return coor;
}

void board::GameBoard::SetStatus(unsigned int Id, CellStatus status){
    CellList[Id].Status = status;
}

board::CellStatus board::GameBoard::GetStatus(unsigned int Id){
    return CellList[Id].Status;
}

void board::GameBoard::PrintBoard(){
    for(auto &i : CellList){
        if(i.Status == Player0)
            printf("X");
        else if(i.Status == Player1)
            printf("O");
        else if(i.Status == Empty)
            printf("E");
        if(i.col == col_size - 1)
            printf("\n");
    }
}
