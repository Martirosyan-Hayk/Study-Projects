#ifndef _TICTACTOE_
#define _TICTACTOE_

#include <iostream>

namespace nonstd
{
    class TicTacToe
    {
    public:
        // constructors
        TicTacToe();                       // constructor the symbols is 'X' and 'Y'.
        TicTacToe(const char, const char); // constructor with parametrs. Parametrs is a symbols of pleyers.

    public:
        // deleted constructors and operators
        TicTacToe(const TicTacToe &) = delete;            // copy constructor
        TicTacToe(TicTacToe &&) = delete;                 // move constructor
        TicTacToe &operator=(const TicTacToe &) = delete; // copy operator
        TicTacToe &operator=(TicTacToe &) = delete;       // move operator

    public:
        // public functions
        void startGame();           // start the game
        void drowBord();            // drow the bord
        int setStepP1();            // set step of pleyer 1
        int setStepP2();            // set step of pleyer 2
        bool haveWinner(int, char); // return true if have a winner

    private:
        // members
        static const int _mSizeOfBord = 9; // size of bord
        char _mBord[_mSizeOfBord];         // bord
        char _mP1Figure;                   // figure of pleyer 1
        char _mP2Figure;                   // figure of pleyer 2

    private:
        // helper function
        char checkStep(); // check the step
        void init();      // init the bord
    };
}

#endif //_TICTACTOE_