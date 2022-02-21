#ifndef _FORWARD_LIST_
#define _FORWARD_LIST_
#include <iostream>

template<typename T>
struct Data
{
	T value;
	Data<T>* next;
};

template<typename T>
class Forward_list
{
public:
	class Iterator
	{
	public:
		Iterator();
		Iterator(const Data<T>*);
		Iterator& operator=(Data<T>*);
		// Prefix ++ overload
		Iterator& operator++();
		// Postfix ++ overload
		Iterator operator++(int);
		bool operator!=(const Iterator&);
		T operator*();
	private:
		const Data<T>* m_Current_Data;
	};
public:
	Forward_list();
	Forward_list(const T& rhs);
	Forward_list(const Forward_list<T>& rhs);
	~Forward_list();
public:
	template<typename T>
	friend std::ostream& operator<<(std::ostream& out, const Forward_list<T>& rhs);
	Forward_list<T>& operator=(const Forward_list<T>& other);
	bool operator==(Forward_list<T>& rhs);
	bool operator!=(Forward_list<T>& rhs);
public:
	void push_front(const T& value);
	void push_back(const T& value);
	void pop_front();
	void pop_back();
	void insert(const int pos, const T& value);
	void erase(const int pos);
	void remove(const T& value);
	Iterator begin();
	Iterator end();
	const Iterator cbegin() const;
	const Iterator cend() const;
	T& front();
	const T& front() const;
	T& back();
	const T& back() const;
	int find(const T& value);
	int index(const T& value);
	bool empty() const;
	void clear();
private:
	Data<T>* m_head;
	int size() const;
	int m_size;

};

//Iterator inplementation********************************************************************************************

template<typename T>
Forward_list<T>::Iterator::Iterator() : m_Current_Data{ nullptr }
{
}
template<typename T>
Forward_list<T>::Iterator::Iterator(const Data<T>* data) : m_Current_Data{ data }
{
}
template<typename T>
typename Forward_list<T>::Iterator& Forward_list<T>::Iterator::operator=(Data<T>* data)
{
	m_Current_Data = data;
	return *this;
}
// Prefix ++ overload
template<typename T>
typename Forward_list<T>::Iterator& Forward_list<T>::Iterator::operator++()
{
	if (m_Current_Data)
	{
		m_Current_Data = m_Current_Data->next;
	}
	return *this;
}
// Postfix ++ overload
template<typename T>
typename Forward_list<T>::Iterator Forward_list<T>::Iterator::operator++(int)
{
	Forward_list<T>::Iterator iterator = *this;
	++* this;
	return iterator;
}
template<typename T>
bool Forward_list<T>::Iterator::operator!=(const Iterator& iterator)
{
	return m_Current_Data != iterator.m_Current_Data;
}
template<typename T>
T Forward_list<T>::Iterator::operator*()
{
	return m_Current_Data->value;
}
//constructors********************************************************************************************************

template<typename T>
Forward_list<T>::Forward_list() : m_head{ nullptr }, m_size{ 0 }
{

}

template<typename T>
Forward_list<T>::Forward_list(const T& rhs) : m_head{ new Data<T> }, m_size{ 1 }
{
	m_head->value = rhs;
	m_head->next = nullptr;
}

template<typename T>
Forward_list<T>::Forward_list(const Forward_list<T>& rhs) : m_head{ nullptr }, m_size{ 0 }
{
	if (rhs.m_head == nullptr)
	{
		return;
	}

	m_head = new Data<T>;
	m_size = rhs.m_size;
	Data<T>* this_tmp = m_head;
	Data<T>* rhs_tmp = rhs.m_head;

	while (rhs_tmp != nullptr)
	{
		this_tmp->value = rhs_tmp->value;
		if (rhs_tmp->next == nullptr)
		{
			break;
		}
		this_tmp->next = new Data<T>;

		this_tmp = this_tmp->next;
		rhs_tmp = rhs_tmp->next;
	}
	this_tmp->next = nullptr;

}

template<typename T>
Forward_list<T>::~Forward_list()
{
	Data<T>* tmp = m_head;
	while (tmp != nullptr) {
		tmp = m_head->next;
		delete m_head;
		m_head = tmp;
	}
	delete m_head;
}

//operators**********************************************************************************************************

template<typename T>
std::ostream& operator<<(std::ostream& out, const Forward_list<T>& rhs)
{
	Data<T>* tmp = rhs.m_head;

	while (tmp != nullptr)
	{
		out << tmp->value;
		tmp = tmp->next;
	}
	return out;
}

template<typename T>
bool Forward_list<T>::operator==(Forward_list<T>& rhs)
{
	if (m_size != rhs.m_size)
	{
		return false;
	}
	if (this == &rhs)
	{
		return false;
	}

	Data<T>* tmp = m_head;
	Data<T>* rhs_tmp = rhs.m_head;
	while (tmp != nullptr && rhs_tmp != nullptr)
	{
		if (tmp->value != rhs_tmp->value)
		{
			return false;
		}
		tmp = tmp->next;
		rhs_tmp = rhs_tmp->next;
	}
	return true;
}

template<typename T>
bool Forward_list<T>::operator!=(Forward_list<T>& rhs)
{
	return !(operator==(rhs));
}

template<typename T>
Forward_list<T>& Forward_list<T>::operator=(const Forward_list<T>& other)
{
	if (this == &other)
	{
		return *this;
	}

	if (other.m_head == nullptr)
	{
		return *this;
	}

	m_head = new Data<T>;
	m_size = other.m_size;
	Data<T>* this_tmp = m_head;
	Data<T>* rhs_tmp = other.m_head;

	while (rhs_tmp != nullptr)
	{
		this_tmp->value = rhs_tmp->value;
		if (rhs_tmp->next == nullptr)
		{
			break;
		}
		this_tmp->next = new Data<T>;

		this_tmp = this_tmp->next;
		rhs_tmp = rhs_tmp->next;
	}
	this_tmp->next = nullptr;

	return *this;
}


//functions**********************************************************************************************************

template<typename T>
void Forward_list<T>::push_front(const T& value)
{
	Data<T>* data = new Data<T>;
	data->value = value;

	if (m_head == nullptr)
	{
		m_head = data;
		data->next = nullptr;
	}

	data->next = m_head;
	m_head = data;
	++m_size;
}
template<typename T>
void Forward_list<T>::push_back(const T& value)
{
	Data<T>* data = new Data<T>;
	data->value = value;
	data->next = nullptr;

	if (m_head == nullptr)
	{
		m_head = data;
		++m_size;
	}

	Data<T>* tmp = new Data<T>;
	tmp = m_head;
	while (tmp->next != nullptr)
	{
		tmp = tmp->next;
	}
	tmp->next = data;
	++m_size;
}
template<typename T>
void Forward_list<T>::pop_front()
{
	if (m_head == nullptr)
	{
		return;
	}
	Data<T>* tmp = m_head->next;
	delete m_head;
	m_head = tmp;
	--m_size;
}
template<typename T>
void Forward_list<T>::pop_back()
{
	if (m_head == nullptr)
	{
		return;
	}

	Data<T>* tmp = new Data<T>;
	tmp = m_head->next;
	Data<T>* ttmp = new Data<T>;
	ttmp = m_head;
	while (tmp->next != nullptr)
	{
		tmp = tmp->next;
		ttmp = ttmp->next;
	}
	delete tmp;
	ttmp->next = nullptr;
	--m_size;
}
template<typename T>
T& Forward_list<T>::front()
{
	return m_head->value;
}
template<typename T>
const T& Forward_list<T>::front() const
{
	return m_head->value;
}
template<typename T>
T& Forward_list<T>::back()
{
	Data<T>* tmp = m_head;
	while (tmp != nullptr)
	{
		if (tmp->next == nullptr)
		{
			return tmp->value;
		}
		tmp = tmp->next;
	}
}
template<typename T>
const T& Forward_list<T>::back() const
{
	Data<T>* tmp = m_head;
	while (tmp != nullptr)
	{
		if (tmp->next == nullptr)
		{
			return tmp->value;
		}
		tmp = tmp->next;
	}
}
template<typename T>
int Forward_list<T>::find(const T& value)
{
	int count = 0;
	Data<T>* tmp = new Data<T>;
	tmp = m_head;
	while (tmp != nullptr)
	{
		if (tmp->value == value)
		{
			++count;
		}
		tmp = tmp->next;
	}
	return count;
}
template<typename T>
int  Forward_list<T>::index(const T& value)
{
	int index = 1;
	Data<T>* tmp = new Data<T>;
	tmp = m_head;
	while (tmp != nullptr)
	{
		if (tmp->value == value)
		{
			return index;
		}
		++index;
		tmp = tmp->next;
	}
	index = 0;
	return index;
}
template<typename T>
bool Forward_list<T>::empty() const
{
	if (m_head != nullptr)
	{
		return false;
	}
	return true;
}
template<typename T>
void Forward_list<T>::clear()
{
	Data<T>* tmp = m_head;
	while (tmp != nullptr) {
		tmp = m_head->next;
		delete m_head;
		m_head = tmp;
	}
	m_head = nullptr;
	m_size = 0;
}
template<typename T>
void Forward_list<T>::insert(const int pos, const T& value)
{
	if (pos < 0 || pos > m_size)
	{
		return;
	}
	else if (pos == 0)
	{
		push_front(value);
	}
	else if (pos == m_size)
	{
		push_back(value);
	}
	else
	{
		Data<T>* tmp = m_head;
		Data<T>* data = new Data<T>;
		data->value = value;
		data->next = nullptr;

		for (int i = 0; i <= pos; ++i)
		{
			if (i == pos)
			{
				data->next = tmp;
			}
			tmp = tmp->next;
		}
		tmp = m_head;

		for (int i = 0; i <= pos; ++i)
		{
			if (i == pos - 1)
			{
				tmp->next = data;
			}
			tmp = tmp->next;
		}

		++m_size;
	}
}
template<typename T>
void Forward_list<T>::erase(const int pos)
{
	if (pos <= 0 || pos > m_size)
	{
		return;
	}
	else if (pos == 1)
	{
		pop_front();
	}
	else if (pos == m_size)
	{
		pop_back();
	}
	else
	{
		Data<T>* tmp = m_head;
		Data<T>* data = new Data<T>;

		data->next = nullptr;

		for (int i = 0; i < pos; ++i)
		{
			if (i == pos - 1)
			{
				data = tmp->next;
				delete tmp;
				break;
			}
			tmp = tmp->next;
		}

		tmp = m_head;

		for (int i = 0; i < pos; ++i)
		{
			if (i == pos - 2)
			{
				tmp->next = data;
				break;
			}
			tmp = tmp->next;
		}

		--m_size;
	}
}
template<typename T>
void Forward_list<T>::remove(const T& value)
{
	int count = find(value);

	if (count == 0)
	{
		return;
	}

	int index_lm = index(value);

	for (int i = 0; i < count; ++i)
	{
		erase(index_lm);
		index_lm = index(value);
	}



}
template<typename T>
typename Forward_list<T>::Iterator Forward_list<T>::begin()
{
	return Iterator(m_head);
}
template<typename T>
typename Forward_list<T>::Iterator Forward_list<T>::end()
{
	return Iterator(nullptr);
}
template<typename T>
typename const Forward_list<T>::Iterator Forward_list<T>::cbegin() const
{
	return Iterator(m_head);
}
template<typename T>
typename const Forward_list<T>::Iterator Forward_list<T>::cend() const
{
	return Iterator(nullptr);
}
template<typename T>
int  Forward_list<T>::size() const
{
	return m_size;
}

#endif  //_FORWARD_LIST_



