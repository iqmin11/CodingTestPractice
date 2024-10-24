//문제 주소 : https://www.acmicpc.net/problem/12869

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>

int IsVisit[61][61][61];
int Damage[6][3] = 
{
	{1, 3, 9},
	{1, 9, 3},
	{3, 1, 9},
	{3, 9, 1},
	{9, 3, 1},
	{9, 1, 3},
};

int BFS(const std::vector<int> StartSCV)
{
	std::queue<std::vector<int>> q;
	IsVisit[StartSCV[0]][StartSCV[1]][StartSCV[2]] = 1;
	q.push(StartSCV);

	while (!q.empty())
	{
		std::vector<int> CurSCV = std::move(q.front());
		q.pop();

		if (CurSCV[0] == 0 && CurSCV[1] == 0 && CurSCV[2] == 0)
		{
			return IsVisit[CurSCV[0]][CurSCV[1]][CurSCV[2]];
		}

		for (int i = 0; i < 6; i++)
		{
			std::vector<int> CheckSCV = CurSCV;
			for (int j = 0; j < 3; j++)
			{
				CheckSCV[j] = std::max(0, CheckSCV[j] - Damage[i][j]);
			}
			
			if (IsVisit[CheckSCV[0]][CheckSCV[1]][CheckSCV[2]] != 0)
			{
				continue;
			}

			IsVisit[CheckSCV[0]][CheckSCV[1]][CheckSCV[2]] = IsVisit[CurSCV[0]][CurSCV[1]][CurSCV[2]] + 1;
			q.push(CheckSCV);
		}
	}

	return -1;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	std::vector<int> SCV(3);

	for (int i = 0; i < N; i++)
	{
		std::cin >> SCV[i];
	}

	std::cout << BFS(SCV) - 1;
	
	return 0;
}