#include "myString.h"

//ctors************************************************************


myString::myString() : m_line_ptr{ nullptr }, m_size{ 0 }   //ctor
{

}

myString::myString(const char* str)   //ctor whit parametrs
{
	m_size = strlen(str);
	m_line_ptr = new char[m_size + 1];
	for (size_t i = 0; i < m_size; ++i)
	{
		m_line_ptr[i] = str[i];
	}
	m_line_ptr[m_size] = '\0';
}

myString::myString(const myString& rhs)   //copy ctor
{
	if (this->m_line_ptr != nullptr)
	{
		delete[] m_line_ptr;
	}
	m_size = strlen(rhs.m_line_ptr);
	m_line_ptr = new char[m_size + 1];
	for (size_t i = 0; i < m_size; ++i)
	{
		m_line_ptr[i] = rhs.m_line_ptr[i];
	}
	m_line_ptr[m_size] = '\0';


}

myString::myString(myString&& rhs)  noexcept //move ctor
{
	m_size = rhs.m_size;
	m_line_ptr = rhs.m_line_ptr;
	rhs.m_size = 0;
	rhs.m_line_ptr = nullptr;
}

myString::~myString()   //dtor
{
	delete[] m_line_ptr;
}

//operators**********************************************************************************

std::istream& operator>>(std::istream& in, myString& rhs)
{
	char* tmp = new char[10001];
	in.getline(tmp, 10000);
	delete[] rhs.m_line_ptr;
	rhs.m_size = strlen(tmp);
	rhs.m_line_ptr = new char[rhs.m_size + 1];	
	for (size_t i = 0; i < rhs.m_size; ++i)
	{
		rhs.m_line_ptr[i] = tmp[i];
	}
	rhs.m_line_ptr[rhs.m_size] = '\0';
	delete[] tmp;

	return in;
}

std::ostream& operator<<(std::ostream& os, const myString& rhs)
{
	for (size_t i = 0; i < rhs.m_size; ++i)
	{
		os << rhs.m_line_ptr[i];
	}
	return os;
}

char& myString::operator[](const size_t ind)  //op[]
{
	return m_line_ptr[ind];
}

myString& myString::operator=(const myString& rhs)   //assignment (op=)
{
	if (this == &rhs)
	{
		return *this;
	}

	if (this->m_line_ptr != nullptr)
	{
		delete[] m_line_ptr;
	}

	m_size = strlen(rhs.m_line_ptr);
	m_line_ptr = new char[m_size + 1];
	for (size_t i = 0; i < m_size; ++i)
	{
		m_line_ptr[i] = rhs.m_line_ptr[i];
	}
	m_line_ptr[m_size] = '\0';

	return *this;

}

myString& myString::operator=(myString&& oth) noexcept   //move assignment (op=)
{
	m_size = oth.m_size;
	m_line_ptr = oth.m_line_ptr;
	oth.m_size = 0;
	oth.m_line_ptr = nullptr;

	return *this;
}

myString operator+(const myString& lhs, const myString& rhs)
{
	myString result;
	result.m_size = strlen(lhs.m_line_ptr) + strlen(rhs.m_line_ptr);
	result.m_line_ptr = new char[result.m_size + 1];
	size_t i = 0;
	for (; i < lhs.m_size; ++i)
	{
		result.m_line_ptr[i] = lhs.m_line_ptr[i];
	}
	for (size_t j = 0; j < rhs.m_size; ++j, ++i)
	{
		result.m_line_ptr[i] = rhs.m_line_ptr[j];
	}
	result.m_line_ptr[result.m_size] = '\0';

	return result;

}


myString operator+=(myString& lhs, const myString& rhs)    //op(+=)
{
	lhs.m_size = lhs.m_size + rhs.m_size;
	char* tmp = new char[lhs.m_size + 1];
	size_t i = 0;
	for (; i < strlen(lhs.m_line_ptr); ++i)
	{
		tmp[i] = lhs.m_line_ptr[i];
	}
	for (size_t j = 0; j < rhs.m_size; ++j, ++i)
	{
		tmp[i] = rhs.m_line_ptr[j];
	}
	tmp[lhs.m_size] = '\0';
	delete[] lhs.m_line_ptr;
	lhs.m_line_ptr = tmp;

	return lhs;

}

bool operator==(const myString& lhs, const myString& rhs)   //op(==)
{
	if (lhs.m_size != rhs.m_size)
	{
		return false;
	}

	for (size_t i = 0; i < lhs.m_size; ++i)
	{
		if (lhs.m_line_ptr[i] != rhs.m_line_ptr[i])
		{
			return false;
		}
	}
	return true;

}

bool operator!=(const myString& lhs, const myString& rhs)
{
	return !(operator==(lhs, rhs));
}

// fanction*************************************************************************


void myString::push_back(const char rhs)
{
	++m_size;
	char* tmp = new char[m_size + 1];
	for (size_t i = 0; i < m_size - 1; ++i)
	{
		tmp[i] = m_line_ptr[i];
	}
	tmp[m_size - 1] = rhs;
	tmp[m_size] = '\0';
	delete[] m_line_ptr;
	m_line_ptr = tmp;
}

void myString::push_front(const char rhs)
{
	++m_size;
	char* tmp = new char[m_size + 1];
	tmp[0] = rhs;
	for (size_t i = 0; i < m_size - 1; ++i)
	{
		tmp[i + 1] = m_line_ptr[i];
	}
	tmp[m_size] = '\0';
	delete[] m_line_ptr;
	m_line_ptr = tmp;
}

void myString::pop_back()
{
	--m_size;
	char* tmp = new char[m_size + 1];
	for (size_t i = 0; i < m_size; ++i)
	{
		tmp[i] = m_line_ptr[i];
	}
	tmp[m_size] = '\0';
	delete[] m_line_ptr;
	m_line_ptr = tmp;
}

void myString::pop_front()
{
	--m_size;
	char* tmp = new char[m_size + 1];
	for (size_t i = 1; i <= m_size; ++i)
	{
		tmp[i - 1] = m_line_ptr[i];
	}
	tmp[m_size] = '\0';
	delete[] m_line_ptr;
	m_line_ptr = tmp;
}

size_t myString::size()
{
	return m_size;
}

size_t myString::strlen(const char* len)
{
	size_t lenght = 0;
	for (; len[lenght] != '\0'; )
	{
		++lenght;
	}

	return lenght;
}

void myString::insert(size_t index, char ch)
{
	if (index > m_size || index < 0)
	{
		return;
	}
	else if (index == 0)
	{
		push_front(ch);
	}
	else if (index == m_size)
	{
		push_back(ch);
	}
	else
	{
		++m_size;
		char* tmp = new char[m_size + 1];
		for (size_t i = 0; i < index - 1; ++i)
		{
			tmp[i] = m_line_ptr[i];
		}
		tmp[index - 1] = ch;
		for (size_t i = index; i < m_size; ++i)
		{
			tmp[i] = m_line_ptr[i - 1];
		}
		delete[] m_line_ptr;
		m_line_ptr = tmp;
	}
}