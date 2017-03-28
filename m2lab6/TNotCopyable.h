#include <iostream>
#include <exception>

class TCastExe : public std::exception
{};

class NotNumber : public TCastExe
{
public:
	const char* what() const
	{
		return "Error: not convertable";
	}
};
class TooMuch : public TCastExe
{
public:
	const char* what() const
	{
		return "Error: overflow";
	}
};