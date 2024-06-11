#include <iostream>
#include <vector>

std::vector<int*> HeapArr;

int FindParent(int ChildIndex)
{
	return ChildIndex / 2;
}

void Push(int Value)
{
	HeapArr.push_back(new int(Value)); //넣고

	int CurIndex = static_cast<int>(HeapArr.size()) - 1;
	int ParentIndex = FindParent(CurIndex);

	//부모보다 자식이 크면 값을 바꿔줌
	while (*HeapArr[ParentIndex] < *HeapArr[CurIndex])
	{
		std::swap(HeapArr[ParentIndex], HeapArr[CurIndex]);
		CurIndex = ParentIndex;
		ParentIndex = FindParent(CurIndex);

		if (ParentIndex == 0)
		{
			break;
		}
	}
}

int main()
{
	HeapArr.reserve(1025);

	Push(10);
	Push(20);
	Push(15);
	Push(12);
	Push(11);
	Push(13);

	for (int i = 0; i < HeapArr.size(); i++)
	{
		delete HeapArr[i];
		HeapArr[i] = nullptr;
	}

	return 0;
}