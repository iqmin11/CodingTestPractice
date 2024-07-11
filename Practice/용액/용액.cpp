//문제 주소 : https://www.acmicpc.net/problem/2467

#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<int> Liquid;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	Liquid.resize(N);
	for (int i = 0; i < N; i++)
	{
		std::cin >> Liquid[i];
	}

	std::sort(Liquid.begin(), Liquid.end(), [](int Left, int Right)
		{
			return std::abs(Left) > std::abs(Right);
		});

	int MinDiffer = INT32_MAX;
	int AnswerMin = 0;
	int AnswerMax = 0;

	for (int i = 0; i < N - 1; i++)
	{
		int CurDiffer = std::abs(Liquid[i] + Liquid[i + 1]);
		if (CurDiffer < MinDiffer)
		{
			MinDiffer = CurDiffer;
			AnswerMin = Liquid[i];
			AnswerMax = Liquid[i + 1];
		}
	}

	if (AnswerMin > AnswerMax)
	{
		std::swap(AnswerMin, AnswerMax);
	}

	std::cout << AnswerMin << ' ' << AnswerMax;

	return 0;
}