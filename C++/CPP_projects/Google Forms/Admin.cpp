#include "Admin.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

Admin::Admin(const std::string& rhs) 
{
	file.open(rhs, std::fstream::in | std::fstream::out | std::fstream::app);
}

Admin::~Admin()
{
	file.close();
}

void Admin::start()
{
	int size_quas;
	char true_ques;
	char num = 96;
	std::string question;
	std::string answer;
	std::cout << "Enter the number of questions" << std::endl;
	std::cin >> size_quas;

	for (int i = 0; i < size_quas; ++i)
	{
		std::cout << "Enter a questions" << std::endl;
		std::cin.get();
		std::getline(std::cin, question);
		file << i + 1 << ")    " << question << std::endl;
		std::cout << "Enter a answers or (exit)" << std::endl;
		std::cout << num <<  ")" << std::endl;
		//std::cin.get();
		std::getline(std::cin, answer);
		++num;
		while (answer != "exit")
		{
			
			file << "          " << num << ")    " << answer << std::endl;
			std::cout << "Enter a answers or (exit)" << std::endl;
			std::cout << num << ")" << std::endl;
			std::getline(std::cin, answer);
			++num;
		}
		std::cout << "Enter the correct answer font" << std::endl;
		std::cin >> true_ques;
		file << "$" << true_ques << std::endl;
		num = 96;
	}
	std::cout << "Thank you " << std::endl;
}

void Admin::set_questions()
{
	questions.push_back(ques);
}

void Admin::set_t_or_f(const int& rhs)
{
	ques.true_or_false = rhs;
}

void Admin::set_ans(const std::string& rhs)
{
	ques.answers.push_back(rhs);
}

void Admin::set_ques(const std::string& rhs)
{
	ques.question = rhs;
}