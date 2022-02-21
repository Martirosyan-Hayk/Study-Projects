#ifndef _ADMIN_
#define _ADMIN_
#include <vector>
#include <string>
#include <fstream>


struct Question
{
	std::string question;
	std::vector<std::string> answers;
	int true_or_false = 0;
};

class Admin
{
public:
	Admin(const std::string& rhs);
	~Admin();
	void start();
	void set_questions();
	void set_t_or_f(const int& rhs);
	void set_ans(const std::string& rhs);
	void set_ques(const std::string& rhs);
private:
	std::fstream file;
	Question ques;
	std::vector<Question> questions;
};

#endif // _ADMIN_

