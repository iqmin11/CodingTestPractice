//문제 주소 : https://www.acmicpc.net/problem/2004

#include <iostream>

std::pair<long long, long long> FindTwoFiveCount(long long Value)
{
	//Value보다 작은 가장큰 5의 배수

	long long TwoCount = 0;
	long long FiveCount = 0;

	for (long long i = 2; i <= Value; i <<= 1)
	{
		TwoCount += Value / i;
	}

	for (long long i = 5; i <= Value; i *= 5)
	{
		FiveCount += Value / i;
	}

	return std::make_pair(TwoCount, FiveCount);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	long long N, R;
	std::cin >> N >> R;

	long long Answer = 0;

	R = std::min(R, N - R);

	//N!
	std::pair<long long, long long> NCount = FindTwoFiveCount(N);

	//R!
	std::pair<long long, long long> RCount = FindTwoFiveCount(R);

	//(N - R)!
	std::pair<long long, long long> NSubRCount = FindTwoFiveCount(N - R);

	std::cout << std::min(NCount.first - RCount.first - NSubRCount.first, NCount.second - RCount.second - NSubRCount.second);

	return 0;
}