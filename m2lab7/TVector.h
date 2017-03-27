#pragma once
#include<iostream>
#include<stdexcept>

#ifndef __TVECTOR_INCLUDED__
#define __TVECTOR_INCLUDED__
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
		if (Count > size) return;
		value_type *tmp = new value_type[size];
		memcpy(tmp, Ptr, Count * sizeof(value_type));
		delete[] Ptr;
		Ptr = tmp;
		InternalCapacity = size;
	}

	TVector(const TVector& rhs)
	{
		InternalCapacity = rhs.InternalCapacity;
		Count = rhs.Count;
		Ptr = new value_type[InternalCapacity];
		memcpy(Ptr, rhs.Ptr, Count * sizeof(value_type));
	}

	TVector& operator=(const TVector& rhs)
	{
		if (this == &rhs) return *this;
		if (Ptr != nullptr) delete[] Ptr;
		InternalCapacity = rhs.InternalCapacity;
		Count = rhs.Count;
		Ptr = new value_type[InternalCapacity];
		memcpy(Ptr, rhs.Ptr, Count * sizeof(value_type));
		return *this;
	}

	void push_back(const value_type& value)
	{
		if (Count < InternalCapacity) {
			Count++;
			Ptr[Count] = value;
		}
		else {
			this->reserve(InternalCapacity * 2);
			Count++;
			Ptr[Count - 1] = value;
		}
	}

	reference at(size_type index)
	{
		if (index <= Count&&index >= 0) return Ptr[index];
		throw std::out_of_range("Invalide Value\n");
	}

	value_type at(size_type index) const
	{
		if (index <= Count&&index >= 0) return Ptr[index];
		throw std::out_of_range("Invalide Value\n");
	}

	reference operator[](size_type index)
	{
		return Ptr[index];
	}

	const_reference operator[](size_type index) const
	{
		return Ptr[index];
	}

	bool Check() const {
		if (empty()) throw std::length_error("Vector is empty\n");
		return true;
	}

	reference front()
	{
		this->Check();
		return Ptr[0];
	}

	const_reference front() const
	{
		this->Check();
		return Ptr[0];
	}

	reference back()
	{
		this->Check();
		return Ptr[Count - 1];
	}

	const_reference back() const
	{
		this->Check();
		return Ptr[Count - 1];
	}

	void clear()
	{
		Count = 0;
		InternalCapacity = 0;
		delete[] Ptr;
	}

	void pop_back()
	{
		this->Check();
		Count--;
	}

	void swap(TVector& other) throw()
	{
		std::swap(other.Ptr, Ptr);
		std::swap(other.Count, Count);
		std::swap(other.InternalCapacity, InternalCapacity);
	}

	void resize(size_type count, value_type value = value_type())
	{
		if (count > SIZE_MAX) throw std::overflow_error("Invalide value\n");
		if (Count = count) return;
		value_type *tmp = new value_type[count];
		if (count < Count) {
			memcpy(tmp, Ptr, count * sizeof(value_type));
		}
		else {
			memcpy(tmp, Ptr, Count * sizeof(value_type));
			InternalCapacity = count;
			for (Count; Count < count; Count++) {
				tmp[Count] = value;
			}
		}
		Count = count;
		delete[] Ptr;
		Ptr = tmp;
	}

	iterator insert(iterator pos, const value_type& value)
	{
		size_type k = pos - Ptr;
		if (Count == InternalCapacity)
			this->reserve(InternalCapacity * 2);
		Count++;
		size_type count = Count - 1;
		for (count; count > k; count--) {
			Ptr[count] = Ptr[count - 1];
		}
		Ptr[k] = value;
		return pos;
	}

	void insert(iterator pos, size_type count, const value_type& value)
	{
		if (pos > Ptr + Count)  throw std::out_of_range("Invalide value of pos\n");
		size_type k = pos - Ptr;
		if (Count == InternalCapacity)
			this->reserve(InternalCapacity * 2);
		Count += count;
		size_type Num = Count - 1;
		for (Num; Num > k; Num--) {
			Ptr[Num] = Ptr[Num - count];
		}
		for (size_type i = k; i < k + count; i++) {
			Ptr[i] = value;
		}
	}

	iterator erase(iterator pos)
	{
		if (pos > Ptr + Count)  throw std::out_of_range("Invalide value of pos\n");
		size_type i = pos - Ptr;
		for (i; i < Count - 1; i++) {
			Ptr[i] = Ptr[i + 1];
		}
		Count--;
		return pos;
	}

	iterator erase(iterator first, iterator last)
	{
		if ((first > Ptr + Count || last >Ptr + Count) && first > last)
			throw std::out_of_range("Invalide value of pos");
		size_type i = first - Ptr;
		size_type k = last - Ptr;
		for (i; i < Count - k; i++) {
			Ptr[i] = Ptr[i + k];
		}
		Count -= k;
		return first;
	}
};


#endif // __TVECTOR_INCLUDED__