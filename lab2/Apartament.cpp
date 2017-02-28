#include<iostream>
#include"Apartament.h"

	Apartament::Apartament()
	{
		price = 0;
		rooms = 0;
	}
	
	Apartament::Apartament(int count1, int count2)
	{
		price = count1;
		rooms = count2;
	}

	float Apartament::average() //средняя стоимость одной комнаты
	{
		float av = 0;
		av = price / rooms;
		return av;
	}
	
	void Apartament::setPrice(int a)
	{
		price = a;
	}

	void Apartament::setRooms(int a)
	{
		rooms = a;
	}
	std::ostream & operator <<(std::ostream &out,Apartament str)
	{
		out << "price = " << str.getPrice() << " rooms = " << str.getRooms() << std::endl;
		return out;
	}
	int Apartament::getPrice()
	{
		return price;
	}
	int Apartament::getRooms()
	{
		return rooms;
	}