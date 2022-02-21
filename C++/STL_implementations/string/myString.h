#ifndef _STRING_
#define _STRING_
#include <ostream>
#include <istream>

class myString
{
public:
	myString();
	myString(const char* str);
	myString(const myString& rhs);
	myString(myString&& rhs) noexcept;
	~myString();
public:
	char& operator[](const size_t ind);
	friend std::ostream& operator<<(std::ostream& os, const myString& rhs);
	friend std::istream& operator>>(std::istream& in, myString& rhs);
	myString& operator=(const myString& rhs);
	myString& operator=(myString&& oth) noexcept;
	friend myString operator+(const myString& lhs, const myString& rhs);
    friend myString operator+=(myString& lhs, const myString& rhs);
	friend bool operator==(const myString& lhs, const myString& rhs);
	friend bool operator!=(const myString& lhs, const myString& rhs);
public:
	void push_back(const char rhs);
	void push_front(const char rhs);
	void pop_back();
	void pop_front();
	size_t size();
	size_t strlen(const char* len);
	void insert(size_t index, char ch);

private:
	char* m_line_ptr;
	size_t m_size;

};

#endif //_STRING_
