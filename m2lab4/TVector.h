#ifndef __TVECTOR_INCLUDED__
#define __TVECTOR_INCLUDED__
#include<iostream>
#include<exception>
class TVector
{
public:
	using value_type = int;
	using size_type = size_t;
	using iterator = value_type *;
	using reference = value_type&;
	using const_reference = const value_type&;

private:
	value_type * Ptr;
	size_type Count; // kol-vo elem v mass
	size_type InternalCapacity; // skolko znach mozhno pomestit
public:
	TVector()
		: Count(0)
		, InternalCapacity(0) // razmer
	{
		Ptr = new value_type;
	}

	TVector(size_type capacity)
		: Ptr(0),
		Count(0)
		, InternalCapacity(capacity)
	{}

	~TVector()
	{
		delete[] Ptr;
	}

	bool empty() const throw()
	{
		return size() == 0;
	}

	size_type size() const throw()
	{
		return Count;
	}

	size_type capacity() const throw()
	{
		return InternalCapacity;
	}

	iterator begin() const throw()
	{
		return Ptr;
	}

	iterator end() const throw()
	{
		return Ptr + Count;
	}

	void reserve(size_type size) // ustanovlenie capacity
	{
		if (size < InternalCapacity) return;
		value_type * ptr = new value_type[size];
		memcpy(ptr, Ptr, Count * sizeof(size_type));
		delete[] Ptr;
		Ptr = ptr;
		InternalCapacity = size;
		
	}

	TVector(const TVector& rhs)
	{
		Count = rhs.Count;
		InternalCapacity = rhs.InternalCapacity;
		Ptr = new value_type[InternalCapacity];
		memcpy(Ptr, rhs.Ptr, Count * sizeof(value_type));
	}

	TVector& operator=(const TVector& rhs)
	{
		Count = rhs.Count;
		InternalCapacity = rhs.InternalCapacity;
		Ptr = new value_type[InternalCapacity];
		memcpy(Ptr, rhs.Ptr, Count * sizeof(value_type));
		return *this;
	}

	void push_back(const value_type& value) // pomestit v konetz
	{
		if (InternalCapacity == 0)
		{
			reserve(InternalCapacity + 1);
		}
		if (InternalCapacity - Count == 0)
		{
			reserve(InternalCapacity * 2);
		}
		Ptr[Count] = value;
		Count = Count + 1;

	}

	reference at(size_type index)
	{
		if (index < 0 || index >= Count)
			throw std::runtime_error("Error: there is not such number\n");
		return Ptr[index];

	}

	value_type at(size_type index) const
	{
		if (index < 0 || index >= Count)
			throw std::runtime_error("Error: there is not such number\n");
		return Ptr[index];
	}

	reference operator[](size_type index)
	{
		if (index < 0 || index >= Count)
			throw std::runtime_error("Error: there is not such number\n");
		return Ptr[index];
	}

	const_reference operator[](size_type index) const
	{
		if (index < 0 || index >= Count)
			throw std::runtime_error("Error: there is not such number\n");
		return Ptr[index];
	}

	reference front()
	{
		return Ptr[0];
	}

	const_reference front() const
	{
		return Ptr[0];
	}

	reference back()
	{
		return Ptr[Count - 1];
	}

	const_reference back() const
	{
		return Ptr[Count - 1];
	}

	void clear()
	{
		delete[] Ptr;
		InternalCapacity = 0;
		Count = 0;
	}

	void pop_back() // ubrat s kontza
	{
		Ptr[Count] = 0;
		Count = Count - 1;
	}

	void swap(TVector& other) throw() //
	{
		value_type * ptr = Ptr;
		Ptr = other.Ptr;
		other.Ptr = ptr;
		int count = Count;
		Count = other.Count;
		other.Count = count;
		count = InternalCapacity;
		InternalCapacity = other.InternalCapacity;
		other.InternalCapacity = count;
	}

	void resize(size_type count, value_type value = value_type()) //
	{
		
		if (Count < count)
		{
			this->reserve(count);

			for (int i = Count; i < count; i++)
			{
				Ptr[i] = value;
			}


		}
		if (Count > count)
		{
			for (int i = count; i < Count; i++)
			{
				Ptr[i] = 0;
			}

		}
		Count = count;
	}

	iterator insert(iterator pos, const value_type& value)
	{
		int tmp;

		for (int i = 0; i < Count; i++)
		{
			if (&(Ptr[i]) == pos)
			{
				tmp = i;
				break;
			}
		}
		reserve(Count + 1);
		value_type *tm = new value_type[Count + 1];
		bool flag = 0;
		for (int i = 0; i < Count + 1; i++)
		{
			if (tmp == i)
			{
				flag = 1;
				tm[i] = value;
			}
			else
			{
				tm[i] = Ptr[i - flag];
			}
		}
		delete[] Ptr;
		Ptr = tm;
		Count += 1;
		InternalCapacity = Count;

		return &(Ptr[tmp]);
	}

	void insert(iterator pos, size_type count, const value_type& value)
	{
		int tmp;

		for (int i = 0; i < Count; i++)
		{
			if (&(Ptr[i]) == pos)
			{
				tmp = i;
				break;
			}
		}
		reserve(Count + count);
		value_type *tm = new value_type[InternalCapacity];
		int flag = count;
		for (int i = 0; i < Count + count; i++)
		{
			if (i < tmp)
			{
				tm[i] = Ptr[i];
			}
			else
			{
				if (flag > 0)
				{
					tm[i] = value;
					flag--;
				}
				else
				{
					tm[i] = Ptr[i - count];
				}
			}
		}
		delete[] Ptr;
		Ptr = tm;
		Count += count;

	}

	iterator erase(iterator pos)
	{
		int tmp;
		bool count = 0;
		for (int i = 0; i < Count; i++)
		{
			if (&(Ptr[i]) == pos)
			{
				tmp = i;
				break;
			}
		}
		value_type *tm = new value_type[Count - 1];
		for (int i = 0; i < Count - 1; i++)
		{
			if (i >= tmp)
			{
				count = 1;
				//tm[i] ==
			}
			tm[i] = Ptr[i + count];
		}
		delete[] Ptr;
		Ptr = tm;
		Count -= 1;
		InternalCapacity = Count - 1; 
		return &(Ptr[tmp]);

	}

	iterator erase(iterator first, iterator last)
	{
		int tmp;

		int left(0), right(Count - 1);

		for (int i = 0; i < Count; i++)
		{
			if (&(Ptr[i]) == first)
			{
				left = i;
			}
			if (&(Ptr[i]) == last)
			{
				right = i;
			}
		}

		int count = right - left + 1;

		value_type *tm = new int[Count - count];
		for (int i = 0; i < Count - count; i++)
		{
			if (i >= left)
			{
				tm[i] = Ptr[i + count];
			}
			else
			{
				tm[i] = Ptr[i];
			}

		}
		delete Ptr;
		Ptr = tm;
		Count -= count;
		InternalCapacity = Count;
		return &(Ptr[left]);
	}
};


#endif // __TVECTOR_INCLUDED__