#include <iostream>
#include <vector>
#include <queue>

template<typename T>
class Heap
{
public:

	Heap()
	{
	}

	Heap(int Capacity)
	{
		Reserve(Capacity);
	}

	~Heap()
	{
		for (int i = 0; i < HeapArr.size(); i++)
		{
			delete HeapArr[i];
			HeapArr[i] = nullptr;
		}
	}

	void Reserve(int Capacity)
	{
		HeapArr.reserve(Capacity + 1);
	}

	int Top()
	{
		return *HeapArr[1];
	}

	void Pop()
	{
		HeapArr.erase(std::next(HeapArr.begin()));

		if (HeapArr.size() >= 4)
		{
			if (*HeapArr[1] < *HeapArr[3])
			{
				std::swap(HeapArr[1], HeapArr[3]);
			}
		}

		if (HeapArr.size() >= 3)
		{
			if (*HeapArr[1] < *HeapArr[2])
			{
				std::swap(HeapArr[1], HeapArr[2]);
			}
		}
	}

	void Push(T Value)
	{
		HeapArr.push_back(new T(Value)); //넣고

		int CurIndex = static_cast<int>(HeapArr.size()) - 1;
		int ParentIndex = FindParent(CurIndex);

		//루트노드까지
		while (ParentIndex != 0)
		{
			//부모보다 자식이 크면 값을 바꿔줌
			if (*HeapArr[ParentIndex] > *HeapArr[CurIndex])
			{
				break;
			}

			std::swap(HeapArr[ParentIndex], HeapArr[CurIndex]);
			CurIndex = ParentIndex;
			ParentIndex = FindParent(CurIndex);
		}
	}

private:
	
	int FindParent(int ChildIndex)
	{
		return ChildIndex / 2;
	}

	int FindLeft(int ParentIndex)
	{
		return ParentIndex * 2;
	}

	int FindRight(int ParentIndex)
	{
		return ParentIndex * 2 + 1;
	}

	std::vector<T*> HeapArr = std::vector<T*>({ nullptr }); //계산하기 편하도록 1부터 시작
};

int main()
{
	Heap<int> A(6);

	A.Push(10);
	std::cout << A.Top() << std::endl;

	A.Push(20);
	std::cout << A.Top() << std::endl;

	A.Push(15);
	A.Push(12);
	A.Push(30);
	std::cout << A.Top() << std::endl;

	A.Push(13);

	A.Pop();
	std::cout << A.Top() << std::endl;
	A.Pop();
	std::cout << A.Top() << std::endl;
	A.Pop();
	std::cout << A.Top() << std::endl;
	A.Pop();
	std::cout << A.Top() << std::endl;
	A.Pop();
	std::cout << A.Top() << std::endl;

	int a = 0;
	
	return 0;
}