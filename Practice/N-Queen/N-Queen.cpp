//https://www.acmicpc.net/problem/9663

#include <iostream>
#include <vector>
#include <deque>
#include <set>

int N;

std::vector<bool> IsVisit_0; //좌상 우하
std::vector<bool> IsVisit_1; //우상 좌하
std::vector<bool> IsVisit_2; //가로

int Answer = 0;
void BT(int CurY)
{
	if (CurY == N)
	{
		Answer++;
		return;
	}

	for (int x = 0; x < N; x++)
	{
		if (IsVisit_0[(N - 1) - x + CurY] || IsVisit_1[x + CurY] || IsVisit_2[x])
		{
			continue;
		}

		IsVisit_0[(N - 1) - x + CurY] = true;
		IsVisit_1[x + CurY] = true;
		IsVisit_2[x] = true;

		BT(CurY + 1);

		IsVisit_0[(N - 1) - x + CurY] = false;
		IsVisit_1[x + CurY] = false;
		IsVisit_2[x] = false;
	}
}

int main()
{
	std::cin >> N;
	IsVisit_0.resize(2*N, false);
	IsVisit_1.resize(2*N, false);
	IsVisit_2.resize(N, false);

	BT(0);

	std::cout << Answer;
	return 0;
}