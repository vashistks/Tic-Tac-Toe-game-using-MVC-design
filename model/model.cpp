#include "model.h"
#include "../controller/TTTController.h"
#include <iostream>
#include <string>

gameplay::gameplay(){
  player_turn = 1;
}

gameplay::~gameplay(){

}

void gameplay::set_Marker(string marker,int playerNum){
  player_marker[playerNum-1] = marker;

}

int gameplay::getCurrentPlayer(){
  return player_turn;
}

void gameplay::switchturn(){
  if(player_turn==1){
    player_turn=2;
    }
  else
  {
    player_turn=1;
    }
  }

void gameplay::createBoard(){
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        board[i][j] = "-";
          }
       }
  }

void gameplay::clearBoard(){
    for (int i = 0; i < 3; i++)
      {for (int j = 0; j < 3; j++){
        board[i][j] = "-";
            }
          }
  }

bool gameplay::checkfree(int row,int col){
  if(board[row][col] == "-"){
    return true;
    }
  else{
    return false;
    }
  }

void gameplay::updateboard(int row,int col,int currentPlayer){
    string updatemarker = player_marker[currentPlayer-1];
    board[row][col] = updatemarker;
  }

string gameplay::getCurrentBoard()
  {
  string board_string ="";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
          board_string = board_string + board[i][j];
        }
      }
    return board_string;
  }

int gameplay::checkWin(int currentPlayer){
  string checkmarker = player_marker[currentPlayer-1];

  if(board[0][0]==board[0][1] && board[0][1]==board[0][2] && board[0][2]==checkmarker)
    {return currentPlayer;}
  else if(board[1][0]==board[1][1] && board[1][1]==board[1][2] && board[1][2]==checkmarker)
    {return currentPlayer;}
  else if(board[2][0]==board[2][1] && board[2][1]==board[2][2] && board[2][2]==checkmarker)
    {return currentPlayer;}
  else if(board[0][0]==board[1][0] && board[1][0]==board[2][0] && board[2][0]==checkmarker)
    {return currentPlayer;}
  else if(board[0][1]==board[1][1] && board[1][1]==board[2][1] && board[2][1]==checkmarker)
    {return currentPlayer;}
  else if(board[0][2]==board[1][2] && board[1][2]==board[2][2] && board[2][2]==checkmarker)
    {return currentPlayer;}
  else if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[2][2]==checkmarker)
    {return currentPlayer;}
  else if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[2][0]==checkmarker)
    {return currentPlayer;}
  else if(board[0][0]!="-" && board[0][1]!="-" && board[0][2]!="-" && board[1][0]!="-" && board[1][1]!="-" && board[1][2]!="-" && board[2][0]!="-" && board[2][1]!="-" && board[2][2]!="-" ){
  return 3;
    }
  else
    {
      return 0;
    }
}

void gameplay::display()
{
  cout<<"    col-0    |    1   |   2   "<<endl;
  cout<<"row-0:  "<<board[0][0]<<"    |    "<<board[0][1]<<"   |   "<<board[0][2]<<"   "<<endl;
  cout<<"----------------------------------  "<<endl;
  cout<<"row-1:  "<<board[1][0]<<"    |    "<<board[1][1]<<"   |   "<<board[1][2]<<"   "<<endl;
  cout<<"----------------------------------  "<<endl;
  cout<<"row-2:  "<<board[2][0]<<"    |    "<<board[2][1]<<"   |   "<<board[2][2]<<"   "<<endl;

}
