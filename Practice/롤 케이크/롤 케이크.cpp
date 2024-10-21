//문제 주소 : https://www.acmicpc.net/problem/3985

#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int L, N;
	std::cin >> L >> N;

	int MaxExpectPersonIndex = -1;
	int MaxExpectLength = INT32_MIN;

	std::vector<int> CakeOner(1001, -1);
	std::vector<int> OnerCount(N, 0);

	for (int i = 0; i < N; i++)
	{
		int S, E;
		std::cin >> S >> E;
		int CurExpectLenght = E - S + 1;
		if (CurExpectLenght > MaxExpectLength)
		{
			MaxExpectPersonIndex = i;
			MaxExpectLength = CurExpectLenght;
		}

		for (int j = S; j <= E; j++)
		{
			int PrevOner = CakeOner[j];
			if (PrevOner != -1)
			{
				continue;
			}
			
			CakeOner[j] = i;
			++OnerCount[i];
		}
	}

	int MaxRealPersonIndex = -1;
	int MaxRealLength = INT32_MIN;

	for (int i = 0; i < OnerCount.size(); i++)
	{
		if (OnerCount[i] > MaxRealLength)
		{
			MaxRealLength = OnerCount[i];
			MaxRealPersonIndex = i;
		}
	}

	std::cout << MaxExpectPersonIndex + 1 << '\n';
	std::cout << MaxRealPersonIndex + 1 << '\n';

	return 0;
}