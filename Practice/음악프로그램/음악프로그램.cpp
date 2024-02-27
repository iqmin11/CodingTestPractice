#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>> LinkNode;
std::vector<int> InDgree;

bool TopologySort(std::vector<int>& _result)
{
	std::vector<int>& result = _result;

	std::queue<int> q;

	for (size_t i = 0; i < InDgree.size(); i++)
	{
		if (InDgree[i] == 0)
		{
			q.push(i);
		}
	}

	for (size_t i = 0; i < InDgree.size(); i++)
	{
		if (q.empty())
		{
			return false;
		}

		int CheckIndex = q.front();
		q.pop();
		result.push_back(CheckIndex);

		for (auto& LinkNode : LinkNode[CheckIndex])
		{
			if (--InDgree[LinkNode] == 0)
			{
				q.push(LinkNode);
			}
		}
	}

	return true;
}

int main()
{
	int N, M;

	std::cin >> N >> M;

	LinkNode.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		LinkNode.reserve(N);
	}

	InDgree.resize(N, 0);

	std::vector<std::vector<int>> TopologyInfo;
	TopologyInfo.resize(M);

	for (size_t i = 0; i < M; i++)
	{
		int Size;
		std::cin >> Size;
		TopologyInfo[i].resize(Size);
		for (size_t j = 0; j < Size; j++)
		{
			int temp;
			std::cin >> temp;
			--temp;
			TopologyInfo[i][j] = temp;
		}

		for (size_t j = 0; j < Size - 1; j++)
		{
			LinkNode[TopologyInfo[i][j]].push_back(TopologyInfo[i][j + 1]);
			++InDgree[TopologyInfo[i][j + 1]];
		}
	}

	std::vector<int> Answer;
	Answer.reserve(N);
	if (TopologySort(Answer))
	{
		for (size_t i = 0; i < N; i++)
		{
			std::cout << Answer[i] + 1 << "\n";
		}
	}
	else
	{
		std::cout << 0;
	}

	return 0;
}