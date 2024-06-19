//문제 주소 : https://www.acmicpc.net/problem/1405

#include <iostream>
#include <vector>

int N;
std::vector<std::vector<bool>> IsVisit;

double dPercentage[] = { 0,0,0,0 };
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

double SumOfPercentage = 0;

void BT(std::pair<int, int> CurPos, double CurPercentage, int Depth)
{
	if (Depth == N)
	{
		SumOfPercentage += CurPercentage;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int CheckX = CurPos.first + dx[i];
		int CheckY = CurPos.second + dy[i];

		if (IsVisit[CheckY][CheckX])
		{
			continue;
		}

		IsVisit[CheckY][CheckX] = true;
		BT(std::make_pair(CheckX, CheckY), CurPercentage * dPercentage[i], Depth + 1);
		IsVisit[CheckY][CheckX] = false;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	for (int i = 0; i < 4; i++)
	{
		std::cin >> dPercentage[i];
		dPercentage[i] *= 0.01;
	}

	IsVisit.resize(29);
	for (int i = 0; i < 29; i++)
	{
		IsVisit[i].resize(29, false);
	}

	IsVisit[14][14] = true;

	BT({ 14, 14 }, 1.0, 0);

	std::cout.precision(10);
	std::cout << SumOfPercentage;

	return 0;
}