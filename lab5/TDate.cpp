#include"TDate.h"

TDate::TDate()
{
	day = 0;
	month = 0;
	year = 0;
}
TDate::TDate(int d, int m, int y): TTriad::TTriad(d, m, y)
{
	day = d;
	month = m;
	year = y;
}
TDate::~TDate()
{
	day = 0;
	month = 0;
	year = 0;
}
int TDate::GetDay() const
{
	return day;
}
int TDate::GetMonth() const
{
	return month;
}
int TDate::GetYear() const
{
	return year;
}
bool TDate::operator ==(const TDate &s) const 
{
	if (day == s.GetDay() && month == s.GetMonth() && year == s.GetYear())
	{
		return 1;
	}
	return 0;
}
bool TDate::operator!=(const TDate& s) const
{
	if (!(*this == s))
	{
		return 1;
	}
	return 0;
}
bool TDate::operator <(const TDate& s) const
{
	if (year < s.GetYear())
	{
		return 1;
	}
	if (year == s.GetYear())
	{
		if (month < s.GetMonth())
		{
			return 1;
		}
		if (month == s.GetMonth())
		{
			if (day < s.GetDay())
			{
				return 1;
			}
		}
	}
	return 0;
}
bool TDate::operator >(const TDate& s) const
{
	if (!(*this < s) && !(*this == s))
	{
		return 1;
	}
	return 0;
}
bool TDate::operator <=(const TDate& s) const
{
	if (*this == s || *this < s)
	{
		return 1;
	}
	return 0;
}
bool TDate::operator >=(const TDate& s) const
{
	if (*this == s || *this > s)
	{
		return 1;
	}
	return 0;
}
void TDate::Print()
{
	std::cout << std::endl << day << "." << month << "." << year << std::endl;
}