//
//  Player.cpp
//  448-BreakThrough
//
//  Created by Liuyi Shi on 10/25/17.
//  Copyright © 2017 Liuyi Shi. All rights reserved.
//

#include "Player.hpp"

bool player::Player::IsLegalMove(unsigned int Id, Action a){
    unsigned row = (*board).IdToCoor(Id).first;
    unsigned col = (*board).IdToCoor(Id).second;
    
    if(side == Player0){
        if( (*board).GetStatus(Id) == board::Player0 ){
            if(a == Stay){
                return true;
            }
            else if(a == LeftUp){
                if( (row > 0) && (col > 0) && ( (*board).GetStatus( (*board).CoorToId(row - 1, col - 1) ) != board::Player0 ) )
                    return true;
                else
                    return false;
            }
            else if(a == Up){
                if( (row > 0) && ( (*board).GetStatus( (*board).CoorToId(row - 1, col) ) == board::Empty ) )
                    return true;
                else
                    return false;
            }
            else if(a == RightUp){
                if( (row > 0) && (col < ((*board).GetRowSize() - 1)) && ( (*board).GetStatus( (*board).CoorToId(row - 1, col + 1) ) != board::Player0 ) )
                    return true;
                else
                    return false;
            }
        }
        else
            return false;
    }
    else if(side == Player1){
        if( (*board).GetStatus(Id) == board::Player1 ){
            if(a == Stay){
                return true;
            }
            else if(a == LeftUp){
                if( (row < ((*board).GetColSize() - 1)) && (col < ((*board).GetRowSize() - 1)) && ( (*board).GetStatus( (*board).CoorToId(row + 1, col + 1) ) != board::Player1 ) )
                    return true;
                else
                    return false;
            }
            else if(a == Up){
                if( (row < ((*board).GetColSize() - 1))  && ( (*board).GetStatus( (*board).CoorToId(row + 1, col) ) == board::Empty ) )
                    return true;
                else
                    return false;
                
            }
            else if(a == RightUp){
                if( (row < ((*board).GetColSize() - 1)) && (col > 0) && ( (*board).GetStatus( (*board).CoorToId(row + 1, col - 1) ) != board::Player1 ) )
                    return true;
                else
                    return false;
            }
        }
        else
            return false;
    }
    return false;
}

void player::Player::Move(unsigned int Id, Action a){
    unsigned row = (*board).IdToCoor(Id).first;
    unsigned col = (*board).IdToCoor(Id).second;
    
    if(side == Player0){
        if( (*board).GetStatus(Id) == board::Player0 ){
            if(a == Stay){
                
            }
            else if(a == LeftUp){
                if( (row > 0) && (col > 0) && ( (*board).GetStatus( (*board).CoorToId(row - 1, col - 1) ) != board::Player0 ) ){
                    (*board).SetStatus( (*board).CoorToId(row, col) , board::Empty);
                    (*board).SetStatus( (*board).CoorToId(row - 1, col - 1) , board::Player0);
                }
                else
                    printf("Error in Player0 move LeftUp.\n");
            }
            else if(a == Up){
                if( (row > 0) && ( (*board).GetStatus( (*board).CoorToId(row - 1, col) ) == board::Empty ) ){
                    (*board).SetStatus( (*board).CoorToId(row, col) , board::Empty);
                    (*board).SetStatus( (*board).CoorToId(row - 1, col) , board::Player0);
                }
                else
                    printf("Error in Player0 move UP.\n");
            }
            else if(a == RightUp){
                if( (row > 0) && (col < ((*board).GetRowSize() - 1)) && ( (*board).GetStatus( (*board).CoorToId(row - 1, col + 1) ) != board::Player0 ) ){
                    (*board).SetStatus( (*board).CoorToId(row, col) , board::Empty);
                    (*board).SetStatus( (*board).CoorToId(row - 1, col + 1) , board::Player0);
                }
                else
                    printf("Error in Player0 move RightUp.\n");
            }
        }
        else
            printf("Error in Player0 move, the cell does not contain Player0.\n");
    }
    else if(side == Player1){
        if( (*board).GetStatus(Id) == board::Player1 ){
            if(a == Stay){
                
            }
            else if(a == LeftUp){
                if( (row < ((*board).GetColSize() - 1)) && (col < ((*board).GetRowSize() - 1)) && ( (*board).GetStatus( (*board).CoorToId(row + 1, col + 1) ) != board::Player1 ) ){
                    (*board).SetStatus( (*board).CoorToId(row, col) , board::Empty);
                    (*board).SetStatus( (*board).CoorToId(row + 1, col + 1) , board::Player1);
                }
                else
                    printf("Error in Player1 move LeftUp.\n");
            }
            else if(a == Up){
                if( (row < ((*board).GetColSize() - 1))  && ( (*board).GetStatus( (*board).CoorToId(row + 1, col) ) == board::Empty ) ){
                    (*board).SetStatus( (*board).CoorToId(row, col) , board::Empty);
                    (*board).SetStatus( (*board).CoorToId(row + 1, col) , board::Player1);
                }
                else
                    printf("Error in Player1 move Up.\n");
                
            }
            else if(a == RightUp){
                if( (row < ((*board).GetColSize() - 1)) && (col > 0) && ( (*board).GetStatus( (*board).CoorToId(row + 1, col - 1) ) != board::Player1 ) ){
                    (*board).SetStatus( (*board).CoorToId(row, col) , board::Empty);
                    (*board).SetStatus( (*board).CoorToId(row + 1, col - 1) , board::Player1);
                }
                else
                    printf("Error in Player1 move RightUp.\n");
            }
        }
        else
            printf("Error in Player1 move, the cell does not contain Player1.\n");
    }
}

board::GameBoard player::Player::ResultOfMove(unsigned int Id, Action a){
    board::GameBoard board_new = *board;
    
    unsigned row = board_new.IdToCoor(Id).first;
    unsigned col = board_new.IdToCoor(Id).second;
    
    if(side == Player0){
        if( board_new.GetStatus(Id) == board::Player0 ){
            if(a == Stay){
                
            }
            else if(a == LeftUp){
                if( (row > 0) && (col > 0) && ( board_new.GetStatus( board_new.CoorToId(row - 1, col - 1) ) != board::Player0 ) ){
                    board_new.SetStatus( board_new.CoorToId(row, col) , board::Empty);
                    board_new.SetStatus( board_new.CoorToId(row - 1, col - 1) , board::Player0);
                }
                else
                    printf("Error in Player0 move LeftUp.\n");
            }
            else if(a == Up){
                if( (row > 0) && ( board_new.GetStatus( board_new.CoorToId(row - 1, col) ) == board::Empty ) ){
                    board_new.SetStatus( board_new.CoorToId(row, col) , board::Empty);
                    board_new.SetStatus( board_new.CoorToId(row - 1, col) , board::Player0);
                }
                else
                    printf("Error in Player0 move UP.\n");
            }
            else if(a == RightUp){
                if( (row > 0) && (col < (board_new.GetRowSize() - 1)) && ( board_new.GetStatus( board_new.CoorToId(row - 1, col + 1) ) != board::Player0 ) ){
                    board_new.SetStatus( board_new.CoorToId(row, col) , board::Empty);
                    board_new.SetStatus( board_new.CoorToId(row - 1, col + 1) , board::Player0);
                }
                else
                    printf("Error in Player0 move RightUp.\n");
            }
        }
        else
            printf("Error in Player0 move, the cell does not contain Player0.\n");
    }
    else if(side == Player1){
        if( board_new.GetStatus(Id) == board::Player1 ){
            if(a == Stay){
                
            }
            else if(a == LeftUp){
                if( (row < (board_new.GetColSize() - 1)) && (col < (board_new.GetRowSize() - 1)) && ( board_new.GetStatus( board_new.CoorToId(row + 1, col + 1) ) != board::Player1 ) ){
                    board_new.SetStatus( board_new.CoorToId(row, col) , board::Empty);
                    board_new.SetStatus( board_new.CoorToId(row + 1, col + 1) , board::Player1);
                }
                else
                    printf("Error in Player1 move LeftUp.\n");
            }
            else if(a == Up){
                if( (row < (board_new.GetColSize() - 1))  && ( board_new.GetStatus( board_new.CoorToId(row + 1, col) ) == board::Empty ) ){
                    board_new.SetStatus( board_new.CoorToId(row, col) , board::Empty);
                    board_new.SetStatus( board_new.CoorToId(row + 1, col) , board::Player1);
                }
                else
                    printf("Error in Player1 move Up.\n");
                
            }
            else if(a == RightUp){
                if( (row < (board_new.GetColSize() - 1)) && (col > 0) && ( board_new.GetStatus( board_new.CoorToId(row + 1, col - 1) ) != board::Player1 ) ){
                    board_new.SetStatus( board_new.CoorToId(row, col) , board::Empty);
                    board_new.SetStatus( board_new.CoorToId(row + 1, col - 1) , board::Player1);
                }
                else
                    printf("Error in Player1 move RightUp.\n");
            }
        }
        else
            printf("Error in Player1 move, the cell does not contain Player1.\n");
    }
    return board_new;
}

player::PlayerSide player::Player::DetectWinner(board::GameBoard b, bool IsThreeWorker){
    unsigned int row_size = b.GetRowSize();
    unsigned int col_size = b.GetColSize();
    
    int Player0Workers = 0;
    int Player1Workers = 0;
    int Player0WorkerAtPlayer1Base = 0;
    int Player1WorkerAtPlayer0Base = 0;
    
    for(int i = 0; i < row_size; ++i){
        for(int j = 0; j < col_size; ++j){
            if( b.GetStatus(b.CoorToId(i, j)) == board::Player0 ){
                if( i == 0)
                    Player0WorkerAtPlayer1Base++;
                Player0Workers++;
            }
            if( b.GetStatus(b.CoorToId(i, j)) == board::Player1 ){
                if( i == col_size - 1)
                    Player1WorkerAtPlayer0Base++;
                Player1Workers++;
            }
        }
    }
    
    if(!IsThreeWorker){
        if( (Player0WorkerAtPlayer1Base >= 1) || (Player1Workers == 0) )
            return player::Player0;
        else if( (Player1WorkerAtPlayer0Base >= 1) || (Player0Workers == 0) )
            return player::Player1;
        else
            return player::None;
    }
    else{
        if( (Player0WorkerAtPlayer1Base >= 3) || (Player1Workers < 3) )
            return player::Player0;
        else if( (Player1WorkerAtPlayer0Base >= 3) || (Player0Workers < 3) )
            return player::Player1;
        else
            return player::None;
    }
}

void player::Player::GetChoiceSet(ChoiceSet &choiceset){
    unsigned int row_size = (*board).GetRowSize();
    unsigned int col_size = (*board).GetColSize();
    Action action_list[] = {LeftUp, Up, RightUp};
    Choice choice;
    
    choiceset.clear();
    
    for(int i = 0; i < row_size; ++i){
        for(int j = 0; j < col_size; ++j){
            if(side == Player0){
                if( (*board).GetStatus( (*board).CoorToId(i, j) ) == board::Player0 ){
                    //the action of "Stay" for every worker just gets the result, therefore only consider it for the first time
                    if(choiceset.size() == 0){
                        choice.first = (*board).CoorToId(i, j);
                        choice.second = Stay;
                        choiceset.push_back(choice);
                    }
                    for(Action a: action_list){
                        if( IsLegalMove((*board).CoorToId(i, j), a) ){
                            choice.first = (*board).CoorToId(i, j);
                            choice.second = a;
                            choiceset.push_back(choice);
                        }
                    }
                }
            }
            else if(side == Player1){
                if( (*board).GetStatus( (*board).CoorToId(i, j) ) == board::Player1 ){
                    //the action of "Stay" for every worker just gets the result, therefore only consider it for the first time
                    if(choiceset.size() == 0){
                        choice.first = (*board).CoorToId(i, j);
                        choice.second = Stay;
                        choiceset.push_back(choice);
                    }
                    for(Action a: action_list){
                        if( IsLegalMove((*board).CoorToId(i, j), a) ){
                            choice.first = (*board).CoorToId(i, j);
                            choice.second = a;
                            choiceset.push_back(choice);
                        }
                    }
                }
            }
        }
    }
}
