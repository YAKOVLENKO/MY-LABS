#include <iostream>
#include<string>
#include<algorithm>
#include<iterator>
#include<cctype>

int main()
{
	std::string str;
	std::string str1;
	std::string str0;
	std::getline(std::cin, str);
	for (std::string::iterator i = str.begin(); i < str.end(); ++i)
	{
		if (ispunct(*i))
		{
			*i = ' ';
		}
	}
	std::remove_copy(str.begin(), str.end(), std::back_inserter(str1), ' ');
	str.clear();
	std::transform(str1.begin(), str1.end(), std::back_inserter(str), tolower);
	str0 = str;
	std::reverse(str.begin(), str.end());
	if (str0 == str)
	{
		std::cout << "Str is Palindrom" << std::endl;
	}
	else
	{
		std::cout << "Str is not Palindrom" << std::endl;
	}
}