#include <iostream>
#include <list>
#include <crtdbg.h>
#include <assert.h>
#include <string>

//typedef int T;
template <typename T>
class MyList
{
private:
	class Node
	{
	public:
		~Node()
		{
			if (next == nullptr)
			{
				return;
			}
			delete next;
		}

		T Value = T();
		Node* prev = nullptr;
		Node* next = nullptr;
		bool IsHead = false;
	};

public:
	class iterator
	{
		friend MyList;
	public:
		iterator()
			:Iter(nullptr)
		{}

		iterator operator++(int)
		{
			assert(!Iter->IsHead);
			Iter = Iter->next;
			return *this;
		}

		iterator operator++()
		{
			assert(!Iter->IsHead);
			iterator temp = Iter;
			Iter = Iter->next;
			return temp;
		}

		bool operator==(const iterator& _Values)
		{
			return _Values.Iter == Iter;
		}

		bool operator!=(const iterator& _Values)
		{
			return _Values.Iter != Iter;
		}

		T& operator*()
		{
			return Iter->Value;
		}

	private:
		iterator(Node* _ptr)
			:Iter(_ptr)
		{

		}

		Node* Iter;
	};

	MyList()
		:Myhead()
	{
		Myhead.prev = &Myhead;
		Myhead.next = &Myhead;
		Myhead.IsHead = true;
	}

	~MyList()
	{
		Myhead.prev->next = nullptr;
	}

	void push_back(const T& _Value)
	{
		Node* tempNode = new Node;

		tempNode->Value = _Value;
		tempNode->next = &Myhead;
		tempNode->prev = Myhead.prev;
		Myhead.prev->next = tempNode;
		Myhead.prev = tempNode;
	}

	void push_front(const T& _Value)
	{
		Node* tempNode = new Node;
		tempNode->Value = _Value;
		tempNode->next = Myhead.next;
		tempNode->prev = &Myhead;
		Myhead.next->prev = tempNode;
		Myhead.next = tempNode;
	}

	void pop_back()
	{
		Node* tempNode = Myhead.prev;
		tempNode->prev->next = &Myhead;
		Myhead.prev = tempNode->prev;
		tempNode->next = nullptr;
		delete tempNode;
	}

	void pop_front()
	{
		Node* tempNode = Myhead.next;
		tempNode->next->prev = &Myhead;
		Myhead.next = tempNode->next;
		tempNode->next = nullptr;
		delete tempNode;
	}

	iterator begin()
	{
		return iterator(Myhead.next);
	}

	iterator end()
	{
		return iterator(&Myhead);
	}

private:
	Node Myhead;
};

int main()
{
	{
		new int; //leak check

		std::list<int> A;

		A.push_back(10);
		A.push_back(20);
		A.push_back(30);
		A.push_back(40);

		MyList<int> B;
		B.push_back(0);
		B.push_back(0);
		B.push_back(0);
		B.push_front(0);
		B.push_front(0);

		//B.pop_back();
		//B.pop_front();
		
		int count = 0;
		for (MyList<int>::iterator CurIter = B.begin(); CurIter != B.end(); ++CurIter)
		{
			*CurIter = count++;
			std::cout << *CurIter << " ";
		}
		std::cout << std:: endl;
	}

	_CrtDumpMemoryLeaks();
	return 0;
}