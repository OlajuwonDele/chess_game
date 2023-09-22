#pragma once
#include <string>

using namespace std;

class Chess_Piece{
//maybe if i add :public chess_board_square it fixes issue with address memory address of chess piece onto chess board
  public:
    virtual bool movePiece(int x, int y, int &dx, int &dy, int player); //each piece can move differently
    //virtual test()=0; // depening on user can they move and can 
    char colour;
    string type;
    int moveNum;
    
    

  private:

};
//Note: You may wish to consider using a chess_piece class to represent a chess piece, but it's probably too complex at this point. It probably requires the use of dynamic data structure techniques and pointers, e.g. a chess_board_square object might contain a pointer to a chess piece object, which would be NULL if the chess board square was empty, etc.)