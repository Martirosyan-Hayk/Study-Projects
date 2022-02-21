#ifndef _EXECUTE_
#define _EXECUTE_

#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <map>

namespace nonstd
{
    class Execute final
    {
        typedef std::vector<std::string> constentsOfFile;                                // saves the contents of the file
        typedef std::map<std::string, std::string> keyWordsMap;                          // stores keywords
        typedef std::map<std::string, std::pair<std::string, std::string> > variablsMap; // stores variables

    public:
        Execute(constentsOfFile, keyWordsMap, variablsMap); // default constructor
        ~Execute();                                         // destructor

    public:
        //deleted cnstructors and operators
        Execute(const Execute &) = delete;            // copy ctor
        Execute(Execute &&) = delete;                 // move ctor
        Execute &operator=(const Execute &) = delete; // copy operator=
        Execute &operator=(Execute &&) = delete;      // move operator=
    public:
        // public function
        void execute();

    private:
        // private function
        void _checker(size_t &);                                                         // checking
        void _checkIf(size_t &);                                                         // check IF
        void _checkElse(size_t &);                                                       // check ELSE
        void _checkLoop(size_t &);                                                       // check LOOP
        void _checkAndDo(size_t &);                                                      // do instruction
        void _commondPRINT(size_t &);                                                    // PRINT function
        bool _isNumber(const std::string &);                                             // chaeck numbers
        void _doInstruction(std::string &, std::string &, std::string &, std::string &); // check operators and do
        // Comparisons
        bool _less(const int &, const int &);                       // operator<
        bool _greater(const int &, const int &);                    // operator>
        bool _lessEqual(const int &, const int &);                  // operator<=
        bool _greaterEqual(const int &, const int &);               // operator>=
        bool _equalTo(const int &, const int &);                    // operator==
        bool _notEqualTo(const int &, const int &);                 // operator!=
        bool _equalTo(const std::string &, const std::string &);    // operator== for STRING
        bool _notEqualTo(const std::string &, const std::string &); // operator!= for STRING
        // Arithmetic operations
        std::string _plus(const int &, const int &);                 // operator+
        std::string _plus(const std::string &, const std::string &); // operator+ for STRING
        std::string _minus(const int &, const int &);                // operator-
        std::string _divides(const int &, const int &);              // operator/
        std::string _multiplies(const int &, const int &);           // operator*

    private:
        // private members
        constentsOfFile _compileText;
        keyWordsMap _keyWords;
        variablsMap _variabls;
    };
}

#include "Execute.hpp"

#endif //_EXECUTE_!