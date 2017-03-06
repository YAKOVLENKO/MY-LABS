#include <iostream>
#include<string>
#include<algorithm>
#include<iterator>
#include <fstream>
#include <sstream>
#include<vector>

std::string ReadF(const std::string & filename)
{
	std::fstream fl(filename, std::fstream::in);
	std::string str;
	std::string str0;
	std::getline(fl, str, '\0');
	return str;
}
std::string DeletePunct(std::string str0)
{
	for (std::string::iterator i = str0.begin(); i < str0.end(); ++i)
	{
		if (ispunct(*i))
		{
			*i = ' ';
		}
	}
	return str0;
}
std::string OneString(std::string str0)
{
	for (std::string::iterator i = str0.begin(); i < str0.end(); ++i)
	{
		if (*i == '\n')
		{
			*i = ' ';
		}
	}
	return str0;
}
std::string Transf(std::string str0)
{
	std::string str;
	std::transform(str0.begin(), str0.end(), std::back_inserter(str), tolower); //большие в маленькие
	str0 = str;
	return str0;
}
std::string NormalPrep(std::string str0)
{
	std::string str;
	str0 = OneString(str0); // из нескольких строк в одну
	str0 = DeletePunct(str0); //удаление пунктуации
	std::transform(str0.begin(), str0.end(), std::back_inserter(str), tolower); //большие в маленькие
	str0 = str;
	return str0;
}

int main()
{
	std::string str;
	int l = 0;
	int n = 0;
	std::cout << "Write n: ";
	std::cin >> n;
	str = NormalPrep(ReadF("E:\\text.txt"));
	std::vector<std::string> words;
	std::istringstream istr(str);
	std::string tmp;
	while (istr >> tmp)
	{
		words.push_back(tmp);
		l++;
	}
	std::string find;
	std::cout << "Write word: ";
	std::cin >> find;
	find = Transf(find);
	for (int i = 0; i < l - 1; i++)
	{
		if (words[i] == find)
		{
			for (int j = i - n; j <= i + n; ++j)
			{
				if (j < 0)
					continue;
				if (j > l - 1)
					break;
				std::cout << words[j] << ' ';
			}
			std::cout << std::endl;
		}
	}
}