//문제 주소 : https://www.acmicpc.net/problem/1043

#include <iostream>
#include <vector>
#include <set>
#include <queue>

//각 파티 있는 사람들을 모두 연결한다.
//진실을 아는사람으로부터 DFS 또는 BFS를 돌아 탐색하고, 진실을 아는자를 추가한다.
//파티별로 진실을 아는 자가 있다면 그 파티는 진실만을 말해야 한다

int PeopleCount, PartyCount;

std::vector<int> FirstTruePeople;
std::vector<bool> IsKnowTruth;
std::vector<std::vector<int>> Partys;
std::vector<std::set<int>> MeetLink;

void MathPeople(const std::vector<int>& CurParty)
{
	size_t CurPartySize = CurParty.size();

	for (size_t i = 0; i < CurPartySize - 1; i++)
	{
		for (size_t j = i + 1; j < CurPartySize; j++)
		{
			MeetLink[CurParty[i]].insert(CurParty[j]);
			MeetLink[CurParty[j]].insert(CurParty[i]);
		}
	}
}

void BFS()
{
	for (size_t T = 0; T < FirstTruePeople.size(); T++)
	{
		int StartIndex = FirstTruePeople[T];
		if (IsKnowTruth[StartIndex])
		{
			continue;
		}

		std::queue<int> q;
		IsKnowTruth[StartIndex] = true;
		q.push(StartIndex);
		
		while (!q.empty())
		{
			int CurIndex = q.front();
			q.pop();

			for (auto LinkNode : MeetLink[CurIndex])
			{
				if (IsKnowTruth[LinkNode])
				{
					continue;
				}

				q.push(LinkNode);
				IsKnowTruth[LinkNode] = true;
			}
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> PeopleCount >> PartyCount;
	
	IsKnowTruth.resize(PeopleCount, false);
	MeetLink.resize(PeopleCount);
	Partys.resize(PartyCount);

	int FirstTrueCount;
	std::cin >> FirstTrueCount;
	FirstTruePeople.resize(FirstTrueCount);

	for (int i = 0; i < FirstTrueCount; i++)
	{
		int temp;
		std::cin >> temp;
		FirstTruePeople[i] = temp - 1;
	}

	for (int i = 0; i < PartyCount; i++)
	{
		int CurPartyPeopleCount;
		std::cin >> CurPartyPeopleCount; 
		Partys[i].resize(CurPartyPeopleCount);
		for (int j = 0; j < CurPartyPeopleCount; j++)
		{
			int temp;
			std::cin >> temp;
			Partys[i][j] = temp - 1;
		}

		MathPeople(Partys[i]);
	}

	BFS();

	int Answer = PartyCount;
	for (int i = 0; i < PartyCount; i++)
	{
		for (int j = 0; j < Partys[i].size(); j++)
		{
			if (IsKnowTruth[Partys[i][j]])
			{
				--Answer;
				break;
			}
		}
	}

	std::cout << Answer;

	return 0;
}