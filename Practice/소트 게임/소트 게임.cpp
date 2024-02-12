#include <iostream>
#include <stack>
#include <queue>
#include <unordered_map>

//�����°� �������� �˷��ִ� �Լ�
bool IsPossibleReversArr(const std::string& Arr, int StartIndex, int ReversSize)
{
	size_t ArrLastIndex = Arr.size() - 1;
	size_t ReversLastIndex = StartIndex + ReversSize - 1;
	return ArrLastIndex >= ReversLastIndex;
}

//���� ���� �ε��� a���� b�� ������ �Լ�
bool Revers(std::string& Arr, int StartIndex, int ReversSize)
{
	if (!IsPossibleReversArr(Arr, StartIndex, ReversSize))
	{
		return false;
	}

	std::stack<char> Stack;

	for (size_t i = StartIndex; i < StartIndex + ReversSize; i++)
	{
		Stack.push(Arr[i]);
	}

	for (size_t i = StartIndex; i < StartIndex + ReversSize; i++)
	{
		Arr[i] = Stack.top();
		Stack.pop();
	}

	return true;
}

int BFS(const std::string& StartArr, const std::string& EndArr, int ReversSize)
{
	std::queue<std::string> q;
	std::unordered_map<std::string, int> Depth;
	q.push(StartArr);
	Depth[StartArr] = 0;

	while (!q.empty())
	{
		std::string CheckArr = q.front();
		q.pop();

		if (CheckArr == EndArr)
		{
			if (Depth.find(EndArr) == Depth.end())
			{
				Depth[EndArr] = 0;
			}

			return Depth[EndArr];
		}

		for (int i = 0; CheckArr.size(); i++)
		{
			std::string LinkArr = CheckArr;
			if (!Revers(LinkArr, i, ReversSize))
			{
				break;
			}

			if (Depth.find(LinkArr) != Depth.end())
			{
				continue;
			}

			q.push(LinkArr);
			Depth[LinkArr] = Depth[CheckArr] + 1;
		}
	}

	return -1;
}

int main()
{
	int N, K;
	std::cin >> N >> K;

	std::string Arr;
	Arr.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		std::cin >> Arr[i];
	}

	std::string SortedArr;
	SortedArr.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		SortedArr[i] = i + 1 + '0';
	}

	int Answer = BFS(Arr, SortedArr, K);
	std::cout << Answer;

	return 0;
}

//����ȭ -> ��Ʈ�� ���ʹ� hashmap�� key�� �� �� ��� str�� �ٲٰ� hashmap���� �޸�, �ð� ��¿�� ����