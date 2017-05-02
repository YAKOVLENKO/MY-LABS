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

	// возвращает функцию которая равна xn с размерностью dimension
	// пример 1
	// n = 0
	// dimension = 3
	// вернется функция "01010101"
	// пример 2
	// n = 1
	// dimension = 4
	// вернется функция "0011001100110011"
	static boolean_function var(size_t n, size_t dimension)
	{

	}

	// тождественный ноль "от dimension переменных"
	static boolean_function zero(size_t dimension)
	{
		std::vector<value_type> newvec;
		for (int i = 0; i < pow(2, dimension); ++i)
			newvec[i] = 0;
		boolean_function bf(newvec);
		return bf;
	}

	// тождественная единица "от dimension переменных"
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

	// задает фунцию тождественного нуля от n переменных
	boolean_function(size_t n)
	{
		for (int i = 0; i < pow(2, n); ++i)
			mainbool[i] = 0;
	}

	// задает фунцию от n переменных. значение равно value
	// пример
	// пусть value = 14, т.е. 0...00001110 в двоичной системе
	// а n = 3
	// тогда АНФ boolean_function будет равна x + y + xy + zx + zy + zyx
	boolean_function(unsigned long long value, size_type n)
	{
		for (int i = 0; i < n; ++i)
		{
			mainbool[i] = value / pow(2, n - i);
			value = value - mainbool[i] * pow(2, n - i);
		}
	}

	// пусть table = "01110000"
	// тогда АНФ boolean_function будет равна x + y + xy + zx + zy + zyx
	boolean_function(const std::string& table)
	{
		for (int i = 0; i < table.size(); i++)
		{
			if (table[i] == '0')
				mainbool[i] = 0;
			else
				mainbool[i] = 1;
		}
	}

	// пусть table = {true, false, false, true};
	// тогда АНФ boolean_function будет равна x + y + 1
	boolean_function(const std::vector<value_type>& table)
	{
		mainbool = table;
	}
	boolean_function(const std::initializer_list<bool> vars)
	{
		for (auto &ind : vars)
		{
			mainbool.push_back(ind);
		}
	}

	boolean_function(const boolean_function& table)
	{
		mainbool = table.mainbool;
	}

	boolean_function& operator=(const boolean_function& rhs)
	{
		mainbool = rhs.mainbool;
		return *this;
	}

	// сложение по модулю 2
	// если разное количество переменных - исключение
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

	// конъюнкция
	// если разное количество переменных - исключение
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

	// дизъюнкция
	// если разное количество переменных - исключение
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

	// побитовое отрицание
	boolean_function operator ~ ()
	{
		for (int i = 0; i < mainbool.size(); ++i)
		{
			mainbool[i] = !mainbool[i];
		}
	}

	// true если функции равны
	//  иначе false
	bool operator == (const boolean_function& rhs) const
	{
			if (mainbool == rhs.mainbool)
				return true;
			return false;
	}

	// true если одна функция сравнима и больше или равна rhs
	// false если сравнима и меньше rhs
	// logic_error если фунции не сравнимы
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

	// длина столбца функции
	size_type size() const throw()
	{
		return mainbool.size();
	}

	// количество переменных
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

	// возвращает значение функции
	// пусть boolean_function задает функцию f(x, y, z)
	// тогда функция вернет f(vars[0], vars[1], vars[2])
	bool operator()(const std::vector<bool>& vars) const;
	bool operator()(const std::initializer_list<bool> vars) const;


	// T(x1, x2, ..., xN) - текущая функция
	// operator вернет новую функцию, которая равна композиции G = T(fs[0], fs[1], ..., fs[N-1])
	boolean_function operator()(const std::vector<boolean_function>& fs) const;
	boolean_function operator()(const std::initializer_list<boolean_function> vars) const;

	bool is_monotone() const;
	bool is_symmetric() const
	{
		std::vector<bool> first = mainbool;
		std::reverse(mainbool.begin(), mainbool.end());
		for (int i = i; i < mainbool.size(); ++i)
		{
			if (mainbool[i] != (!(first[i])))
				return false;
		}
		return true;
	}
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
	bool is_balanced() const //равновесная ли
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

	bool is_functionally_complete_system() const
	{
		if (is_T1() && is_T0() && is_symmetric() && is_monotone() && is_linear())
			return false;
		return true;
	}
	// Возвращает АНФ функции
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

// пусть boolean_function представляет из себя функцию "01110000"
// тогда get_polynom вернет строку "x0 + x1 + x0x1 + x0x2 + x1x2 + x0x1x2"
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
