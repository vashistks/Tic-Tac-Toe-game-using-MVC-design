#ifndef _MODEL_H
#define _MODEL_H
 // _MODEL_H
#include <iostream>
#include <string>

using namespace std;

class gameplay{
  string player_marker[2];
  string board[3][3];
  int player_turn;
public:
  gameplay();
  ~gameplay();
  void set_Marker(string marker,int playerNum=1);
  int getCurrentPlayer();
  void switchturn();
  void createBoard();
  void clearBoard();
  bool checkfree(int row,int col);
  void updateboard(int row,int col,int currentPlayer);
  string getCurrentBoard();
  int checkWin(int currentPlayer);
  void display();
} ;

#endif
