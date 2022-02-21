#ifndef _LIST_
#define _LIST_
#include<iostream>

template<typename T>
class List
{
private:
	struct Node
	{
		Node();
		Node(const T& valu);
		T item;
		List<T>::Node* next;
		List<T>::Node* prev;
		List<T>::Node* asc;
		List<T>::Node* desc;
	};
public:
	class Iterator
	{
	public:
		Iterator();
		Iterator(List<T>::Node*);
		Iterator& operator=(List<T>::Node*);
		// Prefix ++ overload
		Iterator& operator++();
		// Postfix ++ overload
		Iterator operator++(T);
		// Prefix ++ overload
		Iterator& operator--();
		// Postfix ++ overload
		Iterator operator--(T);
		bool operator==(const List<T>::Iterator&);
	    bool operator!=(const List<T>::Iterator&);
		T& operator*() const;
	private:
		 Node* m_current;
	};
public:
	List<T>::Iterator begin();
	const List<T>::Iterator cbegin() const;
	List<T>::Iterator end();
	const List<T>::Iterator cend() const;
	List<T>::Iterator rbegin();
	const List<T>::Iterator crbegin() const;
	List<T>::Iterator rend();
	const List<T>::Iterator crend() const;
public:
	List();
	List(const T&);
	List(const List<T>&);
	List(List<T>&&);
	~List();
public:
	template<typename T>
	friend std::ostream& operator<<(std::ostream&, const List<T>&);
	List<T>& operator=(const List<T>&);
	bool operator==(const List<T>&);
	bool operator!=(const List<T>&);
public:
	void push_back(const T&);
	void push_front(const T&);
	void pop_back();
	void pop_front();
	void insert(const size_t, const T&);
	void erase(const size_t);
	T& back();
	const T& back() const;
	T& front();
	const T& front() const;
	bool bool_find(const T&) const;
	const size_t find(const T&) const;
	bool empty() const;
	void clear();
	T& minimum();
	T& maximum();
	void print_ascending();
	void print_descending();
	size_t size() const;
	const size_t const_size() const;
private:
	Node* m_head;
	Node* m_tail;
	Node* m_asc;
	Node* m_desc;
	size_t m_size;
	void put_sorted(List<T>::Node*);;

};
#include"List.tpp"


#endif  //_LIST_


