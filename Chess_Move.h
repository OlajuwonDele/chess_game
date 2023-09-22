#pragma once
#include <string>
using namespace std;
class Chess_Move {
  public:
    Chess_Move();
    
    void addNode(string addData);
    void delList();
    void printList();
    void resetList();
  
  private:
    string data;
    
    Chess_Move *next;
    Chess_Move *head;
    Chess_Move *current;
    Chess_Move *temporary;

};