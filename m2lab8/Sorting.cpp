#include<iostream>
#include<array>
#include<vector>

template<class IT>
void sorting(IT beg, IT end)
{
	for (IT i = beg; i < end; ++i)
	{
		for (IT j = beg; j < end; ++j)
		{
			if ((*i) < (*j))
			{
				std::swap((*i), (*j));
			}
		}
	}
}

int main()
{
	int a = 0;
	int arr[] = { 123, 3, 0, 13212, -100 };
	sorting(arr + 0, arr + 3); // arr: 0, 3, 123, 13212, -100
	while (a < 5)
	{
		std::cout << arr[a] << " ";
		++a;
	}
	std::cout << std::endl;
	sorting(arr + 2, arr + 5); // arr: 0, 3, -100, 123, 13212
	a = 0;
	while (a < 5)
	{
		std::cout << arr[a] << " ";
		++a;
	}
	std::cout << std::endl;
	sorting(std::begin(arr), std::end(arr)); // arr: -100, 0, 3, 123, 13212
	a = 0;
	while (a < 5)
	{
		std::cout << arr[a] << " ";
		++a;
	}
	std::cout << std::endl;

	std::vector<double> vec = { 123.0, 3.0, 0.0, 13212.0, -100.0 };
	sorting(vec.begin(), vec.end()); // vec: -100.0, 0.0, 3.0, 123.0, 13212.0
	a = 0;
	while (a < 5)
	{
		std::cout << arr[a] << " ";
		++a;
	}
	std::cout << std::endl;
}
