#include <vector>
#include <string>


typedef std::vector<std::string> constentsOfFile;                                // saves the contents of the file
typedef std::map<std::string, std::string> keyWordsMap;                          // stores keywords
typedef std::map<std::string, std::pair<std::string, std::string> > variablsMap; // stores variables

nonstd::Linker::Linker() // constructor
    : _compileText{},
      _keyWords{},
      _variabls{}
{
}
nonstd::Linker::~Linker() // destructor
{
}

// public functions
void nonstd::Linker::writeData(const constentsOfFile &compileText, const keyWordsMap &keyWords, const variablsMap &variabls) // transfers data from the compiler
{
    _compileText = compileText;
    _keyWords = keyWords;
    _variabls = variabls;
}
// public function
const constentsOfFile nonstd::Linker::readCompileText() const // returned contents of the vectro
{
    return _compileText;
}
const keyWordsMap nonstd::Linker::readKeyWords() const // returned keywords
{
    return _keyWords;
}
const variablsMap nonstd::Linker::readVariabls() const // returned variabls
{
    return _variabls;
}