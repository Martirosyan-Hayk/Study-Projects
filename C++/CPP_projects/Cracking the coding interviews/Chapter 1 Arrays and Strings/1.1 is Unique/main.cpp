#include <iostream>
#include <string>
#include <vector>
#include <bitset>

bool is_unique(const std::string&);
bool is_unique1(const std::string&);
bool is_unique2(const std::string&);

int main()
{
    std::vector<std::string> str;
    std::string line ;
    std::cout << "Enter strings (exit) " << std::endl;
    std::getline(std::cin, line);
    while (line != "exit")
    {
        str.push_back(line);
        std::getline(std::cin, line);
    }

    for (auto word : str)
    {
        std::cout << word << " : " << std::boolalpha << is_unique(word) << std::endl;
    }
    std::cout << std::endl;
    for (auto word : str)
    {
        std::cout << word << " : " << std::boolalpha << is_unique1(word) << std::endl;
    }

    std::cout << std::endl;
    for (auto word : str)
    {
        std::cout << word << " : " << std::boolalpha << is_unique2(word) << std::endl;
    }

    return 0;
}

bool is_unique(const std::string& word)
{
    if (word.length() > 128)
    {
        return false;
    }

    bool* bool_array = new bool[128]{ 0 };

    for (size_t i = 0; i < word.length(); ++i)
    {
        int val = word[i];
        if (bool_array[val])
        {
            return false;
        }
        bool_array[val] = true;
    }
    return true;
}

bool is_unique1(const std::string& word)
{
    std::bitset<256> bool_array;

    for (size_t i = 0; i < word.length(); ++i)
    {
        int val = word[i];
        if (bool_array.test(val))
        {
            return false;
        }
        bool_array.set(val,true);
    }
    return true;
}

bool is_unique2(const std::string& word)
{
    unsigned int tuble = 0;
    for (auto ch : word)
    {
        if (tuble & (1 << (ch - 'a')))
        {
            return false;
        }
        tuble |= (1 << (ch - 'a'));
    }
    return true;
}

