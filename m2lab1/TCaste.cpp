#include "TCaste.h"
# include <iostream>
#include<string>
#include<iomanip>

bool CheckOverflowInt(const char* data)
{
	char* intmax = "2147483647";
	char* intmin = "-2147483648";
	if (data[0] == '-' && strcmp(data, intmin) > 0)
	{
		throw TooMuch();
	}
	if (strcmp(data, intmax) > 0)
	{
		throw TooMuch();
	}
	return true;
}
bool CheckOverflowFloat(const char* data)
{
	char* flmax = "2147483647.0";
	char* flmin = "-2147483648.0";
	if (data[0] == '-' && strcmp(data, flmin) > 0)
	{
		throw TooMuch();
	}
	if (strcmp(data, flmax) > 0)
	{
		throw TooMuch();
	}
	return true;
}
size_t Length(const char* data)
{
	size_t l = 0;
	while (data[l])
	{
		l++;
	}
	return l;
}

int intFromString(const char* data)
{
	int newnum = 0;
	size_t one = 1;
	for (size_t i = 1; i < Length(data); i++)
	{
		if (!('0' <= data[i] && data[i] <= '9'))
		{
			throw NotNumber();
		}
	}
	CheckOverflowInt(data);
	if (data[0] == '-')
	{
		one = -1;
	}
	else
		newnum = newnum * 10 + data[0] - '0';
	for (size_t i = 1; i < Length(data); i++)
	{
			newnum = newnum * 10 + data[i] - '0';
			if (one == -1 && i == Length(data) - 1)
				newnum = -newnum;
		
	}
	return newnum;
}
bool boolFromString(const char * data)
{
	if (std::strcmp(data, "true") == 0 || std::strcmp(data, "1") == 0)
	{
		return true;
	}
	if (std::strcmp(data, "false") == 0 || std::strcmp(data, "0") == 0)
	{
		return false;
	}
	throw NotNumber();
}
float floatFromString(const char * data)
{
	int one = 1;
	int len = 0;
	int j = 0;
	bool point = 1;
	float beforepoint = 0;
	float afterpoint = 0;
	int dec = 1;
	
	if (data[0] == '.' || data[Length(data) - 1] == '.' || data[1] == '.' && data[0] == '-')
		throw NotNumber();
	for (int i = 0; i < Length(data); i++)
	{
		if (!('0' <= data[i] && data[i] <= '9' || data[i] == '.' || data[0]) == '-')
		{
			throw NotNumber();
		}
	}
	while (data[j])
	{
		if (data[j] == '.' && point == 0)
			throw NotNumber();
		if (data[j] == '.' && point == 1)
		{
			point = 0;
		}
		
		if (point == 1)
		{
			len++;
		}
		j++;
	}
	CheckOverflowFloat(data);
	if (data[0] == '-')
	{
		one = -1;
	}
	else
		beforepoint = beforepoint * 10 + data[0] - '0';
	for (int i = 1; i < len; i++)
	{
		beforepoint = beforepoint * 10 + data[i] - '0';
	}
	for (int i = len + 1; i < Length(data); i++)
	{
		afterpoint = afterpoint * 10 + (data[i] - '0');
		dec = dec * 10;
	}
	afterpoint = afterpoint / dec;
	beforepoint = beforepoint + afterpoint;
	return beforepoint * one;
}
int main()
{
	//0
	char *mass0 = "-214.01";
	try
	{
		float tm = floatFromString(mass0);
		std::cout << std::fixed << std::setprecision(3) << tm << std::endl;
	}
	catch (const TCastExe & e)
	{
		std::cout << mass0 << " " << e.what() << std::endl;
	}
	//1
	mass0 = "-2147483648.1";
	try
	{
		float tm = floatFromString(mass0);
		std::cout << std::fixed << std::setprecision(3) << tm << std::endl;
	}
	catch (const TCastExe & e)
	{
		std::cout << mass0 << " " << e.what() << std::endl;
	}
	//2
	mass0 = "214748.098";
	try
	{
		float tm = floatFromString(mass0);
		std::cout << std::fixed << std::setprecision(3) << tm << std::endl;
	}
	catch (const TCastExe & e)
	{
		std::cout << mass0 << " " << e.what() << std::endl;
	}
	//3
	mass0 = "2147483";
	try
	{
		int tm = intFromString(mass0);
		std::cout << tm << std::endl;
	}
	catch (const TCastExe & e)
	{
		std::cout << mass0 << " " << e.what() << std::endl;
	}
	//4
	mass0 = "2147483648";
	try
	{
		int tm = intFromString(mass0);
		std::cout << tm << std::endl;
	}
	catch (const TCastExe & e)
	{
		std::cout << mass0 << " " << e.what() << std::endl;
	}
	//5
	mass0 = "-2147483648";
	try
	{
		int tm = intFromString(mass0);
		std::cout << tm << std::endl;
	}
	catch (const TCastExe & e)
	{
		std::cout << mass0 << " " << e.what() << std::endl;
	}
	//6
	mass0 = "1";
	try
	{
		bool tm = boolFromString(mass0);
		std::cout << tm << std::endl;
	}
	catch (const TCastExe & e)
	{
		std::cout << mass0 << " " << e.what() << std::endl;
	}
	//7
	mass0 = "0";
	try
	{
		bool tm = boolFromString(mass0);
		std::cout << tm << std::endl;
	}
	catch (const TCastExe & e)
	{
		std::cout << mass0 << " " << e.what() << std::endl;
	}
	//8
	mass0 = "45";
	try
	{
		bool tm = boolFromString(mass0);
		std::cout << tm << std::endl;
	}
	catch (const TCastExe & e)
	{
		std::cout << mass0 << " " << e.what() << std::endl;
	}
	//9
	mass0 = "345df67";
	try
	{
		int tm = intFromString(mass0);
		std::cout << tm << std::endl;
	}
	catch (const TCastExe & e)
	{
		std::cout << mass0 << " " << e.what() << std::endl;
	}
	//10
	mass0 = "-.8909";
	try
	{
		float tm = floatFromString(mass0);
		std::cout << tm << std::endl;
	}
	catch (const TCastExe & e)
	{
		std::cout << mass0 << " " << e.what() << std::endl;
	}
	//11
	mass0 = "657.67";
	try
	{
		int tm = intFromString(mass0);
		std::cout << tm << std::endl;
	}
	catch (const TCastExe & e)
	{
		std::cout << mass0 << " " << e.what() << std::endl;
	}
}