#ifndef _MODEL_H
#define _MODEL_H
 // _MODEL_H
#include <iostream>
#include <string>

using namespace std;

class gameplay{
  string player_marker[2];
  string player_name[2];
  string board[3][3];
  int player_turn;
public:
  gameplay();
  ~gameplay();
  void set_Marker(string name,string marker,int playerNum=1);
  int getCurrentPlayer();
  string switchturn(string player);
  void createBoard();
  void clearBoard();
  bool checkfree(int row,int col);
  void updateboard(int row,int col,int currentPlayer);
  string getCurrentBoard();
  string checkWin(string playerJsonObj);
  string getCurrentPlayerName();
  void sendString(string jsonboardstring);
  string getCurrentPlayerJson(string jsonboardstring);
  string getCurrentmarker(string playerJsonObj);
} ;

#endif
