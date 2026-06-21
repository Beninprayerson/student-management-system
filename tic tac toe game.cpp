#include <iostream>
using namespace std;

char board[3][3];

void resetBoard() {
    char num = '1';

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = num++;
        }
    }
}

void displayBoard() {

    cout << "\n";

    for(int i = 0; i < 3; i++) {

        cout << " ";

        for(int j = 0; j < 3; j++) {

            cout << board[i][j];

            if(j < 2)
                cout << " | ";
        }

        cout << "\n";

        if(i < 2)
            cout << "---|---|---\n";
    }
}

bool checkWin() {

    for(int i = 0; i < 3; i++) {

        if(board[i][0] == board[i][1] &&
           board[i][1] == board[i][2])
            return true;

        if(board[0][i] == board[1][i] &&
           board[1][i] == board[2][i])
            return true;
    }

    if(board[0][0] == board[1][1] &&
       board[1][1] == board[2][2])
        return true;

    if(board[0][2] == board[1][1] &&
       board[1][1] == board[2][0])
        return true;

    return false;
}

bool boardFull() {

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {

            if(board[i][j] != 'X' &&
               board[i][j] != 'O')
                return false;
        }
    }

    return true;
}

void makeMove(char player) {

    int choice;

    while(true) {

        cout << "\nPlayer "
             << player
             << " Enter Position: ";

        cin >> choice;

        choice--;

        int row = choice / 3;
        int col = choice % 3;

        if(choice >= 0 &&
           choice < 9 &&
           board[row][col] != 'X' &&
           board[row][col] != 'O') {

            board[row][col] = player;

            break;
        }

        cout << "Invalid Move\n";
    }
}

int main() {

    char again;

    do {

        resetBoard();

        char player = 'X';

        while(true) {

            displayBoard();

            makeMove(player);

            if(checkWin()) {

                displayBoard();

                cout << "\nPlayer "
                     << player
                     << " Wins!\n";

                break;
            }

            if(boardFull()) {

                displayBoard();

                cout << "\nMatch Draw\n";

                break;
            }

            if(player == 'X')
                player = 'O';
            else
                player = 'X';
        }

        cout << "\nPlay Again? (y/n): ";
        cin >> again;

    } while(again == 'y' || again == 'Y');

    return 0;
}