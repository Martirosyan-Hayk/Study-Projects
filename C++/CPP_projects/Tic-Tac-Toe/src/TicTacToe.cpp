#include <iostream>
#include "TicTacToe.h"

nonstd::TicTacToe::TicTacToe() 
                    : _mP1Figure{'X'}, _mP2Figure{'O'}   // constructor the symbols is 'X' and 'Y'.
{
    init();
}
nonstd::TicTacToe::TicTacToe(const char p1Figure, const char p2Figure) 
                                : _mP1Figure{p1Figure}, _mP2Figure{p2Figure} // constructor with parametrs. Parametrs is a symbols of pleyers.
{
    init();
}
void nonstd::TicTacToe::startGame() // start the game
{
    int i = 0;
    bool stepOf = true;
    while (i < _mSizeOfBord)
    {
        drowBord();
        char step;
        if (!(i % 2))
        {
            std::cout << "Pleyer 1 '" << _mP1Figure << "' >> ";
            int step = setStepP1();
            if (haveWinner(step, _mP1Figure))
            {
                std::cout << "__________ Winner is pleyer 1 '" << _mP1Figure << "' __________" << std::endl << std::endl;
                return;
            }
        }
        else
        {
            std::cout << "Pleyer 2 '" << _mP2Figure << "' >> ";
            int step = setStepP2();
            if (haveWinner(step, _mP2Figure))
            {
                std::cout << "__________ Winner is pleyer 2 '" << _mP2Figure << "' __________" << std::endl << std::endl;
                return;
            }
        }
        ++i;
    }
}
void nonstd::TicTacToe::drowBord() // drow the bord
{
    system("clear");
    std::cout << std::endl
              << "  " << _mBord[0] << "  |  " << _mBord[1] << "  |  " << _mBord[2] << std::endl;
    std::cout << "-----------------" << std::endl;
    std::cout << "  " << _mBord[3] << "  |  " << _mBord[4] << "  |  " << _mBord[5] << std::endl;
    std::cout << "-----------------" << std::endl;
    std::cout << "  " << _mBord[6] << "  |  " << _mBord[7] << "  |  " << _mBord[8] << std::endl
              << std::endl;
}
int nonstd::TicTacToe::setStepP1() // set step of pleyer 1
{
    char step = checkStep();
    int numberOfField = step - '0';
    _mBord[numberOfField - 1] = _mP1Figure;

    drowBord();
    return numberOfField - 1;
}
int nonstd::TicTacToe::setStepP2() // set step of pleyer 2
{
    char step = checkStep();
    int numberOfField = step - '0';
    _mBord[numberOfField - 1] = _mP2Figure;

    drowBord();
    return numberOfField - 1;
}
bool nonstd::TicTacToe::haveWinner(int step, char figure) // return true if have a winner
{
    switch (step)
    {
    case 0:
        if (_mBord[0] == figure && _mBord[1] == figure && _mBord[2] == figure)
            return true;
        else if (_mBord[0] == figure && _mBord[4] == figure && _mBord[8] == figure)
            return true;
        else if (_mBord[0] == figure && _mBord[3] == figure && _mBord[6] == figure)
            return true;
        break;
    case 1:
        if (_mBord[0] == figure && _mBord[1] == figure && _mBord[2] == figure)
            return true;
        else if (_mBord[1] == figure && _mBord[4] == figure && _mBord[7] == figure)
            return true;
        break;
    case 2:
        if (_mBord[0] == figure && _mBord[1] == figure && _mBord[2] == figure)
            return true;
        else if (_mBord[2] == figure && _mBord[4] == figure && _mBord[6] == figure)
            return true;
        else if (_mBord[2] == figure && _mBord[5] == figure && _mBord[8] == figure)
            return true;
        break;
    case 3:
        if (_mBord[0] == figure && _mBord[3] == figure && _mBord[6] == figure)
            return true;
        else if (_mBord[3] == figure && _mBord[4] == figure && _mBord[5] == figure)
            return true;
        break;
    case 4:
        if (_mBord[1] == figure && _mBord[4] == figure && _mBord[7] == figure)
            return true;
        else if (_mBord[3] == figure && _mBord[4] == figure && _mBord[5] == figure)
            return true;
        else if (_mBord[0] == figure && _mBord[4] == figure && _mBord[8] == figure)
            return true;
        else if (_mBord[2] == figure && _mBord[4] == figure && _mBord[6] == figure)
            return true;
        break;
    case 5:
        if (_mBord[2] == figure && _mBord[5] == figure && _mBord[8] == figure)
            return true;
        else if (_mBord[3] == figure && _mBord[4] == figure && _mBord[5] == figure)
            return true;
        break;
    case 6:
        if (_mBord[0] == figure && _mBord[3] == figure && _mBord[6] == figure)
            return true;
        else if (_mBord[6] == figure && _mBord[7] == figure && _mBord[8] == figure)
            return true;
        else if (_mBord[6] == figure && _mBord[4] == figure && _mBord[2] == figure)
            return true;
        break;
    case 7:
        if (_mBord[6] == figure && _mBord[7] == figure && _mBord[8] == figure)
            return true;
        else if (_mBord[1] == figure && _mBord[4] == figure && _mBord[7] == figure)
            return true;
        break;
    case 8:
        if (_mBord[2] == figure && _mBord[5] == figure && _mBord[8] == figure)
            return true;
        else if (_mBord[6] == figure && _mBord[7] == figure && _mBord[8] == figure)
            return true;
        else if (_mBord[0] == figure && _mBord[4] == figure && _mBord[8] == figure)
            return true;
        break;
    }
}
char nonstd::TicTacToe::checkStep() // check the step
{
    char step;
    std::cin >> step;
    while ((step < 49 || step > 57) || (_mBord[step - '0' - 1] == _mP1Figure || _mBord[step - '0' - 1] == _mP2Figure))
    {
        std::cout << "You entered an incorrect number. Try again:  ";
        std::cin >> step;
    }

    return step;
}
void nonstd::TicTacToe::init() // init the bord
{
    _mBord[0] = '1';
    _mBord[1] = '2';
    _mBord[2] = '3';
    _mBord[3] = '4';
    _mBord[4] = '5';
    _mBord[5] = '6';
    _mBord[6] = '7';
    _mBord[7] = '8';
    _mBord[8] = '9';
}