//******************************iterator implement******************************************
template<typename T>
List<T>::Iterator::Iterator() : m_current{ nullptr } 
{

}
template<typename T>
List<T>::Iterator::Iterator(List<T>::Node* item) : m_current{ item }
{

}
template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator=(List<T>::Node* cur)
{
	m_current = cur;
	return *this;
}
template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator++()
{
	if (m_current)
	{
		m_current = m_current->next;
	}
	return *this;
	
}
template<typename T>
typename List<T>::Iterator List<T>::Iterator::operator++(T)
{
	List<T>::Iterator iterator = *this;
	++* this;
	return iterator;
}
template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator--()
{
	if (m_current)
	{
		m_current = m_current->prev;
	}
	return *this;
}
template<typename T>
typename List<T>::Iterator List<T>::Iterator::operator--(T)
{
	List<T>::Iterator iterator = *this;
	--* this;
	return iterator;
}
template<typename T>
bool List<T>::Iterator::operator==(const List<T>::Iterator& cur)
{
	return m_current == cur.m_current;
}
template<typename T>
bool List<T>::Iterator::operator!=(const List<T>::Iterator& cur)
{
	return m_current != cur.m_current;
}
template<typename T>
T& List<T>::Iterator::operator*() const
{
	return m_current->item;
}

//******************************iterator function implement******************************************

template<typename T>
typename List<T>::Iterator List<T>::begin()
{
	return Iterator(m_head);
}
template<typename T>
typename const List<T>::Iterator List<T>::cbegin() const
{
	return Iterator(m_head);
}
template<typename T>
typename List<T>::Iterator List<T>::end()
{
	return Iterator(nullptr);
}
template<typename T>
typename const List<T>::Iterator List<T>::cend() const
{
	return Iterator(nullptr);
}
template<typename T>
typename List<T>::Iterator List<T>::rbegin()
{
	return Iterator(m_tail);
}
template<typename T>
typename const List<T>::Iterator List<T>::crbegin() const
{
	return Iterator(m_tail);
}
template<typename T>
typename List<T>::Iterator List<T>::rend()
{
	return Iterator(nullptr);
}
template<typename T>
typename const List<T>::Iterator List<T>::crend() const
{
	return Iterator(nullptr);
}

//**********************constructors*****************************************

template<typename T>
List<T>::List() : m_head{ nullptr }, m_tail{ nullptr }, m_asc{ nullptr }, m_desc{ nullptr }, m_size{ NULL }
{

}
template<typename T>
List<T>::List(const T& valu) : m_head{ new List<T>::Node(valu) }, m_tail{ m_head }, m_asc{ m_head }, m_desc{ m_head }, m_size{1}
{
	
}
template<typename T>
List<T>::List(const List<T>& rhs) : m_head { nullptr }, m_tail{ nullptr }, m_asc{ nullptr }, m_desc{ nullptr }, m_size{ NULL }
{

	if (rhs.m_head == nullptr)
	{
		return;
	}

	m_head = new List<T>::Node;
	m_size = rhs.m_size;
	List<T>::Node* this_tmp = m_head;
	List<T>::Node* rhs_tmp = rhs.m_head;
	while (rhs_tmp != nullptr)
	{
		this_tmp->item = rhs_tmp->item;
		if (rhs_tmp->next == nullptr)
		{
			break;
		}
		this_tmp->next = new List<T>::Node;
		this_tmp->next->prev = this_tmp;

		this_tmp = this_tmp->next;
		rhs_tmp = rhs_tmp->next;
	}
	m_tail = this_tmp;
	m_tail->next = nullptr;

	this_tmp = m_head;
	m_asc = m_head;
	m_desc = m_head;
	while (this_tmp != nullptr)
	{
		put_sorted(this_tmp);
		this_tmp = this_tmp->next;
	}

}
template<typename T>
List<T>::List(List<T>&& rhs)
{
	m_size = rhs.m_size;
	m_head = rhs.m_head;
	m_tail = rhs.m_tail;
	m_asc = rhs.m_asc;
	m_desc = rhs.m_desc;
	rhs.m_size = NULL;
	rhs.m_head = nullptr;
	rhs.m_tail = nullptr;
	rhs.m_asc = nullptr;
	rhs.m_desc = nullptr;
}
template<typename T>
List<T>::~List()
{
	List<T>::Node* cur = m_head;
	while (cur != nullptr)
	{
		cur = m_head->next;
		m_head->prev = nullptr;
		m_head->asc = nullptr;
		m_head->desc = nullptr;
		delete m_head;
		m_head = cur;
	}
	delete m_head;
}
template<typename T>
List<T>::Node::Node() :item{ NULL }, next{ nullptr }, prev{ nullptr }, asc{ nullptr }, desc{ nullptr }
{

}
template<typename T>
List<T>::Node::Node(const T& valu) : item{ valu }, next{ nullptr }, prev{ nullptr }, asc{ nullptr }, desc{ nullptr }
{

}
//**********************operators*****************************************

template<typename T>
std::ostream& operator<<(std::ostream& out, const List<T>& rhs)
{
	typename List<T>::Node* cur = rhs.m_head;
	while (cur != nullptr)
	{
		out << cur->item << " ";
		cur = cur->next;
	}
	return out;
}
template<typename T>
List<T>& List<T>::operator=(const List<T>& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}

	if (rhs.m_head == nullptr)
	{
		return *this;
	}

	m_head = new List<T>::Node;
	m_size = rhs.m_size;
	List<T>::Node* this_tmp = m_head;
	List<T>::Node* rhs_tmp = rhs.m_head;
	while (rhs_tmp != nullptr)
	{
		this_tmp->item = rhs_tmp->item;
		if (rhs_tmp->next == nullptr)
		{
			break;
		}
		this_tmp->next = new List<T>::Node;
		this_tmp->next->prev = this_tmp;

		this_tmp = this_tmp->next;
		rhs_tmp = rhs_tmp->next;
	}
	m_tail = this_tmp;
	m_tail->next = nullptr;

	this_tmp = m_head;
	m_asc = m_head;
	m_desc = m_head;
	while (this_tmp != nullptr)
	{
		put_sorted(this_tmp);
		this_tmp = this_tmp->next;
	}
	 
	return *this;
}
template<typename T>
bool List<T>::operator==(const List<T>& rhs)
{
	if (m_size != rhs.m_size)
	{
		return false;
	}

	if (this == &rhs)
	{
		return false;
	}

	List<T>::Node* this_tmp = m_head;
	List<T>::Node* rhs_tmp = rhs.m_head;
	while (this_tmp != nullptr && rhs_tmp != nullptr)
	{
		if (this_tmp->item != rhs_tmp->item)
		{
			return false;
		}
		this_tmp = this_tmp->next;
		rhs_tmp = rhs_tmp->next;
	}
	return true;
}
template<typename T>
bool List<T>::operator!=(const List<T>& rhs)
{
	return !(operator==(rhs));
}

//**********************functions*****************************************

template <typename T>
void List<T>::push_back(const T& elem)
{
	List<T>::Node* item = new Node(elem);

	if (m_head == nullptr)
	{
		m_head = item;
		m_tail = item;
	}
	put_sorted(item);
	item->prev = m_tail;
	m_tail->next = item;
	m_tail = item;
	++m_size;
}
template <typename T>
void List<T>::push_front(const T& elem)
{
	List<T>::Node* item = new Node(elem);

	if(m_head == nullptr)
	{
		m_head = item;
		m_tail = item;
	}

	put_sorted(item);
	item->next = m_head;
	m_head->prev = item;
	m_head = item;
	++m_size;
}
template <typename T>
void List<T>::pop_back()
{
	if (m_head == nullptr)
	{
		return;
	}


	List<T>::Node* cur = m_tail->prev;
	delete m_tail;
	cur->next = nullptr;
	m_tail = cur;
	--m_size;

	cur = m_head;
	m_asc = m_head;
	m_desc = m_head;
	while (cur != nullptr)
	{
		put_sorted(cur);
		cur = cur->next;
	}
	m_desc->asc = nullptr;
	m_asc->desc = nullptr;
}
template <typename T>
void List<T>::pop_front()
{
	if (m_head == nullptr)
	{
		return;
	}

	List<T>::Node* cur = m_head->next;
	delete m_head;
	m_head = cur;
	--m_size;

	cur = m_head;
	m_asc = m_head;
	m_desc = m_head;
	while (cur != nullptr)
	{
		cur->asc = nullptr;
		cur->desc = nullptr;
		put_sorted(cur);
		cur = cur->next;
	}
	if (m_desc->asc != nullptr)
	{
		m_desc->asc = nullptr;
	}
	else if (m_asc->desc != nullptr)
	{
		m_asc->desc = nullptr;
	}

}
template<typename T>
void List<T>::insert(const size_t pos, const T& value)
{
	if (pos < 0 || pos > m_size)
	{
		return;
	}

	if (pos == 0)
	{
		push_front(value);
	}
	else if (pos == m_size)
	{
		push_back(value);
	}
	else
	{
		List<T>::Node* cur = new Node(value);
		List<T>::Node* cur1 = m_head;

		for (size_t i = 0; i < pos; ++i)
		{
			cur1 = cur1->next;
		}

		put_sorted(cur);
		cur1->prev->next = cur;
		cur->prev = cur1->prev;
		cur->next = cur1;
		cur1->prev = cur;

	}
}
template<typename T>
void List<T>::erase(const size_t pos)
{
	if (pos < 0 || pos > m_size)
	{
		return;
	}

	if (pos == 0)
	{
		pop_front();
	}
	else if (pos == m_size)
	{
		pop_back();
	}
	else
	{
		//List<T>::Node* cur = new Node(value);
		List<T>::Node* cur = m_head;

		for (size_t i = 0; i < pos; ++i)
		{
			cur = cur->next;
		}

		//put_sorted(cur);
		cur->next->prev= cur->prev;
		cur->prev->next = cur->next;
		cur->desc->asc = cur->asc;
		cur->asc->desc = cur->desc;
		delete cur;
		
	}
}
template<typename T>
T& List<T>::back()
{
	return m_tail->item;
}
template<typename T>
const T& List<T>::back() const
{
	return m_tail->item;
}
template<typename T>
T& List<T>::front()
{
	return m_head->item;
}
template<typename T>
const T& List<T>::front() const
{
	return m_head->item;
}
template<typename T>
bool List<T>::bool_find(const T& value) const
{
	List<T>::Node* tmp = new Node;
	tmp = m_head;
	while (tmp != nullptr)
	{
		if (tmp->item == value)
		{
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}
template<typename T>
const size_t List<T>::find(const T& value) const
{
	size_t count = 0;
	List<T>::Node* tmp = new Node;
	tmp = m_head;
	while (tmp != nullptr)
	{
		if (tmp->item == value)
		{
			return count;
		}
		++count;
		tmp = tmp->next;
	}
	return NULL;
}
template<typename T>
bool List<T>::empty() const
{
	if (m_head != nullptr)
	{
		return false;
	}
	return true;
}
template<typename T>
void List<T>::clear()
{
	List<T>::Node* cur = m_head;
	while (cur != nullptr)
	{
		cur = m_head->next;
		m_head->prev = nullptr;
		m_head->asc = nullptr;
		m_head->desc = nullptr;
		delete m_head;
		m_head = cur;
	}
	delete m_head;
	m_size = 0;
}
template<typename T>
T& List<T>::minimum()
{
	return m_asc->item;
}
template<typename T>
T& List<T>::maximum()
{
	return m_desc->item;
}
template<typename T>
void List<T>::print_ascending()
{
	List<T>::Node* cur = m_asc;
	while (cur != nullptr)
	{

		std::cout << cur->item << " ";
		cur = cur->asc;
	}
}
template<typename T>
void List<T>::print_descending()
{
	List<T>::Node* cur = m_desc;
	while (cur != nullptr)
	{
		std::cout << cur->item << " ";
		cur = cur->desc;
	}
}
template<typename T>
const size_t List<T>::const_size() const
{
	return m_size;
}
template<typename T>
size_t List<T>::size() const
{
	List<T>::Node* cur = m_head;
	size_t count = 0;
	while (cur != nullptr)
	{
		++count;
		cur = cur->next;
	}
	return count;
}
template <typename T>
void List<T>::put_sorted(List<T>::Node* tmp)
{
		List<T>::Node* cur = m_asc;
	
		if (tmp->item >= m_desc->item)
		{
			tmp->desc = m_desc;
			m_desc->asc = tmp;
			m_desc = tmp;
			return;
		}
		if (tmp->item < m_asc->item)
		{
			tmp->asc = m_asc;
			m_asc->desc = tmp;
			m_asc = tmp;
			return;
		}
		while (cur->asc != nullptr)
		{
			if (tmp->item < cur->asc->item)
			{
				tmp->asc = cur->asc;
				cur->asc->desc = tmp;
				tmp->desc = cur;
				cur->asc = tmp;
				break;
			}
			cur = cur->asc;
		}
}
