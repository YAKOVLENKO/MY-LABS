#include<iostream>
template < size_t N >
class bitset
{
private:
	bool mainmass[N];
public:
	
	// constructors

	bitset() = default;
	
	bitset(bool* mass);
	
	~bitset() = default;
	
	bitset(unsigned long val);
	
	// bit operations

	bitset& set() // заполняет все 1
	{
		memset(mainmass, 1, sizeof(mainmass));
	}; 
	
	bitset& set(size_t index, bool value) //заполняет конкретное значение value; 
	{
		if (index >= N)
			throw() std::exception("Error");
		if (value != 0 || value != 1)
			throw() std::exception("Error");
		mainmass[index] = value;
	}
	
	bitset& reset() 
	{
		memset(mainmass, 0, sizeof(mainmass));
	}
	
	bitset& reset(size_t index)
	{
		mainmass[index] = 0;
	}
	
	bitset& flip()// негатив
	{
		for (int i = 0; i < N; i++)
		{
			if (mainmass[i] == 1)
				mainmass[i] = 0;
			else
				mainmass[i] = 1;
		}
	}
	
	bitset& flip(size_t index)
	{
		if (index >= N)
			throw() std::exception("Error");
		if (mainmass[index] == 1)
			mainmass[index] = 0;
		else
			mainmass[index] = 1;
	}

	// bit access

	bool& operator[](size_t index) const
	{
		return mainmass[index];
	}
	
	size_t count() const // считает 1
	{
		size_t count = 0;
		for (int i = 0; i < N; ++i)
		{
			if (mainmass[i] == 1)
				count++;
		}
		return count;
	}
	
	size_t size() const
	{
		return N;
	}

	bool test(size_t index) const // то же самое, что и [], кидает std::out_of_range (в отличие от []), если больше или = size
	{
		if (index >= N || index < 0)
			throw() std::out_of_range("Error");
		return mainmass[index];
	}
	
	bool any() const // если есть 1 в классе - true, в ином случае - false;
	{
		for (int i = 0; i < N; ++i)
		{
			if (mainmass[i] == 1)
				return true;
		}
		return false;
	}

	bool none() const // не any
	{
		for (int i = 0; i < N; ++i)
		{
			if (mainmass[i] == 1)
				return false;
		}
		return true;
	}

	bool all() const // если все 1 - true
	{
		for (int i = 0; i < N; ++i)
		{
			if (mainmass[i] == 0)
				return false;
		}
		return true;
	}

	// operators

	bitset& operator&= (const bitset& rhs)
	{
		for (int i = 0; i < N; ++i)
		{
			if (mainmass[i] == 0 || rhs.mainmass[i] == 0)
			{
				mainmass[i] = 0;
			}
			else
				mainmass[i] = 1;
		}
		returm *this;
	}

	bitset& operator|= (const bitset& rhs) //
	{

		if (mainmass[i] == 1 || rhs.mainmass[i] == 1)
		{
			mainmass[i] = 1;
		}
		else
			mainmass[i] = 0;
	returm *this;
	}

	bitset& operator^= (const bitset& rhs) 
	{
		for (int i = 0; i < N; ++i)
		{
			if (mainmass[i] == rhs.mainmass[i])
				mainmass[i] = 0;
			else
				mainmass[i] = 1;
		}
		return *this;
	}
	
	bitset& operator<<= (size_t pos);
	
	bitset& operator>>= (size_t pos);
	
	bitset operator~() const
	{
		for (int i = 0; i < N; ++i)
		{
			if (mainmass[i] == 0)
				mainmass[i] = 1;
			else
				mainmass = 0;
		}
		return *this;
	}
	
	bitset operator<<(size_t pos) const;
	
	bitset operator >> (size_t pos) const
	{
		bool tmp = 0;
		for (int i = N - 1; i > 0; --i)
		{
			mainmass[i] = mainmass[i - 1]
		}
		mainmass[0] = 0;
		return *this;
	}
	bool operator== (const bitset& rhs) const;

};

template<size_t N>
bitset<N> operator& (const bitset<N>& lhs, const bitset<N>& rhs)
{
	for (int i = 0; i < N; ++i)
	{
		if (lhs.mainmass[i] == 0 || rhs.mainmass[i] == 0)
		{
			lhs.mainmass[i] = 0;
		}
		else
			lhs.mainmass[i] = 1;
	}
	returm *lhs;
}

template<size_t N>
bitset<N> operator| (const bitset<N>& lhs, const bitset<N>& rhs)
{
	if (lhs.mainmass[i] == 1 || rhs.mainmass[i] == 1)
	{
		lhs.mainmass[i] = 1;
	}
	else
		lhs.mainmass[i] = 0;
	returm *lhs;
}

template<size_t N>
bitset<N> operator^ (const bitset<N>& lhs, const bitset<N>& rhs)
{
	for (int i = 0; i < N; ++i)
	{
		if (lhs.mainmass[i] == rhs.mainmass[i])
			lhs.mainmass[i] = 0;
		else
			lhs.mainmass[i] = 1;
	}
	return *lhs;
}