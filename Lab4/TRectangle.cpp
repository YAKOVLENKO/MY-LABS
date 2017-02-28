#include"TRectangle.h"

using namespace std;
TRect::TRect() : TSquare::TSquare()
{
	b = 0;
}
TRect::TRect(int c, int d) : TSquare::TSquare(c)
{
	a = c;
	b = d;
}
int TRect::Perimeter()
{
	int p = 0;
	p = 2 * (a + b);
	return p;
}
void TRect::Print()
{
	cout << "a = " << a << endl << "b = " << b << endl << "perimeter = " << (*this).Perimeter() << endl;
}
TRect::~TRect()
{
	b = 0;
}