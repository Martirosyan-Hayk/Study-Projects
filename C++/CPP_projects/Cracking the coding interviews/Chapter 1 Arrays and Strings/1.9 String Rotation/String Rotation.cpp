#include <iostream>
#include <string>

bool is_rotation(std::string&, std::string&);


int main()
{
	std::string s1, s2;
	std::cout << "Enter string 1 : ";
	std::cin >> s1;
	std::cout << "Enter string 2 : ";
	std::cin >> s2;
	if (is_rotation(s1, s2)) {
		std::cout << "Yes! " << s2 << " is rotation of " << s1 << std::endl;
	}
	else {
		std::cout << "No! " << s2 << " is not a rotation of " << s1 << std::endl;
	}
	return 0;
}

bool is_rotation(std::string& str1, std::string& str2)
{
	if (str1.length() == 0 || str1.length() != str2.length())
	{
		return false;
	}

	std::string strstr = str1 + str1;
	if (strstr.find(str2) != std::string::npos)
		return true;
	else
		return false;
}