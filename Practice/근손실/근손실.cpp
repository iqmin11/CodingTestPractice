//문제 주소 : https://www.acmicpc.net/problem/18429

#include <iostream>
#include <vector>

int N, K;
std::vector<int> HelthCase;
std::vector<bool> IsVisit;
int CurWeight = 500;
int Answer = 0;

void BT(int CurDate)
{
	if (CurDate == N)
	{
		Answer++;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (IsVisit[i])
		{
			continue;
		}

		int NextWeight = CurWeight - K + HelthCase[i];

		if (NextWeight < 500)
		{
			continue;
		}

		CurWeight = NextWeight;
		IsVisit[i] = true;
		BT(CurDate + 1);
		CurWeight += K;
		CurWeight -= HelthCase[i];
		IsVisit[i] = false;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> K;

	HelthCase.resize(N);
	IsVisit.resize(N, false);

	for (int i = 0; i < N; i++)
	{
		std::cin >> HelthCase[i];
	}

	BT(0);

	std::cout << Answer;

	return 0;
}