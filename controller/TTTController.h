#ifndef _TTTCONTROLLER_H
#define _TTTCONTROLLER_H
#include <iostream>
#include <cstring>
#include "../model/model.h"
using namespace std;

class gameplay;

class TTTController{
  string player[2];
  gameplay g1;
public:
  void createPlayer(string marker,int playerNum=1);
  void startNewGame();
  bool setSelection(int row,int col,int currentPlayer);
  int determineWinner();
  string getGameDisplay();
  void displayboard();
  int currentPlayer();


} ;
#endif
