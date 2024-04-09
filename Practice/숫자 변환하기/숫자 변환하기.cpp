//https://school.programmers.co.kr/learn/courses/30/lessons/154538

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int DP[1000001]; //DP[a] = k; //x에서 a로가는 최소 횟수
const int INF = 10000001;

int solution(int x, int y, int n)
{
	std::fill_n(DP, 1000001, INF);

	DP[x] = 0;

	for (int i = x + 1; i <= y; i++)
	{
		if (i - n > 0)
		{
			DP[i] = DP[i - n] + 1;
		}

		if (i % 3 == 0)
		{
			DP[i] = std::min(DP[i], DP[i / 3] + 1);
		}

		if (i % 2 == 0)
		{
			DP[i] = std::min(DP[i], DP[i / 2] + 1);
		}
	}

	if (DP[y] >= INF)
	{
		DP[y] = -1;
	}

	return DP[y];
}

int main()
{
    int a = solution(1, 1000000, 998);
}