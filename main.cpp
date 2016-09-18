#include <iostream>
#include <cstring>
#include "controller/TTTController.h"
using namespace std;

void run();
int main()
{
cout<<"Welcome to Tic Tac Tor Game"<<endl;
cout<<"Below is the basic board of the game :"<<endl;
cout<<"    r0,c0    |    r0,c1   |   r0,c2    "<<endl;
cout<<" ----------------------------------  "<<endl;
cout<<"    r1,c0    |   r1,c1    |   r1,c2    "<<endl;
cout<<" ----------------------------------  "<<endl;
cout<<"    r2,c0    |   r2,c1    |   r2,c2    "<<endl;

cout<<"Get Ready for the Game!!"<<endl;
run();
}

void run(){
  TTTController controller;
  string player2_marker;
  string player1_marker;
  int row,col;
  int winstatus;
  std::cout<< "player 1 enter your symbol x/o"<<endl;
  std::cin >> player1_marker;
  controller.createPlayer(player1_marker,1);
  if (player1_marker == "x") {player2_marker = "o";}
  else {player2_marker = "x";}
  std::cout<<"player 2 marker is "<<player2_marker<<endl;
  controller.createPlayer(player2_marker,2);
  controller.startNewGame();
  winstatus = controller.determineWinner();
string c = controller.getGameDisplay();
  while(winstatus==0&&winstatus!=3)
  {
    int curplay = controller.currentPlayer();
    bool avail;
    std::cout <<"player "<<curplay<<" enter your row " << std::endl;
    std::cin >> row;
    std::cout <<"player "<<curplay<<" enter your col " << std::endl;
    std::cin >> col;
    avail = controller.setSelection(row,col,curplay);
    if(avail == true){cout<<"Valid entry, good job!"<<endl;}
    winstatus = controller.determineWinner();
    controller.displayboard();
  }

  if(winstatus==1){cout<<"Player 1 wins!! "<<endl;}
  else if(winstatus==2){cout<<"Player 2 wins!! "<<endl;}
  else if(winstatus==3){cout<<"Its a tie"<<endl;}
  else {cout<<"No result "<<endl;}

  cout<<"Do you want to play again?"<<endl;
  char choice;
  cin>>choice;
  if(choice == 'y'){
    run();
  }
  else{
    cout<<"Thank you for playing the game!"<<endl;
  }
}
