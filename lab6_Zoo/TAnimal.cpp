#include "TAnimal.h"
#include<iostream>


TAnimal::TAnimal()
	: Name()
	, Age(0)
	, Death(0)
	, Born(-1)
	, Children(0)
{ }

TAnimal::TAnimal(const std::string & name)
	: Name(name)
	, Age(0)
	, Death(0)
	, Born(-1)
	, Children(0)
{ }

std::string TAnimal::GetName() const
{
	return Name;
}

size_t TAnimal::GetAge() const
{
	return Age;
}
size_t TAnimal::GetDeath()
{
	return Death;
}
bool TAnimal::PAge()
{
	Age = ++Age;
	return true;
}
size_t TAnimal::GetBorn()
{
	return Born;
}
bool TAnimal::EndChi()
{
	Children = 0;
	return true;
}
size_t TAnimal::GetChil()
{
	return Children;
}
bool TAnimal::NullBorn()
{
	Born = 0;
	return true;
}
