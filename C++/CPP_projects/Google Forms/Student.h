#ifndef _STUDENT_
#define _STUDENT_
#include <fstream>
#include <string>
#include <vector>
class Student
{
public:
	Student(const std::string te);
	~Student();
	void red_test(const std::string name);
	void rating();
private:
	std::fstream file_test;
	std::vector<char> ratingvec;
	std::vector<char> answ;
};

#endif //_STUDENT_
