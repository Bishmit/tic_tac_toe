#include <iostream>
using namespace std;

const int Size_of_board = 3;

char board[Size_of_board][Size_of_board];

void Set_board() {
    for (int row = 0; row < Size_of_board; row++) {
        for (int col = 0; col < Size_of_board; col++) {
            board[row][col] = ' ';
        }
    }
}

void display_board() {
    for (int row = 0; row < Size_of_board; row++) {
        for (int col = 0; col < Size_of_board; col++) {
            cout << board[row][col];
            if (col < Size_of_board - 1) {
                cout << "|";
            }
        }
        cout << endl;
        if (row < Size_of_board - 1) {
            cout << "-----" << endl;
        }
    }
}

void get_move(int& row, int& col) {
    cout << "Insert the value of row*column place where you want to insert your element: ";
    cin >> row >> col;
     row--; // initilixing base index to 0
     col--;
    if (row < 0 || row >= Size_of_board || col < 0 || col >= Size_of_board) {
        cout << "Invalid row or column number. Please try again." << endl;
        get_move(row, col);
    } else if (board[row][col] != ' ') {
        cout << "Box is already occupied. Please choose another." << endl;
        get_move(row, col);
    }
}

void update_board(int row, int col, char mark) {
    board[row][col] = mark;
}

	int check(char player_mark){
	// checking rows
	if( board[0][0]==player_mark && board[0][1]==player_mark && board[0][2]==player_mark )
		return 1;
	if( board[1][0]==player_mark && board[1][1]==player_mark && board[1][2]==player_mark )
		return 1;
	if( board[2][0]==player_mark && board[2][1]==player_mark && board[2][2]==player_mark )
		return 1;
		
	
	// checking cols
	if( board[0][0]==player_mark && board[1][0]==player_mark && board[2][0]==player_mark )
		return 1;
	if( board[0][1]==player_mark && board[1][1]==player_mark && board[2][1]==player_mark )
		return 1;
	if( board[0][2]==player_mark && board[1][2]==player_mark && board[2][2]==player_mark )
		return 1;
	
	// checking diagonals
	if( board[0][0]==player_mark && board[1][1]==player_mark && board[2][2]==player_mark )
		return 1;
	if( board[0][2]==player_mark && board[1][1]==player_mark && board[2][0]==player_mark )
		return 1;
		
	return 0;
}

int main() {
    Set_board();
    int winner = 0;
    char player_mark = 'X';
    while (1) {
        display_board();
        int row , col;
        get_move(row, col);
        update_board(row, col, player_mark);
        winner = check(player_mark);
        if (winner == 1) {
            display_board();
            cout << "Player " << (player_mark == 'X' ? 1 : 2) << " won the game!" << endl;
            break;
        } else if (winner == -1) {
            display_board();
            cout << "The game ended in a tie." << endl;
            break;
        }
        if (player_mark == 'X') {
            player_mark = 'O';
        } else {
            player_mark = 'X';
        }       
    }
    return 0;
}
