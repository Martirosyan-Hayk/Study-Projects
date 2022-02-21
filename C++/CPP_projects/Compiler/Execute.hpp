#include <iostream>
#include <utility>
#include <sstream>
#include <vector>
#include <string>
#include <map>



typedef std::vector<std::string> constentsOfFile;                                // saves the contents of the file
typedef std::map<std::string, std::string> keyWordsMap;                          // stores keywords
typedef std::map<std::string, std::pair<std::string, std::string> > variablsMap; // stores variables

nonstd::Execute::Execute(constentsOfFile compileText, keyWordsMap keyWords, variablsMap variabls) // default constructor
    : _compileText{compileText},
      _keyWords{keyWords},
      _variabls{variabls}
{
}

nonstd::Execute::~Execute() // destructor
{
}

// public functions
void nonstd::Execute::execute() // execute file
{
  for (size_t i{}; i < _compileText.size(); ++i)
  {
    std::stringstream stream(_compileText[i]);
    std::string word;
    std::getline(stream, word, ' ');
    if (word == _keyWords["LOOP"])
    {
      _checkLoop(i);
    }
    else if (word == _keyWords["IF"])
    {
      _checkIf(i);
    }
    else if (word == _keyWords["PRINT"])
    {
      _commondPRINT(i);
    }
  }
}
// private functions
void nonstd::Execute::_checker(size_t &index) // checking
{
  std::stringstream stream(_compileText[index]);
  std::string word;
  stream >> word;

  if (word == _keyWords["PRINT"])
  {
    _commondPRINT(index);
  }
}
void nonstd::Execute::_checkIf(size_t &index) // check IF
{
  std::stringstream line(_compileText[index]);
  std::string word;
  line >> word;
  line >> word;
  line >> word;

  std::string variable1;
  std::string variable2;
  std::string stringOrNum;

  if (word == "\"")
  {
    std::getline(line, variable1, '"');
    stringOrNum = "STRING";
  }
  else if (_isNumber(word))
  {
    line >> word;
    variable1 = word;
    stringOrNum = "NUM";
  }
  else
  {
    variable1 = _variabls[word].first;
    stringOrNum = _variabls[word].second;
  }

  line >> word;
  std::string oper = word;

  if (stringOrNum == "NUM")
  {
    line >> word;
    if (_isNumber(word))
      variable2 = word;
    else
      variable2 = _variabls[word].first;
  }
  else
  {
    line >> word;
    if (word == "\"")
      std::getline(line, variable2, '"');
    else
      variable2 = _variabls[word].first;
  }
  ++index;
  ++index;
  if (stringOrNum == "NUM")
  {
    if (oper == ">")
    {
      if (_greater(stoi(variable1), stoi(variable2)))
      {
        for (; _compileText[index] != "]"; ++index)
        {
          std::stringstream tempStream(_compileText[index]);
          std::string tempString;
          tempStream >> tempString;
          if (tempString == _keyWords["PRINT"])
          {
            _commondPRINT(index);
          }
          else
          {
            _checkAndDo(index);
          }
        }
      }
      else
      {
        while (_compileText[index] != "]")
        {
          ++index;
        }
        ++index;
        _checkElse(index);
      }
    }
    else if (oper == "<")
    {
      if (_less(stoi(variable1), stoi(variable2)))
      {
        for (; _compileText[index] != "]"; ++index)
        {
          std::stringstream tempStream(_compileText[index]);
          std::string tempString;
          tempStream >> tempString;
          if (tempString == _keyWords["PRINT"])
          {
            _commondPRINT(index);
          }
          else
          {
            _checkAndDo(index);
          }
        }
      }
      else
      {
        while (_compileText[index] != "]")
        {
          ++index;
        }
        ++index;
        _checkElse(index);
      }
    }
    else if (oper == ">=")
    {
      if (_greaterEqual(stoi(variable1), stoi(variable2)))
      {
        for (; _compileText[index] != "]"; ++index)
        {
          std::stringstream tempStream(_compileText[index]);
          std::string tempString;
          tempStream >> tempString;
          if (tempString == _keyWords["PRINT"])
          {
            _commondPRINT(index);
          }
          else
          {
            _checkAndDo(index);
          }
        }
      }
      else
      {
        while (_compileText[index] != "]")
        {
          ++index;
        }
        ++index;
        _checkElse(index);
      }
    }
    else if (oper == "<=")
    {
      if (_lessEqual(stoi(variable1), stoi(variable2)))
      {
        for (; _compileText[index] != "]"; ++index)
        {
          std::stringstream tempStream(_compileText[index]);
          std::string tempString;
          tempStream >> tempString;
          if (tempString == _keyWords["PRINT"])
          {
            _commondPRINT(index);
          }
          else
          {
            _checkAndDo(index);
          }
        }
      }
      else
      {
        while (_compileText[index] != "]")
        {
          ++index;
        }
        ++index;
        _checkElse(index);
      }
    }
    else if (oper == "==")
    {
      if (_equalTo(stoi(variable1), stoi(variable2)))
      {
        for (; _compileText[index] != "]"; ++index)
        {
          std::stringstream tempStream(_compileText[index]);
          std::string tempString;
          tempStream >> tempString;
          if (tempString == _keyWords["PRINT"])
          {
            _commondPRINT(index);
          }
          else
          {
            _checkAndDo(index);
          }
        }
      }
      else
      {
        while (_compileText[index] != "]")
        {
          ++index;
        }
        ++index;
        _checkElse(index);
      }
    }
    else if (oper == "!=")
    {
      if (_notEqualTo(stoi(variable1), stoi(variable2)))
      {
        for (; _compileText[index] != "]"; ++index)
        {
          std::stringstream tempStream(_compileText[index]);
          std::string tempString;
          tempStream >> tempString;
          if (tempString == _keyWords["PRINT"])
          {
            _commondPRINT(index);
          }
          else
          {
            _checkAndDo(index);
          }
        }
      }
      else
      {
        while (_compileText[index] != "]")
        {
          ++index;
        }
        ++index;
        _checkElse(index);
      }
    }
  }
  else
  {
    if (oper == "==")
    {
      if (_equalTo(variable1, variable2))
      {
        for (; _compileText[index] != "]"; ++index)
        {
          std::stringstream tempStream(_compileText[index]);
          std::string tempString;
          tempStream >> tempString;
          if (tempString == _keyWords["PRINT"])
          {
            _commondPRINT(index);
          }
          else
          {
            _checkAndDo(index);
          }
        }
      }
      else
      {
        while (_compileText[index] != "]")
        {
          ++index;
        }
        ++index;
        _checkElse(index);
      }
    }
    else if (oper == "!=")
    {
      if (_notEqualTo(variable1, variable2))
      {
        for (; _compileText[index] != "]"; ++index)
        {
          std::stringstream tempStream(_compileText[index]);
          std::string tempString;
          tempStream >> tempString;
          if (tempString == _keyWords["PRINT"])
          {
            _commondPRINT(index);
          }
          else
          {
            _checkAndDo(index);
          }
        }
      }
      else
      {
        while (_compileText[index] != "]")
        {
          ++index;
        }
        ++index;
        _checkElse(index);
      }
    }
  }
}
void nonstd::Execute::_checkElse(size_t &index) // check ELSE
{
  for (; _compileText[index] != "]"; ++index)
  {
    std::stringstream tempStream(_compileText[index]);
    std::string tempString;
    tempStream >> tempString;
    if (tempString == _keyWords["PRINT"])
    {
      _commondPRINT(index);
    }
    else
    {
      _checkAndDo(index);
    }
  }
}
void nonstd::Execute::_checkLoop(size_t &index) // check LOOP
{
  std::stringstream line(_compileText[index]);
  std::string word;
  line >> word;
  line >> word;
  line >> word;

  std::string variable1(word);

  line >> word;
  std::string oper = word;
  line >> word;

  std::string variable2(word);

  ++index;
  ++index;

  if (oper == "<=")
  {
    size_t point = index;
    while (stoi(_variabls[variable1].first) <= stoi(_variabls[variable2].first))
    {
      size_t i = index;
      for (; _compileText[i] != "]"; ++i)
      {
        std::stringstream tempStream(_compileText[i]);
        std::string tempString;
        tempStream >> tempString;
        if (tempString == _keyWords["PRINT"])
        {
          _commondPRINT(i);
        }
        else
        {
          _checkAndDo(i);
        }
      }
      point = i;
    }
    index = point;
  }
  else if (oper == ">=")
  {
    size_t point = index;
    while (stoi(_variabls[variable1].first) >= stoi(_variabls[variable2].first))
    {
      size_t i = index;
      for (; _compileText[i] != "]"; ++i)
      {
        std::stringstream tempStream(_compileText[i]);
        std::string tempString;
        tempStream >> tempString;
        if (tempString == _keyWords["PRINT"])
        {
          _commondPRINT(i);
        }
        else
        {
          _checkAndDo(i);
        }
      }
      point = i;
    }
    index = point;
  }
  else if (oper == "<")
  {
    size_t point = index;
    while (stoi(_variabls[variable1].first) < stoi(_variabls[variable2].first))
    {
      size_t i = index;
      for (; _compileText[i] != "]"; ++i)
      {
        std::stringstream tempStream(_compileText[i]);
        std::string tempString;
        tempStream >> tempString;
        if (tempString == _keyWords["PRINT"])
        {
          _commondPRINT(i);
        }
        else
        {
          _checkAndDo(i);
        }
      }
      point = i;
    }
    index = point;
  }
  else if (oper == ">")
  {
    size_t point = index;
    while (stoi(_variabls[variable1].first) > stoi(_variabls[variable2].first))
    {
      size_t i = index;
      for (; _compileText[i] != "]"; ++i)
      {
        std::stringstream tempStream(_compileText[i]);
        std::string tempString;
        tempStream >> tempString;
        if (tempString == _keyWords["PRINT"])
        {
          _commondPRINT(i);
        }
        else
        {
          _checkAndDo(i);
        }
      }
      point = i;
    }
    index = point;
  }
  else if (oper == "!=")
  {
    size_t point = index;
    while (stoi(_variabls[variable1].first) != stoi(_variabls[variable2].first))
    {
      size_t i = index;
      for (; _compileText[i] != "]"; ++i)
      {
        std::stringstream tempStream(_compileText[i]);
        std::string tempString;
        tempStream >> tempString;
        if (tempString == _keyWords["PRINT"])
        {
          _commondPRINT(i);
        }
        else
        {
          _checkAndDo(i);
        }
      }
      point = i;
    }
    index = point;
  }
}
void nonstd::Execute::_checkAndDo(size_t &index) // do instruction
{
  std::stringstream stream(_compileText[index]);
  std::string word;
  stream >> word;

  std::string resVariableName(word);

  stream >> word;
  stream >> word;

  if (_variabls[resVariableName].second == "NUM")
  {
    if (_isNumber(word))
    {
      std::string val1(word);
      stream >> word;

      std::string oper(word);

      stream >> word;

      if (_isNumber(word))
        _doInstruction(resVariableName, val1, word, oper);
      else
        _doInstruction(resVariableName, val1, _variabls[word].first, oper);
    }
    else
    {
      std::string val1(_variabls[word].first);
      stream >> word;

      std::string oper(word);

      stream >> word;

      if (_isNumber(word))
        _doInstruction(resVariableName, val1, word, oper);
      else
        _doInstruction(resVariableName, val1, _variabls[word].first, oper);
    }
  }
  else
  {
    std::string oper("+");
    if (word == "\"")
    {
      std::string text1;
      std::getline(stream, text1, '"');
      stream >> word;
      stream >> word;
      stream >> word;

      if (word == "\"")
      {
        std::string text2;
        std::getline(stream, text2, '"');
        _doInstruction(resVariableName, text1, text2, oper);
      }
      else
        _doInstruction(resVariableName, text1, _variabls[word].first, oper);
    }
    else
    {
      std::string text1(_variabls[word].first);
      stream >> word;
      stream >> word;
      if (word == "\"")
      {
        std::string text2;
        std::getline(stream, text2, '"');
        _doInstruction(resVariableName, text1, text2, oper);
      }
      else
        _doInstruction(resVariableName, text1, _variabls[word].first, oper);
    }
  }
}
void nonstd::Execute::_commondPRINT(size_t &index) // PRINT function
{
  std::stringstream stream(_compileText[index]);
  std::string word;
  stream >> word;
  stream >> word;
  stream >> word;

  while (word != ";")
  {
    if (word == "/")
      stream >> word;

    if (word == "\"")
    {
      std::getline(stream, word, '\"');
      std::cout << word;
    }
    else if (word == _keyWords["ENDL"])
    {
      std::cout << std::endl;
    }
    if (_isNumber(word))
    {
      std::cout << word;
    }
    else if (_variabls.find(word) != _variabls.end())
    {
      if (_variabls[word].second == _keyWords["NUM"])
      {
        std::cout << stoi(_variabls[word].first);
      }
      else
      {
        std::cout << _variabls[word].first;
      }
    }
    stream >> word;
  }
}
bool nonstd::Execute::_isNumber(const std::string &value) // chaeck numbers
{
  for (int i = 0; i < value.size(); ++i)
  {
    if (value[i] > 48 && value[i] > 57)
      return false;
  }
  return true;
}
void nonstd::Execute::_doInstruction(std::string &res, std::string &arg1, std::string &arg2, std::string &oper) // check operators and do
{
  if (_variabls[res].second == "NUM")
  {
    if (oper == "+")
      _variabls[res].first = _plus(stoi(arg1), stoi(arg2));
    else if (oper == "-")
      _variabls[res].first = _minus(stoi(arg1), stoi(arg2));
    else if (oper == "*")
      _variabls[res].first = _multiplies(stoi(arg1), stoi(arg2));
    else
      _variabls[res].first = _divides(stoi(arg1), stoi(arg2));
  }
  else
  {
    _variabls[res].first = _plus(arg1, arg2);
  }
}
// Comparisons
bool nonstd::Execute::_less(const int &arg1, const int &arg2) // operator<
{
  return (arg1 < arg2);
}
bool nonstd::Execute::_greater(const int &arg1, const int &arg2) // operator>
{
  return (arg1 > arg2);
}
bool nonstd::Execute::_lessEqual(const int &arg1, const int &arg2) // operator<=
{
  return (arg1 <= arg2);
}
bool nonstd::Execute::_greaterEqual(const int &arg1, const int &arg2) // operator>=
{
  return (arg1 >= arg2);
}
bool nonstd::Execute::_equalTo(const int &arg1, const int &arg2) // operator==
{
  return (arg1 == arg2);
}
bool nonstd::Execute::_notEqualTo(const int &arg1, const int &arg2) // operator!=
{
  return (arg1 != arg2);
}
bool nonstd::Execute::_equalTo(const std::string &arg1, const std::string &arg2) // operator== for STRING
{
  return (arg1 == arg2);
}
bool nonstd::Execute::_notEqualTo(const std::string &arg1, const std::string &arg2) // operator!= for STRING
{
  return (arg1 != arg2);
}
// Arithmetic operations
std::string nonstd::Execute::_plus(const int &arg1, const int &arg2) // operator+
{
  return std::to_string(arg1 + arg2);
}
std::string nonstd::Execute::_plus(const std::string &arg1, const std::string &arg2) // operator+
{
  return std::string(arg1 + arg2);
}
std::string nonstd::Execute::_minus(const int &arg1, const int &arg2) // operator-
{
  return std::string(std::to_string(arg1 - arg2));
}
std::string nonstd::Execute::_divides(const int &arg1, const int &arg2) // operator/
{
  return std::string(std::to_string(arg1 / arg2));
}
std::string nonstd::Execute::_multiplies(const int &arg1, const int &arg2) // operator*
{
  return std::string(std::to_string(arg1 * arg2));
}