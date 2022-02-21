#include "Student.h"
#include <fstream>
#include <string>
#include <iostream>


Student::Student(const std::string te)
{

	file_test.open(te);
	//std::string test_line;
	//while (!file_test.eof())
	//{
	//	std::getline(file_test, test_line);
	//	if (test_line[0] == '$')
	//	{
	//		answ.push_back(test_line[1]);
	//	}
	//}
}

Student::~Student()
{
	file_test.close();
}

void Student::red_test(const std::string name)
{
	std::string test_line;
	//std::string g;
	char rat;
	int i = 0;
	while (!file_test.eof())
	{
		std::getline(file_test, test_line);
		if (test_line[0] == '$')
		{
			answ.push_back(test_line[1]);
		}
	}

	file_test.close();
	file_test.open(name);
	for (int i = 0; i < answ.size(); )
	{
		std::getline(file_test, test_line);
		while (test_line[0] != '$')
		{
			std::cout << test_line << std::endl;
			std::getline(file_test, test_line);
		}

		if (test_line[0] == '$')
		{
			std::cout << "Choose the correct answer (a; b; c;...)>> ";
			std::cin.get();
			std::cin >> rat;
			ratingvec.push_back(rat);
		}

		if (answ[i] == ratingvec[i])
		{
			std::cout << "true" << std::endl;
			++i;
		}
		else
		{
			std::cout << "false" << std::endl;
			++i;
		}
	}
}

void Student::rating()
{
	int true_answ = 0;
	for (int i = 0; i < answ.size(); ++i)
	{
		if (answ[i] == ratingvec[i])
		{
			true_answ += 1;
		}
	}
	std::cout << true_answ << " / " << answ.size();
}