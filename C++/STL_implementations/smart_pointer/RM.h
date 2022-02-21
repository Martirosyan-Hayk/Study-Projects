#ifndef _RESOURCEMENEGMENT_
#define  _RESOURCEMENEGMENT_

template<typename T>
class RM
{
public:
	RM();
	RM(T* ptr);
	~RM();
public:
	RM<T>& operator=(T* ptr);
	T& operator[](size_t i) const;
	T operator*() const;
	T* operator->() const;
public:
	T* get() const;
private:
	T* m_ptr;
};


//constructors******************************************
template<typename T>
RM<T>::RM() : m_ptr{ nullptr }
{

}

template<typename T>
RM<T>::RM(T* ptr) : m_ptr{ ptr }
{

}

template<typename T>
RM<T>::~RM()
{
	delete m_ptr;
}

//operators*********************

template<typename T>
RM<T>& RM<T>::operator=(T* ptr)
{
	if (this == ptr)
	{
		return *this;
	}

	m_ptr = ptr;
	return *this;
}
template<typename T>
T& RM<T>::operator[](size_t i) const
{
	return m_ptr[i];
}
template<typename T>
T RM<T>::operator*() const
{
	return *m_ptr;
}
template<typename T>
T* RM<T>::operator->() const
{
	return m_ptr;
}

//function *********************
template<typename T>
T* RM<T>::get() const
{
	if (m_ptr == nullptr)
	{
		return nullptr;
	}
	return m_ptr;
}


#endif // !_RESOURCEMENEGMENT_

