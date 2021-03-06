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
  void createPlayer(string playerJsonObj);
  void startNewGame();
  bool setSelection(string playerJsonObj);
  string do_selection(string playerJsonObj);
  int determineWinner();
  string getGameDisplay();
  void displayboard();
  int currentPlayer();
  string currentPlayerName();
  string getAllSavedPlayers(string playerJsonObj);
} ;
#endif
