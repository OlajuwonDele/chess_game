#include <iostream>
#include "Application.h"
#include "Chess_Board_Square.h"
#include "Chess_Piece.h"

using namespace std;


int main() {
  char choice;
  Application myapp;
  cout << "Choose (1) to use the run method or (2) to use the test method\n";
  cin >> choice;
  if(choice == '1')
    myapp.run();
  else if (choice == '2')
    myapp.test();
  return 0;
}
