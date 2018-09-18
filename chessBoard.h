//chessBoard.h
//Aaron Nicanor
//anicanor

#ifndef CHESSBOARD_H_
#define CHESSBOARD_H_

#include<iostream>
#include<string>

using namespace std;

class chessBoard
{
        public:
                chessBoard();
                void fill(char);
                void win();
                void restart();
                bool isEmpty();
                bool isFull();
                //pieces
                bool pawn(char, int, int);
                bool knight(char, int, int);
                bool rook(char, int, int);
                bool bish(char, int, int);
                bool queen(char, int, int);
                bool king(char, int, int);

        private:
                char board[8][8];
                int x;
                int y;
                int gameCount;
};
#endif
