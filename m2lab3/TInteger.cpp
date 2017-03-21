#include"TInteger.h"
#include <iostream>

bool Err(long long int val)
{
	if (val > INT_MAX || val < INT_MIN)
	{
		throw std::exception();
	}
	return true;
}

TInteger::TInteger()
{
	value = 0;
}
TInteger::TInteger(long long int val)
{
	Err(val);
	value = val;
}
TInteger::TInteger(TInteger &integ)
{
	Err(integ.value);
	value = integ.value;
}
TInteger::~TInteger()
{
	value = 0;
}

TInteger & TInteger::operator = (const TInteger & val)
{
	Err(val.value);
	value = val.value;
	return *this;
}
TInteger & TInteger::operator = (const long long int val)
{
	Err(val);
	value = val;
	return *this;
}

bool TInteger::operator <= (const TInteger & val)
{
	if (!(value > val.value))
		return true;
	return false;
}
bool TInteger::operator <= (const int val)
{
	if (!(value > val))
		return true;
	return false;
}

bool TInteger::operator >= (const TInteger & val)
{
	if (!(value < val.value))
		return true;
	return false;
}
bool TInteger::operator >= (const int val)
{
	if (!(value < val))
		return true;
	return false;
}

bool TInteger::operator < (const TInteger & val)
{
	if (value < val.value)
		return true;
	return false;
}
bool TInteger::operator < (const int val)
{
	if (value < val)
		return true;
	return false;
}

bool TInteger::operator > (const TInteger & val)
{
	if (!(value < val.value) && value != val.value)
		return true;
	return false;
}
bool TInteger::operator > (const int val)
{
	if (!(value < val) && value != val)
		return true;
	return false;
}

bool TInteger::operator == (const TInteger & val)
{
	if (value == val.value)
		return true;
	return false;
}
bool TInteger::operator == (const int val)
{
	if (value == val)
		return true;
	return false;
}

TInteger & TInteger::operator *= (const TInteger & val)
{
	Err(val.value * value);
	value = value * val.value;
	return *this;
}
TInteger & TInteger::operator *= (const int val)
{
	Err(val * value);
	value = value * val;
	return *this;
}

TInteger & TInteger::operator -= (const TInteger & val)
{
	Err(val.value - value);
	value = value - val.value;
	return *this;
}
TInteger & TInteger::operator -= (const int val)
{
	Err(val - value);
	value = value - val;
	return *this;
}

TInteger & TInteger::operator += (const TInteger & val)
{
	Err(val.value + value);
	value = value + val.value;
	return *this;
}
TInteger & TInteger::operator += (const int val)
{
	Err(val + value);
	value = value + val;
	return *this;
}

TInteger & TInteger::operator /= (const TInteger & val)
{
	if (val.value == 0)
	{
		throw std::exception();
	}
	Err(value / val.value);
	value = value / val.value;
	return *this;
}
TInteger & TInteger::operator /= (const int val)
{
	if (val == 0)
	{
		throw std::exception();
	}
	Err(value / val);
	value = value / val;
	return *this;
}

TInteger TInteger::operator % (const TInteger & val)
{
	if (val.value == 0)
	{
		throw std::exception();
	}
	Err(value % val.value);
	value = value % val.value;
	return *this;
}
TInteger TInteger::operator % (const int val)
{
	if (val == 0)
	{
		throw std::exception();
	}
	Err(value % val);
	value = value % val;
	return *this;
}

bool TInteger::operator != (const TInteger & val) const
{
	if (value != val.value)
		return true;
	return false;
}
bool TInteger::operator != (const int val) const
{
	if (value != val)
		return true;
	return false;
}

int TInteger::GetValue() const
{
	return value;
};

TInteger operator + (const TInteger & val, const TInteger & num)
{
	Err(val.GetValue() + num.GetValue());
	TInteger ptr(val.GetValue() + num.GetValue());
	return ptr;
}
TInteger operator + (const TInteger & val, const int num)
{
	Err(val.GetValue() + num);
	TInteger ptr(val.GetValue() + num);
	return ptr;
}
TInteger operator + (const int num, const TInteger & val)
{
	Err(val.GetValue() + num);
	TInteger ptr(val.GetValue() + num);
	return ptr;
}

TInteger operator - (const TInteger & val, const TInteger & num)
{
	Err(val.GetValue() - num.GetValue());
	TInteger ptr(val.GetValue() + num.GetValue());
	return ptr;
}
TInteger operator - (const TInteger & val, const int num)
{
	Err(val.GetValue() - num);
	TInteger ptr(val.GetValue() - num);
	return ptr;
}
TInteger operator - (const int num, const TInteger & val)
{
	Err(num - val.GetValue());
	TInteger ptr(num - val.GetValue());
	return ptr;
}

TInteger operator * (const TInteger & val, const TInteger & num)
{
	Err(val.GetValue() * num.GetValue());
	TInteger ptr(val.GetValue() * num.GetValue());
	return ptr;
}
TInteger operator * (const TInteger & val, const int num)
{
	Err(val.GetValue() * num);
	TInteger ptr(val.GetValue() * num);
	return ptr;
}
TInteger operator * (const int num, const TInteger & val)
{
	Err(val.GetValue() * num);
	TInteger ptr(val.GetValue() * num);
	return ptr;
}


TInteger operator / (const TInteger & val, const TInteger & num)
{
	if (num.GetValue() == 0)
	{
		throw std::exception();
	}
	Err(val.GetValue() / num.GetValue());
	TInteger ptr(val.GetValue() / num.GetValue());
	return ptr;
}
TInteger operator / (const TInteger & val, const int num)
{
	if (num == 0)
	{
		throw std::exception();
	}
	Err(val.GetValue() / num);
	TInteger ptr(val.GetValue() / num);
	return ptr;
}
TInteger operator / (const int num, const TInteger & val)
{
	if (val.GetValue() == 0)
	{
		throw std::exception();
	}
	Err(num / val.GetValue());
	TInteger ptr(num / val.GetValue());
	return ptr;
}
TInteger::operator int()
{
	return value;
}
std::ostream & operator << (std::ostream & out, const TInteger &val)
{
	out << val.value;
	return out;
}