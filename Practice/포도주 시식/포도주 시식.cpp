//문제 주소 : https://www.acmicpc.net/problem/2156

#include <iostream>
#include <vector>

int DP[10001];
std::vector<int> Arr;
int N;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	Arr.resize(N + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		std::cin >> Arr[i];
	}
	
	DP[0] = 0;
	DP[1] = Arr[1];
	DP[2] = Arr[1] + Arr[2];

	for (int i = 3; i <= N; i++)
	{
		DP[i] = std::max(std::max(DP[i - 3] + Arr[i - 1] + Arr[i], DP[i - 2] + Arr[i]), DP[i - 1]);
	}

	std::cout << DP[N];

	return 0;
}