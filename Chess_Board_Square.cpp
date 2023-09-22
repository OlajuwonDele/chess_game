#include "Chess_Board_Square.h"
#include "Application.h"
#include "Chess_Piece.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <regex>
#include <sstream> 

using namespace std;

Chess_Board_Square::Chess_Board_Square(){}

Chess_Board_Square::~Chess_Board_Square(){
  for (int i = 0; i <= 8+8*8; i++){
    square[i] = NULL;
    delete square[i];
  }
}

void Chess_Board_Square:: set(){

  int i, j;

  for  (j=0; j<8; j++) {
    for (i=0; i<8; i++)
     square[i+j*8] = new Chess_Board_Square[8*8];
  }
  
  for (i=0; i<16; i++){
    switch (i){
      case 0:
        chessP1[i].type = " K  ";
        chessP2[i].type = "[k] ";
        break;
      case 1:
        chessP1[i].type = " Q  ";
        chessP2[i].type = "[q] ";
        break;
      case 2 ... 3:
        chessP1[i].type = " B  ";
        chessP2[i].type = "[b] ";
        break;
      case 4 ... 5:
        chessP1[i].type = " N  ";
        chessP2[i].type = "[n] ";
        break;    
      case 6 ... 7:
        chessP1[i].type = " R  ";
        chessP2[i].type = "[r] ";
        break;
      default:

        chessP1[i].type =  " P  ";
        chessP2[i].type = "[p] ";
        chessP1[i].moveNum = 0;
        chessP2[i].moveNum = 0;
    }
  }

   for (i=0; i<16; i++){
    chessP1[i].colour = 'w';
    chessP2[i].colour = 'b';
  }
  
   empty.type = "    ";
   empty.colour = 'e';

    for(int y=0; y<8; y++) {
      for(int x=0; x<8; x++){
        switch (y){
          case 0:
            switch(x){
              case 0:
                square[x+y*8]->piece = chessP1[6];
                break;
              case 7:
                square[x+y*8]->piece = chessP1[7];
                break;
              case 1:
                square[x+y*8]->piece = chessP1[4];
                break;
              case 6:
                square[x+y*8]->piece = chessP1[5];
                break;
              case 2:
                square[x+y*8]->piece = chessP1[2];
                break;
              case 5:
                square[x+y*8]->piece = chessP1[3];
                break;
              case 3:
                square[x+y*8]->piece = chessP1[0];
                break;
              case 4:
                square[x+y*8]->piece = chessP1[1]; 
                break;
              default:;
            }
            break;
          case 1:
            square[x+y*8]->piece = chessP1[x+8]; 
            break;
          case 6:
            square[x+y*8]->piece = chessP2[x+8]; 
            break;
          case 2 ... 5:
            square[x+y*8]->piece = empty;
            break;
          case 7:
            switch(x){
              case 0:
                square[x+y*8]->piece = chessP2[6];
                break;
              case 7:
                square[x+y*8]->piece = chessP2[7];
                break;
              case 1:
                square[x+y*8]->piece = chessP2[4];
                break;
              case 6:
                square[x+y*8]->piece = chessP2[5];
                break;
              case 2:
                square[x+y*8]->piece = chessP2[2];
                break;
              case 5:
                square[x+y*8]->piece = chessP2[3];
                break;
              case 3:
                square[x+y*8]->piece = chessP2[0];
                break;
              case 4:
                square[x+y*8]->piece = chessP2[1]; 
                break;
              default:
                square[x+y*8]->piece = empty;
            }

        } 
      }
    
    } 
}

void Chess_Board_Square::print(){
   for(int y=0; y<8; y++) {
    cout <<"\n" << y+1 << "  ";
		for(int x=0; x<8; x++){
      cout << "|| ";
       cout << square[x+y*8]->piece.type;
      }
      cout << "|| ";
    }
    cout <<"\n";
    cout << setw(9) << " A " << setw(7) << " B " << setw(7) << " C " << setw(7) << " D ";
    cout << setw(7) << " E " << setw(7) << " F " << setw(7) << " G " << setw(7) << " H ";
    cout << setw(7)<< endl;
  }

 bool Chess_Board_Square::check(int player, int x, int y, int dx, int dy, Chess_Piece &newPiece) {
  y--;
  dy--;

  
  if(square[x+y*8]->piece.colour != 'w' && player == 1)
    return false;
  else if (square[x+y*8]->piece.colour != 'b' && player == -1)
    return false;
  if(square[dx+dy*8]->piece.colour == 'w' && player == 1)
    return false;
  else if (square[dx+dy*8]->piece.colour == 'b' && player == -1)
    return false;

  int i=x, di=dx, j=y, dj=dy;

  if (square[x+y*8]->piece.type == " Q  " || square[x+y*8]->piece.type == " R  " || square[x+y*8]->piece.type == "[q] " || square[x+y*8]->piece.type == "[r] "){
   
        if(dy>y && dx-x == 0) {
           while (j < dy-1) {
            j++;
            if(square[i+j*8]->piece.colour != 'e'){
              cout << j << endl;
              cout << "error\n";
              return false;
              }
            }
        }
        else if(y>dy && dx-x == 0) {
           while (j > dy-1) {
            j--;
            if(square[i+j*8]->piece.colour != 'e')
              return false;
          }
        }
        else if(dy-y == 0 && dx>x) {
           while (i < dx-1) {
            i++;
            if(square[i+j*8]->piece.colour != 'e')
              return false;
          }
        }
        else if(dy-y == 0 && dx<x) {
           while (i > dx-1) {
            i--;
            if(square[i+j*8]->piece.colour != 'e')
              return false;
          }
        }
  }
   
  
  if (square[x+y*8]->piece.type == " P  "){
    if (square[dx+dy*8]->piece.colour == 'b')
      player = 2;
  }
  
  if (square[x+y*8]->piece.type == "[p] "){
    if (square[dx+dy*8]->piece.colour == 'w')
      player = 3;
  }

  if (square[x+y*8]->piece.type == " Q  " || square[x+y*8]->piece.type == " B  " || square[x+y*8]->piece.type == "[q] " || square[x+y*8]->piece.type == "[b] "){
    
        if(dy>y && dx-x>0) {
           while (i != dx && j != dy) {
            i++;
            j++;
            if(square[i+j*8]->piece.colour != 'e')
              return false;
          }
        }
        else if(y>dy && dx-x>0) {
          while (i != dx && j != dy) {
            i++;
            j--;
            if(square[i+j*8]->piece.colour != 'e')
              return false;
          }
        }
        else if(y>dy && dx-x<0) {
          while (i != dx && j != dy) {
            i--;
            j--;
            if(square[i+j*8]->piece.colour != 'e')
              return false;
          }
        }
        else if(dy>y && dx-x<0) {
          while (i != dx && j != dy) {
            i--;
            j++;
            if(square[i+j*8]->piece.colour != 'e')
              return false;
          }
        }
      
    }
  
  bool playerMove = square[x+y*8]->piece.movePiece(x,y,dx,dy,player);

  if(!playerMove){
    cout << "This move is not possible\n";
    return false;
  }

  newPiece = square[x+y*8]->piece;
  newPiece.type = square[x+y*8]->piece.type;
  newPiece.colour = square[x+y*8]->piece.colour;
  square[dx+dy*8]->piece = newPiece;
  square[dx+dy*8]->piece.type = newPiece.type;
  square[dx+dy*8]->piece.colour = newPiece.colour;
  square[x+y*8]->piece = empty;
  square[x+y*8]->piece.type = empty.type;
  square[x+y*8]->piece.colour= empty.colour;
  return true;
}


int Chess_Board_Square::regexUpdate(string move, int &x, int &y, int &dx, int &dy){

  smatch matches;
  regex match("(^([a-h])([1-8])(-)([a-h])([1-8])$)");
  if (move == "q")
    return 2;
  else if (move == "r")
    return 3;
  else if (move == "v")
    return 4;
  try{
    if(regex_search(move, matches, match)){
      
      stringstream yConvert(matches[3].str());
      yConvert >> y;
      
      stringstream dyConvert(matches[6].str());
      dyConvert >> dy;
      
      if (matches[2].str() == "a")
        x = 0;
      else if (matches[2].str() == "b")
        x = 1;
      else if (matches[2].str() == "c")
        x = 2;
      else if (matches[2].str() == "d")
        x = 3;
      else if (matches[2].str() == "e")
        x = 4;
      else if (matches[2].str() == "f")
        x = 5;
      else if (matches[2].str() == "g")
        x = 6;
      else if (matches[2].str() == "h")
        x = 7;
      
      if (matches[5].str() == "a")
        dx = 0;
      else if (matches[5].str() == "b")
        dx = 1;
      else if (matches[5].str() == "c")
        dx = 2;
      else if (matches[5].str() == "d")
        dx = 3;
      else if (matches[5].str() == "e")
        dx = 4;
      else if (matches[5].str() == "f")
        dx = 5;
      else if (matches[5].str() == "g")
        dx = 6;
      else if (matches[5].str() == "h")
        dx = 7;
    }
    else
      throw 0;
  }
  catch (int x){
    cout << "Error " << x << endl;
    return 0;
  }
  return 1;
}


