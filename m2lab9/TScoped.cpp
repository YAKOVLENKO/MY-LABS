#ifndef __SCOPED_PTR__
#define __SCOPED_PTR__

template<class T>
class TScopedPtr
{
private:
	T* ptr;
public:
	TScopedPtr(TScopedPtr const &) = delete;
	TScopedPtr & operator=(TScopedPtr const &) = delete;

	explicit TScopedPtr(T * p = nullptr)
	{
		delete ptr;
		ptr = p;
	}

	~TScopedPtr()
	{
		delete ptr;
		
	}

	void reset(T * p = nullptr)
	{
		delete ptr;
		ptr = p;
	}

	T & operator*() const
	{
		return *ptr;
	}

	T * operator->() const
	{
		return ptr;
	}

	T * get() const throw()
	{
		return ptr;
	}

	void swap(TScopedPtr & b) throw()
	{
		std::swap(ptr, b.ptr);
	}

	bool operator! () const throw()
	{
		if (ptr == nullptr)
			return true;
		return false;
	}
		

	explicit operator bool() const throw()
	{
		if (ptr != nullptr)
			return true;
		return false;
	}
};

template<class T>
inline bool operator==(TScopedPtr<T> const & p, std::nullptr_t) throw()
{
	if (p.get == nullptr)
		return true;
	return false;
}

template<class T>
inline bool operator==(std::nullptr_t, TScopedPtr<T> const & p) throw()
{
	if (p.get() == nullptr)
		return true;
	return false;
}

template<class T>
inline bool operator!=(TScopedPtr<T> const & p, std::nullptr_t) throw()
{
	if (p.get() != nullptr)
		return true;
	return false;
}

template<class T>
inline bool operator!=(std::nullptr_t, TScopedPtr<T> const & p) throw()
{
	if (p.get() != nullptr)
		return true;
	return false;
}

template<class T>
inline void swap(TScopedPtr<T> & a, TScopedPtr<T> & b) throw()
{
	std::swap(a.get(), b.get());
}

// get_pointer(p) is a generic way to say p.get()
template<class T>
inline T * get_pointer(TScopedPtr<T> const & p) throw()
{
	return p.get();
}

#endif // __SCOPED_PTR__

