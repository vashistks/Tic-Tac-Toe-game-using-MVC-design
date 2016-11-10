#include <iostream>
#include <cstring>
#include "controller/TTTController.h"
#include <sstream>
#include <fstream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
using namespace std;

void run();
int main()
{
  cout << "content-type: text/html\n\n";

    stringstream post;
    post << cin.rdbuf();
    string incomingJsonObjectString = post.str();
    TTTController controller;
    std::size_t pos1 = incomingJsonObjectString.find("method");
    std::string namestr = incomingJsonObjectString.substr(pos1);
    std::string nameval = namestr.substr(9);
    std::size_t pos2 = nameval.find("\"");
    std::string methodname = nameval.substr(0,pos2);
    if(methodname == "addPlayer"){
controller.createPlayer(incomingJsonObjectString);
//string val = controller.checkValue();
//cout<<val;
}
else if(methodname == "setSelection"){
  string display = controller.do_selection(incomingJsonObjectString);
}
else if(methodname == "startGame"){
  controller.startNewGame();
string display = controller.getGameDisplay();
string jsondisplay = "{\"methodcalled\":\"startGame\",\"displayboard\":\""+display+"\",\"currentplayer\":\"1\"}";
cout<<jsondisplay;
  //winstatus = controller.determineWinner();
  //cout<<winstatus;
}
else if(methodname == "showplayers"){
  string players = controller.getAllSavedPlayers(incomingJsonObjectString);
}
// cout<<"Welcome to Tic Tac Tor Game"<<endl;
// cout<<"Below is the basic board of the game :"<<endl;
// cout<<"    r0,c0    |    r0,c1   |   r0,c2    "<<endl;
// cout<<" ----------------------------------  "<<endl;
// cout<<"    r1,c0    |   r1,c1    |   r1,c2    "<<endl;
// cout<<" ----------------------------------  "<<endl;
// cout<<"    r2,c0    |   r2,c1    |   r2,c2    "<<endl;
//
// cout<<"Get Ready for the Game!!"<<endl;
//run();
}
//
// void run(){
//   TTTController controller;
//   string player2_marker;
//   string player1_marker;
//   string player1_name;
//   string player2_name;
//   int row,col;
//   int winstatus;
//   std::cout<< "player 1 enter your symbol x/o"<<endl;
//   std::cin >> player1_marker;
//   std::cout<< "player 1 enter your name"<<endl;
//   std::cin >> player1_name;
//   controller.createPlayer(player1_name,player1_marker,1);
//   if (player1_marker == "x") {player2_marker = "o";}
//   else {player2_marker = "x";}
//   std::cout<<"player 2 marker is "<<player2_marker<<endl;
//   std::cout<< "player 2 enter your name"<<endl;
//   std::cin >> player2_name;
//   controller.createPlayer(player2_name,player2_marker,2);
//   controller.startNewGame();
//   winstatus = controller.determineWinner();
//   string c = controller.getGameDisplay();
//   while(winstatus==0&&winstatus!=3)
//   {
//     int curplay = controller.currentPlayer();
//     string curname = controller.currentPlayerName();
//     bool avail;
//     std::cout <<"player "<<curname<<" enter your row " << std::endl;
//     std::cin >> row;
//     std::cout <<"player "<<curname<<" enter your col " << std::endl;
//     std::cin >> col;
//     avail = controller.setSelection(row,col,curplay);
//     if(avail == true){cout<<"Valid entry, good job!"<<endl;}
//     winstatus = controller.determineWinner();
//     controller.displayboard();
//   }
//
//   if(winstatus==1){cout<<"Player 1 wins!! "<<endl;}
//   else if(winstatus==2){cout<<"Player 2 wins!! "<<endl;}
//   else if(winstatus==3){cout<<"Its a tie"<<endl;}
//   else {cout<<"No result "<<endl;}
//
//   cout<<"Do you want to play again?"<<endl;
//   char choice;
//   cin>>choice;
//   if(choice == 'y'){
//     run();
//   }
//   else{
//     cout<<"Thank you for playing the game!"<<endl;
//   }
// }
