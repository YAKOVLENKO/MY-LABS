#include"TTriad.h"

TTriad::TTriad()
{
	first = 0;
	second = 0;
	third = 0;
}
TTriad::TTriad(int f, int s, int t)
{
	first = f;
	second = s;
	third = t;
}
TTriad::~TTriad()
{
	first = 0;
	second = 0;
	third = 0;
}
int TTriad::GetFirst() const
{
	return first;
}
int TTriad::GetSecond() const
{
	return second;
}
int TTriad::GetThird() const
{
	return third;
}
void TTriad::Change(int f, int s, int t)
{
	first = f;
	second = s;
	third = t;
}
bool TTriad::Compare(TTriad &s)
{
	if (first == s.GetFirst() && second == s.GetSecond() && third == s.GetThird())
	{
		return 1;
	}
	return 0;
}
void TTriad::Print()
{
	std::cout << std::endl << first << " " << second << " " << third << std::endl;
}
