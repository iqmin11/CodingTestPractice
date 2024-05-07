//문제 주소 : https://www.acmicpc.net/problem/13904

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int N;
int WholeDeadline = INT32_MIN;
std::map<int, int> HomeWorkInfo; // Deadline, Score

int CurScore = 0;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		int Deadline, Score;
		std::cin >> Deadline >> Score;
		HomeWorkInfo[Deadline] = std::max(HomeWorkInfo[Deadline], Score);
		WholeDeadline = std::max(WholeDeadline, Score);
	}

	int Answer = 0;

	for (auto i : HomeWorkInfo)
	{
		Answer += i.second;
	}
	
	std::cout << Answer;

	return 0;
}