#include"TSquare.h"

class TRect : public TSquare
{
private:
	int b = 0;
public:
	TRect();
	TRect(int c, int d);
	~TRect();
	int Perimeter();
	void Print();
};

