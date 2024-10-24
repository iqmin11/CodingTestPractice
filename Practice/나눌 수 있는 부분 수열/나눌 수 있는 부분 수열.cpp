//문제 주소 : https://www.acmicpc.net/problem/3673

#include <iostream>
#include <vector>
#include <map>


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int T;
	std::cin >> T;

	for (int t = 0; t < T; t++)
	{
		long long Mod, N;
		std::cin >> Mod >> N;

		std::map<long long, long long> NumCount;

		std::vector<long long> Arr(N);

		for (int i = 0; i < N; i++)
		{
			std::cin >> Arr[i];
			Arr[i] %= Mod;
		}

		for (int i = 1; i < N; i++)
		{
			Arr[i] += Arr[i - 1];
		}

		for (int i = 0; i < N; i++)
		{
			Arr[i] %= Mod;
			NumCount[Arr[i]]++;
		}

		long long Answer = NumCount[0];

		for (auto i : NumCount)
		{
			long long All = i.second;
			Answer += (All * (All - 1)) / 2;
		}

		std::cout << Answer << '\n';
	}

	return 0;
}