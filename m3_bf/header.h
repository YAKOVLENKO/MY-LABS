#ifndef __BOOLEAN_FUNCTION_INCLUDED__
#define __BOOLEAN_FUNCTION_INCLUDED__

#include <string>
#include <vector>

class boolean_function
{
	
public:
	using value_type = bool;
	using size_type = size_t;
	using reference = std::vector<value_type>::reference;
	using const_reference = std::vector<value_type>::const_reference;

	using iterator = typename std::vector<value_type>::iterator;
	using const_iterator = typename std::vector<value_type>::const_iterator;
private:
	std::vector<value_type> mainbool;
public:

	// ���������� ������� ������� ����� xn � ������������ dimension
	// ������ 1
	// n = 0
	// dimension = 3
	// �������� ������� "01010101"
	// ������ 2
	// n = 1
	// dimension = 4
	// �������� ������� "0011001100110011"
	static boolean_function var(size_t n, size_t dimension);

	// ������������� ���� "�� dimension ����������"
	static boolean_function zero(size_t dimension)
	{
		std::vector<value_type> newvec;
		for (int i = 0; i < pow(2, dimension); ++i)
			newvec[i] = 0;
		boolean_function bf(newvec);
		return bf;
	}

	// ������������� ������� "�� dimension ����������"
	static boolean_function one(size_t dimension)
	{
		std::vector<value_type> newvec;
		for (int i = 0; i < pow(2, dimension); ++i)
			newvec[i] = 0;
		boolean_function bf(newvec);
		return bf;
	}

	static boolean_function from_anf(std::vector<value_type> v);

	boolean_function() = default;

	// ������ ������ �������������� ���� �� n ����������
	boolean_function(size_t n)
	{
		for (int i = 0; i < pow(2, n); ++i)
			mainbool[i] = 0;
	}

	// ������ ������ �� n ����������. �������� ����� value
	// ������
	// ����� value = 14, �.�. 0...00001110 � �������� �������
	// � n = 3
	// ����� ��� boolean_function ����� ����� x + y + xy + zx + zy + zyx
	boolean_function(unsigned long long value, size_type n)
	{
		for (int i = 0; i < n; ++i)
		{
			mainbool[i] = value / pow(2, n - i);
			value = value - mainbool[i] * pow(2, n - i);
		}
	}

	// ����� table = "01110000"
	// ����� ��� boolean_function ����� ����� x + y + xy + zx + zy + zyx
	boolean_function(const std::string& table)
	{
		char * ctable = new char[table.length() + 1];
		std::strcpy(ctable, table.c_str());
		for (int i = 0; i <= table.length(); ++i)
		{
			mainbool[i] = ctable[i];
		}
	}

	// ����� table = {true, false, false, true};
	// ����� ��� boolean_function ����� ����� x + y + 1
	boolean_function(const std::vector<value_type>& table)
	{
		mainbool = table;
	}
	boolean_function(const std::initializer_list<bool> vars);

	boolean_function(const boolean_function& table)
	{
		mainbool = table.mainbool;
	}

	boolean_function& operator=(const boolean_function& rhs)
	{
		mainbool = rhs.mainbool;
		return *this;
	}

	// �������� �� ������ 2
	// ���� ������ ���������� ���������� - ����������
	boolean_function& operator += (const boolean_function& rhs)
	{
		if (mainbool.size() != rhs.mainbool.size())
			throw std::exception("Different sizes!");
		for (int i = 0; i < mainbool.size(); ++i)
		{
			mainbool[i] = (mainbool[i] + rhs.mainbool[i]) % 2;
		}
		return *this;
	}

	// ����������
	// ���� ������ ���������� ���������� - ����������
	boolean_function& operator *= (const boolean_function& rhs)
	{
		if (mainbool.size() != rhs.mainbool.size())
			throw std::exception("Different sizes!");
		for (int i = 0; i < mainbool.size(); ++i)
		{
			mainbool[i] = mainbool[i] * rhs.mainbool[i];
		}
		return *this;
	}

	// ����������
	// ���� ������ ���������� ���������� - ����������
	boolean_function& operator |= (const boolean_function& rhs)
	{
		if (mainbool.size() != rhs.mainbool.size())
			throw std::exception("Different sizes!");
		for (int i = 0; i < mainbool.size(); ++i)
		{
			if (mainbool[i] == 0 && rhs.mainbool[i] == 0)
				mainbool[i] = 0;
			else mainbool[i] = 1;
		}
		return *this;
	}

	// ��������� ���������
	boolean_function operator ~ ()
	{
		for (int i = 0; i < mainbool.size(); ++i)
		{
			mainbool[i] = !mainbool[i];
		}
	}

	// true ���� ������� �����
	//  ����� false
	bool operator == (const boolean_function& rhs) const
	{
			if (mainbool == rhs.mainbool)
				return true;
			return false;
	}

	// true ���� ���� ������� �������� � ������ ��� ����� rhs
	// false ���� �������� � ������ rhs
	// logic_error ���� ������ �� ��������
	bool operator >= (const boolean_function& rhs) const
	{
		if (mainbool.size() != rhs.mainbool.size())
			throw std::exception("Different sizes!");
		int pass = 0;
		for (int i = 0; i < mainbool.size(); ++i)
		{
			if (mainbool[i] >= rhs.mainbool[i])
				++pass;
			else --pass;
		}
		if (pass == mainbool.size())
			return true;
		if (pass * (-1) == mainbool.size())
			return false;
		throw std::logic_error("Functions are incomparable");
	}

	reference operator[](size_type ind)
	{
		return mainbool[ind];
	}
	const_reference operator[](size_type ind) const
	{
		return mainbool[ind];
	}

	reference at(size_type ind)
	{
		if (ind >= mainbool.size() || ind < 0)
			throw std::exception("Wrong index!");
		return mainbool[ind];
	}
	const_reference at(size_type ind) const
	{
		if (ind >= mainbool.size() || ind < 0)
			throw std::exception("Wrong index!");
		return mainbool[ind];
	}

	iterator begin()
	{
		return mainbool.begin();
	}
	iterator end()
	{
		return mainbool.end();
	}
	const_iterator cbegin() const
	{
		return mainbool.cbegin();
	}
	const_iterator cend() const
	{
		return mainbool.cend();
	}

	// ����� ������� �������
	size_type size() const throw()
	{
		return mainbool.size();
	}

	// ���������� ����������
	size_type dimension() const throw()
	{
		size_t p = 0;
		size_t ves = mainbool.size();
		while (ves > 1)
		{
			ves /= 2;
			++p;
		}
		return p;
	}

	// ���������� �������� �������
	// ����� boolean_function ������ ������� f(x, y, z)
	// ����� ������� ������ f(vars[0], vars[1], vars[2])
	bool operator()(const std::vector<bool>& vars) const;
	bool operator()(const std::initializer_list<bool> vars) const;


	// T(x1, x2, ..., xN) - ������� �������
	// operator ������ ����� �������, ������� ����� ���������� G = T(fs[0], fs[1], ..., fs[N-1])
	boolean_function operator()(const std::vector<boolean_function>& fs) const;
	boolean_function operator()(const std::initializer_list<boolean_function> vars) const;

	bool is_monotone() const;
	bool is_symmetric() const;
	bool is_linear() const
	{
		int znach = mainbool.size();
		std::vector<bool> maxANF;
		for (int i = mainbool.size() - 1; i >= 0; --i)
		{
			if (i == znach / 2 - 1)
			{
				maxANF[i] = 1;
				znach / 2;
			}
			else
				maxANF[i] = 0;
		}
		std::vector<value_type> ANF = anf();
		for (int i = 0; i < mainbool.size(); ++i)
		{
			if (ANF[i] > maxANF[i])
				return false;
		}
		return true;
	}
	bool is_T1() const
	{
		return mainbool[mainbool.size() - 1] == 1;
	}
	bool is_T0() const
	{
		return mainbool[0] == 0;
	}
	bool is_balanced() const //����������� ��
	{
		int znach = 0;
		for (int i = 0; i < mainbool.size(); ++i)
		{
			if (mainbool[i] == 1)
				++znach;
			else --znach;
		}
		if (znach != 0)
			return false;
		return true;
	}
	size_t weight() const
	{
		size_t weight = 0;
		for (int i = 0; i < mainbool.size(); ++i)
		{
			if (mainbool[i] == 1)
				++weight;
		}
		return weight;
	}

	bool is_functionally_complete_system() const;

	// ���������� ��� �������
	std::vector<value_type> anf() const
	{
		std::vector<value_type> anf;
		std::vector<value_type> zag = mainbool;
		int wall = mainbool.size() - 1;
		while (wall >= 0)
		{
			anf[wall] = zag[0];
			for (int i = 0; i < mainbool.size() - 1; ++i)
			{
				zag[i] = (zag[i] + zag[i + 1]) % 2;
			}
			zag.pop_back();
			--wall;
		}
		std::reverse(anf.begin(), anf.end());
		return anf;
	}
	
};

// ����� boolean_function ������������ �� ���� ������� "01110000"
// ����� get_polynom ������ ������ "x0 + x1 + x0x1 + x0x2 + x1x2 + x0x1x2"
std::string get_polynom(const boolean_function&);

boolean_function operator + (const boolean_function& a, const boolean_function& b)
{
	boolean_function newfunc = a;
	return newfunc += b;
}

boolean_function operator * (const boolean_function& a, const boolean_function& b)
{
	boolean_function newfunc = a;
	return newfunc *= b;
}

boolean_function operator | (const boolean_function& a, const boolean_function& b)
{
	boolean_function newfunc = a;
	return newfunc |= b;
}

bool operator != (const boolean_function& a, const boolean_function& b)
{
	return a != b;
}


#endif // __BOOLEAN_FUNCTION_INCLUDED__