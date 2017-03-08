#include <iostream>
#include <fstream>
#include <string>
#include<vector>


int main()
{
	size_t k = 0;
	size_t l = 0;
	std::string string1;
	std::string string2;
	std::cout << "Write space of file1: ";
	std::cin >> string1;
	std::cout << "Write space of file2: ";
	std::cin >> string2;
	std::vector<std::string> strings1;
	std::vector<std::string> strings2;
	std::fstream fl1(string1);
	std::fstream fl2(string2);
	if (fl1.is_open())
	{
		for (std::string str1; std::getline(fl1, str1);)
		{
			strings1.push_back(std::move(str1));
		}
	}
	if (fl2.is_open())
	{
		for (std::string str2; std::getline(fl2, str2);)
		{
			strings2.push_back(std::move(str2));
		}
	}
	if (strings1.size() > strings2.size())
	{
		for (int i = 0; i < strings2.size(); i++)
		{
			if (strings1[i] != strings2[i])
				std::cout << string1 << " " << i + 1 << " " << strings1[i] << std::endl;
		}
		for (int i = strings2.size(); i < strings1.size(); i++)
		{
			std::cout << string1 << " " << i + 1 << " " << strings1[i] << std::endl;
		}
	}
	if (strings2.size() > strings1.size())
	{
		for (int i = 0; i < strings1.size(); i++)
		{
			if (strings1[i] != strings2[i])
				std::cout << string2 << " " << i + 1 << " " << strings2[i] << std::endl;
		}
		for (int i = strings1.size(); i < strings2.size(); i++)
		{
			std::cout << string2 << " " << i + 1 << " " << strings2[i] << std::endl;
		}
	}
	fl1.close();
	fl2.close();
}
