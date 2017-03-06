#pragma once
#include "TAnimal.h"

const float STEP = 1.0;

class TZoo
{
	typedef TAnimal * TPtrAnimal;


	/// �����
	TPtrAnimal * Animals;

	/// ������������ ����������� ��������
	size_t Capacity;

	/// ���������� ������ � ��������
	size_t NumAnimals;

	/// ����� �����
	float Time;
public:
	TZoo(size_t capacity);
	bool AddNewAnimal(TAnimal ** newAnimal);
	void Work();
	~TZoo();
	bool DeleteAnimal(size_t k);
	bool Check();
	float GetTime();
	TAnimal ** operator [](size_t index);
	TAnimal ** operator[](size_t index) const;
	//TAnimal operator[](size_t index) const;
	//TAnimal operator [](size_t index) const
	

};