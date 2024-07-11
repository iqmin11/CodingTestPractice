//문제 주소 : https://www.acmicpc.net/problem/1238

#include <iostream>
#include <vector>

const int INF = 100001;
int VertexCount, EdgeCount, Party;
std::vector<std::vector<int>> Cost;

int FW(int Start)
{
	std::vector<std::vector<int>>& Dist = Cost;

	for (int k = 0; k < VertexCount; k++)
	{
		for (int i = 0; i < VertexCount; i++)
		{
			for (int j = 0; j < VertexCount; j++)
			{
				Dist[i][j] = std::min(Dist[i][j], Dist[i][k] + Dist[k][j]);
			}
		}
	}

	int Answer = INT32_MIN;
	for (int i = 0; i < VertexCount; i++)
	{
		Answer = std::max(Answer, Dist[i][Start] + Dist[Start][i]);
	}

	return Answer;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> VertexCount >> EdgeCount >> Party;

	Cost.resize(VertexCount);
	for (int i = 0; i < VertexCount; i++)
	{
		Cost[i].resize(VertexCount, INF);
		Cost[i][i] = 0;
	}

	for (int i = 0; i < EdgeCount; i++)
	{
		int From, To, Time;

		std::cin >> From >> To >> Time;

		Cost[From - 1][To - 1] = Time;
	}

	std::cout << FW(Party - 1);

	return 0;
}