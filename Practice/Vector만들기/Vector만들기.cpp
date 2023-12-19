#include <iostream>
#include <vector>
#include <crtdbg.h>

typedef int T;
//template <typename T>
class MyVector
{
public:
	class iterator
	{
		friend MyVector;
	public:
		iterator() {}
		iterator(const iterator& _Value)
			: Iter(_Value.Iter)
		{}

		iterator operator++()
		{
			++Iter;
			return *this;
		}

		iterator operator++(int)
		{
			iterator temp = *this;
			++Iter;
			return temp;
		}

		iterator operator--()
		{
			--Iter;
			return *this;
		}

		iterator operator--(int)
		{
			iterator temp = *this;
			--Iter;
			return temp;
		}

		bool operator!=(const iterator& _Value)
		{
			return Iter != _Value.Iter;
		}

		bool operator==(const iterator& _Value)
		{
			return Iter == _Value.Iter;
		}

		T operator*()
		{
			return *Iter;
		}

	private:
		iterator(T* _Tptr)
			: Iter(_Tptr)
		{

		}
		T* Iter = nullptr;
	};

public:
	MyVector()
	{
	}

	MyVector(size_t _size)
	{
		m_begin = new T[_size]();
		m_capacity = _size;
		m_size = _size;
	}

	~MyVector()
	{
		delete[] m_begin;
	}

	size_t size() const
	{
		return m_size;
	}

	size_t capacity() const
	{
		return m_capacity;
	}

	void reserve(size_t _capacity)
	{
		m_capacity = _capacity;
		T* TempBegin = new T[_capacity];
		memcpy_s(TempBegin, sizeof(T) * m_size, m_begin, sizeof(T) * m_size);
		delete[] m_begin;
		m_begin = TempBegin;
	}

	void push_back(const T& _Value)
	{
		if (++m_size > m_capacity)
		{
			reserve(m_capacity * 2);
		}

		m_begin[m_size - 1] = _Value;
	}

	void pop_back()
	{
		--m_size;
	}

	MyVector::iterator erase(const MyVector::iterator& _Iterator)
	{
		unsigned __int64 beginptr = reinterpret_cast<unsigned __int64>(m_begin);
		unsigned __int64 eraseptr = reinterpret_cast<unsigned __int64>(_Iterator.Iter);

		size_t Index = (eraseptr - beginptr) / sizeof(T);

		MyVector::iterator NextIter(_Iterator.Iter + 1);

		for (MyVector::iterator CurIter = NextIter; CurIter != end(); CurIter++)
		{
			m_begin[Index++] = *CurIter;
		}
		
		m_size -= 1;
		
		return NextIter;
	}

	MyVector::iterator begin()
	{
		return MyVector::iterator(m_begin);
	}

	MyVector::iterator end()
	{
		return MyVector::iterator(m_begin + m_size);
	}

	T& operator[](size_t _index)
	{
		return m_begin[_index];
	}

private:
	size_t m_capacity = 0;
	size_t m_size = 0;
	T* m_begin = nullptr;
};

int main()
{
	{
		int* Leak = new int;
		std::vector<int> A(10, 2);
		A.push_back(1);
		int count = 0;

		MyVector B(10);

		for (size_t i = 0; i < B.size(); i++)
		{
			B[i] = static_cast<int>(i);
			std::cout << B[i] << " ";
		}
		std::cout << std::endl;
		
		MyVector::iterator AAA = B.begin();
		AAA++;
		AAA++;
		B.erase(AAA);

		for (MyVector::iterator CurIter = B.begin(); CurIter != B.end(); CurIter++)
		{
			std::cout << *CurIter << " ";
		}
		std::cout << std::endl;

		B.reserve(20);

		for (size_t i = 0; i < B.size(); i++)
		{
			std::cout << B[i] << " ";
		}
	}

	_CrtDumpMemoryLeaks();
}