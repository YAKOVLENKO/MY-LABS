#pragma once
#include <string>


class TAnimal
{
	std::string Name;
	size_t Age;
protected:
	size_t Death;
	size_t Born;
	size_t Children;

public:
	TAnimal();
	TAnimal(const std::string & name);

	/// Используем деструктор по умолчанию.
	/// т.к. специальных действия для очистки объектов не требуется
	virtual ~TAnimal() = default;

	/// Абстрактный метод
	/// <param name="time"> Время суток </param>
	virtual void Live(float time) = 0;
	std::string GetName() const;
	size_t GetAge() const;
	size_t GetDeath();
	bool PAge();
	size_t GetBorn();
	bool EndChi();
	size_t GetChil();
	virtual TAnimal * BChil() = 0;
	bool NullBorn();
};
