#include <thread>
#include <iostream>
#include "TZoo.h"
#include "TProboscidea.cpp"
#include "TArtiodactyla.cpp"
#include "TCarnivora.cpp"
class TCat
	: public TAnimal
{
public:
	TCat(const std::string & name)
		: TAnimal(name)
	{ 
		Death = 2;
		Born = 1;
	}

	virtual void Live(float time) override
	{
		// с 6 до 7 кот ест
		if (time >= 6.f && time <= 7.f)
			std::cout << GetName() << " is eating" << std::endl;

		// остальное время спит
		else
			std::cout << GetName() << " is sleeping" << std::endl;
	}
	virtual TAnimal * BChil()
	{
		(*this).NullBorn();
		std::string nsname;
		std::cout << "Write name";
		std::cin >> nsname;
		TAnimal *newcat = new TCat(nsname);
		return newcat;
	}
	
};

class TPussInBoots
	: public TCat
{
public:
	TPussInBoots(const std::string & name)
		: TCat(name)
	{ 
		Death = 2;
		Born = 1;
		Children = 1;
	}

	virtual void Live(float time) override
	{
		// с 6 до 7 кот в сапогах ест
		if (time >= 6.f && time <= 7.f)
			std::cout << GetName() << " is eating" << std::endl;
		// с 8 до 15 кот в сапогах спит
		else if (time >= 8.f && time <= 15.f)
			std::cout << GetName() << " is sleeping" << std::endl;
		// остальное время бежит
		else
			std::cout << GetName() << " is running" << std::endl;
	}
	virtual TAnimal * BChil()
	{
		
		std::string nsname;
		std::cout << "Write name";
		std::cin >> nsname;
		TAnimal *newcat = new TPussInBoots(nsname);
		return newcat;
	}
};
bool Exchange(TZoo &zoo0, TZoo &zoo1, size_t ind0, size_t ind1)
{
	if ((*(zoo1[ind1]))->GetBorn() == (*(zoo0[ind0]))->GetBorn())
	{
		zoo0.AddNewAnimal(zoo1[ind1]);
		zoo1.AddNewAnimal(zoo0[ind0]);
		zoo0.DeleteAnimal(ind0);
		zoo1.DeleteAnimal(ind1);
		return true;
	}
	return false;
}

int main()
{
	TZoo myZoo(10);
	TZoo yourZoo(10);

	TAnimal * myCat = new TProboscidea("Snowball");
	TAnimal * catCalledGav = new TElephas("Gav");
	TAnimal * pussBoots = new TElephas("TPussInBoots");
	TAnimal * pussBoots1 = new TLoxodonta("TPussInBoots1");
	TAnimal * myCa1t = new THippopotamus("Snowbally");
	// если не удалось добавить, то очищаем память
	if (!myZoo.AddNewAnimal(&myCat))
		delete myCat;
	// если не удалось добавить, то очищаем память
	if (!myZoo.AddNewAnimal(&catCalledGav))
		delete catCalledGav;
	// если не удалось добавить, то очищаем память
	if (!myZoo.AddNewAnimal(&pussBoots))
		delete pussBoots;
	if (!myZoo.AddNewAnimal(&pussBoots1))
		delete pussBoots1;
	if (!myZoo.AddNewAnimal(&myCa1t))
		delete myCa1t;
	TAnimal * Nick = new TProboscidea("Nick");
	TAnimal * Car = new TGiraffa("Car");
	TAnimal * Lim = new TArtiodactyla("Lim");
	TAnimal * Ted = new TCarnivora("Ted");
	TAnimal * Snow = new TTigirs("Snow");
	TAnimal * Yo = new TLeo("Yo");
	TAnimal * Mike = new TLeo("Mike");
	if (!yourZoo.AddNewAnimal(&Nick))
		delete Nick;
	if (!yourZoo.AddNewAnimal(&Car))
		delete Car;
	if (!yourZoo.AddNewAnimal(&Lim))
		delete Lim;
	if (!yourZoo.AddNewAnimal(&Ted))
		delete Ted;
	if (!yourZoo.AddNewAnimal(&Snow))
		delete Snow;
	if (!yourZoo.AddNewAnimal(&Yo))
		delete Yo;
	if (!yourZoo.AddNewAnimal(&Mike))
		delete Mike;

	for (size_t i = 0; i < 100; ++i)
	{
		if (myZoo.GetTime() == 5)
			Exchange(myZoo, yourZoo, 0, 0);
		std::cout << "MyZoo:" <<std::endl;
		myZoo.Work();
		std::cout << std::endl;
		std::cout << "YourZoo:" <<std::endl;
		yourZoo.Work();
		std::cout << std::endl;
		// поток ждет 1 секунду
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	system("pause");
}