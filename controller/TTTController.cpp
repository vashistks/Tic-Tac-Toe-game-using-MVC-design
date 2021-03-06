#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "TTTController.h"
#include "../model/model.h"
#include "../rapidjson/document.h"
#include "../rapidjson/writer.h"
#include "../rapidjson/stringbuffer.h"

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
      string boardstring = g1.getCurrentBoard();
    int k=0;
      for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
      board[i][j] = boardstring[k];
      k++;
        }
      }
  }

  string TTTController::getAllSavedPlayers(string playerJsonObj){
  std::size_t pos1 = playerJsonObj.find("player1_name");
  string playerstr1 = playerJsonObj.substr(pos1);
  string player1 = playerstr1.substr(14,1);
  std::size_t pos2 = playerJsonObj.find("player2_name");
  string playerstr2 = playerJsonObj.substr(pos2);
  string player2 = playerstr2.substr(14,1);
  std::size_t mpos1 = playerJsonObj.find("player1_marker");
  string markerstr1 = playerJsonObj.substr(mpos1);
  string marker1 = markerstr1.substr(16,1);
  std::size_t mpos2 = playerJsonObj.find("player2_marker");
  string markerstr2 = playerJsonObj.substr(mpos2);
  string marker2 = markerstr2.substr(16,1);
  std::string getplayers = "{\"methodcalled\":\"showplayers\",\"player1\":\""+player1+"\",\"marker1\":\""+marker1+"\",\"player2\":\""+player2+"\",\"marker2\":\""+marker2+"\"}";
  cout<<getplayers;
  return getplayers;
}

string TTTController::do_selection(string playerJsonObj)
{
  TTTController t;
  bool avail = t.setSelection(playerJsonObj);
  ostringstream ss;
  ss << boolalpha << avail;
  std::string avail1 = ss.str();
  string display = t.getGameDisplay();
  string curplayer = g1.getCurrentPlayerJson(playerJsonObj);
  string nextplayer = g1.switchturn(curplayer);
  string currentmarker = g1.getCurrentmarker(playerJsonObj);
  string winstatus = g1.checkWin(playerJsonObj);
  //cout<<winstatus;
  // stringstream ss1;
  // ss1 << winstatusint;
  // string winstatus = ss1.str();
  std::string tempavail = "{\"methodcalled\":\"setSelection\",\"bool\": "+avail1+",\"displayselecteddata\": \""+display+"\",\"currentplayer\" : \""+nextplayer+"\",\"winstatus\":\""+winstatus+"\"}";
  cout<<tempavail;
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
    string cp = g1.getCurrentPlayerJson(playerJsonObj);
    int currentPlayer = 1; //TO BE MODIFIED
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
// int TTTController::determineWinner()
// {
//   //int currentPlayer = g1.getCurrentPlayer();
//
//   //int winstatus = g1.checkWin(currentPlayer);
// return winstatus;
// }

int TTTController::currentPlayer(){
  return g1.getCurrentPlayer();
}

string TTTController::currentPlayerName(){
  return g1.getCurrentPlayerName();
}

string TTTController::getGameDisplay()
{
    string boardstring = g1.getCurrentBoard();
  int k=0;
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){

    k++;
      }
    }
return boardstring;
}
