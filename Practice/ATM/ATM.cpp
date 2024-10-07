//문제 주소 : https://www.acmicpc.net/problem/11399

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	std::vector<int> People(N);

	for (int i = 0; i < N; i++)
	{
		std::cin >> People[i];
	}

	std::sort(People.begin(), People.end());

	for (int i = 1; i < N; i++)
	{
		People[i] += People[i - 1];
	}
	
	std::cout << std::accumulate(People.begin(), People.end(), 0);

	return 0;
}