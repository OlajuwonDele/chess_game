#include "Application.h"
#include "Chess_Board_Square.h"
#include "Chess_Piece.h"
#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>




using namespace std;


void Application::run(){
  int x=0, y=0, dx=0, dy=0, game=1, player=1, regexCheck;
  bool check = false;
  char answer='b';
  string move;

  Chess_Piece newPiece;
  Chess_Board_Square chessSquare;

  chessSquare.set();
  chessSquare.print();
  while (answer != 'q') {
    while (game > 0 && answer != 'q' && answer != 'r' && regexCheck != 2 && regexCheck != 3) {
      if (player == 1)
        cout << "It is the White player's turn.\n";
      else 
        cout << "It is the Black player's turn.\n";
      
      cout << "Choose the piece you wish to use \n";
      cout << "Enter the letter followed by number of the block you wish to choose \n";
      cout << "Enter \"-\" followed by the next block you wish to take \n";
      cout << "Example: f1-f2, F1-f3, A2-A3 or a2-A4.\n";
      cout << "If you wish to quit enter: \"q\".\n";
      cout << "If you wish to reset enter: \"r\".\n";
      cout << "If you wish to view the move list enter: \"v\".\n";
      cin >> move;
      moveList.addNode(move);
      boost::to_lower(move);
      
      check = false;
      regexCheck = chessSquare.regexUpdate(move, x, y, dx, dy);

      if (regexCheck == 4){
        moveList.printList();
        regexCheck = 0;
      }

      while (!check) {
        while (regexCheck == 0){
          if (move == "v"){
            cout << "Now, enter a valid move to make.\n";
          }
          else {
            cout << "Incorrect input for a move, re-enter your move\n";
          }
            cin >> move;
            moveList.addNode(move);
            boost::to_lower(move);
            regexCheck = chessSquare.regexUpdate(move, x, y, dx, dy);
            
        }
        switch (regexCheck){
          case 1: 
            regexCheck=0;
            check = chessSquare.check(player,x,y,dx,dy,newPiece);
            break;
          case 2:
            check = true;
            answer = 'q';
            break;
          case 3:
            check = true;
            answer = 'r';
            break;
          default:
            moveList.printList();
            regexCheck = 0;
        }
      }
      
      if (answer!= 'r' && answer != 'q'){
        chessSquare.print();
        cout << "If you wish to quit enter: \"q\".\n";
        cout << "If you wish to reset enter: \"r\".\n";
        cout << "If you wish to view the move list enter: \"v\".\n";
        cout << "To continue enter any other key.\n";

        cin >> answer;
        player = -player;
      }
      if (answer == 'v'){
        moveList.printList();
        cout << "If you wish to quit enter: \"q\".\n";
        cout << "If you wish to reset enter: \"r\".\n";
        cout << "To continue enter any other key.\n";
        cin >> answer;
      }
    }
    if (answer == 'r' || regexCheck == 3){
      moveList.resetList();
      chessSquare.set();
      chessSquare.print();
      player = 1;
      regexCheck = 0;
      answer = 'b';
    }
  }
  cout << "Game has ended\n";
  moveList.resetList();
  moveList.delList();
}


void Application::test(){
  int x=0, y=0, dx=0, dy=0, game=1, player=1, regexCheck, count=1;
  bool check = false;
  char answer='b';
  string move;

  Chess_Piece newPiece;
  Chess_Board_Square chessSquare;

  chessSquare.set();
  chessSquare.print();
  while (count !=5) {
    while (count != 5) {
      if (player == 1)
        cout << "It is the White player's turn.\n";
      else 
        cout << "It is the Black player's turn.\n";
      
      cout << "Choose the piece you wish to use \n";
      cout << "Enter the letter followed by number of the block you wish to choose \n";
      cout << "Enter \"-\" followed by the next block you wish to take \n";
      cout << "Example: f1-f2, F1-f3, A2-A3 or a2-A4.\n";
      cout << "If you wish to quit enter: \"q\".\n";
      cout << "If you wish to reset enter: \"r\".\n";
      cout << "If you wish to view the move list enter: \"v\".\n";
      switch (count){
        case 1:
          move = "a2-a4";
          cout << " move = \"a2-a4\" " << endl;
          break;
        case 2:
          move = "B7-B5";
          cout << " move = \"B7-B5\" " << endl;
          break;
        case 3:
          move = "v";
          cout << " move = \"v\" " << endl;
          break;
        case 4:
          move = "r";
          cout << " move = \"r\" " << endl;
          break;
        case 5:
          move = "v";
          cout << " move = \"v\" " << endl;
          break;
      }
      count++;
      moveList.addNode(move);
      boost::to_lower(move);
      
      check = false;
      regexCheck = chessSquare.regexUpdate(move, x, y, dx, dy);

      if (regexCheck == 4){
        moveList.printList();
        regexCheck = 0;
      }

      while (!check) {
        while (regexCheck == 0){
          if (move == "v"){
            cout << "Now, enter a valid move to make.\n";
          }
          else {
            cout << "Incorrect input for a move, re-enter your move\n";
          }
            if(count == 3){
              move = "a4-b5";
              cout << " move = \"a4-a5\" " << endl;
            }
            else {
              move = "b1-c3";
              cout << "move = \"b1-c3\" " << endl;
            }
            moveList.addNode(move);
            boost::to_lower(move);
            regexCheck = chessSquare.regexUpdate(move, x, y, dx, dy);
            
        }
        switch (regexCheck){
          case 1: 
            regexCheck=0;
            check = chessSquare.check(player,x,y,dx,dy,newPiece);
            break;
          case 2:
            check = true;
            answer = 'q';
            break;
          case 3:
            check = true;
            answer = 'r';
            break;
          default:
            moveList.printList();
            regexCheck = 0;
        }
      }
      
      if (answer!= 'r' && answer != 'q'){
        chessSquare.print();
        cout << "If you wish to quit enter: \"q\".\n";
        cout << "If you wish to reset enter: \"r\".\n";
        cout << "If you wish to view the move list enter: \"v\".\n";
        cout << "To continue enter any other key.\n";
        
        player = -player;
      }
      if (answer == 'v'){
        moveList.printList();
        cout << "If you wish to quit enter: \"q\".\n";
        cout << "If you wish to reset enter: \"r\".\n";
        cout << "To continue enter any other key.\n";
        
      }
    }
    if (answer == 'r' || regexCheck == 3){
      moveList.resetList();
      chessSquare.set();
      chessSquare.print();
      player = 1;
      regexCheck = 0;
      answer = 'b';
    }
  }
  cout << "Test has ended\n";
  moveList.resetList();
  moveList.delList();
}