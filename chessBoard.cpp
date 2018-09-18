//chessBoard.cpp
//Aaron Nicanor
//anicanor
#include<iostream>
#include<string>

#include"chessBoard.h"

using namespace std;

//constructor, will initialize the board and save which game number this is
chessBoard::chessBoard()
{
        x = 0;
        y = 0;
        gameCount = 1;
        //This loop will fill board with empty elements
        for(int i = 0; i < 8; i++)
                for(int o = 0; o < 8; o++)
                        board[i][o] = '.'; 
}

//Fills the board with the inputed char
void chessBoard::fill(char input)
{
        //if you're at the last column, move onto a new row and start again
        if(x==7)
        {
                y++;
                x=0;
                board[y][x] = input;
        }
        else
        {
                board[y][x] = input;
                x++;
        }
}

//Checks to see who won
void chessBoard::win()
{
        bool blackW, whiteW;
        blackW = false;
        whiteW = false;
        
        //This will loop through the entire board array
        for(int i = 0; i <= 7; i++)
        {
                for(int o = 0; o <= 7; o++)
                {
                        //This will check which piece this is, and if it has the king in check
                        switch(board[i][o])
                        {
                                case 'a':
                                        if (pawn('a', o, i))
                                                whiteW = true;
                                        break;
                                case 'A':
                                        if (pawn('A', o, i))
                                                blackW = true;
                                        break;
                                case 'n':
                                        if (knight('n', o, i))
                                                whiteW = true;
                                        break;
                                case 'N':
                                        if (knight('N', o, i))
                                                blackW = true;
                                        break;
                                case 'b':
                                        if (bish('b', o, i))
                                                whiteW = true;
                                        break;
                                case 'B':
                                        if (bish('B', o, i))
                                                blackW = true;
                                        break;
                                case 'r':
                                        if (rook('r', o, i))
                                                whiteW = true;
                                        break;
                                case 'R':
                                        if (rook('R', o, i))
                                                blackW = true;
                                        break;
                                case 'q':
                                        if (queen('q', o, i))
                                                whiteW = true;
                                        break;
                                case 'Q':
                                        if (queen('Q', o, i))
                                                blackW = true;
                                        break;
                                case 'k':
                                        if (king('k', o, i))
                                                whiteW = true;
                                        break;
                                case 'K':
                                        if (king('k', o, i))
                                                blackW = true;
                                        break;
                        }
                }
        }

        //This control statement reports who is in check
        if (whiteW == true && blackW == false)
                cout << "Game #" << gameCount << ": black king is in check" << endl;
        else if (blackW == true && whiteW == false)
                cout << "Game #" << gameCount << ": white king is in check" << endl;
        else if (whiteW == true && blackW == true)
                cout << "Game #" << gameCount << ": both kings are in check" << endl;
        else
                cout << "Game #" << gameCount << ": no kings are in check" << endl;
}

//Will empty the chess board, set x and y to 0, and increase the game count
void chessBoard::restart()
{
        //This loop will replace chessboard with an empty element
        for(int i = 0; i < 8; i++)
                for(int o = 0; o < 8; o++)
                        board[i][o] == '.';
        //resets variables and increases game count
        x = 0;
        y = 0;
        gameCount++;
}

//Checks if the board is empty, filled with only .'s
bool chessBoard::isEmpty()
{
        for(int i = 0; i <= 7; i++)
                for(int o = 0; 0 <= 7; o++)
                        if(board[i][o] != '.')
                                return false;

        return true;
}

//checks if the board is full
bool chessBoard::isFull()
{
        if(x == 7 && y == 7)
                return true;
        return false;
}

bool chessBoard::pawn(char type, int x, int y)
{
        //checks the white piece. If it's at the top of the board, no point in checking
        if(type == 'a' && y != 7)
        {
                //looks for king
                if(x-1 > 0)
                        if(board[y+1][x-1] == 'K')
                                return true;
                if(x+1 < 7)
                        if(board[y+1][x+1] == 'K')
                                return true;
        }
        //checks the black piece. If it's at the bottom of the board, no point in checking
        else if(type == 'A' && y != 0)
        {
                //looks for king
                if(x-1 > 0)
                        if(board[y-1][x-1] == 'k')
                                return true;
                if(x+1 < 7)
                        if(board[y-1][x+1] == 'k')
                                return true;
        }
        return false;

}

bool chessBoard::knight(char type, int x, int y)
{
        //checks if the piece will move out of bounds.
        //checks if the diagonal up-right movements are in bounds
        if (x+2 < 7 && y-1 > 0)
        {
                if (type == 'n' && board[y-1][x+2] == 'K')
                        return true;
                if (type == 'N' && board[y-1][x+2] == 'k')
                        return true;
        }
        else if (x+1 < 7 && y-2 > 0)
        {
                if (type == 'n' && board[y-2][x+1] == 'K')
                        return true;
                if (type == 'N' && board[y-2][x+1] == 'k')
                        return true;
        }
        //checks if the diagonal down-right movements are in bounds
        else if (x+2 < 7 && y+1 > 0)
        {
                if (type == 'n' && board[y+1][x+2] == 'K')
                        return true;
                if (type == 'N' && board[y+1][x+2] == 'k')
                        return true;
        }
        else if (x+1 < 7 && y+2 > 0)
        {
                if (type == 'n' && board[y+2][x+1] == 'K')
                        return true;
                if (type == 'N' && board[y+2][x+1] == 'k')
                        return true;
        }
        //checks if the diagonal down-left movements are in bounds
        else if (x-2 < 7 && y+1 > 0)
        {
                if (type == 'n' && board[y+1][x-2] == 'K')
                        return true;
                if (type == 'N' && board[y+1][x-2] == 'k')
                        return true;
        }
        else if (x-1 < 7 && y+2 > 0)
        {
                if (type == 'n' && board[y+2][x-1] == 'K')
                        return true;
                if (type == 'N' && board[y+2][x-1] == 'k')
                        return true;
        }
        //checks if the diagonal up-left movements are in bounds
        else if (x-2 < 7 && y-1 > 0)
        {
                if (type == 'n' && board[y-1][x-2] == 'K')
                        return true;
                if (type == 'N' && board[y-1][x-2] == 'k')
                        return true;
        }
        else if (x-1 < 7 && y-2 > 0)
        {
                if (type == 'n' && board[y-2][x-1] == 'K')
                        return true;
                if (type == 'N' && board[y-2][x-1] == 'k')
                        return true;
        }
        return false;
}

bool chessBoard::rook(char type, int x, int y)
{
        //loop will check for king above the rook
        for (int i = y; i > 0; i--)
        {
                //if the space is not empty
                if (board[i][x] != '.')
                {
                        //if it's not a king, then stop moving in that direction
                        if (board[i][x] != 'k' || board[i][x] != 'K')
                                break;
                        //checks for king
                        else if (type == 'r' && board[i][x] == 'K')
                                return true;
                        else if (type == 'R' && board[i][x] == 'k')
                                return true;
                }
        }
        //loop will check for king below the rook
        for (int i = y; i < 7; i++)
        {
                //if the space is not empty
                if (board[i][x] != '.')
                {
                        //if it's not a king, then stop moving in that direction
                        if (board[i][x] != 'k' || board[i][x] != 'K')
                                break;
                        //checks for king
                        else if (type == 'r' && board[i][x] == 'K')
                                return true;
                        else if (type == 'R' && board[i][x] == 'k')
                                return true;
                }
        }
        //loop will check for king to the left of the rook
        for (int i = x; i > 0; i--)
        {
                //if the space is empty
                if (board[y][i] != '.')
                {
                        //if it's not a king, then stop mocing in that direction
                        if (board[y][i] != 'k' || board[y][i] != 'K')
                                break;
                        //checks for king
                        else if (type == 'r' && board[y][i] == 'K')
                                return true;
                        else if (type == 'R' && board[y][i] == 'k')
                                return true;
                }
        }
        //loop will check for the king to the right of the rook
        for (int i = x; i < 7; i++)
        {
                //if the space is not empty
                if (board[y][i] != '.')
                {
                        //if it's not a king, then stop moving in that direction
                        if (board[y][i] != 'k' || board[y][i] != 'K')
                                break;
                        //checks for king
                        else if (type == 'r' && board[y][i] == 'K')
                                return true;
                        else if (type == 'R' && board[y][i] == 'k')
                                return true;
                }
        }
        return false;
}

bool chessBoard::bish(char type, int x, int y)
{
        int i, o;
        i = x;
        o = y;
        //loop will look diagonal up-right for king
        while(i < 7 && o > 0)
        {
                //if it's not empty
                if (board[o][i] != '.')
                {
                        //if it's not king, then stop moving in that direction
                        if(board[o][i] != 'k' || board[o][i] != 'K')
                                break;
                        //check for king
                        else if (type == 'b' && board[o][i] == 'K')
                                return true;
                        else if (type == 'B' && board[o][i] == 'k')
                                return true;
                }
                //increase count
                i++;
                o--;
        }
        //resets variables for loop
        i = x;
        o = y;
        //loop will look diagonal down-right for king
        while(i > 0 && o > 0)
        {
                //if it's not empty
                if (board[o][i] != '.')
                {
                        //if it's not king, then stop moving in that direction
                        if(board[o][i] != 'k' || board[o][i] != 'K')
                                break;
                        //check for king
                        else if (type == 'b' && board[o][i] == 'K')
                                return true;
                        else if (type == 'B' && board[o][i] == 'k')
                                return true;
                }
                //increase count
                i--;
                o--;
        }
        //resets variables for loop
        i = x;
        o = y;
        //loop will look diagonal down-left for king
        while(i > 0 && o < 7)
        {
                //if it's not empty
                if (board[o][i] != '.')
                {
                        //if it's not king, then stop moving in that direction
                        if(board[o][i] != 'k' || board[o][i] != 'K')
                                break;
                        //check for king
                        else if (type == 'b' && board[o][i] == 'K')
                                return true;
                        else if (type == 'B' && board[o][i] == 'k')
                                return true;
                }
                //increase count
                i--;
                o++;
        }
        //resets variables for loop
        i = x;
        o = y;
        //loop will look diagonal up-left for king
        while(i < 7 && o < 7)
        {
                //if it's not empty
                if (board[o][i] != '.')
                {
                        //if it's not a king, then stop moving in that direction
                        if(board[o][i] != 'k' || board[o][i] != 'K')
                                break;
                        //check for king
                        else if (type == 'b' && board[o][i] == 'K')
                                return true;
                        else if (type == 'B' && board[o][i] == 'k')
                                return true;
                }
                //increase count
                i++;
                o++;
        }
        return false;
}

bool chessBoard::queen(char type, int x, int y)
{
        //checks for white piece
        if(type == 'q')
        {
                //looks at the vertical and horizontal spaces for king
                if (rook('r', x, y))
                        return true;
                //looks at the diagonal spaces for king
                if (bish('b', x, y))
                        return true;
        }
        //checks for black piece
        else if(type == 'Q')
        {
                //looks at the vertical and horizontal spaces for king
                if (rook('R', x, y))
                        return true;
                //looks at the diagonal spaces for king
                if (bish('B', x, y))
                        return true;
        }
        else
                return false;

}

bool chessBoard::king(char type, int x, int y)
{
        //will check white piece
        if(type == 'k')
        {
        //checks top right movements
        if (x < 7 && y > 0)
                if (board[y+1][x] == 'K' || board[y+1][x+1] == 'K' || board[y][x+1] == 'K')
                        return true;
        //checks bottom right movements
        if (x < 7 && y < 7)
                if (board[y-1][x+1] == 'K' || board[y-1][x+1] == 'K')
                        return true;
        //checks bottom left movements
        if (x > 0 && y < 7)
                if (board[y-1][x-1] == 'K' || board[y][x-1] == 'K')
                        return true;
        //checks top left movements
        if (x > 0 && y > 0)
                if (board[y+1][x-1] == 'K')
                        return true;
        }

        //will check black piece
        if(type == 'K')
        {
        //checks top right movements
        if (x < 7 && y > 0)
                if (board[y+1][x] == 'k' || board[y+1][x+1] == 'k' || board[y][x+1] == 'k')
                        return true;
        //checks bottom right movements
        if (x < 7 && y < 7)
                if (board[y-1][x+1] == 'k' || board[y-1][x+1] == 'k')
                        return true;
        //checks bottom left movements
        if (x > 0 && y < 7)
                if (board[y-1][x-1] == 'k' || board[y][x-1] == 'k')
                        return true;
        //checks top left movements
        if (x > 0 && y > 0)
                if (board[y+1][x-1] == 'k')
                        return true;
        }
        return false;
}
