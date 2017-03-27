
#ifndef __TVECTOR_INCLUDED__
#define __TVECTOR_INCLUDED__
#include<string>
template <typename T>
class TVector
{
public:
	using value_type = T;
	using size_type = size_t;
	using iterator = value_type *;
	using reference = value_type&;
	using const_reference = const value_type&;

private:
	value_type * Ptr;
	size_type Count;
	size_type InternalCapacity;
public:
	TVector()
		: Ptr(nullptr)
		, Count(0)
		, InternalCapacity(0)
	{ }

	TVector(size_type capacity)
		: Count(0)
		, InternalCapacity(capacity)
	{
		Ptr = new value_type[InternalCapacity];
	}

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

	void reserve(size_type size)
	{
		if (size < InternalCapacity) return;
		value_type* ptr = new value_type[size];
		memcpy(ptr, Ptr, Count * sizeof(size_type));
		delete[] Ptr;
		Ptr = ptr;
		InternalCapacity = size;
	}

	TVector(const TVector& rhs)
	{
		this->reserve(rhs.InternalCapacity);
		memcpy(Ptr, rhs.Ptr, rhs.Count * sizeof(size_type));
		Count = rhs.Count;
	}

	TVector& operator=(const TVector& rhs)
	{
		if (this == &rhs) return *this;
		this->reserve(rhs.InternalCapacity);
		Count = rhs.Count;
		memcpy(Ptr, rhs.Ptr, Count * sizeof(size_type));
		return *this;
	}

	void push_back(const value_type& value)
	{
		if (InternalCapacity == Count)
			this->reserve(InternalCapacity + 1);
		Ptr[Count] = value;
		Count++;

	}

	reference at(size_type index)
	{
		if (index < 0 || index >= Count)
			throw std::exception("Error: there is not such number\n");
		return Ptr[index];
	}

	value_type at(size_type index) const
	{
		if (index < 0 || index >= Count)
			throw std::exception("Error: there is not such number\n");
		return Ptr[index];
	}

	reference operator[](size_type index)
	{
		if (index < 0 || index >= Count)
			throw std::exception("Error: there is not such number\n");
		return Ptr[index];
	}

	const_reference operator[](size_type index) const
	{
		if (index < 0 || index >= Count)
			throw std::exception("Error: there is not such number\n");
		return Ptr[index];
	}

	reference front()
	{
		if (Count == 0)
			throw std::exception("Error: there is not such number\n");
		return Ptr[0];
	}

	const_reference front() const
	{
		if (Count == 0)
			throw std::exception("Error: there is not such number\n");
		return Ptr[0];
	}

	reference back()
	{
		if (Count == 0)
			throw std::exception("Error: there is not such number\n");
		return Ptr[Count - 1];
	}

	const_reference back() const
	{
		if (Count == 0)
			throw std::exception("Error: there is not such number\n");
		return Ptr[Count - 1];
	}

	void clear()
	{
		if (Ptr != nullptr)
		{
			delete[] Ptr;
			Count = 0;
			InternalCapacity = 0;
		}
	}

	void pop_back()
	{
		if (Count == 0)
			throw std::exception("Error: This vector is empty!\n");
		value_type* ptr = new value_type[Count - 1];
		memcpy(ptr, Ptr, (Count - 1) * sizeof(size_type));
		delete Ptr;
		Ptr = ptr;
		Count = Count - 1;
	}

	void swap(TVector& other) throw()
	{
		TVector ptr = other;
		other = *this;
		*this = ptr;
	}

	void resize(size_type count, value_type value = value_type())
	{
		if (count < Count)
		{
			size_type co = Count - count;
			for (int i = 0; i < co; ++i)
			{
				this->pop_back();
			}
			Count = count;
		}
		if (count > Count)
		{
			this->reserve(count);
			for (int i = Count; i < count; ++i)
			{
				this->push_back(value);
			}
			Count = count;
		}
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
