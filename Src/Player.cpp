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
            if(a == LeftUp){
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
            if(a == LeftUp){
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

bool player::Player::IsLegalMove(board::GameBoard board, PlayerSide side, unsigned int Id, Action a){
    unsigned row = board.IdToCoor(Id).first;
    unsigned col = board.IdToCoor(Id).second;
    
    if(side == Player0){
        if( board.GetStatus(Id) == board::Player0 ){
            if(a == LeftUp){
                if( (row > 0) && (col > 0) && ( board.GetStatus( board.CoorToId(row - 1, col - 1) ) != board::Player0 ) )
                    return true;
                else
                    return false;
            }
            else if(a == Up){
                if( (row > 0) && ( board.GetStatus( board.CoorToId(row - 1, col) ) == board::Empty ) )
                    return true;
                else
                    return false;
            }
            else if(a == RightUp){
                if( (row > 0) && (col < (board.GetRowSize() - 1)) && ( board.GetStatus( board.CoorToId(row - 1, col + 1) ) != board::Player0 ) )
                    return true;
                else
                    return false;
            }
        }
        else
            return false;
    }
    else if(side == Player1){
        if( board.GetStatus(Id) == board::Player1 ){
            if(a == LeftUp){
                if( (row < (board.GetColSize() - 1)) && (col < (board.GetRowSize() - 1)) && ( board.GetStatus( board.CoorToId(row + 1, col + 1) ) != board::Player1 ) )
                    return true;
                else
                    return false;
            }
            else if(a == Up){
                if( (row < (board.GetColSize() - 1))  && ( board.GetStatus( board.CoorToId(row + 1, col) ) == board::Empty ) )
                    return true;
                else
                    return false;
                
            }
            else if(a == RightUp){
                if( (row < (board.GetColSize() - 1)) && (col > 0) && ( board.GetStatus( board.CoorToId(row + 1, col - 1) ) != board::Player1 ) )
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
            if(a == LeftUp){
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
            if(a == LeftUp){
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
            if(a == LeftUp){
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
            if(a == LeftUp){
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

board::GameBoard player::Player::ResultOfMove(board::GameBoard board, PlayerSide side, unsigned int Id, Action a){
    board::GameBoard board_new = board;
    
    unsigned row = board_new.IdToCoor(Id).first;
    unsigned col = board_new.IdToCoor(Id).second;
    
    if(side == Player0){
        if( board_new.GetStatus(Id) == board::Player0 ){
            if(a == LeftUp){
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
            if(a == LeftUp){
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
    
    for(int i = 0; i < col_size; ++i){
        for(int j = 0; j < row_size; ++j){
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
    
    for(int i = 0; i < col_size; ++i){
        for(int j = 0; j < row_size; ++j){
            if(side == Player0){
                if( (*board).GetStatus( (*board).CoorToId(i, j) ) == board::Player0 ){
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

void player::Player::GetChoiceSet(board::GameBoard board, PlayerSide side, ChoiceSet &choiceset){
    unsigned int row_size = board.GetRowSize();
    unsigned int col_size = board.GetColSize();
    Action action_list[] = {LeftUp, Up, RightUp};
    Choice choice;
    
    choiceset.clear();
    
    for(int i = 0; i < col_size; ++i){
        for(int j = 0; j < row_size; ++j){
            if(side == Player0){
                if( board.GetStatus( board.CoorToId(i, j) ) == board::Player0 ){
                    for(Action a: action_list){
                        if( IsLegalMove(board, side, board.CoorToId(i, j), a) ){
                            choice.first = board.CoorToId(i, j);
                            choice.second = a;
                            choiceset.push_back(choice);
                        }
                    }
                }
            }
            else if(side == Player1){
                if( board.GetStatus( board.CoorToId(i, j) ) == board::Player1 ){
                    for(Action a: action_list){
                        if( IsLegalMove(board, side, board.CoorToId(i, j), a) ){
                            choice.first = board.CoorToId(i, j);
                            choice.second = a;
                            choiceset.push_back(choice);
                        }
                    }
                }
            }
        }
    }
}

player::Choice player::Player::MakeChoice(unsigned int *NumOfNode){
    Choice c;
    (*NumOfNode) = 0;
    if(strategy == 0){
        MiniMax((*board), side, 0, depth, NumOfNode, &c);
    }
    else if(strategy == 1){
        MaxValue((*board), side, 0, depth, -99999999, 99999999, NumOfNode, &c);
    }
    else if(strategy == 2){
        ChoiceSet c_set;
        GetChoiceSet(c_set);
        c = c_set[rand() % c_set.size()];
    }
    return c;
}

float player::Player::MiniMax(board::GameBoard board, PlayerSide side, unsigned int Current_Depth, unsigned int Depth_Limit, unsigned int *NumOfNode, Choice *choice){
    if(Current_Depth == Depth_Limit)
        return (*heuristic)(board, side);
    else{
        (*NumOfNode)++;
        if( (Current_Depth % 2) == 0 ){
            float value_max = -99999999;
            ChoiceSet c_set;
            GetChoiceSet(board, side, c_set);
            for(auto &i : c_set){
                board::GameBoard board_next( board.GetRowSize(), board.GetColSize() );
                board_next = PlayResult(board, i);
                float value = MiniMax(board_next, side, Current_Depth + 1, Depth_Limit, NumOfNode);
                if( value >= value_max ){
                    value_max = value;
                    if(Current_Depth == 0)
                        (*choice) = i;
                }
            }
            return value_max;
        }
        else{
            float value_min = 99999999;
            ChoiceSet c_set;
            GetChoiceSet(board, GetOppositeSide(side), c_set);
            for(auto &i : c_set){
                board::GameBoard board_next( board.GetRowSize(), board.GetColSize() );
                board_next = PlayResult(board, i);
                float value = MiniMax(board_next, side, Current_Depth + 1, Depth_Limit, NumOfNode);
                if( value <= value_min )
                    value_min = value;
            }
            return value_min;
        }
    }
}

bool myLess(std::pair<float, player::Choice> a, std::pair<float, player::Choice> b)
{
    return a.first < b.first;
}

bool myGreater(std::pair<float, player::Choice> a, std::pair<float, player::Choice> b)
{
    return a.first > b.first;
}

void player::Player::ChangeMoveOrder(ChoiceSet *c_set, board::GameBoard board, PlayerSide side, bool IsAscending){
    std::pair<float, Choice> heu_and_choice_pair;
    std::vector< std::pair<float, Choice> > heu_and_choice;
    for(auto &i : (*c_set) ){
        board::GameBoard board_next( board.GetRowSize(), board.GetColSize() );
        board_next = player::Player::PlayResult(board, i);
        heu_and_choice_pair.first = (*heuristic)(board, side);
        heu_and_choice_pair.second = i;
        heu_and_choice.push_back(heu_and_choice_pair);
    }
    if(IsAscending)
        std::sort(heu_and_choice.begin(), heu_and_choice.end(), myLess);
    else
        std::sort(heu_and_choice.begin(), heu_and_choice.end(), myGreater);
    
    (*c_set).clear();
    
    for(auto &i : heu_and_choice)
        (*c_set).push_back(i.second);
    
}

float player::Player::MaxValue(board::GameBoard board, PlayerSide side, unsigned int Current_Depth, unsigned int Depth_Limit, float alpha, float beta, unsigned int *NumOfNode, Choice *choice){
    if(Current_Depth == Depth_Limit)
        return (*heuristic)(board, side);
    else{
        (*NumOfNode)++;
        float value_max = -99999999;
        ChoiceSet c_set;
        GetChoiceSet(board, side, c_set);
        //order the choice from bigger heuristic value to smaller
        //ChangeMoveOrder( &c_set, board, side, false);
        for(auto &i : c_set){
            board::GameBoard board_next( board.GetRowSize(), board.GetColSize() );
            board_next = PlayResult(board, i);
            float value = MinValue(board_next, side, Current_Depth + 1, Depth_Limit, alpha, beta, NumOfNode);
            if( value >= value_max ){
                value_max = value;
                if(Current_Depth == 0)
                    (*choice) = i;
            }
            if( value_max >= beta )
                return value_max;
            if( value_max > alpha )
                alpha = value;
        }
        return value_max;
    }
}

float player::Player::MinValue(board::GameBoard board, PlayerSide side, unsigned int Current_Depth, unsigned int Depth_Limit, float alpha, float beta, unsigned int *NumOfNode){
    if(Current_Depth == Depth_Limit)
        return (*heuristic)(board, side);
    else{
        (*NumOfNode)++;
        float value_min = 99999999;
        ChoiceSet c_set;
        GetChoiceSet(board, GetOppositeSide(side), c_set);
        //order the choice from smaller heuristic value to bigger
        //ChangeMoveOrder( &c_set, board, side, true);
        for(auto &i : c_set){
            board::GameBoard board_next( board.GetRowSize(), board.GetColSize() );
            board_next = PlayResult(board, i);
            float value = MaxValue(board_next, side, Current_Depth + 1, Depth_Limit, alpha, beta, NumOfNode);
            if( value <= value_min ){
                value_min = value;
            }
            if( value_min <= alpha )
                return value_min;
            if( value_min > beta )
                beta = value;
        }
        return value_min;
    }
}

unsigned int player::Player::play(){
    Choice c;
    unsigned int NumOfNode = 0;
    c = MakeChoice(&NumOfNode);
    Move(c.first, c.second);
    return NumOfNode;
}

board::GameBoard player::Player::PlayResult(board::GameBoard board, Choice choice){
    board::GameBoard board_new( board.GetRowSize(), board.GetColSize() );
    if( board.GetStatus(choice.first) == board::Player0 )
        board_new = ResultOfMove(board, player::Player0, choice.first, choice.second);
    else if( board.GetStatus(choice.first) == board::Player1 )
        board_new = ResultOfMove(board, player::Player1, choice.first, choice.second);
    return board_new;
}

player::PlayerSide player::Player::GetOppositeSide(PlayerSide side){
    if(side == Player0)
        return Player1;
    else if(side == Player1)
        return Player0;
    else
        return None;
}
