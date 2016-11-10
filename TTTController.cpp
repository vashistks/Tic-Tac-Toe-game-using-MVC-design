#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "TTTController.h"
#include "../model/model.h"

void TTTController::createPlayer(string playerJsonObj)
 {
   ofstream file;
   file.open("op.txt");
   std::size_t pos = playerJsonObj.find("marker");
   string markerstr = playerJsonObj.substr(pos);
   std::string marker = markerstr.substr(9,1);
   file<<marker;
   std::size_t pos1 = playerJsonObj.find("name");
   std::string namestr = playerJsonObj.substr(pos1);
   std::string nameval = namestr.substr(7);
   std::size_t pos2 = nameval.find("\"");
   std::string name = nameval.substr(0,pos2);
   file<<name;
   file.close();
   int playerNum = 1;
    g1.set_Marker(name,marker,playerNum);

 }
void TTTController::startNewGame()
  {
    g1.createBoard();
  }

void TTTController::displayboard()
  {
    string board[3][3];
    //cout<<"display called"<<endl;
      //g1.display();
      string boardstring = g1.getCurrentBoard();
    int k=0;
      for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
      board[i][j] = boardstring[k];
      k++;
        }
      }
  //       cout<<"    col-0    |    1   |   2   "<<endl;
  // cout<<"row-0:  "<<board[0][0]<<"    |    "<<board[0][1]<<"   |   "<<board[0][2]<<"   "<<endl;
  // cout<<"----------------------------------  "<<endl;
  // cout<<"row-1:  "<<board[1][0]<<"    |    "<<board[1][1]<<"   |   "<<board[1][2]<<"   "<<endl;
  // cout<<"----------------------------------  "<<endl;
  // cout<<"row-2:  "<<board[2][0]<<"    |    "<<board[2][1]<<"   |   "<<board[2][2]<<"   "<<endl;

  }

string TTTController::do_selection(string playerJsonObj)
{
  TTTController t;
  bool avail = t.setSelection(playerJsonObj);
  ostringstream ss;
  ss << boolalpha << avail;
  std::string avail1 = ss.str();
  string display = t.getGameDisplay();
return display;
}

bool TTTController::setSelection(string playerJsonObj)
  {
    std::size_t pos1 = playerJsonObj.find("row");
    string markerstr1 = playerJsonObj.substr(pos1);
    string rowstr = markerstr1.substr(5,1);
    std::size_t pos2 = playerJsonObj.find("col");
    string markerstr2 = playerJsonObj.substr(pos2);
    string colstr = markerstr2.substr(5,1);
    istringstream buffer1(rowstr);
    int row;
    buffer1 >> row;
    istringstream buffer2(colstr);
    int col;
    buffer2 >> col;
    std::size_t strpos1 = playerJsonObj.find("boardstring");
    std::string stringpos1 = playerJsonObj.substr(strpos1);
    std::string strval = stringpos1.substr(14);
    std::size_t strpos2 = strval.find("\"");
    std::string jsonboardstring = strval.substr(0,strpos2);
    g1.sendString(jsonboardstring);
    int currentPlayer = 1;
    //cout<<row<<":"<<col;
    bool availability;

    if(row<3 && col <3){
      availability = g1.checkfree(row,col);
      if(availability == true){
        g1.updateboard(row,col,currentPlayer);
      }
      else{
        //cout<<"invalid play, Loose your turn!"<<endl;
      }
    }
    return availability;
  }
int TTTController::determineWinner()
{
  int currentPlayer = g1.getCurrentPlayer();
//  cout<<"ended"<<currentPlayer<<endl;
  int winstatus = g1.checkWin(currentPlayer);
  g1.switchturn();
  return winstatus;
}

int TTTController::currentPlayer(){
  return g1.getCurrentPlayer();
}

string TTTController::currentPlayerName(){
  return g1.getCurrentPlayerName();
}

string TTTController::getGameDisplay()
{
  //string board[3][3];
//  cout<<"display called"<<endl;
    //g1.display();
    string boardstring = g1.getCurrentBoard();
    cout<<boardstring<<endl;
  int k=0;
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
    //board[i][j] = boardstring[k];
    //cout<<board[i][j];
    k++;
      }
    }
//       cout<<"    col-0    |    1   |   2   "<<endl;
// cout<<"row-0:  "<<board[0][0]<<"    |    "<<board[0][1]<<"   |   "<<board[0][2]<<"   "<<endl;
// cout<<"----------------------------------  "<<endl;
// cout<<"row-1:  "<<board[1][0]<<"    |    "<<board[1][1]<<"   |   "<<board[1][2]<<"   "<<endl;
// cout<<"----------------------------------  "<<endl;
// cout<<"row-2:  "<<board[2][0]<<"    |    "<<board[2][1]<<"   |   "<<board[2][2]<<"   "<<endl;

return boardstring;
}
