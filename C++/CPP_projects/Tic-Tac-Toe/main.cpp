#include <iostream>
#include "src/TicTacToe.h"

int main()
{
    std::cout << std::endl << "Starting The Game" << std::endl
              << std::endl;
    std::cout << "You want to select a symbol (y/n)" << std::endl;
    char selectSymbol;
    std::cin >> selectSymbol;

    if (selectSymbol == 'y')
    {
        char symbol1;
        char symbol2;
        std::cout << "Entered the symbol of Player 1 >> ";
        std::cin >> symbol1;
        std::cout << "Entered the symbol of Player 2 >> ";
        std::cin >> symbol2;
        nonstd::TicTacToe obj(symbol1, symbol2);
        obj.startGame();
    }
    else
    {
        nonstd::TicTacToe obj;
        obj.startGame();
    }
}