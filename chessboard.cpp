#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;


const int pawn = 100;
const int bishop = 305;
const int knight = 300;
const int rook = 500;
const int queen = 900;
const int king = 2000;



int board[8][8];



const int startup[8][8] = { rook, knight, bishop, queen, king, bishop, knight, rook, pawn, pawn,pawn,pawn,pawn,pawn,pawn, pawn, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, -pawn, -pawn, -pawn, -pawn, -pawn, -pawn, -pawn, -pawn, -rook, -knight, -bishop, -queen, -king, -bishop, -knight, -rook};



void setup (void) {
int i, j;
	for (i = 0; i < 8; i++){
		  for (j = 0; j < 8; j++){
			board[i][j] = startup[i][j]; //setup starting position
	  }
		}

}



void printb (void){
using namespace std; // this must be here in order to begin using strings.
int a, b;
string piece;
for (a = 7; a > -1; a--){  // we must iterate the ranks down from 7 to 0 otherwise the board will be upside down
cout << endl;
 for (b = 0; b < 8; b++){
 switch (board[a][b]){
 case 0:
 piece = "-";
 break;
 case 1:
 piece = "-";
 break;
 case pawn:
 piece = "P";
 break;
 case knight:
 piece = "N";
 break;
 case bishop:
 piece = "B";
 break;
 case rook:
 piece = "R";
 break;
 case queen:
 piece = "Q";
 break;
 case king:
 piece = "K";
 break;
 case -pawn:
 piece = "p";
 break;
 case -knight:
 piece = "n";
 break;
 case -bishop:
 piece = "b";
 break;
 case -rook:
 piece = "r";
 break;
 case -queen:
 piece = "q";
 break;
 case -king:
 piece = "k";
 break;
 }
  cout << " " << piece << " ";
 }
}

 cout << endl << endl;
}


// every program in win32 console must have a main


int main (void) {

cout << "Type 'new' to start a new game" << endl;
cout << "Type 'exit' to quit the game, type 'forfeit' to forfeit the game and  type 'print' to display the board." << endl << endl;

cout << "Please type your moves in 4 letter algebraic such as e2e4 in lower case only" << endl;
string passd; // this will be the string that contains info from the user
setup(); //we must set up the initial position
while (1){ // a while loop that always loops; except when a break; statement occurs

	getline (cin, passd );  //ask the user to input what he wants the app to do
		 if (passd.substr(0, 4) == "exit" || passd.substr(0, 5) == "abort" )   { //test //for quit or exit statements
		  break;
		 }
		 if (passd.substr(0, 5) == "print")   { // display the board
		  printb();
		 }
		 if (passd.substr(0, 3) == "new")   { // ask for a new game
		  setup();
		 }
		 if (passd.substr(0, 1) >= "a" && passd.substr(0, 1) <= "h" && passd.substr(1, 1) >= "1" && passd.substr(1, 1) <= "8" && passd.substr(2, 1) >= "a" && passd.substr(2, 1) <= "h" && passd.substr(3, 1) >= "1" && passd.substr(3, 1) <= "8")   { // this statement makes sure both squares are on the chess board when executing //a move
		  // execute move
		  // then display new board position

		  int a, b, c, d;


		  a = passd[0] - 'a';
		  b = passd[1] - '1';
		  c = passd[2] - 'a';
		  d = passd[3] - '1';

//executes the move if its on the board!
		  board[d][c] = board[b][a];
		  board[b][a] = 0;

		  printb(); //prints out to the screen the updated position after moving the pieces
		 }
		}
}
 
