#include <iostream>
#include <vector>
#include <queue>
#include <functional>

std::vector<int*> CBTArr;

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

void Push(int Value)
{
	CBTArr.push_back(new int(Value));
}

// BFS로 할 필요가 없죠? 어차피 맨뒤에 들어가는거니까 걍 push_back하면됩니다.
// 트리의 특별한 구조로 인해서 건너뛰어서 들어가는 경우는 없어요
// BST같이 삽입 로직이 특이한 경우에만 BFS또는 DFS를 통해서 넣어주면 됩니다.
// 이제야 깨달아요~
//void Push(int Value)
//{
//	std::queue<int> q;
//	if (CBTArr[1] == nullptr)
//	{
//		CBTArr[1] = new int;
//		*CBTArr[1] = Value;
//		return;
//	}
//
//	q.push(1);
//	std::function<int(int)> LinkFuncs[2] = { FindLeft , FindRight };
//
//	while (!q.empty())
//	{
//		int CurIndex = q.front();
//		q.pop();
//
//		for (int i = 0; i < 2; i++)
//		{
//			int CheckIndex = LinkFuncs[i](CurIndex);
//
//			if (CBTArr[CheckIndex] == nullptr)
//			{
//				CBTArr[CheckIndex] = new int;
//				*CBTArr[CheckIndex] = Value;
//				return;
//			}
//
//			q.push(CheckIndex);
//		}
//	}
//}

int main()
{
	CBTArr.reserve(1025);

	//걍 push_back하면 그만임
	Push(10);
	Push(20);
	Push(15);
	Push(12);
	Push(11);
	Push(13);
	return 0;
}