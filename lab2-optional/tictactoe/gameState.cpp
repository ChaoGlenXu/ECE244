//
//  gameState.cpp
//  TicTacTo
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Copyright © 2019 Tarek Abdelrahman. All rights reserved.

#include "tictactoe.h"
#include "gameState.h"

    // Return the clicked row (0..boardSize-1)
    int gameState::get_clickedRow(){
        return clickedRow;
    }     

    // Return the clicked column (0..boardSize-1)
    int gameState::get_clickedColumn(){
        return clickedColumn;
    }  
    
    // Set the clicked row to value (0..boardSize-1)
    // An invalid value is ignored and no action is taken
    void gameState::set_clickedRow(int value){
        if ((value <= 2 ) && (value >= 0)){
        clickedRow = value;//i need to come back to think -1 or not!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        }
    }     

    // Set the clicked column (0..boardSize-1)
    // An invalid value is ignored and no action is taken
    void gameState::set_clickedColumn(int value){
        if ((value <= 2 ) && (value >= 0)){
        clickedColumn = value;
        }
    }  
    
    // Get the moveValid value
    bool gameState::get_moveValid(){
        return moveValid;
    }

    // Set the moveValid variable to value
    void gameState::set_moveValid(bool value){
        moveValid = value;
    }

    // Get the gameOver value
    bool gameState::get_gameOver(){
        return gameOver;
    }

    // Set the gameOver variable to value
    void gameState::set_gameOver(bool value){
        gameOver = value;
    }

    // Get the winCode
    int gameState::get_winCode(){
        return winCode;
    }
    
    // Set the winCode to value
    // An invalid value is ignored and no action is takem
    void gameState::set_winCode(int value){
        
        switch (value){//come back to think about if already 1-8!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:           
                winCode = value;
        }
    }
    
    // Get the value of turn
    bool gameState::get_turn(){
        return turn;
    }

    // Set the value of turn
    void gameState::set_turn(bool value){
        turn = value;
    }
    
    // Get the game board value at the board location at row and col
    int gameState::get_gameBoard(int row, int col){
        //need to google the gameBoard[][] syntax!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        return gameBoard[row][col];
    } 

    // Set the game board value at the board location at row and col to value
    // This method checks that row, col and value are valid and if not it
    // performs no action
    void gameState::set_gameBoard(int row, int col, int value){ 
        if( (row >=0) && (row<=2) && (col >=0) && (col<=2)){ // i checked if gameBoard[row][col] == 0, but it gives me not showing on the screen!!!!! need to think
            gameBoard[row][col] = value;
        }
    }
