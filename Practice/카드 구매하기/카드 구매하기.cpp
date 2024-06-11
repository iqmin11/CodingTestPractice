//문제 주소 : https://www.acmicpc.net/source/79376528

#include <iostream>
#include <vector>

int DP[10001] = { 0, }; //DP[a] = 카드 a개로 만들 수 있는 최대값

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	std::vector<int> Arr;
	Arr.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		std::cin >> Arr[i];
	}

	DP[0] = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = i; j <= N; j++)
		{
			DP[j] = std::max(DP[j - i] + Arr[i], DP[j]);
		}
	}

	std::cout << DP[N];
	
	return 0;
}