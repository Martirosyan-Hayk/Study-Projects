#ifndef _LINKER_
#define _LINKER_

#include <vector>
#include <string>
#include <map>

namespace nonstd
{
    class Linker final
    {
        typedef std::vector<std::string> constentsOfFile;                                // saves the contents of the file
        typedef std::map<std::string, std::string> keyWordsMap;                          // stores keywords
        typedef std::map<std::string, std::pair<std::string, std::string> > variablsMap; // stores variables

    public:
        Linker();  // default constructor
        ~Linker(); // destructor

    public:
        // deleted cnstructors and operators
        Linker(const Linker &) = delete;            // copy ctor
        Linker(Linker &&) = delete;                 // move ctor
        Linker &operator=(const Linker &) = delete; // copy operator=
        Linker &operator=(Linker &&) = delete;      // move operator=

    public:
        // public function
        void writeData(const constentsOfFile &compileText, const keyWordsMap &keyWords, const variablsMap &variabls); // transfers data from the compiler

    public:
        // public geters
        const constentsOfFile readCompileText() const; // returned contents of the vectro
        const keyWordsMap readKeyWords() const;        // returned keywords
        const variablsMap readVariabls() const;        // returned variabls

    private:
        // private members
        constentsOfFile _compileText;
        keyWordsMap _keyWords;
        variablsMap _variabls;
    };

}

#include "Linker.hpp"

#endif // _LINKER_!