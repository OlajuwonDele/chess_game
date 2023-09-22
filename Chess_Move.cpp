#include "Chess_Move.h"
#include <iostream>
#include <string>

using namespace std;


Chess_Move::Chess_Move(){
  head = NULL;
  current = NULL;
  temporary = NULL;
}

void Chess_Move::addNode(string addData){
  Chess_Move *n = new Chess_Move;
  n->next = NULL;
  n->data = addData;

  if (addData == "v" || addData == "V")
    return;
  
  if (head != NULL){
    current = head;
    while (current->next != NULL){
      current = current->next;
    }
    current->next = n;
  }

  else {
    head = n;
  }
}

void Chess_Move::delList(){
  delete head;
}

void Chess_Move::printList(){
  current = head;
  int counter=1;
  if (head == NULL)
    cout << "No moves have been made in this game yet.\n";

  else if (current != NULL){
    cout << "The moves entered in this game have been: \n";
    while(current!=NULL){
      cout << counter++ << ". " << current->data << endl;
      current = current->next;
    }
  }
}

void Chess_Move::resetList(){
  current = head;
  head = NULL;
  
  while (current->next != NULL){
    current = current->next;
    temporary = current;
    delete temporary;
  }
  delete temporary;
  delete current->next;
  delete current;

}
