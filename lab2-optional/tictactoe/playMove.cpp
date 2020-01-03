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
 
    //implement logic first, then try to merge it to the rest

// start over again    
    if (game_state.get_gameOver() == true)
        return;
   
        
    if ((game_state.get_gameBoard(game_state.get_clickedRow(),game_state.get_clickedColumn()) != X ) && // need to think why = empty not work!!!!
            (game_state.get_gameBoard(game_state.get_clickedRow(),game_state.get_clickedColumn()) != O)){//move is valid
        game_state.set_moveValid(true);// ASK WHY ?

       // cout<<"A";
    }else{//for move is invalid
        game_state.set_moveValid(false);
        //cout<<"B";// PLEASE CLICK AGAIN: at set_moveValid part
    }
    
    if(game_state.get_moveValid() != true){       
            //cout<<"C "; //PLEASE CLICK AGAIN: AT GET MOVE PART: DO NOTHING
            return;
    }
    
   //     game_state.set_clickedColumn(game_state.get_clickedColumn());
    //    game_state.set_clickedRow(game_state.get_clickedRow());   
    
    if(game_state.get_turn() == X){
        game_state.set_gameBoard(game_state.get_clickedRow(), game_state.get_clickedColumn(), X);

        //game_state.set_turn(O);
       // cout<<"D ";
        
    }else { //if turn == -1
        game_state.set_gameBoard(game_state.get_clickedRow(), game_state.get_clickedColumn(), O);// the space may cause bug                 
        
        //game_state.set_turn(X);   // if flip the turn in the  DO NOT works, but in the end, works, need to think!!!!
       // cout<<"E ";
    }   

            
//    //check the full board(if full board but no wincode matchs ,
//            game_state.set_gameOver(true);
//    for (int k = 0; k <= 2; k++){
//        for (int w = 0; w <= 2; w++){
//            if(game_state.get_gameBoard(k,w) != Empty){
//                game_state.set_gameOver(false);
//            }else{
//                if ((game_state.get_winCode() != 1)&& (game_state.get_winCode() != 2) && (game_state.get_winCode() != 3) && 
//                        (game_state.get_winCode() != 4) && (game_state.get_winCode() != 5) && (game_state.get_winCode() != 6) && 
//                        (game_state.get_winCode() != 7) && (game_state.get_winCode() != 8)){
//                    game_state.set_winCode(0);
//                }
//                    
//            }
//                
//        }
//    } 
            checkWin(1,game_state);
            checkWin(-1,game_state);     
            
// // start over ends here   
//    for (int i=0;i<=2;i++){
//            for (int j=0;j<=2;j++){
//                cout<< game_state.get_gameBoard(i,j) << " ";
//            }
//            cout<< endl;
//        }
//        cout << game_state.get_clickedRow() << " ";
//        cout << game_state.get_clickedColumn() << " ";
//        cout << game_state.get_turn() << " ";
//        cout << game_state.get_moveValid() << " "; 
//        cout << game_state.get_gameOver();
//        cout<<endl;
    game_state.set_turn(!(game_state.get_turn()));
//        
//    //cout << "No Win";   
}

void checkWin(int three, gameState& game_state){
    
        if( (game_state.get_gameBoard(0,0) == three) && (game_state.get_gameBoard(0,1) == three) && (game_state.get_gameBoard(0,2) == three) ){
            game_state.set_winCode(1);
          //  cout << "Row0 of the grid, cell(0,0) to cell(0,2)";
            game_state.set_gameOver(true);
       }else if( (game_state.get_gameBoard(1,1) == three) && (game_state.get_gameBoard(1,1) == three) && (game_state.get_gameBoard(1,2) == three) ){
            game_state.set_winCode(2);
          //  cout << "Row1 of the grid, cell(1,0) to cell(1,2)";
            game_state.set_gameOver(true);
       }else if( (game_state.get_gameBoard(2,1) == three) && (game_state.get_gameBoard(2,1) == three) && (game_state.get_gameBoard(2,2) == three) ){
            game_state.set_winCode(3);
          //  cout << "Row2 of the grid, cell(2,0) to cell(2,2)";
            game_state.set_gameOver(true);
       }else if( (game_state.get_gameBoard(0,0) == three) && (game_state.get_gameBoard(1,0) == three) && (game_state.get_gameBoard(2,0) == three) ){
            game_state.set_winCode(4);
           // cout << "column0 of the grid, cell(0,0) to cell(2,0)";
            game_state.set_gameOver(true);
       }else if( (game_state.get_gameBoard(0,1) == three) && (game_state.get_gameBoard(1,1) == three) && (game_state.get_gameBoard(2,1) == three) ){
            game_state.set_winCode(5);
           // cout << "column1 of the grid, cell(0,1) to cell(2,1)";
            game_state.set_gameOver(true);
       }else if( (game_state.get_gameBoard(0,2) == three) && (game_state.get_gameBoard(1,2) == three) && (game_state.get_gameBoard(2,2) == three) ){
            game_state.set_winCode(6);
          //  cout << "column2 of the grid, cell(0,0) to cell(2,0)"; 
            game_state.set_gameOver(true);
       }else if( (game_state.get_gameBoard(0,0) == three) && (game_state.get_gameBoard(1,1) == three) && (game_state.get_gameBoard(2,2) == three) ){
            game_state.set_winCode(7);
           // cout << "Left to right diagonal, cell(0,0) to cell(2,2)";
            game_state.set_gameOver(true);
       }else if( (game_state.get_gameBoard(0,2) == three) && (game_state.get_gameBoard(1,1) == three) && (game_state.get_gameBoard(2,0) == three) ){
            game_state.set_winCode(8);
          //  cout << "Right to left diagonal, cell(0,0) to cell(2,0)";
            game_state.set_gameOver(true);
       }//else 
        return;
  
   }