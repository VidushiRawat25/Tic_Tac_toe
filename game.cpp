#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

static char a[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

int choice;
int row, column;
char turn = 'X';
bool draw = false;
void display(){
    cout << "CHOOSE A CELL NO FROM 1 TO 9 TO PLAY";
    cout<<endl;
    cout<<"PLAYER-X AND COMPUTER-0";
    cout << endl
         << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j <3; j++)
        {
            cout << a[i][j] << " "
                 << "|";
        }
        cout << endl
             << "---------" << endl;
    }
    cout << endl;
}
void playerturn()
{
    if (turn == 'X')
    {
        cout << "\n\tPlayer [X] turn : ";

        cin >> choice;

        if (choice == 1)
        {
            row = 0;
            column = 0;
        }
        else if (choice == 2)
        {
            row = 0;
            column = 1;
        }
        else if (choice == 3)
        {
            row = 0;
            column = 2;
        }
        else if (choice == 4)
        {
            row = 1;
            column = 0;
        }
        else if (choice == 5)
        {
            row = 1;
            column = 1;
        }
        else if (choice == 6)
        {
            row = 1;
            column = 2;
        }
        else if (choice == 7)
        {
            row = 2;
            column = 0;
        }
        else if (choice == 8)
        {
            row = 2;
            column = 1;
        }
        else if (choice == 9)
        {
            row = 2;
            column = 2;
        }
        else
            cout << "invalid choice";
    }

    else if (turn == 'O')
    {
        cout << "\n\t Computer [0] turn : ";
        srand(time(NULL));
        int m = (rand() % 9) + 1;
        if (m == 1)
        {
            row = 0;
            column = 0;
        }
        else if (m == 2)
        {
            row = 0;
            column = 1;
        }
        else if (m == 3)
        {
            row = 0;
            column = 2;
        }
        else if (m == 4)
        {
            row = 1;
            column = 0;
        }
        else if (m == 5)
        {
            row = 1;
            column = 1;
        }
        else if (m == 6)
        {
            row = 1;
            column = 2;
        }
        else if (m == 7)
        {
            row = 2;
            column = 0;
        }
        else if (m == 8)
        {
            row = 2;
            column = 1;
        }
        else if (m == 9)
        {
            row = 2;
            column = 2;
        }
        else
            cout << "invalid choice";
    }

if (turn == 'X' && a[row][column] != 'X' && a[row][column] != 'O')
{
    a[row][column] = 'X';
    turn = 'O';
}
else if (turn == 'O' && a[row][column] != 'X' && a[row][column] != 'O')
{
    a[row][column] = 'O';
    turn = 'X';
}
else
{

    // cout << "Box is already filled!n Please enter another choice!!\n\n";
    playerturn();
}

//  display();
    
}
bool gameover()
{

    for (int i = 0; i < 3; i++){
        if (a[i][0] == a[i][1] && a[i][0] == a[i][2] || a[0][i] == a[1][i] && a[0][i] == a[2][i])
            return false;
    }
    if (a[0][0] == a[1][1] && a[0][0] == a[2][2] || a[0][2] == a[1][1] && a[0][2] == a[2][0])
        return false;
else{
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] != 'X' && a[i][j] != 'O')
                return true;
        }
    }
    draw = true;
    return false;
}
}

int main()
{
    cout << "T I C K -- T A C -- T O E -- G A M E\t\t";
    cout << "\nFOR 1 PLAYER AND COMPUTER\n";
    while (gameover())
    {
        display();
        playerturn();
        gameover();
    }
    display();
    if (turn == 'X' && draw == false)
    {
        cout << "\n\nCongratulations!COMPUTER HAS WON THE GAME";
    }
    else if (turn == 'O' && draw == false)
    {
        cout << "\n\nCongratulations!PlAYER HAS WON THE GAME";
    }
    else
        cout << "\n\nGAME DRAW!!!\n\n";
}