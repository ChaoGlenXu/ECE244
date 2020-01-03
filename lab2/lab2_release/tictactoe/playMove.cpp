//
//  playMove.cpp
//  TicTacTo
//
//  Updated by Tarek Abdelrahman on 2019-06-07.
//  Created by Tarek Abdelrahman on 2018-05-15.
//  Copyright © 2018-2019 Tarek Abdelrahman. All rights reserved.
//

#include "tictactoe.h"
#include "gameState.h"
#include <iostream>
using namespace std;

void checkWin(int three, gameState& game_state);

void playMove(gameState& game_state) {
 
    //if game is over
    if (game_state.get_gameOver() == true)
        return;
    
    //check if the move is valid
    if(game_state.get_gameBoard(game_state.get_clickedRow(),game_state.get_clickedColumn()) == Empty){
        game_state.set_moveValid(true);     
    }else{//if move is invalid
        game_state.set_moveValid(false);
    }
    //if move is not valid, then end playMove
    if(game_state.get_moveValid() != true){       
            return;
    }
    
    //flip the turns and place X or O
    if(game_state.get_turn() == X){
        game_state.set_gameBoard(game_state.get_clickedRow(), game_state.get_clickedColumn(), X);
        game_state.set_turn(0);       
    }else { //for O's turn 
        game_state.set_gameBoard(game_state.get_clickedRow(), game_state.get_clickedColumn(), O);                       
        game_state.set_turn(1);  
    }   
           
    checkWin(1,game_state);// Check if X won the game   
    checkWin(-1,game_state);// Check if O won the game                
    
    // Check if draw
    bool is_draw = true;
    for (int k = 0; k <= 2; k++){
        for (int w = 0; w <= 2; w++){
            if(game_state.get_gameBoard(k,w) == Empty){
                is_draw = false;
            }   
        }
    }
    if (is_draw) {
        game_state.set_winCode(0);
        game_state.set_gameOver(true);
    }
}
//"three" is the parameter for X and O, check the winCode 
void checkWin(int three, gameState& game_state){
    
        if( (game_state.get_gameBoard(0,0) == three) && (game_state.get_gameBoard(0,1) == three)
                && (game_state.get_gameBoard(0,2) == three) ){
            game_state.set_winCode(1);
            game_state.set_gameOver(true);
       }else if( (game_state.get_gameBoard(1,0) == three) && (game_state.get_gameBoard(1,1) == three)
               && (game_state.get_gameBoard(1,2) == three) ){
            game_state.set_winCode(2);
            game_state.set_gameOver(true);
       }else if( (game_state.get_gameBoard(2,0) == three) && (game_state.get_gameBoard(2,1) == three)
               && (game_state.get_gameBoard(2,2) == three) ){
            game_state.set_winCode(3);
            game_state.set_gameOver(true);
       }else if( (game_state.get_gameBoard(0,0) == three) && (game_state.get_gameBoard(1,0) == three)
               && (game_state.get_gameBoard(2,0) == three) ){
            game_state.set_winCode(4);         
            game_state.set_gameOver(true);
       }else if( (game_state.get_gameBoard(0,1) == three) && (game_state.get_gameBoard(1,1) == three)
               && (game_state.get_gameBoard(2,1) == three) ){
            game_state.set_winCode(5);
            game_state.set_gameOver(true);
       }else if( (game_state.get_gameBoard(0,2) == three) && (game_state.get_gameBoard(1,2) == three)
               && (game_state.get_gameBoard(2,2) == three) ){
            game_state.set_winCode(6); 
            game_state.set_gameOver(true);
       }else if( (game_state.get_gameBoard(0,0) == three) && (game_state.get_gameBoard(1,1) == three) 
               && (game_state.get_gameBoard(2,2) == three) ){
            game_state.set_winCode(7);
            game_state.set_gameOver(true);
       }else if( (game_state.get_gameBoard(0,2) == three) && (game_state.get_gameBoard(1,1) == three)
               && (game_state.get_gameBoard(2,0) == three) ){
            game_state.set_winCode(8);
            game_state.set_gameOver(true);
       }
        return;
   }


