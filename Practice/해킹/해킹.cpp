//문제 주소 : https://www.acmicpc.net/problem/10282

#include <iostream>
#include <vector>
#include <set>
#include <queue>

int T;

std::pair<int, int> Dijk(int StartCom, const std::vector<std::set<std::pair<int, int>>>& LinkedInfo, int ComCount)
{
	std::priority_queue<std::pair<int, int>> pq; // {-cost, node}
	std::vector<int> Dist(ComCount + 1, INT32_MAX);
	Dist[StartCom] = 0;
	pq.push(std::make_pair(-Dist[StartCom], StartCom));
	int LinkCount = 0;
	int DistMax = INT32_MIN;

	while (!pq.empty())
	{
		int CurCom = pq.top().second;
		int CurCost = -pq.top().first;
		pq.pop();

		if (Dist[CurCom] < CurCost)
		{
			continue;
		}

		for (auto LinkComInfo : LinkedInfo[CurCom])
		{
			int ViaCom = LinkComInfo.second;
			int ViaCost = CurCost + LinkComInfo.first;

			if (Dist[ViaCom] > ViaCost)
			{
				Dist[ViaCom] = ViaCost;
				pq.push(std::make_pair(-ViaCost, ViaCom));
			}
		}
	}

	for (int i : Dist)
	{
		if (i == INT32_MAX)
		{
			continue;
		}
		LinkCount++;
		DistMax = std::max(DistMax, i);
	}

	return std::make_pair(LinkCount, DistMax);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> T;
	while (T-- > 0)
	{
		int ComCount, DependancyCount, HackedCom;
		std::cin >> ComCount >> DependancyCount >> HackedCom;
		std::vector<std::set<std::pair<int, int>>> LinkedInfo(ComCount + 1); //LinkedInfo[From] = { Time, To }

		for (int i = 0; i < DependancyCount; i++)
		{
			int To, From, Time;
			std::cin >> To >> From >> Time;
			LinkedInfo[From].insert(std::make_pair(Time, To));
		}

		std::pair<int, int> Answer = Dijk(HackedCom, LinkedInfo, ComCount);
		std::cout << Answer.first << ' ' << Answer.second << '\n';
	}

	return 0;
}