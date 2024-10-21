//문제 주소 : https://www.acmicpc.net/problem/11509

#include <iostream>
#include <vector>

int ThereIsArrow[1000001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;
	std::vector<int> Balloon(N);
	for (int i = 0; i < N; i++)
	{
		std::cin >> Balloon[i];
	}
	
	int Answer = 0;

	for (int i = 0; i < N; i++)
	{
		if (ThereIsArrow[Balloon[i]] == 0)
		{
			Answer++;
			ThereIsArrow[Balloon[i] - 1]++;
		}
		else
		{
			ThereIsArrow[Balloon[i]]--;
			ThereIsArrow[Balloon[i] - 1]++;
		}
	}

	std::cout << Answer;

	return 0;
}