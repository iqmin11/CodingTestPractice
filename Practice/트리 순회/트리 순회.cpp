//문제 주소 : https://www.acmicpc.net/problem/1991

#include <iostream>
#include <vector>

std::vector<std::vector<int>> LinkNodes;

void DFS(int CurNode, int OrderingOption)
{
	for (int i = 0; i <= 2; i++)
	{
		if (OrderingOption == i)
		{
			std::cout << static_cast<char>(CurNode + 'A');
		}

		if (i == 2)
		{
			break;
		}

		if (LinkNodes[CurNode][i] == '.' - 'A')
		{
			continue;
		}

		DFS(LinkNodes[CurNode][i], OrderingOption);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	LinkNodes.resize(N);
	for (int i = 0; i < N; i++)
	{
		LinkNodes[i].resize(2);
	}

	for (int i = 0; i < N; i++)
	{
		char Root, Left, Right;
		std::cin >> Root >> Left >> Right;

		LinkNodes[Root - 'A'][0] = static_cast<int>(Left - 'A');
		LinkNodes[Root - 'A'][1] = static_cast<int>(Right - 'A');
	}

	DFS(0, 0);
	std::cout << '\n';
	DFS(0, 1);
	std::cout << '\n';
	DFS(0, 2);

	return 0;
}