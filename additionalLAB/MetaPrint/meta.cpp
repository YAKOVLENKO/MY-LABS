#include<iostream>

template<int T>
void print()
{
	std::cout << T << std::endl;
	print<T + 1>();
}

template<>
void  print<101>()
{
	return;
}

int main()
{
	print<0>();
}