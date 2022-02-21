#include <iostream>
#include <string>

void URLif(std::string&);

int main()
{
    std::string str;
    std::cout << "Enter the line ";
    std::getline(std::cin, str);
    URLif(str);
    std::cout << "(space) == %20  : " << str;

    return 0;
}

void URLif(std::string& line)
{
    std::string newline;
    for (size_t i = 0; i < line.size(); ++i)
    {
        if (line[i] != ' ')
        {
            newline += line[i];
        }
        else
        {
            newline += "%20";
        }
    }
    line = newline;
    
}
