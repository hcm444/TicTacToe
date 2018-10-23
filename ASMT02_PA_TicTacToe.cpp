/****************************************************************
*
* File: [ASMT02_PA_TicTacToe.cpp]
* By: [Henry Meier]
* Date: [10/22/18]
*
* Description: [Cool TicTacToe game!]
*
****************************************************************/
#include <iostream> 
using namespace std;

bool isWon(char a, char board[][3]) { //winning is a boolian condition


int n = 3;
  /*

  reference
  012
  345
  678

  8 ways to win tic tac toe

  1   2   3   4   5
  ooo xxx xxx oxx xox
  xxx ooo xxx oxx xox
  xxx xxx ooo oxx xox

  6   7   8
  xxo oxx xxo
  xxo xox xox
  xxo xxo oxx 

  */

  for (int i = 0; i < 3; i++) { //sweep

    if (board[0][0] == board[1][1] && //diag
        board[1][1] == board[2][2] &&  
        board[0][0] != ' ') 
        return(true);
      
     if (board[0][2] == board[1][1] && //diag
        board[1][1] == board[2][0] && 
         board[0][2] != ' ') 
        return(true); 

     if (board[i][0] == board[i][1] && //row
            board[i][1] == board[i][2] &&  
            board[i][0] != ' ') 
            return (true); 

   if (board[0][i] == board[1][i] && //col
            board[1][i] == board[2][i] &&  
            board[0][i] != ' ') 
            return (true); 

    
    return false;

  }

}

bool isDraw(char board[][3]) {

  int z = 0; //define
  for (int i = 0; i < 3; i++) { //row

    for (int j = 0; j < 3; j++) { //column
      if (board[i][j] == 'X' || board[i][j] == 'O')
        z++;
    }
  }
  if (z != 9) //if z is not equal to 9
    return false; //not a draw
  if (!isWon('X', board) && !isWon('O', board)) //if X didn't win and O didn't
    //it's a draw, draw =true
    return true;
}

void displayBoard(char board[][3]) {

  cout << "-------------\n";
  for (int i = 0; i < 3; i++) { // vertical lines
    cout << "| "; //this took me a while to figure out
    //slash space
    for (int j = 0; j < 3; j++) { //horizontal
      cout << board[i][j] << " | "; //it just works
      //space slash space
    }

    cout << endl;
    cout << "-------------\n";

  }
}

void makeAMove(char board[][3], char a) {

  while (true) {
    cout << "Enter a row (0, 1, 2) for player " << a << "   : ";
    int x; // int for player row
    cin >> x;
    cout << "Enter a column (0, 1, 2) for player " << a << ": ";
    int y; // int for player column
    cin >> y;
    if (x < 0 || x > 2 || y < 0 || y > 2) {
      //if row less then 0 or more then 2
      //or
      //if column less then 0 or more then 2
      cout << "Invalid Move\n"; //invalid due to data 
    } else {
      if (board[x][y] != 'X' && board[x][y] != 'O') {

        board[x][y] = a; //available

        break;  //break herwe
      } else { //else

        cout << "Invalid Move\n"; //invalid due to occupation
      }
    }
  }
}

int main() {
  //
  //	PLEASE DO NOT CHANGE function main
  //
  char board[3][3] = {
    {
      ' ',
      ' ',
      ' '
    },
    {
      ' ',
      ' ',
      ' '
    },
    {
      ' ',
      ' ',
      ' '
    }
  };
	cout << "                                                               " << endl;
	cout << "|-------------------------------------------------------------|" << endl;
	cout << "|.-----. _            .-----.                .-----.          |" << endl;
	cout << "|`-. .-':_;           `-. .-'                `-. .-'          |" << endl;
	cout << "|  : :  .-. .--.  _____ : : .--.   .--.  _____ : : .--.  .--. |" << endl;
	cout << "|  : :  : :'  ..':_____:: :' .; ; '  ..':_____:: :' .; :' '_.'|" << endl;
	cout << "|  :_;  :_;`.__.'       :_;`.__,_;`.__.'       :_;`.__.'`.__.'|" << endl;
	cout << "|-------------------------------------------------------------|" << endl;
	cout << "                                                               " << endl;

  displayBoard(board);



  while (true) {
    // The first player makes a move
    makeAMove(board, 'X');
    displayBoard(board);
    if (isWon('X', board)) {
      cout << "X player won" << endl;
      exit(0);
    } else if (isDraw(board)) {
      cout << "No winner" << endl;
      exit(0);
    }

    // The second player makes a move
    makeAMove(board, 'O');
    displayBoard(board);

    if (isWon('O', board)) {
      cout << "O player won" << endl;
      exit(0);
    } else if (isDraw(board)) {
      cout << "No winner" << endl;
      exit(0);
    }
  }

  return 0;
}
