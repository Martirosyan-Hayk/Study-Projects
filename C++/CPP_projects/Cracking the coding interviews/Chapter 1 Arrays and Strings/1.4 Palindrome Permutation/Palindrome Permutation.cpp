#include <iostream>
#include <string>

bool is_palindrome_permutation(const std::string&);
int  get_char_index(char ch);
void count(const std::string&, int*);

int main()
{
	std::string line;
	std::cout << "Enter a line ";
	std::getline(std::cin, line);
	//new_line(line);
	bool x = is_palindrome_permutation(line);
	if(x)
		std::cout << "This is palindrome string :";
	else
		std::cout << "This is not palindrome string :";

	std::cout << std::boolalpha << x;
	
	return 0;
}

bool is_palindrome_permutation(const std::string& str)
{
	int frequency[26] = { 0 };
	count(str, frequency);

	bool oddAppeared = false;

	for (int i = 0; i < 26; ++i) {
		if (frequency[i] % 2 && oddAppeared) {
			return false;
		}
		else if (frequency[i] % 2 && !oddAppeared) {
			oddAppeared = true;
		}
	}
	return true;
}

int  get_char_index(char ch)
{
	int index = -1;
	if (ch >= 'a' && ch <= 'z')
	{
		index = ch - 'a';
	}
	else if (ch >= 'A' && ch <= 'Z')
	{
		index = ch - 'A';
	}
	return index;
}

void count(const std::string& line, int* co)
{
	int index;
	for (const char& c : line)
	{
		index = get_char_index(c);
		if (index != -1)
		{
			++co[index];
		}
	}
}