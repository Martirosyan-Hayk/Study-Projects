
//canstruktors******************************************************************************************

template<std::size_t N>
Bitset<N>::Bitset() : m_array{ new unsigned int[set_array_size(N)]{0} }, bits_size{N}
{
	m_array_index = N / (sizeof(int) * 8) + 1;
	positon = N % (sizeof(int) * 8);
}



template<std::size_t N>
Bitset<N>::Bitset(unsigned int num) : m_array{ new unsigned int[set_array_size(N)]{0} }, bits_size{ N }, m_num{num}
{
	m_array_index = N / (sizeof(int) * 8) + 1;
	positon = N % (sizeof(int) * 8);
	m_array[0] = num;
}

template<std::size_t N>
Bitset<N>::~Bitset()
{
	delete[] m_array;
}

//operators*********************************************************************************************
template<std::size_t N>
std::ostream& operator<<(std::ostream& out, const Bitset<N>& rhs)
{

	int esim = rhs.bits_size;
	int ix = rhs.bits_size % (sizeof(int) * 8);

		for (int j = rhs.m_array_index - 1; j >= 0; --j)
		{
			if (j == rhs.m_array_index - 1 && esim < (sizeof(int) * 8))
			{
				for (int i = esim - 1; i >= 0; --i)
				{
					bool x = (rhs.m_array[j] & (1 << i));
					out << x;
				}
			}
			if (j == 0 && esim >= (sizeof(int) * 8))
			{
				for (int i = (sizeof(int) * 8) - 1; i >= 0; --i)
				{
					bool x = (rhs.m_array[j] & (1 << i));
					out << x;
				}
			}
			else if (esim >= (sizeof(int) * 8))
			{
				for (ix -= 1; ix >= 0; --ix)
				{
					bool x = (rhs.m_array[j] & (1 << ix));
					out << x;
				}
				ix = (sizeof(int) * 8);
			}
		}

	return out;
}


template<size_t N>
Bitset<N> Bitset<N>::operator&(const Bitset<N>& rhs)
{
	Bitset<N> result(this->m_num);
	for (size_t i = 0; i < this->m_array_index; i++)
	{
		result.m_array[i] &= rhs.m_array[i];
	}

	return result;

}
template<size_t N>
Bitset<N> Bitset<N>::operator|(const Bitset<N>& rhs)
{
	Bitset<N> result(this->m_num);
	for (size_t i = 0; i < this->m_array_index; i++)
	{
		result.m_array[i] |= rhs.m_array[i];
	}

	return result;
}

template<size_t N>
Bitset<N> Bitset<N>::operator^(const Bitset<N>& rhs)
{
	Bitset<N> result(this->m_num);
	for (size_t i = 0; i < this->m_array_index; i++)
	{
		result.m_array[i] ^= rhs.m_array[i];
	}

	return result;
}

template<size_t N>
bool Bitset<N>::operator==(const Bitset<N>& rhs) const
{
	if (rhs.m_array_index == 0)
	{
		for (std::size_t i = 0; i <= rhs.m_array_index; ++i)
		{
			for (std::size_t j = (sizeof(int) * 8); j > 0; --j)
			{
				if ((m_array[i] & (1 << j - 1)) != (rhs.m_array[i] & (1 << (j - 1))))
				{
					return false;
				}
			}
		}
	}
	else if ((rhs.m_array_index % 2) == 0 && rhs.positon == 0)
	{
		for (std::size_t i = 0; i < rhs.m_array_index; ++i)
		{
			for (std::size_t j = (sizeof(int) * 8); j > 0; --j)
			{
				if ((m_array[i] & (1 << j - 1)) != (rhs.m_array[i] & (1 << (j - 1))))
				{
					return false;
				}
			}
		}
	}
	else
	{
		for (std::size_t i = 0; i < rhs.m_array_index; ++i)
		{
			for (std::size_t j = (sizeof(int) * 8); j > 0; --j)
			{
				if ((m_array[i] & (1 << j - 1)) != (rhs.m_array[i] & (1 << (j - 1))))
				{
					return false;
				}
			}
		}
		for (std::size_t j = positon; j > 0; --j)
		{
			if ((m_array[m_array_index - 1] & (1 << j - 1)) != (rhs.m_array[m_array_index - 1] & (1 <<( j - 1))))
			{
				return false;
			}
		}
	}
	return true;
}

template<size_t N>
bool Bitset<N>::operator!=(const Bitset<N>& rhs) const
{
	return !(operator==(rhs));
}

template<rsize_t N>
Bitset<N>& Bitset<N>::operator&=(const Bitset<N>& other)
{
	for (int i = 0; i < m_array_index; ++i)
	{
		m_array[i] &= other.m_array[i];
	}
	return *this;
}

template<rsize_t N>
Bitset<N>& Bitset<N>::operator|=(const Bitset<N>& other)
{
	for (int i = 0; i < m_array_index; ++i)
	{
		m_array[i] |= other.m_array[i];
	}
	return *this;
}

template<rsize_t N>
Bitset<N>& Bitset<N>::operator^=(const Bitset<N>& other)
{
	for (int i = 0; i < m_array_index; ++i)
	{
		m_array[i] ^= other.m_array[i];
	}
	return *this;
}

template<size_t N>
Bitset<N>& Bitset<N>::operator<<=(std::size_t pos)
{
	for (int j = m_array_index - 1; j >= 0; --j)
	{
		if (j == 0)
		{
			(m_array[j] <<=  pos);
		}

		if (j > 0)
		{
			(m_array[j] <<= (sizeof(int) * 8) - 1);
		}
	}
	return *this;
}

template<size_t N>
Bitset<N>& Bitset<N>::operator>>=(std::size_t pos)
{
	for (int j = m_array_index - 1; j >= 0; --j)
	{
		if (j == 0)
		{
			(m_array[j] >>= pos);
		}

		if (j > 0)
		{
			(m_array[j] >>= (sizeof(int) * 8) - 1);
		}
	}
	return *this;
}


//funcion***********************************************************************************************
template <size_t N>
int Bitset<N>::set_array_size(const std::size_t n)
{
	if (N <= 32)
	{
		return 1;
	}
	else if (N % (sizeof(int) * 8) == 0)
	{
		return N / (sizeof(int) * 8);
	}
	else
	{
		return (N / (sizeof(int) * 8)) + 1;
	}
}

template <size_t N>
void Bitset<N>::set_ind_pos()
{
	m_array_index = N / (sizeof(int) * 8) + 1;
	positon = N % (sizeof(int) * 8);
}

template<size_t N>
Bitset<N>& Bitset<N>::set()
{
	set_ind_pos();
	for (int j = m_array_index - 1; j >= 0; --j)
	{
		if (j == 0)
		{
			(m_array[j] |= ~(0 << positon - 1));
		}

		if (j > 0)
		{
			(m_array[j] |= ~(0 << (sizeof(int) * 8) - 1));
		}
	}
	return *this;
}

template<size_t N>
Bitset<N>& Bitset<N>::set(std::size_t pos, bool value)
{
	set_ind_pos();
	if (pos >= bits_size)
	{
		std::cout << "Out of range " << std::endl;
		exit(0);
	}

	if (pos <= ((sizeof(int) * 8) - 1))
	{
		if (value)
		{
			m_array[0] |= (1 << pos);
		}
		else
		{
			m_array[0] ^= (1 << pos);
		}
	}
	else
	{
		int index = (bits_size / ((sizeof(int) * 8)))-1;
		int n = ((pos % (sizeof(int) * 8 )));
		if (value)
		{
			m_array[index] |= (1 << n);
		}
		else
		{
			m_array[index] ^= (1 << n);
		}
	}

	return *this;
}

template<size_t N>
Bitset<N>& Bitset<N>::reset()
{
	set_ind_pos();
	for (int j = m_array_index - 1; j >= 0; --j)
	{
		if (j == 0)
		{
			(m_array[j] &= (0 << positon - 1));
		}

		if (j > 0)
		{
			(m_array[j] &= (0 << (sizeof(int) * 8) - 1));
		}
	}
	return *this;
}

template<size_t N>
Bitset<N>& Bitset<N>::reset(std::size_t pos)
{
	set_ind_pos();
	if (pos >= bits_size)
	{
		std::cout << "Out of range " << std::endl;
		exit(0);
	}

	if (pos <= ((sizeof(int) * 8) - 1))
	{
		m_array[0] ^= (1 << pos - 1);

	}
	else
	{
		int index = (bits_size / ((sizeof(int) * 8))) - 1;
		int n = ((pos % (sizeof(int) * 8)));
		m_array[index] ^= (1 << n);
	
	}
	return *this;
}

template<size_t N>
Bitset<N>& Bitset<N>::flip()
{
	set_ind_pos();
	for (int j = m_array_index - 1; j >= 0; --j)
	{
		if (j == 0)
		{
			(m_array[j] = ~(0 << positon - 1));
		}

		if (j > 0)
		{
			(m_array[j] = ~(m_array[j]));
		}
	}
	return *this;
}

template<size_t N>
Bitset<N>& Bitset<N>::flip(size_t pos)
{
	set_ind_pos();
	if (pos >= bits_size)
	{
		std::cout << "Out of range " << std::endl;
		exit(0);
	}

	if (pos <= ((sizeof(int) * 8) - 1))
	{
		m_array[0] &= ~(1 << pos);
	}
	else
	{
		int index = (bits_size / ((sizeof(int) * 8))) - 1;
		int n = ((pos % (sizeof(int) * 8)));
	
		m_array[index] &= ~(1 << n);
	}
	return *this;
}

template <size_t N>
unsigned long Bitset<N>::to_ulong() const
{
	if (bits_size >= sizeof(int) * 8)
	{
		std::cout << "ERROR....." << std::endl;
		exit(0);
	}
	if (bits_size > sizeof(int) * 8)
	{
		std::cout << "Overflow_error.." << std::endl;
		exit(0);
	}
	else
	{
		unsigned long num = m_array[0];
		return num;
	}
}

template <size_t N>
unsigned long long Bitset<N>::to_ullong() const
{
	if (bits_size >= (2 * (sizeof(int) * 8)))
	{
		std::cout << "ERROR....." << std::endl;
		exit(0);
	}
	if (bits_size >= (2 * (sizeof(int) * 8)))
	{
		std::cout << "Overflow_error.." << std::endl;
		exit(0);
	}
	unsigned long long num = m_array[1];
	num <<= 32;
	unsigned long num1 = m_array[0];
	num ^= num1;
	return num;
}

template <size_t N>
unsigned int Bitset<N>::size()
{
	return bits_size;
}