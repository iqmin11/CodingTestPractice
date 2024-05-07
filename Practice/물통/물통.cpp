//문제 주소 : https://www.acmicpc.net/problem/2251

#include <iostream>
#include <vector>
#include <set>
#include <map>

std::set<int> Answer;
std::map<std::vector<std::pair<int, int>>, bool> IsVisit;

//X->Y
void XtoY(std::pair<int, int> X, std::pair<int, int> Y, std::pair<int, int>& XResult, std::pair<int, int>& YResult)
{
	int EmptySizeY = Y.first - Y.second;

	if (X.second > EmptySizeY)
	{
		X.second -= EmptySizeY;
		Y.second = Y.first;
	}
	else
	{
		Y.second += X.second;
		X.second = 0;
	}

	XResult = X;
	YResult = Y;
}

//A->B A->C B->A B->C C->A C->B
std::vector<std::vector<std::pair<int, int>>> AllCase(const std::vector<std::pair<int, int>>& CurIndex)
{
	std::vector<std::vector<std::pair<int, int>>> Result;
	Result.resize(6);
	for (int i = 0; i < 6; i++)
	{
		Result[i].resize(3);
	}

	XtoY(CurIndex[0], CurIndex[1], Result[0][0], Result[0][1]);
	Result[0][2] = CurIndex[2];

	XtoY(CurIndex[0], CurIndex[2], Result[1][0], Result[1][2]);
	Result[1][1] = CurIndex[1];

	XtoY(CurIndex[1], CurIndex[0], Result[2][1], Result[2][0]);
	Result[2][2] = CurIndex[2];

	XtoY(CurIndex[1], CurIndex[2], Result[3][1], Result[3][2]);
	Result[3][0] = CurIndex[0];

	XtoY(CurIndex[2], CurIndex[0], Result[4][2], Result[4][0]);
	Result[4][1] = CurIndex[1];

	XtoY(CurIndex[2], CurIndex[1], Result[5][2], Result[5][1]);
	Result[5][0] = CurIndex[0];

	return Result;
}

void DFS(std::vector<std::pair<int, int>>& CurIndex)
{
	IsVisit[CurIndex] = true;

	if (CurIndex[0].second == 0)
	{
		Answer.insert(CurIndex[2].second);
	}

	std::vector<std::vector<std::pair<int, int>>> LinkNodes = AllCase(CurIndex);

	for (int i = 0; i < 6; i++)
	{
		if (IsVisit[LinkNodes[i]])
		{
			continue;
		}

		DFS(LinkNodes[i]);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::vector<std::pair<int, int>> Beakur; // Max, Cur
	Beakur.resize(3);

	std::cin >> Beakur[0].first >> Beakur[1].first >> Beakur[2].first;

	Beakur[0].second = 0;
	Beakur[1].second = 0;
	Beakur[2].second = Beakur[2].first;

	DFS(Beakur);

	for (auto& i : Answer)
	{
		std::cout << i << ' ';
	}

	return 0;
}