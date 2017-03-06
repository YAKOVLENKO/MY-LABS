#include "TZoo.h"
#include<iostream>


TZoo::TZoo(size_t capacity)
	: Capacity(capacity)
	, NumAnimals(0)
	, Time(0)
{
	Animals = new TPtrAnimal[Capacity];
	memset(Animals, 0, sizeof(TPtrAnimal) * Capacity);
}

bool TZoo::AddNewAnimal(TAnimal ** newAnimal)
{
	// Проверяем корректность входного параметра
	if (newAnimal == nullptr)
		return false;

	// Зоопарк полон, нельзя добавить нового зверя
	if (NumAnimals == Capacity)
		return false;

	// Добавляем зверя в массив
	Animals[NumAnimals] = *newAnimal;

	// Забираем зверя у старого владельца, чтобы не удалить зверя дважды
	*newAnimal = nullptr;

	// Увеличиваем счетчик
	++NumAnimals;

	return true;
}

void TZoo::Work()
{
	(*this).Check();
	for (size_t i = 0; i < NumAnimals; ++i)
	{
		if (Animals[i] != nullptr)
			// Демонстрация работы динамического полиморфизма
			Animals[i]->Live(Time);

	}
	for (size_t i = 0; i < NumAnimals; ++i)
	{
		for (size_t j = i + 1; j < NumAnimals; ++j)
		{
			if (Animals[i]->GetBorn() == Animals[j]->GetBorn() 
				&& Animals[i]->GetBorn() == Animals[i]->GetAge() 
					&& Animals[j]->GetBorn() == Animals[j]->GetAge()
						&& Animals[i]->GetChil() != 0 
							&& Animals[j]->GetChil() != 0
								&& Animals[i]->GetBorn() == Time)
			{
				TAnimal * newCC = Animals[i]->BChil();
				AddNewAnimal(&newCC);
			}
		}
	}

	Time += STEP;
	if (Time > 24.f)
	{
		for (size_t i = 0; i < NumAnimals; ++i)
		{
			Animals[i]->PAge();
		}
		Time -= 24.f;
	}
}


TZoo::~TZoo()
{
	for (size_t i = 0; i < NumAnimals; ++i)
	{
		delete Animals[i];
	}
	delete[] Animals;
}


bool TZoo::DeleteAnimal(size_t k) 
{
		Animals[k] = nullptr;

		for (int i = k + 1; i < NumAnimals; i++)
		{
			Animals[i - 1] = Animals[i];
		}
		NumAnimals = NumAnimals - 1;
	return true;
}
bool TZoo::Check()
{
	size_t* k;
	size_t l = 0;
	size_t h = 0;
	for (size_t i = 0; i < NumAnimals; ++i)
	{
		if (Animals[i]->GetAge() >= Animals[i]->GetDeath())
			++l;
	}
	k = new size_t[l];
	for (size_t i = 0; i < NumAnimals; ++i)
	{
		if (Animals[i]->GetAge() >= Animals[i]->GetDeath())
		{
			k[h] = i;
			++h;
		}
	}

	int t = 0;
	for (h = 0; h < l; h++)
	{
		(*this).DeleteAnimal(k[h+t]);
		t -= 1;
	}
	return true;
}
float TZoo::GetTime()
{
	return Time;
}
TAnimal ** TZoo::operator [](size_t index)
{
	return &Animals[index];
}
TAnimal ** TZoo::operator [](size_t index) const
{
	return &Animals[index];
}
