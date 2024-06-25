//문제 주소 : https://www.acmicpc.net/problem/11265

#include <iostream>
#include <vector>

int PartyCount, PeopleCount;
std::vector<std::vector<int>> Cost;

std::vector<std::vector<int>> FW()
{
	std::vector<std::vector<int>> Dist = Cost;

	for (int k = 0; k < PartyCount; k++)
	{
		for (int i = 0; i < PartyCount; i++)
		{
			for (int j = 0; j < PartyCount; j++)
			{
				Dist[i][j] = std::min(Dist[i][j], Dist[i][k] + Dist[k][j]);
			}
		}
	}

	return Dist;
}

int main()
{
	std::cin >> PartyCount >> PeopleCount;
	Cost.resize(PartyCount);
	for (int i = 0; i < PartyCount; i++)
	{
		Cost[i].resize(PartyCount);
		for (int j = 0; j < PartyCount; j++)
		{
			std::cin >> Cost[i][j];
		}
	}

	std::vector<std::vector<int>> Dist = FW();
	std::vector<bool> Answers;

	for (int i = 0; i < PeopleCount; i++)
	{
		int CurPartyPlace, NextPartyPlace, PartyTime;
		std::cin >> CurPartyPlace >> NextPartyPlace >> PartyTime;

		if (Dist[CurPartyPlace - 1][NextPartyPlace - 1] > PartyTime)
		{
			Answers.push_back(false);
		}
		else
		{
			Answers.push_back(true);
		}
	}

	for (auto i : Answers)
	{
		if (i)
		{
			std::cout << "Enjoy other party" << std::endl;
		}
		else
		{
			std::cout << "Stay here" << std::endl;
		}
	}

	return 0;
}