#include<iostream>

class TTriad
{
private:
	int first, second, third;
public:
	TTriad();
	TTriad(int f, int s, int t);
	~TTriad();
	void Change(int f, int s, int t);
	bool Compare(TTriad& s);
	int GetFirst() const;
	int GetSecond() const;
	int GetThird() const;
	void Print();
	void PrintCmp();
};