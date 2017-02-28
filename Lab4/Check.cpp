#include"TRectangle.h"

int main()
{
	TSquare S(10);
	TRect R(20, 30);
	std::cout << "Square: " << std::endl;
	S.Print();
	std::cout << "Rectangle: " << std::endl;
	R.Print();
}