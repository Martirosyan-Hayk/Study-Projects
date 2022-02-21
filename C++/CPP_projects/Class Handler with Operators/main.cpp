#include <iostream>
#include <string>
#include "handler.h"

class X : public nonstd::NewHandlerSupport<X> // Inherited at NewHandlerSupport
{
public:
    void setWord(const std::string &rhs)
    {
        m_word = rhs;
    }
    std::string getWord() const
    {
        return m_word;
    }

private:
    std::string m_word;
};

void noMemory() // new handler
{
    std::cout << " ************ ERROR: NO MORE MEMORY ************ " << std::endl;
    abort();
}

int main()
{
    X::set_new_handler(noMemory); // set_new_handler in class X
    X *arr = new X();
    X *arr1 = new X[1000000000000000];

    return 0;
}