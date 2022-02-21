#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Linker.h"

nonstd::Compiler::Compiler(const std::string &nameFile, nonstd::Linker &linker) // constructor
    : _nameOfFile{nameFile},
      _linker{linker},
      _compileText{},
      _keyWords{},
      _variabls{}
{
    _insertKeyWords(_keyWords);
    _readCompileFile(nameFile);
}

nonstd::Compiler::~Compiler() // destructor
{
}

// public function
void nonstd::Compiler::check() // syntax analysis
{
    for (size_t i{}; i < _compileText.size(); ++i)
    {
        std::stringstream stream(_compileText[i]);
        std::string word;
        std::getline(stream, word, ' ');
        if (word == _keyWords["NUM"])
        {
            _checkVariabl(_compileText[i]);
        }
        else if (word == _keyWords["STRING"])
        {
            _checkVariabl(_compileText[i]);
        }
        else if (word == _keyWords["LOOP"])
        {
            i = _checkLoop(_compileText[i], i);
        }
        else if (word == _keyWords["IF"])
        {
            _checkIf(_compileText[i], i);
        }
        else if (word == _keyWords["ELSE"])
        {
            _checkElse(_compileText[i], i);
        }
        else if (word == _keyWords["PRINT"])
        {
            _checkPrint(_compileText[i]);
        }
    }
    _linker.writeData(_compileText, _keyWords, _variabls);
}
// private functions
void nonstd::Compiler::_readCompileFile(const std::string &nameOfFile) // reade file
{
    std::fstream file(nameOfFile, std::fstream::in);
    if (!file.is_open())
        _error("The open of file is faled");

    std::string readingLine;
    while (!file.eof())
    {
        std::getline(file, readingLine);
        _compileText.push_back(readingLine);
    }
    file.close();
}
void nonstd::Compiler::_insertKeyWords(std::map<std::string, std::string> &keyWords) // inserting keywords
{
    keyWords["NUM"] = "NUM";
    keyWords["STRING"] = "STRING";
    keyWords["LOOP"] = "LOOP";
    keyWords["IF"] = "IF";
    keyWords["ELSE"] = "ELSE";
    keyWords["PRINT"] = "PRINT";
    keyWords["ENDL"] = "ENDL";
}
void nonstd::Compiler::_error(const std::string &massage) // error massage
{
    std::cout << "COMPILE ERROR */ " << massage << " /* " << std::endl;
    exit(1);
}
void nonstd::Compiler::_checkVariabl(const std::string &line) // checking variabls
{
    std::stringstream str(line);
    std::string word;
    std::string variableName;
    str >> word;
    std::string type = word;
    str >> word;
    variableName = word;

    if (variableName == _keyWords["NUM"] || variableName == _keyWords["STRING"])
        _error(std::string("The variable name cannot be a type name '") + word + "'");

    if (word[0] <= 64 || word[0] == 91 || word[0] == 92 || word[0] == 93 || word[0] == 94 || word[0] == 96 || word[0] >= 123)
        _error(std::string("The variable cannot be a started white '") + word[0] + "'");

    if (_variabls.find(variableName) != _variabls.end())
        _error(std::string("Redefinition of '") + variableName + "'");

    str >> word;

    if (variableName == word)
    {
        if (type == "NUM")
            _variabls[variableName] = std::make_pair(0, type);
        else if (type == "STRING")
            _variabls[variableName] = std::make_pair("", type);

        return;
    }

    if (word != "=")
        _error(std::string("Not allowed symbol '") + word + "'");

    if (type == "NUM")
    {
        str >> word;
        std::string old(word);
        if (_isNumber(word))
        {
            _checkNumber(word);
            int var1 = stoi(word);
            str >> word;
            if (old == word)
            {
                _variabls[variableName] = std::make_pair(std::to_string(var1), type);
                return;
            }

            int var2{};

            if (word != "+" && word != "-" && word != "*" && word != "/")
                _error(std::string("Use of undeclared operator '") + word + "'");

            std::string op(word);
            str >> word;
            if (word == "\"")
                _error(std::string("You can not '") + op + "' two different types 'NUM' and 'STRING' ");

            if (_isNumber(word))
            {
                _checkNumber(word);
                var2 = stoi(word);
            }
            else
            {
                if (_variabls.find(word) == _variabls.end())
                    _error(std::string("Use of undeclared identifier '") + word + "'");
                if (word == variableName)
                    _error(std::string("You can not use the same name in the statement '") + word + "'");
                if (_variabls[word].second == "STRING")
                    _error(std::string("You can not '") + op + "' two different types 'NUM' and 'STRING' ");

                var2 = stoi(_variabls[word].first);
            }

            if (op == "+")
                _variabls[variableName] = std::make_pair(_plus(var1, var2), type);
            if (op == "-")
                _variabls[variableName] = std::make_pair(_minus(var1, var2), type);
            if (op == "/")
                _variabls[variableName] = std::make_pair(_divides(var1, var2), type);
            if (op == "*")
                _variabls[variableName] = std::make_pair(_multiplies(var1, var2), type);
        }
        else
        {
            if (_variabls.find(word) == _variabls.end())
                _error(std::string("Use of undeclared identifier '") + word + "'");
            if (word == variableName)
                _error(std::string("You can not use the same name in the statement '") + word + "'");
            int var1 = stoi(_variabls[word].first);
            int var2{};
            str >> word;
            if (word != "+" && word != "-" && word != "*" && word != "/")
                _error(std::string("Use of undeclared operator '") + word + "'");
            std::string op(word);
            str >> word;
            if (word == "\"")
                _error(std::string("You can not '") + op + "' two different types 'NUM' and 'STRING' ");

            if (_isNumber(word))
            {
                _checkNumber(word);
                var2 = stoi(word);
            }
            else
            {
                if (_variabls.find(word) == _variabls.end())
                    _error(std::string("Use of undeclared identifier '") + word + "'");
                if (word == variableName)
                    _error(std::string("You can not use the same name in the statement '") + word + "'");
                if (_variabls[word].second == "STRING")
                    _error(std::string("You can not '") + op + "' two different types 'NUM' and 'STRING' ");

                var2 = stoi(_variabls[word].first);
            }

            if (op == "+")
                _variabls[variableName] = std::make_pair(_plus(var1, var2), type);
            if (op == "-")
                _variabls[variableName] = std::make_pair(_minus(var1, var2), type);
            if (op == "/")
                _variabls[variableName] = std::make_pair(_divides(var1, var2), type);
            if (op == "*")
                _variabls[variableName] = std::make_pair(_multiplies(var1, var2), type);
        }
    }
    else if (type == "STRING")
    {
        str >> word;
        if (word == "\"")
        {
            std::string text1;
            std::getline(str, text1, '"');
            str >> word;
            if (word == "\"")
            {
                _variabls[variableName] = std::make_pair(text1, type);
                return;
            }
            if (word != "+")
                _error(std::string("Use of undeclared operator '") + word + "'");

            str >> word;

            if (_isNumber(word))
                _error(std::string("You can not '+' two different types 'STRING' and 'NUM' "));

            if (word == "\"")
            {
                std::string text2;
                std::getline(str, text2, '"');
                str >> word;
                if (word != "\"")
                    _error(std::string("STRING must end with '\"' "));
                _variabls[variableName] = std::make_pair(_plus(text1, text2), type);
            }
            else
            {
                if (_variabls.find(word) == _variabls.end())
                    _error(std::string("Use of undeclared identifier '") + word + "'");
                if (_variabls[word].second == "NUM")
                    _error(std::string("You can not '+' two different types 'STRING' and 'NUM' "));

                _variabls[variableName] = std::make_pair(_plus(text1, _variabls[word].first), type);
            }
        }
        else if (_variabls.find(word) != _variabls.end() && _variabls[word].second == "STRING")
        {
            std::string text1(_variabls[word].first);

            str >> word;
            if (word != "+")
                _error(std::string("Use of undeclared operator '") + word + "'");
            str >> word;
            if (_isNumber(word))
                _error(std::string("You can not '+' two different types 'STRING' and 'NUM' "));
            if (word == "\"")
            {
                std::string text2;
                std::getline(str, text2, '"');
                str >> word;
                if (word != "\"")
                    _error(std::string("STRING must end with '\"' "));
                _variabls[variableName] = std::make_pair(text1 + text2, type);
            }
            else
            {
                if (_variabls.find(word) == _variabls.end())
                    _error(std::string("Use of undeclared identifier '") + word + "'");
                if (_variabls[word].second == "NUM")
                    _error(std::string("You can not '+' two different types 'STRING' and 'NUM' "));
                _variabls[variableName] = std::make_pair(text1 + _variabls[word].first, type);
            }
        }
        else if (_variabls.find(word) != _variabls.end())
            _error(std::string("Use of undeclared identifier '") + word + "'");
        else if (word[0] == '"' && word[word.size() - 1] == '"')
        {
            std::string temp(word.begin() + 1, word.end() - 1);
            _variabls[variableName] = std::make_pair(temp, type);
        }
        else
        {
            _error(std::string("STRING must start with '\"' and end with '\"' "));
        }
    }
}
void nonstd::Compiler::_checkPrint(const std::string &line) // check PRINT
{
    std::stringstream str(line);
    std::string word;
    str >> word;
    str >> word;

    if (word != "/")
        _error(std::string("Expected '/' after 'PRINT' "));

    if (line[line.size() - 1] != ';')
        _error(std::string("Expected ';' at the end of 'PRINT' "));

    str >> word;
    if (word != "\"" && _isNumber(word))
    {
        if (_variabls.find(word) == _variabls.end())
            _error(std::string("Use of undeclared identifier '") + word + "'");
    }
}
void nonstd::Compiler::_checkInstructionSyntax(const std::string &str) // check instruction syntax
{
    std::stringstream stream(str);
    std::string word;
    stream >> word;

    if (_variabls.find(word) == _variabls.end())
        _error(std::string("Use of undeclared identifier '") + word + "'");

    std::string resType(_variabls[word].second);
    stream >> word;

    if (word != "=")
        _error(std::string("Not allowed symbol '") + word + "'");

    stream >> word;

    if (resType == "NUM")
    {
        if (_isNumber(word))
        {
            _checkNumber(word);

            stream >> word;

            if (word != "+" && word != "-" && word != "*" && word != "/")
                _error(std::string("Use of undeclared operator '") + word + "'");

            stream >> word;

            if (word == "\"")
                _error(std::string("You can not add two different types ") + "'STRING' " + "and '" + resType + "'");

            if (_isNumber(word))
            {
                _checkNumber(word);
                if (word == "0")
                    _error(std::string("Divide in zero is not allowed "));
            }
            else if (_variabls.find(word) == _variabls.end())
                _error(std::string("Use of undeclared identifier '") + word + "'");
        }
        else
        {
            if (_variabls.find(word) == _variabls.end())
                _error(std::string("Use of undeclared identifier '") + word + "'");

            stream >> word;

            if (word != "+" && word != "-" && word != "*" && word != "/")
                _error(std::string("Use of undeclared operator '") + word + "'");

            stream >> word;

            if (word == "\"")
                _error(std::string("You can not add two different types ") + "'STRING' " + "and '" + resType + "'");

            if (_isNumber(word))
            {
                _checkNumber(word);
            }
            else if (_variabls.find(word) == _variabls.end())
                _error(std::string("Use of undeclared identifier '") + word + "'");
        }
    }
    else
    {
        if (word == "\"")
        {
            std::string text1;
            std::getline(stream, text1, '"');
            stream >> word;

            if (word != "\"")
                _error(std::string("STRING must end with '\"' "));

            stream >> word;

            if (word != "+")
                _error(std::string("Use of undeclared operator '") + word + "'");

            stream >> word;
            if (word == "\"")
            {
                std::string text2;
                std::getline(stream, text2, '"');
                stream >> word;
                if (word != "\"")
                    _error(std::string("STRING must end with '\"' "));
            }
            else
            {
                if (_isNumber(word))
                    _error(std::string("You can not add two different types '") + resType + "'and '" + "'STRING' ");
                if (_variabls.find(word) == _variabls.end())
                    _error(std::string("Use of undeclared identifier '") + word + "'");
            }
        }
        else if (_variabls.find(word) != _variabls.end())
        {
            stream >> word;
            if (word != "+")
                _error(std::string("Use of undeclared operator '") + word + "'");
            stream >> word;
            if (word == "\"")
            {
                std::string text2;
                std::getline(stream, text2, '"');
                stream >> word;
                if (word != "\"")
                    _error(std::string("STRING must end with '\"' "));
            }
            else
            {
                if (_isNumber(word))
                    _error(std::string("You can not add two different types '") + resType + "'and '" + "'STRING' ");

                if (_variabls.find(word) == _variabls.end())
                    _error(std::string("Use of undeclared identifier '") + word + "'");
            }
        }
        else if (_variabls.find(word) == _variabls.end())
            _error(std::string("Use of undeclared identifier '") + word + "'");
    }
}
void nonstd::Compiler::_checkNumber(const std::string &value) // check numbers
{
    for (int i = 0; i < value.size(); ++i)
    {
        if (value[i] < 48 || value[i] > 57)
            _error(std::string("Undeclared symbol in number ") + value[i]);
    }
}
bool nonstd::Compiler::_isNumber(const std::string &value) // chaeck numbers
{
    for (int i = 0; i < value.size(); ++i)
    {
        if (value[i] < 48 || value[i] > 57)
            return false;
    }
    return true;
}
bool nonstd::Compiler::_checkScope(size_t index) // check scope
{
    while (_compileText[index] != "]")
    {
        if (_compileText[index] == "[")
            return false;
    }
    return true;
}
size_t nonstd::Compiler::_checker(size_t index) // checking
{
    std::stringstream stream(_compileText[index]);
    std::string word;
    stream >> word;
    if (word == _keyWords["NUM"])
    {
        _checkVariabl(_compileText[index]);
    }
    else if (word == _keyWords["STRING"])
    {
        _checkVariabl(_compileText[index]);
    }
    else if (word == _keyWords["LOOP"])
    {
        index = _checkLoop(_compileText[index], index);
    }
    else if (word == _keyWords["IF"])
    {
        _checkIf(_compileText[index], index);
    }
    else if (word == _keyWords["ELSE"])
    {
        _checkElse(_compileText[index], index);
    }
    else if (word == _keyWords["PRINT"])
    {
        _checkPrint(_compileText[index]);
    }
    else if (_variabls.find(word) != _variabls.end())
    {
        _checkInstructionSyntax(_compileText[index]);
    }
    else if (_variabls.find(word) == _variabls.end())
    {
        _error(std::string("Use of undeclared identifier '") + word + "'");
    }

    return index;
}
size_t nonstd::Compiler::_checkLoop(const std::string &line, size_t index) // check LOOP
{
    std::stringstream str(line);
    std::string word;
    str >> word;
    str >> word;

    if (word != "/")
        _error(std::string("Expected '/' after 'LOOP' "));

    if (line[line.size() - 1] != '/')
        _error(std::string("Expected '/' at the end of 'LOOP' "));

    str >> word;
    if (!_isNumber(word))
    {
        if (_variabls.find(word) == _variabls.end())
            _error(std::string("Use of undeclared identifier '") + word + "'");
    }
    else
        _error(std::string("You can not use literals in the LOOP statement '") + word + "'");
    std::string variableName(word);

    if (_variabls[variableName].second == "NUM")
        _checkNumber(_variabls[variableName].first);
    else if (_variabls[variableName].second == "STRING")
        _error(std::string("You can not use a 'STRING' in 'LOOP'"));

    str >> word;

    if (word != ">" && word != "<" && word != ">=" && word != "<=" && word != "!=")
        _error(std::string("Not allowed symbol '") + word + "'");

    str >> word;
    if (!_isNumber(word))
    {
        if (_variabls.find(word) == _variabls.end())
            _error(std::string("Use of undeclared identifier '") + word + "'");
    }
    else
        _error(std::string("You can not use literals in the LOOP statement '") + word + "'");

    if (_compileText[++index] == "[")
    {
        if (!_checkScope(index))
            if (std::find(_compileText.begin(), _compileText.end(), "]") == _compileText.end())
                _error(std::string("Expected ']'"));

        while (_compileText[++index] != "]")
        {
            index = _checker(index);
        }
    }
    else
        _error(std::string("Expected '") + _compileText[index] + "'");

    return index;
}
size_t nonstd::Compiler::_checkIf(const std::string &line, size_t index) // check IF
{
    std::stringstream str(line);
    std::string word;
    str >> word;
    str >> word;
    if (word != "/")
        _error(std::string("Expected '/' after 'IF' "));

    if (line[line.size() - 1] != '/')
        _error(std::string("Expected '/' at the end of 'IF' "));

    str >> word;
    if (word != "\"" && !_isNumber(word))
    {
        if (_variabls.find(word) == _variabls.end())
            _error(std::string("Use of undeclared identifier '") + word + "'");

        if (_variabls[word].second == "NUM")
        {
            str >> word;

            if (word != "<" && word != ">" && word != "<=" && word != ">=" && word != "==" && word != "!=")
                _error(std::string("Use of undeclared operator '") + word + "'");

            str >> word;

            if (word == "\"")
                _error(std::string("You can not compare two different types 'NUM' and 'STRING' "));

            if (_isNumber(word))
                _checkNumber(word);
            else if (_variabls.find(word) == _variabls.end())
                _error(std::string("Use of undeclared identifier '") + word + "'");
            else if (_variabls[word].second == "STRING")
                _error(std::string("You can not compare two different types 'NUM' and 'STRING' "));
        }
        else
        {
            str >> word;

            if (word != "==" && word != "!=")
                _error(std::string("Use of undeclared operator '") + word + "'");

            str >> word;
            if (word == "\"")
            {
                std::string text2;
                std::getline(str, text2, '"');
                if (word != "\"")
                    _error(std::string("STRING must end with '\"' in 'IF' statement "));
            }
            else
            {
                if (_isNumber(word))
                    _error(std::string("You can not compare two different types 'STRING' and 'NUM' "));
                else if (_variabls.find(word) == _variabls.end())
                    _error(std::string("Use of undeclared identifier '") + word + "'");
                else if (_variabls[word].second == "NUM")
                    _error(std::string("You can not compare two different types 'STRING' and 'NUM' "));
            }
        }
    }
    if (word == "\"")
    {
        std::string text1;
        std::getline(str, text1, '"');

        if (word != "\"")
            _error(std::string("STRING must end with '\"' in 'IF' statement "));

        str >> word;

        if (word != "==" && word != "!=")
            _error(std::string("Use of undeclared operator '") + word + "'");

        str >> word;
        if (word == "\"")
        {
            std::string text2;
            std::getline(str, text2, '"');
            if (word != "\"")
                _error(std::string("STRING must end with '\"' in 'IF' statement "));
        }
        else
        {
            if (_isNumber(word))
                _error(std::string("You can not compare two different types 'STRING' and 'NUM' "));
            else if (_variabls.find(word) == _variabls.end())
                _error(std::string("Use of undeclared identifier '") + word + "'");
            else if (_variabls[word].second == "NUM")
                _error(std::string("You can not compare two different types 'STRING' and 'NUM' "));
        }
    }
    else
    {
        if (_isNumber(word))
        {
            _checkNumber(word);

            str >> word;

            if (word != "<" && word != ">" && word != "<=" && word != ">=" && word != "==" && word != "!=")
                _error(std::string("Use of undeclared operator '") + word + "'");

            str >> word;

            if (word == "\"")
                _error(std::string("You can not add two different types 'NUM' and 'STRING' "));

            if (_isNumber(word))
                _checkNumber(word);
            else if (_variabls.find(word) == _variabls.end())
                _error(std::string("Use of undeclared identifier '") + word + "'");
            else if (_variabls[word].second == "STRING")
                _error(std::string("You can not compare two different types 'NUM' and 'STRING' "));
        }
    }
    if (_compileText[++index] == "[")
    {
        if (!_checkScope(index))
            if (std::find(_compileText.begin(), _compileText.end(), "]") == _compileText.end())
                _error(std::string("Expected ']'"));

        while (_compileText[++index] != "]")
        {
            index = _checker(index);
        }
    }
    else
        _error(std::string("Expected '") + _compileText[index] + "'");

    return index;
}
size_t nonstd::Compiler::_checkElse(const std::string &line, size_t index) // check ELSE
{
    if (_compileText[++index] == "[")
    {
        if (!_checkScope(index))
            if (std::find(_compileText.begin(), _compileText.end(), "]") == _compileText.end())
                _error(std::string("Expected ']'"));

        while (_compileText[++index] != "]")
        {
            index = _checker(index);
        }
    }
    else
        _error(std::string("Expected '") + _compileText[index] + "'");

    return index;
}
std::string nonstd::Compiler::_plus(const int &val1, const int &val2) // operator+
{
    return std::string(std::to_string(val1 + val2));
}
std::string nonstd::Compiler::_plus(const std::string &val1, const std::string &val2) // operator+
{
    return std::string(val1 + val2);
}
std::string nonstd::Compiler::_minus(const int &val1, const int &val2) // operator-
{
    return std::string(std::to_string(val1 - val2));
}
std::string nonstd::Compiler::_divides(const int &val1, const int &val2) // operator/c
{
    if (val2 == 0)
        _error(std::string("Divide in zero is not allowed "));
    return std::string(std::to_string(val1 / val2));
}
std::string nonstd::Compiler::_multiplies(const int &val1, const int &val2) // operator*
{
    return std::string(std::to_string(val1 * val2));
}