#include<iostream>
#include <initializer_list>
#include <exception>

template <class T, std::size_t N>
struct TArray
{
private:
	T mass[N];
public:
	TArray() = default;
	~TArray() = default;
	TArray(std::initializer_list<T> is) 
	{
		int i = 0;
		for (auto & v : is)
		{
			mass[i] = v;
			++i;
		}
	}
	T* begin()
	{
		return mass;
	}
	T* end()
	{
		return mass + N;
	}
	size_t size()
	{
		return N;
	}
	size_t max_size()
	{
		return N;
	}
	bool empty()
	{
		for (int i = 0; i < N; ++i)
			if (mass[i])
				return false;
		return true;
	}
	T & operator[](int index)
	{
		return mass[index];
	}
	T& front()
	{
		return mass[0];
	}
	T& back()
	{
		return mass[N - 1]; 
	}
	T* data()
	{
		return mass;
	}
	void fill(T value)
	{
		for (int i = 0; i < N; ++i)
			mass[i] = value;
	}
	void swap(TArray <T, N > & arr)
	{
		std::swap(arr.mass, mass);
	}
	T& at(int index)
	{
		if (index < 0 || index >= N)
			throw std::out_of_range("Error");
		return mass[index];
	}
	bool operator==(TArray <T, N > & arr)
	{
		if (memcmp(mass, arr.mass, N) == 0)
			return true;
		return false;
	}
	bool operator!=(TArray <T, N > & arr)
	{
		if (!(mass == arr.mass))
			return true;
		return false;
	}
	bool operator>(TArray <T, N > & arr)
	{
		if (memcmp(mass, arr.mass, N) > 0)
			return true;
		return false;
	}
	bool operator<(TArray <T, N > & arr)
	{
		if ( !(mass > arr.mass) && mass != arr.mass)
			return true;
		return false;
	}
	bool operator>=(TArray <T, N > & arr)
	{
		if (mass == arr.mass || mass > arr.mass)
			return true;
		return false;
	}
	bool operator<=(TArray <T, N > & arr)
	{
		if (mass == arr.mass || mass < arr.mass)
			return true;
		return false;
	}
};

int main()
{
	TArray <int, 2> b = { 1, 2 };
	TArray <int, 2> c = { 3, 4 };
	std::cout << b[0] << " " << b[1] <<  std::endl;
	b.fill(1);
	std::cout << b[0] << " " << b[1] << std::endl;
	b.swap(c);
	std::cout << "New mass:" << std::endl;
	std::cout << b[0] << " " << b[1] << std::endl;
	std::cout << c[0] << " " << c[1] << std::endl;
	std::cout << b.front() << " " << b.back() << std::endl;
	std::cout << c.begin() << " " << c.end() << std::endl;
	if (!c.empty())
	{
		std::cout << "This object(c) is not empty" << std::endl;
	}
	TArray <int, 2> a = { 3, 4 };
	if (a == b)
	{
		std::cout << "A and B are the same" << std::endl;
	}
	if (b > c)
	{
		std::cout << "B is bigger" << std::endl;
	}
	if (a != c)
	{
		std::cout << "A and C are not the same" << std::endl;
	}
}