//문제 주소 : https://www.acmicpc.net/problem/2631

#include <iostream>
#include <vector>

std::vector<int> Arr;
int DP[201]; //DP[a] = b: Arr[a] 까지의 증가하는 부분수열의 크기는 b

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;
	Arr.resize(N + 1);
	
	for (int i = 1; i <= N; i++)
	{
		std::cin >> Arr[i];
	}

	int Answer = INT32_MIN;
	
	DP[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (Arr[i] > Arr[j])
			{
				DP[i] = std::max(DP[i], DP[j] + 1);
			}
		}
		Answer = std::max(Answer, DP[i]);
	}

	std::cout << N - Answer;

	return 0;
}