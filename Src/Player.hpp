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
#include "GameBoard.hpp"
#include "Heuristic.hpp"
#include "Header.h"

namespace player{
    
    enum action {LeftUp, Up, RightUp};
    typedef enum action Action;
    
    typedef std::pair<unsigned int, Action> Choice;
    typedef std::vector<Choice> ChoiceSet;
    
    class Player{
    private:
        board::GameBoard *board;
        PlayerSide side;
        heu::Heuristic *heuristic; // evaluation function used to evaluate a game status
        int strategy; //0:MiniMax 1:AlphaBeta 2:Randomly pick up a choice
        
    public:
        Player(board::GameBoard *b, PlayerSide s, heu::Heuristic *h, int stra = 2):board(b), side(s), heuristic(h), strategy(stra) {};
        
        void SetPlayerSide(PlayerSide s){ side = s; }
        void SetGameBoard(board::GameBoard *b){ board = b; }
        void SetHeuristic(heu::Heuristic *h){ heuristic = h; }
        void SetStrategy(int stra){ strategy = stra; }
        
        bool IsLegalMove(unsigned int Id, Action a);
        static bool IsLegalMove(board::GameBoard board, PlayerSide side, unsigned int Id, Action a);
        
        void Move(unsigned int Id, Action a);
        board::GameBoard ResultOfMove(unsigned int Id, Action a);
        static board::GameBoard ResultOfMove(board::GameBoard board, PlayerSide side, unsigned int Id, Action a);
        
        static PlayerSide DetectWinner(board::GameBoard b, bool IsThreeWorker = false);
        
        void GetChoiceSet(ChoiceSet &choiceset);
        
        static void GetChoiceSet(board::GameBoard board, PlayerSide side, ChoiceSet &choiceset);
        
        Choice MakeChoice();
        
        //when depth=0, choice will contain the choice that has the minimax evalution value
        float MiniMax(board::GameBoard board, PlayerSide side, unsigned int Current_Depth, unsigned int Depth_Limit, Choice *choice = nullptr);
        
        //menthods for aplha-beta pruning
        float MaxValue(board::GameBoard board, PlayerSide side, unsigned int Current_Depth, unsigned int Depth_Limit, float alpha, float beta, Choice *choice = nullptr);
        float MinValue(board::GameBoard board, PlayerSide side, unsigned int Current_Depth, unsigned int Depth_Limit, float alpha, float beta);
        
        void play();
        static board::GameBoard PlayResult(board::GameBoard board, Choice choice);
        
        static PlayerSide GetOppositeSide(PlayerSide side);
    };
}

#endif /* Player_hpp */
