#include <iostream>
#include <iomanip>
using namespace std;

void gameBoard(int board[]) {
    cout << endl;
    cout << endl;
    for (int i = 0; i <= 8; i++) {
        if (board[i] == 0) {
            //
            if (i + 1 == 3 || i + 1 == 6) {
                cout << setw(2) << 'O' << endl;
                cout << "------------" << endl;
            }
            else {
                cout << setw(2) << 'O';
                if (i != 8) {
                    cout << setw(2) << "|";
                }
            }
        }
        else {
            if (board[i] == 10) {
                if (i+1 == 3 || i+1 == 6) {
                    cout << setw(2) << 'X' << endl;
                    cout << "------------" << endl;
                }
                else {
                    cout << setw(2) << 'X';
                    if (i != 8) {
                        cout << setw(2) << "|";
                    }
                }
            }
            else {
                if (board[i] % 3 == 0 && board[i] != 9) {
                    cout << setw(2) << board[i] << endl;
                    cout << "------------" << endl;
                }
                else {
                    cout << setw(2) << board[i];
                    if (i != 8) {
                        cout << setw(2) << "|";
                    }
                }
            }
        }
    }
}
int player1Turn(string player1) {
    int place;
    cout << endl;
    cout << player1 << "'s turn: ";
    cin >> place;
    return(place);
}
int player2Turn(string player2) {
    int place;
    cout << endl;
    cout << player2 << "'s turn: ";
    cin >> place;
    return(place);
}
int win(int board[]) {
    int win = 1;
    // check horizontal win
    for (int i = 0; i <= 6; i += 3) {
        if (board[i] == board[i+1] && board[i+1] == board[i+2]) {
            win = board[i];
        }
    }
    // check vertical win
    for (int j = 0; j <= 2; j++) {
        if (board[j] == board[j + 3] && board[j + 3] == board[j + 6]) {
            win = board[j];
        }
    }
    // check for diagonal win
    if (board[0] == board[4] && board[4] == board[8]) {
        win = board[4];
    }
    else {
        if (board[2] == board[4] && board[4] == board[6]) {
            win = board[4];
        }
    }
    return win;
}

int main()
{
    string player1, player2;
    cout << "Player 1 Name: ";
    cin >> player1;
    cout << "Player 2 Name: ";
    cin >> player2;
    //establish game board
    char replay;
    int win1 = 0;
    int win2 = 0;
    int draw = 0;


    do {
        int board[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        bool flag = true;
        bool check = true;
        gameBoard(board);
        int place, turns = 1;
        do {
            // checks whos turn it is and asks for their place
            // flag: true = player1's turn, false = player2's turn
            // player1 = 10 (X), player 2 = 0 (O)
            // implement another do-while here to ensure the player inputs a valid game spot
            if (flag) {
                do {
                    place = player1Turn(player1);
                } while ((board[place - 1] == 0) || (board[place - 1] == 10));
                board[place - 1] = 10;
                flag = false;
            }
            else {
                do {
                    place = player2Turn(player2);
                } while ((board[place - 1] == 0) || (board[place - 1] == 10));
                board[place - 1] = 0;
                flag = true;
            }
            gameBoard(board);
            turns++;

        } while (win(board) == 1 && turns <= 9);

        // game is over, let's return the result
        if (win(board) == 10) {
            cout << endl;
            win1++;
            cout << player1 << " wins!" << endl;
        }
        else {
            if (win(board) == 0) {
                cout << endl;
                win2++;
                cout << player2 << " wins!" << endl;
            }
            else {
                cout << endl;
                draw++;
                cout << "Draw" << endl;
            }
        }
        // total games
        cout << endl;
        cout << "********************" << endl;
        cout << "*******Totals*******" << endl;
        cout << "********************" << endl;
        cout << player1 << ": " << win1 << endl;
        cout << player2 << ": " << win2 << endl;
        cout << "Draws: " << draw << endl;
        do {
            cout << "Play again? (y/n): ";
            cin >> replay;
        } while (replay != 'y' && replay != 'n');
    } while (replay == 'y');
    return 0;
}

