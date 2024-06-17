//���� �ּ� : https://www.acmicpc.net/problem/1043

#include <iostream>
#include <vector>
#include <set>
#include <queue>

//�� ��Ƽ �ִ� ������� ��� �����Ѵ�.
//������ �ƴ»�����κ��� DFS �Ǵ� BFS�� ���� Ž���ϰ�, ������ �ƴ��ڸ� �߰��Ѵ�.
//��Ƽ���� ������ �ƴ� �ڰ� �ִٸ� �� ��Ƽ�� ���Ǹ��� ���ؾ� �Ѵ�

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