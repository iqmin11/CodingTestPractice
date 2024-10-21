//���� �ּ� : https://www.acmicpc.net/problem/15900

#include <iostream>
#include <vector>

int N;
std::vector<std::vector<int>> LinkedInfo;
std::vector<bool> IsVisit;
int Depth = -1;
int Answer = 0;

void DFS(int CurNode)
{
	++Depth;
	IsVisit[CurNode] = true;
	bool IsLeafNode = true;

	for (auto CheckNode : LinkedInfo[CurNode])
	{
		if (IsVisit[CheckNode])
		{
			continue;
		}

		IsLeafNode = false;
		DFS(CheckNode);
	}

	if (IsLeafNode)
	{
		Answer += Depth;
	}
	--Depth;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	//��Ʈ ��忡�� ���� �������� �Ÿ��� ���� ���Ѵ�
	std::cin >> N;
	LinkedInfo.resize(N);
	IsVisit.resize(N, false);
	for (int i = 0; i < N - 1; i++)
	{
		int From, To;
		std::cin >> From >> To;
		From--;
		To--;

		LinkedInfo[From].push_back(To);
		LinkedInfo[To].push_back(From);
	}

	int RootNode = 0;

	DFS(RootNode);

	if (Answer % 2 == 1)
	{
		std::cout << "Yes";
	}
	else
	{
		std::cout << "No";
	}

	return 0;
}