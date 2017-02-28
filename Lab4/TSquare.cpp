#include"TRectangle.h"

using namespace std;

TSquare::TSquare()
{
	a = 0;
}

TSquare::TSquare(int c)
{
	a = c;
}

TSquare::~TSquare()
{
	a = 0;
}

int TSquare::Perimeter()
{
	int p = 0;
	p = a * 4;
	return p;
}

void TSquare::Print()
{
	cout << "a = " << a << endl << "perimeter = " << (*this).Perimeter() << endl;
}
