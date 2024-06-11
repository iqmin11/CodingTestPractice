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

// BFS�� �� �ʿ䰡 ����? ������ �ǵڿ� ���°Ŵϱ� �� push_back�ϸ�˴ϴ�.
// Ʈ���� Ư���� ������ ���ؼ� �ǳʶپ ���� ���� �����
// BST���� ���� ������ Ư���� ��쿡�� BFS�Ǵ� DFS�� ���ؼ� �־��ָ� �˴ϴ�.
// ������ ���޾ƿ�~
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

	//�� push_back�ϸ� �׸���
	Push(10);
	Push(20);
	Push(15);
	Push(12);
	Push(11);
	Push(13);
	return 0;
}