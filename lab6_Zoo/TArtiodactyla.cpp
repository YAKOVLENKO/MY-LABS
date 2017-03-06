#include "TAnimal.h"
#include<iostream>

class TArtiodactyla : public TAnimal
{
public:
	TArtiodactyla(const std::string & name)
		: TAnimal(name)
	{
		Death = 5;
		Born = 0;
	}

	virtual void Live(float time) override
	{
		if (time >= 8.f && time <= 19.f)
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
		TAnimal *newcat = new TArtiodactyla(nsname);
		return newcat;
	}
};
class TGiraffa
	: public TArtiodactyla
{
public:
	TGiraffa(const std::string & name)
		: TArtiodactyla(name)
	{
		Death = 6;
		Born = 5;
		Children = 1;
	}

	virtual void Live(float time) override
	{
		{
			if (time >= 8.f && time <= 19.f)
				std::cout << GetName() << " is eating" << std::endl;
			else
				if (time > 19.f && time < 23.f)
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
		TAnimal *newcat = new TGiraffa(nsname);
		return newcat;
	}
};
class THippopotamus
	: public TArtiodactyla
{
public:
	THippopotamus(const std::string & name)
		: TArtiodactyla(name)
	{
		Death = 7;
		Born = 6;
		Children = 1;
	}

	virtual void Live(float time) override
	{
		{
			if ((time >= 8.f && time <= 12.f) || (time >= 18.f && time <= 23.f))
				std::cout << GetName() << " is eating" << std::endl;
			else
				if (time > 12.f && time < 18.f)
					std::cout << GetName() << " is swimming" << std::endl;
				else
					std::cout << GetName() << " is sleeping" << std::endl;
		}
	}
	virtual TAnimal * BChil()
	{

		std::string nsname;
		std::cout << "Write name";
		std::cin >> nsname;
		TAnimal *newcat = new THippopotamus(nsname);
		return newcat;
	}
};