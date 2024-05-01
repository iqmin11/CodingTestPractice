//문제 주소 : https://www.acmicpc.net/problem/20922

#include <iostream>
#include <vector>

int NumCheck[100001] = { 0, };

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, K;
	std::cin >> N >> K;

	std::vector<int> Data;
	Data.resize(N + 1);
	for (int i = 0; i < N; i++)
	{
		int Num;
		std::cin >> Num;
		Data[i] = Num;
	}

	int right = 0;
	int MaxLength = INT32_MIN;

	for (int left = 0; left < N; left++)
	{
		while (NumCheck[Data[right]] < K && right < N)
		{
			++NumCheck[Data[right]];
			right++;
		}

		MaxLength = std::max(MaxLength, right - left);

		--NumCheck[Data[left]];
	}

	std::cout << MaxLength;

	return 0;
}