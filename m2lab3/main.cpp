#include "TInteger.h"

int main() {
	TInteger one(128);
	int two = 4;
	try 
	{
		one = one + two;
		std::cout << one << std::endl;
	}
	catch (const std::exception & e) 
	{
		std::cout << e.what() << std::endl;
	}
	try 
	{
		one -= two;
		std::cout << one << std::endl;
	}
	catch (const std::exception & e) 
	{
		std::cout << e.what() << std::endl;
	}
	try 
	{
		std::cout << one * two << std::endl;
	}
	catch (const std::exception & e) 
	{
		std::cout << e.what() << std::endl;
	}
		try 
		{
			one = one / two;
			std::cout << one << std::endl;
		}
		catch (const std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
		
	one = 21474;
	two = 21473;
	if (one != two) std::cout << "one != two" << std::endl;
	try 
	{
		TInteger one(1234);
		std::cout << one << std::endl;
	}
	catch (const std::exception & e) 
	{
		std::cout << e.what() << std::endl;
	}

	
	
}