#include<iostream>
#include<string>
#include<array>
#include <math.h>

template < size_t N >
class bitT {
public:
	long long int bit_num = 0;
	int len = N;
	bitT() { bit_num = 0; }

	~bitT()
	{
		bit_num = 0;
	}


	bool operator[](int index) const
	{

		long long int tmp = bit_num;

		int real_i = len - 1 - index;

		bool b;

		for (int x = 0; x <= real_i; x++) {
			b = tmp % 2;
			tmp /= 2;
		}
		return b;
	}

	void setBit(int index, bool b)
	{

		int real_i = len - index - 1;

		bool curr_bit = (*this)[index];
		if (curr_bit == 0 && b == 1) bit_num += pow(2, real_i);
		else if (curr_bit == 1 && b == 0) bit_num -= pow(2, real_i);

	}
};

template < size_t N >
class TBitset
{
private:
	bitT<N> mainmass;
public:

	// constructors

	TBitset() = default;

	TBitset(unsigned long val)
	{
		for (int i = N - 1; i >= 0; --i)
		{
			mainmass.setBit(i, val % 2);
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
				mainmass.setBit(j, 0);
			else if (str[i] == '1')
				mainmass.setBit(j, 1);
			else
			{
				~TBitset();
				throw std::exception();
			}
			j++;
		}
	}

	~TBitset() = default;

	// bit operations

	TBitset& set() // çàïîëíÿåò âñå 1
	{

		mainmass.bit_num = pow(2, N) - 1;

		return *this;
		//memset(mainmass, 1, sizeof(mainmass));
	};

	TBitset& set(size_t index, bool value) //çàïîëíÿåò êîíêðåòíîå çíà÷åíèå value;
	{
		if (index >= N || index < 0)
			throw std::exception();
		mainmass.setBit(index, value);
		return *this;
	}

	TBitset& reset()
	{
		mainmass.bit_num = 0;
		return *this;
	}

	TBitset& reset(size_t index)
	{
		mainmass.setBit(index, 0);
		return *this;
	}

	TBitset& flip()// íåãàòèâ
	{
	
		for (int i = 0; i < N; i++)
		{
			mainmass.setBit(i, mainmass[i] ^ 1);
		}
		return *this;
	}

	TBitset& flip(size_t index)
	{
		if (index >= N || index < 0)
			throw std::exception();
		mainmass.setBit(index, mainmass[index] ^ 1);
		return *this;
	}

	// bit access

	bool& operator[](size_t index) const
	{
		bool a = mainmass[index];
		return a;
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
			throw std::out_of_range("Error");
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
				mainmass.setBit(i, 0);
			}
			else
				mainmass.setBit(i, 1);
		}
		return *this;
	}

	TBitset& operator|= (const TBitset& rhs) //
	{
		for (int i = 0; i < N; ++i)
		{
			if (mainmass[i] == 1 || rhs.mainmass[i] == 1)
			{
				mainmass.setBit(i, 1);
			}
			else
				mainmass.setBit(i, 0);
		}
		return *this;
	}

	TBitset& operator^= (const TBitset& rhs)
	{
		for (int i = 0; i < N; ++i)
		{
			mainmass.setBit(i, !(mainmass[i] == rhs.mainmass[i]));
		}
		return *this;
	}

	TBitset& operator<<= (size_t pos)
	{
		for (int i = 0; i < N; ++i)
		{
			if (i + pos < N)
				mainmass.setBit(i, mainmass[i + pos]);
			else
				mainmass.setBit(i, 0);
		}
		return *this;
	}

	TBitset& operator>>= (size_t pos)
	{
		for (int i = N - 1; i > 0; --i)
		{
			if (i - pos >= 0)
				mainmass.setBit(i, mainmass[i - pos]);
			else
				mainmass.setBit(i, 0);
		}
		return *this;
	}

	TBitset operator~()
	{
		for (int i = 0; i < N; ++i)
		{
			if (mainmass[i] == 0)
				mainmass.setBit(i, 1);
			else
				mainmass.setBit(i, 0);
		}
		return *this;
	}

	TBitset operator<<(size_t pos)
	{
		for (int i = 0; i < N; ++i)
		{
			if (i + pos < N)
				mainmass.setBit(i, mainmass[i + pos]);
			else
				mainmass.setBit(i, 0);
		}
		return *this;
	}

	TBitset operator >> (size_t pos)
	{
		for (int i = N - 1; i >= 0; --i)
		{
			if (i - pos >= 0) {
				int a = mainmass[i - pos];
				mainmass.setBit(i, mainmass[i - pos]);
			}
			else
				mainmass.setBit(i, 0);
		}
		return *this;
	}
	bool operator== (const TBitset& rhs)
	{
		if (N != rhs.size())
			return false;
		for (int i = 0; i < N; ++i)
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
		return str;
	}

	unsigned long to_ulong()
	{
		double tolong = 0;
		int two = 1;
		for (int i = N - 1; i >= 0; --i)
		{
			if (tolong + mainmass[i] * two > 4294967295)
				throw std::overflow_error("Overflow");
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
	return out;
}

template<size_t N>
std::ostream & operator >> (std::ostream &in, TBitset<N> &tmb)
{
	for (int i = 0; i < N; ++i)
		in << tmb[i];
	return in;
}


template<size_t N>
TBitset<N> operator& (const TBitset<N>& lhs, const TBitset<N>& rhs)
{
	TBitset<N> tmp = lhs;

	for (int i = 0; i < N; ++i)
	{
		if (lhs.mainmass[i] == 0 || rhs.mainmass[i] == 0)
		{
			tmp.mainmass.setBit(i, 0);
		}
		else
			tmp.mainmass.setBit(i, 1);
	}
	return tmp;
}

template<size_t N>
TBitset<N> operator| (const TBitset<N>& lhs, const TBitset<N>& rhs)
{

	TBitset<N> tmp = lhs;

	for (int i = 0; i < N; ++i)
	{
		if (lhs.mainmass[i] == 0 && rhs.mainmass[i] == 0)
		{
			tmp.mainmass.setBit(i, 0);
		}
		else
			tmp.mainmass.setBit(i, 1);
	}
	return tmp;
}

template<size_t N>
TBitset<N> operator^ (const TBitset<N>& lhs, const TBitset<N>& rhs)
{
	TBitset<N> tmp = lhs;

	for (int i = 0; i < N; ++i)
	{
		tmp.mainmass.setBit(i, lhs.mainmass[i] ^ rhs.mainmass[i]);
	}
	return tmp;
}


