#include"TDate.h"

int main()
{
	TTriad tr1(10, 20, 30);
	TTriad tr2(40, 50, 60);
	TDate d1(21, 3, 18);
	TDate d2(22, 3, 18);
	std::cout << "Triad 1: ";
	tr1.Print();
	std::cout << "Triad 2: ";
	tr2.Print();
	std::cout << "Data 1: ";
	d1.Print();
	std::cout << "Data 2: ";
	d2.Print();
	// сравнение троек 1
	if (tr1.Compare(tr2))
	{
		std::cout << "Triad 1 == triad 2" << std::endl;
	}
	else 
	{
		std::cout << "Triad 1 != triad 2" << std::endl;
	}
	tr1.Change(40, 50, 60);
	std::cout << "Triad 1:";
	tr1.Print();
	// сравнение троек 2
	if (tr1.Compare(tr2))
	{
		std::cout << "Triad 1 == triad 2" << std::endl;
	}
	else
	{
		std::cout << "Triad 1 != triad 2" << std::endl;
	}
	// сравнение дат 1  (==)
	if (d1 == d2)
	{
		std::cout << "Data 1 == Data 2" << std::endl;
	}
	else
	{
		std::cout << "Data 1 != Data 2" << std::endl;
	}
	// сравнение дат 2 (>=, <=)
	if (d1 >= d2)
	{
		std::cout << "Data 1 >= Data 2" << std::endl;
	}
	else
	{
		std::cout << "Data 1 <= Data 2" << std::endl;
	}
	//сравнение дат 3 (>, <)
	if (d1 > d2)
	{
		std::cout << "Data 1 > Data 2" << std::endl;
	}
	else
	{
		if (d1 < d2)
		{
			std::cout << "Data 1 < Data 2" << std::endl;
		}
		else
		{
			std::cout << "Data 1 == Data 2";
		}
	}
	//сравнение дат 4
	if (d1 != d2)
	{
		std::cout << "Data 1 != Data 2" << std::endl;
	}
	else
	{
		std::cout << "Data 1 == Data 2" << std::endl;
	}
}