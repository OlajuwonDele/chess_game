#pragma once
#include "Chess_Piece.h"

class Chess_Board_Square{
  //fix order of how i have operations of board etc

  public:
    Chess_Board_Square();
    ~Chess_Board_Square();

    void set();
    void print();
    int regexUpdate(string move, int &x, int &y, int &dx, int &dy);
    
    bool check(int player, int x, int y, int dx, int dy,Chess_Piece &newPiece);
    bool setPiece(Chess_Piece *piece);

    Chess_Board_Square *square[8+8*8];

    Chess_Piece chessP1[17];
    Chess_Piece chessP2[17];
    Chess_Piece empty;
    Chess_Piece piece;

};
//An object of this class must be able to hold a chess piece, and to be able to respond to messages indicating the presence or absence of a chess piece and provide its colour and type, etc