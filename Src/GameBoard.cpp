//
//  GameBoard.cpp
//  448-BreakThrough
//
//  Created by Liuyi Shi on 10/25/17.
//  Copyright © 2017 Liuyi Shi. All rights reserved.
//

#include "GameBoard.hpp"

board::GameBoard::GameBoard(unsigned int col_size, unsigned int row_size): row_size(row_size), col_size(col_size){
    CellList.resize(row_size * col_size);
    
    Cell c;
    
    for(int i = 0; i < col_size; ++i){
        for(int j = 0; j < row_size; ++j){
            c.row = i;
            c.col = j;
            if( i<2 )
                c.Status = Player1;
            else if ( i >= (col_size-2) )
                c.Status = Player0;
            else
                c.Status = Empty;
            CellList[ CoorToId(i, j) ] = c;
        }
    }
    
}

board::Coor  board::GameBoard::IdToCoor(unsigned int Id){
    Coor coor;
    coor.first = Id / row_size;
    coor.second = Id % row_size;
    return coor;
}

void board::GameBoard::SetStatus(unsigned int Id, CellStatus status){
    CellList[Id].Status = status;
}

board::CellStatus board::GameBoard::GetStatus(unsigned int Id){
    return CellList[Id].Status;
}

void board::GameBoard::PrintBoard(){
    printf("\n");
    for(int j=0; j < row_size+1; j++){
        if(j == 0)
            printf("  ");
        else
            printf("%d ",j);
        
        if(j == row_size)
            printf("\n");
    }
    
    for(auto &i : CellList){
        if(i.col == 0)
            printf("%d ",i.row+1);
        if(i.Status == Player0)
            printf("0 ");
        else if(i.Status == Player1)
            printf("1 ");
        else if(i.Status == Empty)
            printf("- ");
        if(i.col == row_size - 1)
            printf("\n");
    }
    printf("\n");
}

unsigned int board::GameBoard::GetStatusNum(CellStatus status){
    unsigned int num = 0;
    for(auto &i : CellList){
        if( i.Status == status)
            num++;
    }
    return num;
}
