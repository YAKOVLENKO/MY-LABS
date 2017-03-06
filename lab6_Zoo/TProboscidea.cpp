#include "TAnimal.h"
#include<iostream>

class TProboscidea : public TAnimal
{
public:
	TProboscidea(const std::string & name)
		: TAnimal(name)
	{
		Death = 3;
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
		TAnimal *newcat = new TProboscidea(nsname);
		return newcat;
	}
};
class TElephas
	: public TProboscidea
{
public:
	TElephas(const std::string & name)
		: TProboscidea(name)
	{
		Death = 3;
		Born = 2;
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
		TAnimal *newcat = new TElephas(nsname);
		return newcat;
	}

};
class TLoxodonta
	: public TProboscidea
{
public:
	TLoxodonta(const std::string & name)
		: TProboscidea(name)
	{
		Death = 2;
		Born = 1;
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
		TAnimal *newcat = new TLoxodonta(nsname);
		return newcat;
	}
};