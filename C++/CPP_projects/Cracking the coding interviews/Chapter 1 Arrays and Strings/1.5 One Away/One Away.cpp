#include <iostream>
#include <string>
#include <cmath>

bool one_away(const std::string&, const std::string&);

int main()
{
    std::string str1, str2;
    std::cout << "Enter the 2 strings " << std::endl;
    std::getline(std::cin, str1);
    std::getline(std::cin, str2);
    bool x = one_away(str1, str2);
    if (x)
        std::cout << str1 << " and " << str2 << " are one edit away " << std::endl;
    else
        std::cout << str1 << " and " << str2 << " are not one edit away " << std::endl;
    


	return 0;
}

bool one_away(const std::string& str1, const std::string& str2)
{
    if (std::abs(int(str1.length()) - int(str2.length())) > 1) {
        return false;
    }

    std::string smaller = str1.length() < str2.length() ? str1 : str2;
    std::string bigger = str1.length() < str2.length() ? str2 : str1;

    unsigned int i = 0, j = 0;
    bool m_bool = false;
    while (i < smaller.length() && j < bigger.length())
    {
        if (smaller[i] != bigger[j]) {
            if (m_bool) {
                return false;
            }
            m_bool = true;
            if (str1.length() == str2.length()) {
                ++i;   
            }
        }
        else {
            ++i;   
        }
        ++j;       
    }
    return true;
	
}
