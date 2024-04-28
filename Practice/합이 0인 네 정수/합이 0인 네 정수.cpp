//문제 주소 : https://www.acmicpc.net/problem/7453

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;
	std::vector<std::vector<long long>> Arrays;
	Arrays.resize(4);
	for (int i = 0; i < 4; i++)
	{
		Arrays[i].reserve(N);
	}

	for (int i = 0; i < N; i++)
	{
		long long a, b, c, d;
		std::cin >> a >> b >> c >> d;

		Arrays[0].push_back(a);
		Arrays[1].push_back(b);
		Arrays[2].push_back(c);
		Arrays[3].push_back(d);
	}

	std::vector<long long> AB;
	AB.reserve(N * N);
	for (int A = 0; A < N; A++)
	{
		for (int B = 0; B < N; B++)
		{
			AB.push_back(Arrays[0][A] + Arrays[1][B]);
		}
	}

	std::vector<long long> CD;
	CD.reserve(N * N);
	for (int C = 0; C < N; C++)
	{
		for (int D = 0; D < N; D++)
		{
			CD.push_back(Arrays[2][C] + Arrays[3][D]);
		}
	}

	std::sort(AB.begin(), AB.end());
	std::sort(CD.begin(), CD.end());
	
	long long Answer = 0;

	int NN = N * N;

	for (int i = 0; i < NN; i++)
	{
		long long FindValue = -(AB[i]);
		long long left = 0;
		long long right = NN - 1;

		while (left <= right)
		{
			long long mid = (right + left) / 2;

			if (CD[mid] == FindValue)
			{
				auto Start = std::lower_bound(CD.begin(), CD.end(), FindValue);
				auto End = std::upper_bound(CD.begin(), CD.end(), FindValue);

				int Size = End - Start;
				
				Answer += Size;
				break;
			}
			else if (CD[mid] < FindValue)
			{
				left = mid + 1;
			}
			else if (CD[mid] > FindValue)
			{
				right = mid - 1;
			}
		}
	}

	std::cout << Answer;

	return 0;
}