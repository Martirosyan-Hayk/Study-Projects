#include <iostream>
#include "../Compiler.h"
#include "../Linker.h"
#include "../Execute.h"

using nonstd::Linker;
using nonstd::Compiler;
using nonstd::Execute; 

int main() 
{
    Linker linker;

    std::string nameFile = "example.txt";
    Compiler a(nameFile, linker);
    a.check();

    Execute exe(linker.readCompileText(), linker.readKeyWords(), linker.readVariabls());

    exe.execute();
    return 0;
}