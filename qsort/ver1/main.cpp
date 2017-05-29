#include<iostream>
#include"Addings.h"
#include<vector>
bool compare(int a, int b)
{
	return a >= b;
}

int main()
{
	std::vector<int> mass = { 1, 5, 2, 7, 4, 2, 6 };
	mass.begin();

	qsort_for_one(mass.begin(), mass.end(), &compare);

	int a = 0;

}
