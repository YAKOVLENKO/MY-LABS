#include<iostream>
#include"Apartament.h"

int main()
{
	int n = 0;
	int max = 0;
	std::cout << "Write n: ";
	std::cin >> n;
	Apartament *a1 = new Apartament[n];
	int* l = new int[n];
	int* p = new int[n];
	std::cout << "Write price you search: ";
	std::cin >> max;
	for (int i = 0; i < n; i++)
	{
		std::cout << "write rooms for apartament " << i + 1 << " :";
		std::cin >> l[i];
		a1[i].setRooms(l[i]);
		std::cout << "write price for apartament " << i + 1 << " :";
		std::cin >> p[i];
		a1[i].setPrice(p[i]);
	}
	std::cout << "parameters for all apartaments: ";
	for (int i = 0; i < n; i++)
	{
		std::cout << "Apartament " << i + 1 << " :" << std::endl;
		std::cout << a1[i];
	}
	std::cout << "apartaments with the pice which is lower you want: " << std::endl;
	for (int i = 0; i < n; i++)
	{
		if (a1[i].average() <= max)
		{
			std::cout << "Apartament " << i + 1 << std::endl;
		}
	}
	return 0;
}