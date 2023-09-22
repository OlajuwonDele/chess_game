#include "Chess_Piece.h"
#include <iostream>
#include <cmath>

using namespace std;

bool Chess_Piece::movePiece(int x, int y, int &dx, int &dy, int player) {

    if (type == " K  " || type == "[k] "){ 
      try{
        if(abs(dy-y) > 1 || abs(dx-x) > 1)
          throw 1;
      }
      catch (int j){
        cout << "Error " <<  j << ". King cannot make this move\n";
        return false;
      }
      return true;
    }
    else if (type == " Q  " || type == "[q] "){
      try{
        if (abs(dy-y)!= abs(dx-x) && abs(dy-y)>0 && abs(dx-x)!=0)
          throw 1;
        else if (abs(dy-y)!= abs(dx-x) && abs(dx-x)>0 && abs(dy-y)!=0)
          throw 2;
      }
      catch (int j){
          cout << "Error " <<  j << ". Queen cannot make this move\n";
          return false;
      }
      return true;
    }
    else if (type == " R  " || type == "[r] "){  
      try{
        if (abs(dy-y)>0 && abs(dx-x)!=0)
          throw 1;
        else if (abs(dx-x)>0 && abs(dy-y)!=0)
          throw 2;
      }
      catch (int j){
        cout << "Error " <<  j << ". Rook cannot make this move\n";
        return false;
      }
      return true;
      }
    else if (type == " N  " || type == "[n] "){
      try{
          if((abs(dy-y) !=2 && abs(dx-x) !=1 ) && (abs(dy-y) !=1 && abs(dx-x) !=2))
            throw 1;
        }
        catch (int j){
          cout << "Error " <<  j << ". Knight cannot be moved to this position\n.";
          return false;
        }
      return true;
      }
    else if (type == " B  " || type == "[b] ") {
      try{
      if (abs(dy-y)!= abs(dx-x))
        throw 1;
      }
      catch (int j){
        cout << "Error " <<  j <<  ". Bishop cannot make this move\n";
        return false;
      }
      return true;
      }
      else if (type == "[p] " || type == " P  "){
        if (player == 1) {
          if (moveNum == 0){
            try{
              if (dy-y < 0)
                throw 1;
              else if(dy-y !=0 && dx-x !=0)
                throw 2;
              else if(dy-y !=1 && dx-x !=0)
                throw 3;
            }
            catch (int j){
              cout << "Error " <<  j << ". Pawn cannot make this move\n";
              return false;
            }
          }
          try{
            if (dy-y < 0)
              throw 1;
            else if(dy-y !=0 && dx-x !=0)
              throw 2;
            else if(dy-y !=2 && dx-x !=0)
              throw 3;
          }
          catch (int j){
            cout << "Error " <<  j << ". Pawn cannot make this move\n";
            return false;
          }
        }
        else if (player == 2){
          try{
            if (dy-y != 1 && abs(dx-x) != 1){
            cout << "y" << dy-y << endl;
            cout << "x" << dx-x << endl;
            cout << "CHECK" << endl;
            throw 5;
            }
          }
          catch (int x){
             cout << "Error " <<  x << ". Pawn cannot make this move\n";
            return false;
          }
        }
        else if (player == 3){
          try{
            if (y-dy != 1 && abs(dx-x) != 1)
              throw 5;
          }
          catch (int x){
             cout << "Error " <<  x << ". Pawn cannot make this move\n";
            return false;
          }
        }
        else if (player == -1){
          if (moveNum == 0){
            try{
              if (y-dy < 0)
                throw 10;
              else if(y-dy !=0 && dx-x !=0)
                throw 20;
              else if(y-dy !=1 && dx-x !=0)
                throw 30;
            }
            catch (int j){
              cout << "Error " <<  j << ". Pawn cannot make this move\n";
              return false;
            }
          }
          try{
              if (y-dy < 0)
                throw 100;
              else if(y-dy !=0 && dx-x !=0)
                throw 200;
              else if(y-dy !=2 && dx-x !=0)
                throw 300;
            }
          catch (int j){
              cout << "Error " <<  j <<  ". Pawn cannot make this move\n";
              return false;
          }
        }
        return true;
        }
  return true;
  
}