//���� �ּ� : https://www.biko.kr/problem/1700

#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <queue>

//�ð��뺰 ��ũ��带 �����, �ð��뺰�� BFS ����
std::vector<bool> IsVisit; // �湮üũ
std::map<int, std::unordered_map<int, std::unordered_set<int>>> LinkedNodeByTime;
//LinkedNodeByTime[a][b] = a�ð��뿡 b����� ������ ����Ǿ��ִ°�
std::set<int> InfectionList;
std::vector<int> IsInfection;

void BFS(std::unordered_map<int, std::unordered_set<int>>& CurTimeLinkNode, int StartIndex)
{
	std::queue<int> q;
	IsVisit[StartIndex] = true;
	q.push(StartIndex);

	while (!q.empty())
	{
		int CurIndex = q.front();
		q.pop();

		for (const auto& LinkNode : CurTimeLinkNode[CurIndex])
		{
			if (IsVisit[LinkNode])
			{
				continue;
			}

			IsVisit[LinkNode] = true;
			q.push(LinkNode);

			if (IsInfection[LinkNode])
			{
				continue;
			}

			IsInfection[LinkNode] = true;
			InfectionList.insert(LinkNode);
		}
	}
}

int main()
{
	int N, M;
	std::cin >> N >> M;

	IsVisit.resize(N, false);
	for (int i = 0; i < M; i++)
	{
		int x, y, t;
		std::cin >> x >> y >> t;

		LinkedNodeByTime[t][x - 1].insert(y - 1);
		LinkedNodeByTime[t][y - 1].insert(x - 1);
	}

	IsInfection.resize(N, false);
	IsInfection[0] = true;
	InfectionList.insert(0);
	std::vector<bool> InitVisit = IsVisit;

	for (auto LinkNodes : LinkedNodeByTime)
	{
		IsVisit = InitVisit;
		for (auto InfectionPerson : InfectionList)
		{
			if (IsVisit[InfectionPerson])
			{
				continue;
			}

			BFS(LinkNodes.second, InfectionPerson);
		}
	}

	for (auto i : InfectionList)
	{
		std::cout << i + 1 << " ";
	}

	return 0;
}