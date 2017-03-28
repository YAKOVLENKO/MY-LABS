#include "TNotCopyable.h"
# include <iostream>
#include<string>
#include<iomanip>


size_t LenBeforePoint(const std::string& data) {
	size_t l = 0;
	while (data[l] != '.') {
		l++;
	}
	return l;
}

bool CheckOverflowInt(const std::string& data) {
	std::string intmax = "2147483647";
	std::string intmin = "-2147483648";
	//1
	if (data[0] == '-' && data.size() > intmin.size())
	{
		throw TooMuch();
	}
	if (data[0] != '-' && data.size() > intmax.size())
	{
		throw TooMuch();
	}
	if (data[0] == '-' && data.size() == intmin.size() && data > intmin) {
		throw TooMuch();
	}
	if (data[0] != 0 && data.size() == intmax.size() && data > intmax) {
		throw TooMuch();
	}
	return true;
}

bool CompareAfterPoint(const std::string& data) // предполагаетс€, что длина до точки одинакова€
{
	char null = '0';
	for (int i = LenBeforePoint(data) + 1; i < data.size(); i++)
	{
			
		if (data[i] != null )
			throw TooMuch();
	}
	return true;
}

bool CompareBeforePoint(const std::string& data, const std::string& val)
{
	for (int i = 0; i < LenBeforePoint(data); i++)
	{
		if (data[i] > val[i])
			throw TooMuch();
	}
	return true;
}

bool CompareEqualityBeforePoint(const std::string& data, const std::string& val)
{
	for (int i = 0; i < LenBeforePoint(data); i++)
	{
		if (data[i] != val[i])
			return false;
	}
	return true;
}

bool CheckOverflowFloat(const std::string& data) {
	const std::string flmax = "2147483647.0";
	const std::string flmin = "-2147483648.0";

	if (data[0] == '-' && LenBeforePoint(data) == LenBeforePoint(flmin))
	{
		CompareBeforePoint(data, flmin);
		if (CompareEqualityBeforePoint(data, flmin) == true)
			CompareAfterPoint(data);
	}
	if (data[0] != '-' && LenBeforePoint(data) == LenBeforePoint(flmax))
	{
		CompareBeforePoint(data, flmax);
		if (CompareEqualityBeforePoint(data, flmax) == true)
		CompareAfterPoint(data);
	}
	if (data[0] != '-' && LenBeforePoint(data) > LenBeforePoint(flmax))
	{
		throw TooMuch();
	}
	if (data[0] == '-' && LenBeforePoint(data) > LenBeforePoint(flmin))
	{
		throw TooMuch();
	}
	return true;
}
template <typename T>
T fromString(const std::string& str) {
	throw NotNumber();
}
template <>
int fromString<int> (const std::string& data) {

	//s1234
	int newnum = 0;
	size_t one = 1;
	for (size_t i = 1; i < data.size(); i++) {
		if (!('0' <= data[i] && data[i] <= '9')) {
			throw NotNumber();
		}
	}
	CheckOverflowInt(data);
	if (data[0] == '-') {
		one = -1;
	}
	else {
		if (!('0' <= data[0] && data[0] <= '9')) {
			throw NotNumber();
		}
		newnum = newnum * 10 + data[0] - '0';
	}
	for (size_t i = 1; i < data.size(); i++) {
		newnum = newnum * 10 + data[i] - '0';
		if (one == -1 && i == data.size() - 1)
			newnum = -newnum;

	}
	return newnum;
}
template <>
bool fromString<bool> (const std::string& data) {
	if ( data == "true"|| data == "1") 
	{
		return true;
	}
	if (data == "false" || data == "0") 
	{
		return false;
	}
	throw NotNumber();
}
template <>
float fromString<float> (const std::string& data) {
	int one = 1;
	int len = 0;
	int j = 0;
	bool point = 1;
	float beforepoint = 0;
	float afterpoint = 0;
	int dec = 1;

	if (data[0] == '.' || data[data.size() - 1] == '.' || data[1] == '.' && data[0] == '-')
		throw NotNumber();
	for (int i = 0; i < data.size(); i++) {
		if (!('0' <= data[i] && data[i] <= '9' || data[i] == '.' || data[0]) == '-') {
			throw NotNumber();
		}
	}
	while (data[j]) {
		if (data[j] == '.' && point == 0)
			throw NotNumber();
		if (data[j] == '.' && point == 1) {
			point = 0;
		}

		if (point == 1) {
			len++;
		}
		j++;
	}
	CheckOverflowFloat(data);
	if (data[0] == '-') {
		one = -1;
	}
	else
		beforepoint = beforepoint * 10 + data[0] - '0';
	for (int i = 1; i < len; i++) {
		beforepoint = beforepoint * 10 + data[i] - '0';
	}
	for (int i = len + 1; i < data.size(); i++) {
		afterpoint = afterpoint * 10 + (data[i] - '0');
		dec = dec * 10;
	}
	afterpoint = afterpoint / dec;
	beforepoint = beforepoint + afterpoint;
	return beforepoint * one;
}

int main()
{
	std::string a = "-2147483649";
	try
	{
		
		std::cout << fromString<int>(a) << std::endl;
	}
	catch (const TCastExe & e)
	{
		std::cout << a << " " << e.what() << std::endl;
	}
	a = "asd";
	try
	{
		
		std::cout << fromString<int>(a) << std::endl;
	}
	catch (const TCastExe & e)
	{
		std::cout << a << " " << e.what() << std::endl;
	}
	a = "123.456";
	try
	{
		
		std::cout << fromString<float>(a) << std::endl;
	}
	catch (const TCastExe & e)
	{
		std::cout << a << " " << e.what() << std::endl;
	}
	a = "true";
	try
	{
		std::cout << fromString<bool>(a) << std::endl;
	}
	catch (const TCastExe & e)
	{
		std::cout << a << " " << e.what() << std::endl;
	}
	a = "-2147483648.01";
	try
	{
		
		std::cout << std::fixed << fromString<float>(a) << std::endl;
	}
	catch (const TCastExe & e)
	{
		std::cout << a << " " << e.what() << std::endl;
	}
}