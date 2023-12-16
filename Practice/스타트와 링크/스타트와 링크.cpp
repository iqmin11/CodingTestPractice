#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <algorithm>

std::vector<std::vector<int>> Score;
//std::vector<int> RecordStack;

//void DFS(std::vector<bool> _IsVisit, int _n, int _Start, int _r, std::list<std::vector<int>>& _Result)
//{
//	_IsVisit[_Start] = true;
//	RecordStack.emplace_back(_Start);
//
//	if (RecordStack.size() == _r)
//	{
//		_Result.emplace_back(RecordStack);
//		_IsVisit[_Start] = false;
//		RecordStack.pop_back();
//		return;
//	}
//
//	for (int i = 0; i < _n; i++)
//	{
//		if (_Start == i)
//		{
//			continue;
//		}
//
//		if (!_IsVisit[i] && i > RecordStack.back())
//		{
//			DFS(_IsVisit, _n, i, _r, _Result);
//		}
//	}
//
//	_IsVisit[_Start] = false;
//	RecordStack.pop_back();
//}
//
//void Combination(int _n, int _r, std::list<std::vector<int>>& _Result)
//{
//	std::vector<bool> IsVisit;
//	IsVisit.resize(_n, false);
//
//	for (size_t i = 0; i < _n; i++)
//	{
//		DFS(IsVisit, _n, i, _r, _Result);
//	}
//}

int main()
{
	int N;
	std::cin >> N;

	Score.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		Score[i].reserve(N);
		for (size_t j = 0; j < N; j++)
		{
			int input;
			std::cin >> input;
			Score[i].emplace_back(input);
		}
	}

	//std::list<std::vector<int>> Team; //ÆÀ¿øÀ» ±¸¼ºÇÏ´Â ¹æ¹ý
	//Combination(N, N/2, Team);
	//
	//int MinDiffer = INT32_MAX;
	//int TeamCount = Team.size() / 2;

	//std::list<std::vector<int>> Pair; //ÆÀ¿øÀ» µÑ¾¿ Â¦Áþ´Â ¹æ¹ý(ÀÎµ¦½º)
	//Combination(N/2, 2, Pair);

	//for (auto& T : Team)
	//{
	//	if (TeamCount-- == 0)
	//	{
	//		std::cout << MinDiffer;
	//		break;
	//	}

	//	std::vector<int> Team1 = T; //ÆÀ1 ±¸¼º 1 2 3 8
	//	std::vector<int> Team2; // ÆÀ2 ±¸¼º 
	//	Team2.reserve(Team1.size());
	//	for (size_t i = 0; i < N; i++)
	//	{
	//		if (std::binary_search(Team1.begin(), Team1.end(), i))
	//		{
	//			continue;
	//		}

	//		Team2.emplace_back(i);
	//	}

	//	int Team1Score = 0;
	//	int Team2Score = 0;

	//	for (auto& i : Pair) //°°Àº ÆÀ¿ø µÎ¸í¾¿ Â¦Áþ±â
	//	{
	//		Team1Score += Score[Team1[i[0]]][Team1[i[1]]] + Score[Team1[i[1]]][Team1[i[0]]];
	//		Team2Score += Score[Team2[i[0]]][Team2[i[1]]] + Score[Team2[i[1]]][Team2[i[0]]];
	//	}

	//	MinDiffer = std::min(MinDiffer, abs(Team1Score - Team2Score));

	//	if (MinDiffer == 0)
	//	{
	//		std::cout << MinDiffer;
	//		break;
	//	}
	//}

	std::vector<int> TeamSelect;
	TeamSelect.resize(N);
	for (size_t i = 0; i < N/2; i++)
	{
		TeamSelect[i] = 0;
	}

	for (size_t i = N/2; i < N; i++)
	{
		TeamSelect[i] = 1;
	}

	std::vector<int> Team1;
	std::vector<int> Team2;

	Team1.reserve(N/2);
	Team2.reserve(N/2);

	int MinDiffer = INT32_MAX;

	do
	{
		Team1.clear();
		Team2.clear();

		for (size_t i = 0; i < TeamSelect.size(); i++)
		{
			if (TeamSelect[i] == 0)
			{
				Team1.emplace_back(i);
			}
			else
			{
				Team2.emplace_back(i);
			}
		}

		int Team1Score = 0;
		int Team2Score = 0;

		for (size_t i = 0; i < N/2; i++)
		{
			for (size_t j = 0; j < N/2; j++)
			{
				Team1Score += Score[Team1[i]][Team1[j]];
				Team2Score += Score[Team2[i]][Team2[j]];
			}
		}

		MinDiffer = std::min(MinDiffer, abs(Team1Score - Team2Score));

		if (MinDiffer == 0)
		{
			std::cout << MinDiffer;
			return 0;
		}

	} while (std::next_permutation(TeamSelect.begin(), TeamSelect.end()));
	std::cout << MinDiffer;
	return 0;
}