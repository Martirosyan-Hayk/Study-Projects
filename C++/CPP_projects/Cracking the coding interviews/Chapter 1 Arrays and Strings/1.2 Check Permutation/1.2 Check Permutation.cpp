#include <iostream>
#include <string>


bool check_permutation( std::string&, std::string&);
std::string sorting_string(std::string&);

int main()
{
    std::string str1;
    std::string str2;
    std::cout << "Enter 2 strings" << std::endl;
    std::getline(std::cin, str1);
    //std::cin.get();
    std::getline(std::cin, str2);

    std::cout << "Check Permutation " << std::boolalpha << check_permutation(str1, str2);
    

    return 0;
}

std::string sorting_string(std::string& str)
{
    
    for (size_t i = 0; i < str.size() - 1; ++i)
    {
        for (size_t j = 0; j < str.size() - i - 1; ++j)
        {
            if (str[j] > str[j+1])
            {
                char tmp = str[j + 1];
                str[j+1] = str[j];
                str[j] = tmp;
            }
        }
    }
    return str;
}


bool check_permutation(std::string& word1, std::string& word2)
{
    if (word1.size() != word2.size())
    {
        return false;
    }
  
    return (sorting_string(word1) == sorting_string(word2));
  
}
