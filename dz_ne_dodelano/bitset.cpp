#include<iostream>
#include<string>
#include<array>
#include <math.h>



template < int N >
class TBit {

public:

	unsigned char * bit_num;
	int len;
	TBit() 
	{
		bit_num = new unsigned char[(N / 8) + ((N % 8) > 0)];
		len = (N / 8) + ((N % 8) > 0);
		for (int i = 0; i < len; ++i)
			bit_num[i] = 0;
		len = N;
	}

	~TBit()
	{
		//if (bit_num != nullptr && bit_num != NULL)  delete[] bit_num;
	}

	class TChangeBit : public TBit 
	{
	public:
		int index;
		TBit point;

		TChangeBit(int ind, TBit&  p) // пров
		{
			index = ind;
			point = p;
		}


		TChangeBit operator=(bool val) // пров
		{
			point.setBit(index, val);
			return *this;
		}


		operator bool() 
		{
			return point.getbyte(index);
		}

	};




	const bool operator[](int index) const // пров
	{
		int real_i = len - 1 - index;
		bool b;
		int chunk_num = (real_i / 8);
		int num_in_chunk = real_i % 8;
		unsigned char current_chank = bit_num[chunk_num];
		for (int i = 0; i <= num_in_chunk; ++i) 
		{
			b = current_chank % 2;
			current_chank /= 2;
		}
		return b;

	}


	bool getbyte(int index) const // пров 
	{
		int real_i = len - 1 - index;
		bool b;
		int chunk_num = (real_i / 8);
		int num_in_chunk = real_i % 8;
		unsigned char current_chank = bit_num[chunk_num];
		for (int i = 0; i <= num_in_chunk; ++i) 
		{
			b = current_chank % 2;
			current_chank /= 2;
		}
		return b;

	}


	TChangeBit operator[](int index) // пров
	{
		TChangeBit a(index, *this);
		return a;
	}

	TChangeBit change(int index) // пров
	{
		TChangeBit a(index, *this);
		return a;
	}

	void setBit(int index, bool b) // пров
	{
		int real_i = len - 1 - index;
		int chunk_num = (real_i / 8);
		int num_in_chunk = real_i % 8;

		bool curr_bit;
		unsigned char current_chank = bit_num[chunk_num];
		for (int i = 0; i <= num_in_chunk; ++i) 
		{
			curr_bit = current_chank % 2;
			current_chank /= 2;
		}
		if (curr_bit == 0 && b == 1) 
			bit_num[chunk_num] += pow(2, num_in_chunk);
		else if (curr_bit == 1 && b == 0) 
			bit_num[chunk_num] -= pow(2, num_in_chunk);
	}



};



template < size_t N >
class TBitset
{
private:
	TBit<N> mainmass;
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

	TBitset& set() // ????????? ??? 1
	{
		for (int i = 0; i < N; ++i)
			mainmass.setBit(i, 1);
		return *this;
	};

	TBitset& set(size_t index, bool value = true) //????????? ?????????? ???????? value;
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

	TBitset& flip()// ???????
	{

		for (int i = 0; i < N; i++)
		{
			mainmass.setBit(i, mainmass.getbyte(i) ^ 1);
		}
		return *this;
	}

	TBitset& flip(size_t index)
	{
		if (index >= N || index < 0)
			throw std::exception();
		mainmass.setBit(index, mainmass.getbyte(index) ^ 1);
		return *this;
	}

	// bit access


	typename TBit<N>::TChangeBit operator[](size_t index)
	{
		//bool a = mainmass[index];

		typename TBit<N>::TChangeBit tmp = mainmass.change(index);
		return tmp;
	}


	size_t count() const // ??????? 1
	{
		size_t count = 0;
		for (int i = 0; i < N; ++i)
		{
			count += mainmass.getbyte(i);
		}
		return count;
	}

	size_t size() const
	{
		return N;
	}

	bool test(size_t index) const // ?? ?? ?????, ??? ? [], ?????? std::out_of_range (? ??????? ?? []), ???? ?????? ??? = size
	{
		if (index >= N || index < 0)
			throw std::out_of_range("Error");
		return mainmass.getbyte(index);
	}

	bool any() // ???? ???? 1 ? ?????? - true, ? ???? ?????? - false;
	{
		for (int i = 0; i < N; ++i)
		{
			if ((*this).operator[](i) == 1)
				return true;
		}
		return false;
	}

	bool none() // ?? any
	{
		return !(any());
	}

	bool all() const // ???? ??? 1 - true
	{
		for (int i = 0; i < N; ++i)
		{
			if (mainmass.getbyte(i) == 0)
				return false;
		}
		return true;
	}

	// operators

	TBitset& operator&= (const TBitset& rhs)
	{
		for (int i = 0; i < N; ++i)
		{
			if (mainmass.getbyte(i) == 0 || rhs.mainmass.getbyte(i) == 0)
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
			if (mainmass.getbyte(i) == 1 || rhs.mainmass.getbyte(i) == 1)
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
			mainmass.setBit(i, !(mainmass.getbyte(i) == rhs.mainmass.getbyte(i)));
		}
		return *this;
	}

	TBitset& operator<<= (size_t pos)
	{
		for (int i = 0; i < N; ++i)
		{
			if (i + pos < N)
				mainmass.setBit(i, mainmass.getbyte(i + pos));
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
				mainmass.setBit(i, mainmass.getbyte(i - pos));
			else
				mainmass.setBit(i, 0);
		}
		return *this;
	}

	TBitset operator~()
	{
		for (int i = 0; i < N; ++i)
		{
			if (mainmass.getbyte(i) == 0)
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
				mainmass.setBit(i, mainmass.getbyte(i + pos));
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
				int a = mainmass.getbyte(i - pos);
				mainmass.setBit(i, mainmass.getbyte(i - pos));
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
			if (mainmass.getbyte(i) != rhs.mainmass.getbyte(i))
				return false;
		}
		return true;
	}

	std::string to_string() // 
	{
		/*std::string str;
		str.reserve(N);*/
		char* str = new char[N+1];
		for (int i = 0; i < N; ++i)
		{
			str[i] = 48 + mainmass.getbyte(i);
		}
		str[N] = '\0';
		std::string stri;
		stri.reserve(N);
		stri = str;
		delete[] str;
		return stri;
	}

	unsigned long to_ulong()
	{
		double tolong = 0;
		int two = 1;
		for (int i = N - 1; i >= 0; --i)
		{
			if (tolong + mainmass.getbyte(i) * two > 4294967295)
				throw std::overflow_error("Overflow");
			tolong += mainmass.getbyte(i) * two;
			two *= 2;
		}
		return tolong;
	}



	// iterator
/*	class TIterator :public TBitset
	{
	public:
		int index;

		TIterator(int ind) {
			index = ind;
		}

		TIterator operator=(TIterator iter) {
			index = iter.index;
			return *this;
		}

		bool operator==(TIterator iter) {
			return index == iter.index;
		}

		bool operator!=(TIterator iter) {
			return index != iter.index;
		}

		bool operator++(int) {
			index++;
		}

		bool operator++() {
			index++;
		}


		bool operator *()
		{
			return (*this)[index];
		}

	};*/

};

template<size_t N>
std::ostream & operator<<(std::ostream &out, TBitset<N> &rhs)
{
	for (int i = 0; i < N; ++i)
		out << rhs[i];
	return out;
}

template<size_t N>
TBitset<N> operator& (const TBitset<N>& lhs, const TBitset<N>& rhs)
{
	TBitset<N> tmp = lhs;

	for (int i = 0; i < N; ++i)
	{
		if (lhs.mainmass.getbyte(i) == 0 || rhs.mainmass.getbyte(i) == 0)
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
		if (lhs.mainmass.getbyte(i) == 0 && rhs.mainmass.getbyte(i) == 0)
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
		tmp.mainmass.setBit(i, lhs.mainmass.getbyte(i) ^ rhs.mainmass.getbyte(i));
	}
	return tmp;
}
