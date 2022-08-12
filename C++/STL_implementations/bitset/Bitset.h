#ifndef _BITSET_
#define  _BITSET_
#include <iostream>


template<std::size_t N>
class Bitset
{
public:
	Bitset();
	Bitset(unsigned int num);
	~Bitset();
public:
	template<size_t N>
	friend std::ostream& operator<<(std::ostream& out, const Bitset<N>& rhs);  
public:
	bool operator==(const Bitset<N>& rhs) const;
	bool operator!=(const Bitset<N>& rhs) const;
	Bitset& operator&=(const Bitset& other);   
	Bitset& operator|=(const Bitset& other);
	Bitset& operator^=(const Bitset& other);
	Bitset<N> operator&(const Bitset<N>& rhs);
	Bitset<N> operator|(const Bitset<N>& rhs);
	Bitset<N> operator^(const Bitset<N>& rhs);
	Bitset<N>& operator<<=(std::size_t pos);     
    	Bitset<N>& operator>>=(std::size_t pos);
public:
	Bitset<N>& set();
	Bitset<N> & set(std::size_t pos, bool value = true);
	Bitset& reset();               
	Bitset& reset(std::size_t pos);
	Bitset<N>& flip();             	
	Bitset<N>& flip(size_t pos); 
	unsigned long to_ulong() const;
	unsigned long long to_ullong() const;
	unsigned int size();
private:
	int set_array_size(const std::size_t n);
	void set_ind_pos();
	unsigned int* m_array;
	unsigned int m_array_index;
	unsigned int positon;
	unsigned int bits_size;
	unsigned int m_num;

};

#include "Bitset.tpp"


#endif // !_BITSET_

