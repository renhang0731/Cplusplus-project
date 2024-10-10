#include <iostream>

using namespace std;

// {char space[][]} : to mark up the position of the X and O, there are 9 spaces in Tik Tac Toe so there are [3][3] of array which 3*3.
// {char X = 'X', O = 'O'} : to define the marks for player 1 and player 2.
// {int row, column} : define the space [][], which is [row][column] to implement the function to place the mark.
// {int player = 1} : to set default starter player is player 1.
// {int endgame = 1} : to check whether the game is end or not.
// {int d_loop = 0} : to check the situation of draw, the loop will end the game when the players placed 9 marks.

char space[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
char X = 'X', O = 'O';
int row, column;
int player = 1;
int endgame = 1;
int d_loop = 0;

// Function of players, including player place mark, player switch, apply mark, and error message.
void playerFun() {

    int num;

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

// Display board of the game, player can place their mark in the display board.
void tictactoe() {

    cout << "     |     |    " << endl;
    cout << "  " << space[0][0] << "  |  " << space[0][1] << "  |  " << space[0][2] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |    " << endl;
    cout << "  " << space[1][0] << "  |  " << space[1][1] << "  |  " << space[1][2] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |    " << endl;
    cout << "  " << space[2][0] << "  |  " << space[2][1] << "  |  " << space[2][2] << "  " << endl;
    cout << "     |     |    " << endl <<endl;
}

// check the game is end or not, player 1 win, player 2 win or draw match. Basically hardcode all the possibility of the game.
void check() {

    if (space[0][0] == X && space[0][1] == X && space[0][2] == X) {
        cout << "player 1 WIN!!" << endl;
        endgame = 0;
    }
    else if (space[0][0] == X && space[1][0] == X && space[2][0] == X) {
        cout << "player 1 WIN!!" << endl;
        endgame = 0;
    }
    else if (space[0][0] == X && space[1][1] == X && space[2][2] == X) {
        cout << "player 1 WIN!!" << endl;
        endgame = 0;
    }
    else if (space[0][1] == X && space[1][1] == X && space[2][1] == X) {
        cout << "player 1 WIN!!" << endl;
        endgame = 0;
    }
    else if (space[0][2] == X && space[1][1] == X && space[2][0] == X) {
        cout << "player 1 WIN!!" << endl;
        endgame = 0;
    }
    else if (space[0][2] == X && space[1][2] == X && space[2][2] == X) {
        cout << "player 1 WIN!!" << endl;
        endgame = 0;
    }
    else if (space[2][0] == X && space[2][1] == X && space[2][2] == X) {
        cout << "player 1 WIN!!" << endl;
        endgame = 0;
    }
    else if (space[1][0] == X && space[1][1] == X && space[1][2] == X) {
        cout << "player 1 WIN!!" << endl;
        endgame = 0;
    }
    else if (space[0][0] == O && space[0][1] == O && space[0][2] == O) {
        cout << "player 2 WIN!!" << endl;
        endgame = 0;
    }
    else if (space[0][0] == O && space[1][0] == O && space[2][0] == O) {
        cout << "player 2 WIN!!" << endl;
        endgame = 0;
    }
    else if (space[0][0] == O && space[1][1] == O && space[2][2] == O) {
        cout << "player 2 WIN!!" << endl;
        endgame = 0;
    }
    else if (space[0][1] == O && space[1][1] == O && space[2][1] == O) {
        cout << "player 2 WIN!!" << endl;
        endgame = 0;
    }
    else if (space[0][2] == O && space[1][1] == O && space[2][0] == O) {
        cout << "player 2 WIN!!" << endl;
        endgame = 0;
    }
    else if (space[0][2] == O && space[1][2] == O && space[2][2] == O) {
        cout << "player 2 WIN!!" << endl;
        endgame = 0;
    }
    else if (space[2][0] == O && space[2][1] == O && space[2][2] == O) {
        cout << "player 2 WIN!!" << endl;
        endgame = 0;
    }
    else if (space[1][0] == O && space[1][1] == O && space[1][2] == O) {
        cout << "player 2 WIN!!" << endl;
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
