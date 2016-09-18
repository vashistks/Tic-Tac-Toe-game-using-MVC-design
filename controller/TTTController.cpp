#include <string>
#include <iostream>
#include "TTTController.h"
#include "../model/model.h"

void TTTController::createPlayer(string marker,int playerNum)
 {
    g1.set_Marker(marker,playerNum);
 }
void TTTController::startNewGame()
  {
    g1.createBoard();
  }
  void TTTController::displayboard()
  {
      g1.display();
  }
bool TTTController::setSelection(int row,int col,int currentPlayer)
  {
    bool availability;
    if(row<3 && col <3){

      availability = g1.checkfree(row,col);

      if(availability == true){
        g1.updateboard(row,col,currentPlayer);
      }
      else{
        cout<<"invalid play, Loose your turn!"<<endl;
      }
    }
    return availability;
  }
int TTTController::determineWinner()
{
  int currentPlayer = g1.getCurrentPlayer();
  int winstatus = g1.checkWin(currentPlayer);
  g1.switchturn();
  return winstatus;
}

int TTTController::currentPlayer(){
  return g1.getCurrentPlayer();
}

string TTTController::getGameDisplay()
{
  displayboard();
  string displayboard = g1.getCurrentBoard();
  return displayboard;

}
