//Aaron Nicanor
//checkKing.cpp
//anicanor
#include<iostream>
#include<string>

#include"chessBoard.h"

using namespace std;



int main()
{
        //declares variables to get users input
        chessBoard board;
        string input;
        string save;
        //loop will save all of the user's inputs into the "save" string
        while(getline(cin, input))
                save += input;

        //looks at each letter of the string
        for(char& c : save)
        {
                //checks if the board is full
                if (board.isFull())
                {
                        //if the board is empty, breaks out of loop
                        if (board.isEmpty())
                                break;
                        else
                        {
                                //reports win and resets board
                                board.win();
                                board.restart();
                        }
                }else
                {
                        //fills board and increases the counter
                        board.fill(c);
                }
        }
        return 0;
}
//I'm just going to scream "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
