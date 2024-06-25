//문제 주소 : https://www.acmicpc.net/problem/13164

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int N, K;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> K;

	std::vector<int> StudentsHight;
	StudentsHight.resize(N);

	for (int i = 0; i < N; i++)
	{
		std::cin >> StudentsHight[i];
	}

	std::vector<int> Differ;
	Differ.resize(N - 1);

	for (int i = 0; i < N - 1; i++)
	{
		Differ[i] = StudentsHight[i + 1] - StudentsHight[i];
	}

	std::sort(Differ.begin(), Differ.end());

	int Answer = std::accumulate(&Differ[0], &Differ[N - K], 0);
	
	std::cout << Answer;
	return 0;
}