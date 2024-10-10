#include <iostream>
#include <limits>

using namespace std;

//all good
char space[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
char X = 'X', O = 'O';
int row;
int column;
int player = 1;
int endgame = 1;
int d_loop = 0;

void playerFun() {
    
    int num = 0;

    if (player == 1) {
        cout << "Player 1 please enter: ";
        cin >> num;
        cout << endl;
    }
    else if (player == 2) {
        cout << "Player 2 please enter: ";
        cin >> num;
        cout << endl;
    }

    if (num < 1 && num > 9) {
        num = 0;
        cout << "Invalid number!! Try again." << endl;
        playerFun();
    }

    switch (num) {

    case 1: row = 0, column = 0; break;
    case 2: row = 0, column = 1; break;
    case 3: row = 0, column = 2; break;
    case 4: row = 1, column = 0; break;
    case 5: row = 1, column = 1; break;
    case 6: row = 1, column = 2; break;
    case 7: row = 2, column = 0; break;
    case 8: row = 2, column = 1; break;
    case 9: row = 2, column = 2; break;
    default: cout << "Invalid number!" << endl; break;

    }

    if (player == 1 && space[row][column] != X && space[row][column] != O) {
        space[row][column] = X;
        player = 2;
    }
    else if (player == 2 && space[row][column] != X && space[row][column] != O) {
        space[row][column] = O;
        player = 1;
    }
    else {
        cout << "Try again!" << endl;
        num = 0;
        playerFun();
    }

}

// all good
void tictactoe() {

    cout << "     |     |    " << endl;
    cout << "  " << space[0][0] << "  |  " << space[0][1] << "  |  " << space[0][2] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |    " << endl;
    cout << "  " << space[1][0] << "  |  " << space[1][1] << "  |  " << space[1][2] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |    " << endl;
    cout << "  " << space[2][0] << "  |  " << space[2][1] << "  |  " << space[2][2] << "  " << endl;
    cout << "     |     |    " << endl << endl;
}

void check() {

        if (space[0][0] == X && space[0][1] == X && space[0][2] == X) {
            cout << "player 1 win!!" << endl;
            endgame = 0;
        }
        else if (space[0][0] == X && space[1][0] == X && space[2][0] == X) {
            cout << "player 1 win!!" << endl;
            endgame = 0;
        }
        else if (space[0][0] == X && space[1][1] == X && space[2][2] == X) {
            cout << "player 1 win!!" << endl;
            endgame = 0;
        }
        else if (space[0][1] == X && space[1][1] == X && space[2][1] == X) {
            cout << "player 1 win!!" << endl;
            endgame = 0;
        }
        else if (space[0][2] == X && space[1][1] == X && space[2][0] == X) {
            cout << "player 1 win!!" << endl;
            endgame = 0;
        }
        else if (space[0][2] == X && space[1][2] == X && space[2][2] == X) {
            cout << "player 1 win!!" << endl;
            endgame = 0;
        }
        else if (space[2][0] == X && space[2][1] == X && space[2][2] == X) {
            cout << "player 1 win!!" << endl;
            endgame = 0;
        }
        else if (space[1][0] == X && space[1][1] == X && space[1][2] == X) {
            cout << "player 1 win!!" << endl;
            endgame = 0;
        }
        else if (space[0][0] == O && space[0][1] == O && space[0][2] == O) {
            cout << "player 2 win!!" << endl;
            endgame = 0;
        }
        else if (space[0][0] == O && space[1][0] == O && space[2][0] == O) {
            cout << "player 2 win!!" << endl;
            endgame = 0;
        }
        else if (space[0][0] == O && space[1][1] == O && space[2][2] == O) {
            cout << "player 2 win!!" << endl;
            endgame = 0;
        }
        else if (space[0][1] == O && space[1][1] == O && space[2][1] == O) {
            cout << "player 2 win!!" << endl;
            endgame = 0;
        }
        else if (space[0][2] == O && space[1][1] == O && space[2][0] == O) {
            cout << "player 2 win!!" << endl;
            endgame = 0;
        }
        else if (space[0][2] == O && space[1][2] == O && space[2][2] == O) {
            cout << "player 2 win!!" << endl;
            endgame = 0;
        }
        else if (space[2][0] == O && space[2][1] == O && space[2][2] == O) {
            cout << "player 2 win!!" << endl;
            endgame = 0;
        }
        else if (space[1][0] == O && space[1][1] == O && space[1][2] == O) {
            cout << "player 2 win!!" << endl;
            endgame = 0;
        }
        else {
            d_loop = d_loop + 1;

            if (d_loop == 9) {
                cout << "Draw Game!!" << endl;
                endgame = 0;
            }
        }
}

void loop() {

    while (endgame != 0) {
        tictactoe();
        playerFun();
        check();
    }
}

int main()
{

    cout << "Welcome to our mini game TIC TAC TOE!!!" << endl << endl;
    cout << "Player 1 play as X, Player 2 play as O." << endl;
    cout << "Type numbers between 1 to 9 to place your mark." << endl << endl;

    loop();

    tictactoe();

}
