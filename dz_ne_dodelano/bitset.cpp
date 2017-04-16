#include<iostream>
#include<string>
#include<array>
template < size_t N >
class TBitset
{
private:
	std::array<bool, N> mainmass;
public:

	// constructors

	TBitset() = default;

	TBitset(unsigned long val)
	{
		
		for (int i = N - 1; i >= 0; --i)
		{
			mainmass[i] = val % 2;
			val = val / 2;
		}
	}

	TBitset(const std::string& str, size_t pos, size_t n)
	{
		size_t j = 0;
		if (pos >= str.size())
			throw std::out_of_range("Error!");
		for (int i = pos; i < n; ++i)
		{
			if (j >= N)
				return;
			if (str[i] == '0')
				mainmass[j] = 0;
			else if (str[i] == '1')
				mainmass[j] = 1;
			else
			{
				~TBitset();
				throw std::exception("Error!");
			}
		}
	}

	~TBitset() = default;

	// bit operations

	TBitset& set() // çàïîëíÿåò âñå 1
	{
		memset(mainmass, 1, sizeof(mainmass));
	};

	TBitset& set(size_t index, bool value) //çàïîëíÿåò êîíêðåòíîå çíà÷åíèå value; 
	{
		if (index >= N || index < 0)
			throw() std::exception("Error");
		if (value != 0 || value != 1)
			throw() std::exception("Error");
		mainmass[index] = value;
	}

	TBitset& reset()
	{
		memset(mainmass, 0, sizeof(mainmass));
	}

	TBitset& reset(size_t index)
	{
		mainmass[index] = 0;
	}

	TBitset& flip()// íåãàòèâ
	{
		for (int i = 0; i < N; i++)
		{
			mainmass[i] ^= 1;
		}
	}

	TBitset& flip(size_t index)
	{
		if (index >= N || index < 0)
			throw() std::exception("Error");
		mainmass[index] ^= 1;
	}

	// bit access

	bool& operator[](size_t index) const
	{
		return mainmass[index];
	}

	size_t count() const // ñ÷èòàåò 1
	{
		size_t count = 0;
		for (int i = 0; i < N; ++i)
		{
			count += mainmass[i];
		}
		return count;
	}

	size_t size() const
	{
		return N;
	}

	bool test(size_t index) const // òî æå ñàìîå, ÷òî è [], êèäàåò std::out_of_range (â îòëè÷èå îò []), åñëè áîëüøå èëè = size
	{
		if (index >= N || index < 0)
			throw() std::out_of_range("Error");
		return mainmass[index];
	}

	bool any() const // åñëè åñòü 1 â êëàññå - true, â èíîì ñëó÷àå - false;
	{
		for (int i = 0; i < N; ++i)
		{
			if (mainmass[i] == 1)
				return true;
		}
		return false;
	}

	bool none() const // íå any
	{
		return !(any());
	}

	bool all() const // åñëè âñå 1 - true
	{
		for (int i = 0; i < N; ++i)
		{
			if (mainmass[i] == 0)
				return false;
		}
		return true;
	}

	// operators

	TBitset& operator&= (const TBitset& rhs)
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

	TBitset& operator|= (const TBitset& rhs) //
	{

		if (mainmass[i] == 1 || rhs.mainmass[i] == 1)
		{
			mainmass[i] = 1;
		}
		else
			mainmass[i] = 0;
		returm *this;
	}

	TBitset& operator^= (const TBitset& rhs)
	{
		for (int i = 0; i < N; ++i)
		{
			mainmass[i] = !(mainmass[i] == rhs.mainmass[i]);
		}
		return *this;
	}

	TBitset& operator<<= (size_t pos)
	{
		for (int i = 0; i < N; ++i)
		{
			if (i + pos < N)
				mainmass[i] = mainmass[i + pos];
			else
				mainmass[i] = 0;
		}
		return *this;
	}

	TBitset& operator>>= (size_t pos)
	{
		for (int i = N - 1; i > 0; --i)
		{
			if (i - pos >= 0)
				mainmass[i] = mainmass[i - pos];
			else
				mainmass[i] = 0;
		}
		return *this;
	}

	TBitset operator~() 
	{
		for (int i = 0; i < N; ++i)
		{
			if (mainmass[i] == 0)
				mainmass[i] = 1;
			else
				mainmass[i] = 0;
		}
		return *this;
	}

	TBitset operator<<(size_t pos) const
	{
		for (int i = 0; i < N; ++i)
		{
			if (i + pos < N)
				mainmass[i] = mainmass[i + pos];
			else
				mainmass[i] = 0;
		}
		return *this;
	}

	TBitset operator >> (size_t pos) const
	{
		for (int i = N - 1; i > 0; --i)
		{
			if (i - pos >= 0)
				mainmass[i] = mainmass[i - pos];
			else
				mainmass[i] = 0;
		}
		return *this;
	}
	bool operator== (const TBitset& rhs) const
	{
		if (N != rhs.N)
			return false;
		for (int i == 0; i < N; ++i)
		{
			if (mainmass[i] != rhs.mainmass[i])
				return false;
		}
		return true;
	}
	
	std::string to_string() // error
	{
		std::string str = nullptr;
		int j = 0;
		for (int i = N - 1; i >= 0; --i)
		{
			if (mainmass[j] == false)
				str[i] = 0;
			else str[i] = 1;
			j++;
		}
		return *str;
	}
	
	unsigned long to_ulong()
	{
		double tolong = 0;
		int two = 1;
		for (int i = N - 1; i >= 0; --i)
		{
			if (tolong + mainmass[i] * two > 4 294 967 295)
				throw() std::overflow_error("Overflow");
			tolong += mainmass[i] * two;
			two *= 2;
		}
		return tolong;
	}
};

template<size_t N>
std::ostream & operator<<(std::ostream &out, TBitset<N> &tmb)
{
	for (int i = 0; i < N; ++i)
		out << tmb[i];
}


template<size_t N>
TBitset<N> operator& (const TBitset<N>& lhs, const TBitset<N>& rhs)
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
TBitset<N> operator| (const TBitset<N>& lhs, const TBitset<N>& rhs)
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
TBitset<N> operator^ (const TBitset<N>& lhs, const TBitset<N>& rhs)
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

int main()
{
	std::string mainmass = "00101101";
	TBitset<4> bit(mainmass, 0, 8);
	std::cout << bit;
}



