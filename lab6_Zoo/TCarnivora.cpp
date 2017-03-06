#include "TAnimal.h"
#include<iostream>

class TCarnivora : public TAnimal
{
public:
	TCarnivora(const std::string & name)
		: TAnimal(name)
	{ 
		Death = 5;
		Born = 0;
	}

	virtual void Live(float time) override
	{
		if (time >= 8.f && time <= 23.f)
			std::cout << GetName() << " is eating" << std::endl;
		else
			std::cout << GetName() << " is sleeping" << std::endl;
	}
	virtual TAnimal * BChil()
	{
		(*this).NullBorn();
		std::string nsname;
		std::cout << "Write name";
		std::cin >> nsname;
		TAnimal *newcat = new TCarnivora(nsname);
		return newcat;
	}
};
class TLeo
	: public TCarnivora
{
public:
	TLeo(const std::string & name)
		: TCarnivora(name)
	{
		Death = 4;
		Born = 3;
		Children = 1;
	}

	virtual void Live(float time) override
	{
		{
			if (time >= 8.f && time <= 10.f)
				std::cout << GetName() << " is eating" << std::endl;
			else
				if (time > 10.f && time < 23.f)
					std::cout << GetName() << " is playing" << std::endl;
				else
					std::cout << GetName() << " is sleeping" << std::endl;
		}
	}
	virtual TAnimal * BChil()
	{

		std::string nsname;
		std::cout << "Write name";
		std::cin >> nsname;
		TAnimal *newcat = new TLeo(nsname);
		return newcat;
	}
};
class TTigirs
	: public TCarnivora
{
public:
	TTigirs(const std::string & name)
		: TCarnivora(name)
	{
		Death = 5;
		Born = 4;
		Children = 1;
	}

	virtual void Live(float time) override
	{
		{
			if ((time >= 8.f && time <= 10.f) || (time >= 21.f && time <= 23.f))
				std::cout << GetName() << " is eating" << std::endl;
			else
				if (time > 10.f && time < 21.f)
					std::cout << GetName() << " is lying" << std::endl;
				else
					std::cout << GetName() << " is sleeping" << std::endl;
		}
	}
	virtual TAnimal * BChil()
	{

		std::string nsname;
		std::cout << "Write name";
		std::cin >> nsname;
		TAnimal *newcat = new TTigirs(nsname);
		return newcat;
	}
};