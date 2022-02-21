#ifndef _COMPILER_
#define _COMPILER_

#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include "Linker.h"

namespace nonstd
{
    class Compiler final
    {
        typedef std::map<std::string, std::pair<std::string, std::string>> variablsMap; // stores variables

    public:
        Compiler(const std::string &, nonstd::Linker &); // default constructor for open file and read the file
        ~Compiler();                                     // destructor

    public:
        // deleted cnstructors and operators
        Compiler(const Compiler &) = delete;            // copy ctor
        Compiler(Compiler &&) = delete;                 // move ctor
        Compiler &operator=(const Compiler &) = delete; // copy operator=
        Compiler &operator=(Compiler &&) = delete;      // move operator=

    public:
        // public function
        void check(); // chacking sintax of file

    private:
        // private functions
        void _readCompileFile(const std::string &);                  // reade file
        void _insertKeyWords(std::map<std::string, std::string> &);  // inserting keywords
        void _error(const std::string &);                            // error massage
        void _checkVariabl(const std::string &);                     // checking variabls
        void _checkPrint(const std::string &);                       // check PRINT
        void _checkInstructionSyntax(const std::string &);           // check instruction syntax
        void _checkNumber(const std::string &);                      // check numbers
        bool _isNumber(const std::string &);                         // chaeck numbers
        bool _checkScope(size_t);                                    // check scope
        size_t _checker(size_t);                                     // checking
        size_t _checkLoop(const std::string &, size_t);              // check LOOP
        size_t _checkIf(const std::string &, size_t);                // check IF
        size_t _checkElse(const std::string &, size_t);              // check ELSE
        std::string _plus(const int &, const int &);                 // operator+
        std::string _plus(const std::string &, const std::string &); // operator+
        std::string _minus(const int &, const int &);                // operator-
        std::string _divides(const int &, const int &);              // operator/
        std::string _multiplies(const int &, const int &);           // operator*

    private:
        // private members
        std::string _nameOfFile;
        nonstd::Linker &_linker;
        std::vector<std::string> _compileText;
        std::map<std::string, std::string> _keyWords;
        variablsMap _variabls;
    };
}

#include "Compiler.hpp"

#endif // _COMPILER_!