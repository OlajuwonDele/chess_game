#pragma once
#include "Chess_Move.h"
class Application {

  public:
    void test();
    void run();

  private:
    Chess_Move moveList;

};
  //The user should be able to create a new chess board with a full set of chess pieces, white and black, in the standard positions. In addition, the user should be able to print out all the pieces and their positions on request and to move a piece from one position to another if permissible.  Finally, it must be possible to reinitialise a board (or alternatively, to simply delete it) and start over.