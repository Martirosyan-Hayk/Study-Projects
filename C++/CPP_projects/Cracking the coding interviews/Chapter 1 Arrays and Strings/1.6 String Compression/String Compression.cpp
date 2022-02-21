#include <iostream>
#include <string>


std::string string_compression(const std::string&);


int main()
{
    std::string str;
    std::cout << "Enter successive letters ";
    std::getline(std::cin, str);
    std::cout << std::endl;
    std::cout << "This is counting the number of letters in the same line ";
    std::cout << string_compression(str);
    std::cout << std::endl;


    return 0;
}

std::string string_compression(const std::string& str)
{
    std::string newstr;
    int count = 1;
    for (size_t i = 0; i < str.size(); ++i)
    {
        if (str[i] != str[i + 1] && i + 1 != str.size() - 1)
        {
            newstr += str[i];
            newstr += std::to_string(count);
            count = 0;
        }
        ++count;
    }
    return newstr;
}
