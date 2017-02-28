#include<iostream>

class TSquare
{
protected:
	int a = 0;
public:
	TSquare();
	TSquare(int c);
	~TSquare();
	virtual int Perimeter();
	virtual void Print();
};





