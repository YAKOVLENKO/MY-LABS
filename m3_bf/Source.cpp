#ifndef __BOOLEAN_FUNCTION_INCLUDED__
#define __BOOLEAN_FUNCTION_INCLUDED__

#include <string>
#include <vector>
#include <cmath>

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
		std::vector<bool> nned;
		std::vector<bool> tmp;
		for (int i = 0; i <= n; ++i)
		{
			tmp.push_back(0);
		}
		for (int i = 0; i <= n; ++i)
		{
			tmp.push_back(1);
		}
		while (nned.size() < pow(2, dimension))
		{
			nned.insert(nned.end(), tmp.begin(), tmp.end());
		}

		boolean_function dom(nned);

		return dom;
	}

	// тождественный ноль "от dimension переменных"
	static boolean_function zero(size_t dimension)
	{
		std::vector<value_type> newvec;
		for (int i = 0; i < pow(2, dimension); ++i)
			newvec.push_back(0);
		boolean_function bf(newvec);
		return bf;
	}

	// тождественная единица "от dimension переменных"
	static boolean_function one(size_t dimension)
	{
		std::vector<value_type> newvec;
		for (int i = 0; i < pow(2, dimension); ++i)
			newvec.push_back(1);
		boolean_function bf(newvec);
		return bf;
	}

	static boolean_function from_anf(std::vector<value_type> v)
	{
		//todo
		std::vector<value_type> newvec;
		int wall = v.size() - 1;
		while (wall >= 0)
		{
			newvec[wall] = v[0];
			for (int i = 0; i < v.size() - 1; ++i)
			{
				v[i] = (v[i] + v[i + 1]) % 2;
			}
			v.pop_back();
			--wall;
		}
		std::reverse(newvec.begin(), newvec.end());
		return newvec;
	}

	boolean_function() = default;

	// задает фунцию тождественного нуля от n переменных
	boolean_function(size_t n)
	{
		for (int i = 0; i < pow(2, n); ++i)
			mainbool.push_back(0);
	}

	// задает фунцию от n переменных. значение равно value
	// пример
	// пусть value = 14, т.е. 0...00001110 в двоичной системе
	// а n = 3
	// тогда АНФ boolean_function будет равна x + y + xy + zx + zy + zyx
	boolean_function(unsigned long long value, size_type n)
	{
		mainbool.clear();
		for (int i = 0; i < pow(2, n); i++) {
			mainbool.push_back(0);
		}

		int i = mainbool.size() - 1;

		while (value)
		{
			mainbool[i] = value % 2;
			i -= 1;
			value /= 2;
		}

		std::reverse(mainbool.begin(), mainbool.end());
	}

	// пусть table = "01110000"
	// тогда АНФ boolean_function будет равна x + y + xy + zx + zy + zyx
	boolean_function(const std::string& table)
	{
		if (log2(table.size()) != (double)((int)log2(table.size())))
			throw std::exception();

		//todo
		for (int i = 0; i < table.size(); i++)
		{
			mainbool.clear();

			if (table[i] != '0' || table[i] != '1') throw std::exception();

			mainbool.push_back(table[i] == '1');
		}
	}

	// пусть table = {true, false, false, true};
	// тогда АНФ boolean_function будет равна x + y + 1
	boolean_function(const std::vector<value_type>& table)
	{
		if (log2(table.size()) != (double)((int)log2(table.size())))
			throw std::exception();
		mainbool = table;
	}
	boolean_function(const std::initializer_list<bool> vars)
	{
		if (log2(vars.size()) != (double)((int)log2(vars.size())))
			throw std::exception();

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
			throw std::exception();
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
			throw std::exception();
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
			throw std::exception();
		for (int i = 0; i < mainbool.size(); ++i)
		{
			mainbool[i] = mainbool[i] && rhs.mainbool[i];
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
		return *this;
	}

	// true если функции равны
	//  иначе false
	bool operator == (const boolean_function& rhs) const
	{
		return mainbool == rhs.mainbool;
	}

	// true если одна функция сравнима и больше или равна rhs
	// false если сравнима и меньше rhs
	// logic_error если фунции не сравнимы
	bool operator >= (const boolean_function& rhs) const
	{
		if (mainbool.size() != rhs.mainbool.size())
			throw std::exception();
		int pass = 0;
		bool larger = 0;
		bool lower = 0;
		for (int i = 0; i < mainbool.size(); ++i)
		{
			if (mainbool[i] > rhs.mainbool[i])
				larger = 1;
			else if (mainbool[i] < rhs.mainbool[i])
				lower = 1;
		}
		if ((larger && !lower) && (!larger && !lower))
			return true;
		if (!larger && lower)
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
		return mainbool.at(ind);
	}
	const_reference at(size_type ind) const
	{
		return mainbool.at(ind);
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

		if (mainbool.size() == 0) return 0;

		double ans = log2(mainbool.size());

		return (size_type)ans;
	}

	// возвращает значение функции
	// пусть boolean_function задает функцию f(x, y, z)
	// тогда функция вернет f(vars[0], vars[1], vars[2])
	bool operator()(const std::vector<bool>& vars) const
	{

		int index = 0;
		long long int two = 1;
		for (int i = vars.size() - 1; i >= 0; ++i) {

			index += vars[i] * two;
			two *= 2;
		}
		return mainbool[index];
	}

	bool operator()(const std::initializer_list<bool> vars) const
	{
		std::vector<bool> tmp = vars;

		return operator()(tmp);
	}


	// T(x1, x2, ..., xN) - текущая функция
	// operator вернет новую функцию, которая равна композиции G = T(fs[0], fs[1], ..., fs[N-1])
	boolean_function operator()(std::vector<boolean_function>& fs) const {
		//todo
		std::vector<bool> tmp = mainbool;
		std::vector<bool>new_mainbool;
		if (fs.size() != mainbool.size())
			throw std::exception();
		for (int i = 0; i < fs.size(); ++i)
		{
			new_mainbool[i] = tmp[fs[i].number()];
		}
		boolean_function new_bool(new_mainbool);
		return new_bool;
	}
	boolean_function operator()(const std::initializer_list<boolean_function> vars) const {

		//todo
		std::vector<boolean_function> fs = vars;
		std::vector<bool> tmp = mainbool;
		std::vector<bool>new_mainbool;
		if (fs.size() != mainbool.size())
			throw std::exception();
		for (int i = 0; i < fs.size(); ++i)
		{
			new_mainbool[i] = tmp[fs[i].number()];
		}
		boolean_function new_bool(new_mainbool);
		return new_bool;
	}

	int number()
	{
		int index = 1;
		int result = 0;
		for (int i = mainbool.size() - 1; i >= 0; --i)
		{
			result += index * mainbool[i];
			index *= 2;
		}
		return result;
	}

	bool is_monotone() const
	{

		for (int i = 0; i < mainbool.size(); ++i)
		{
			if (mainbool[i] == 0)
			{
				for (int j = 0; j < i; ++j)
				{
					if (mainbool[j] == 1)
					{
						boolean_function tmp1(i, dimension());
						boolean_function tmp2(j, dimension());
						try {
							if (tmp1 >= tmp2) return 0;
						}
						catch (...) {

						}
					}
				}
			}
		}
		return 1;

	}
	bool is_symmetric() const
	{
		std::vector<bool> first = mainbool;
		std::reverse(first.begin(), first.end());
		for (int i = i; i < mainbool.size(); ++i)
		{
			if (mainbool[i] != (!(first[i])))
				return false;
		}
		return true;
	}
	bool is_linear() const
	{

		//todo
		int znach = mainbool.size();
		std::vector<bool> maxANF;
		for (int i = mainbool.size() - 1; i >= 0; --i)
		{
			if (i == znach / 2)
			{
				maxANF[i] = 1;
				znach / 2;
			}
			else
				maxANF[i] = 0;
			maxANF[0] = 1;
		}
		std::vector<value_type> ANF = this->anf();
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
			if (mainbool[i])
				++znach;
			else --znach;
		}
		return znach == 0;
	}
	size_t weight() const
	{
		size_t weight = 0;
		for (int i = 0; i < mainbool.size(); ++i)
		{
			weight += mainbool[i];
		}
		return weight;
	}

	bool is_functionally_complete_system() const
	{
		if (!is_T1() && !is_T0() && !is_symmetric() && !is_monotone() && !is_linear())
			return true;
		return false;
	}
	// Возвращает АНФ функции
	std::vector<value_type> anf() const
	{
		//todo
		std::vector<value_type> anf;
		for (int i = 0; i < mainbool.size(); ++i)
		{
			anf.push_back(0);
		}
		std::vector<value_type> zag = mainbool;
		int wall = mainbool.size() - 1;
		while (wall >= 0)
		{
			anf[wall] = zag[0];
			for (int i = 0; i <= zag.size() - 2; ++i)
			{
				zag[i] = (zag[i] + zag[i + 1]) % 2;
			}
			zag.pop_back();
			--wall;
		}
		std::reverse(anf.begin(), anf.end());
		return anf;
	}
	std::vector<bool> GetMainbool()
	{
		return  mainbool;
	}

};

// пусть boolean_function представляет из себя функцию "01110000"
// тогда get_polynom вернет строку "x0 + x1 + x0x1 + x0x2 + x1x2 + x0x1x2"
std::string get_polynom(boolean_function& smth)
{
	//todo
	std::string result = 0;
	std::vector<bool> anf;
	for (int i = 0; i < smth.GetMainbool().size(); ++i)
	{
		anf.push_back(0);
	}
	std::vector<bool> zag = smth.GetMainbool();
	int wall = smth.GetMainbool().size() - 1;
	while (wall >= 0)
	{
		anf[wall] = zag[0];
		for (int i = 0; i <= zag.size() - 2; ++i)
		{
			zag[i] = (zag[i] + zag[i + 1]) % 2;
		}
		zag.pop_back();
		--wall;
	}
	std::reverse(anf.begin(), anf.end());
	for (int i = 0; i < anf.size(); ++i)
	{
		result.push_back(anf[i]);
	}
	return result;
}

boolean_function operator + (const boolean_function& a, const boolean_function& b)
{
	boolean_function newfunc = a;
	newfunc += b;
	return newfunc;
}

boolean_function operator * (const boolean_function& a, const boolean_function& b)
{
	boolean_function newfunc = a;
	newfunc *= b;
	return newfunc;
}

boolean_function operator | (const boolean_function& a, const boolean_function& b)
{
	boolean_function newfunc = a;
	newfunc |= b;
	return newfunc;
}

bool operator != (const boolean_function& a, const boolean_function& b)
{
	return !(a == b);
}


#endif // __BOOLEAN_FUNCTION_INCLUDED__
