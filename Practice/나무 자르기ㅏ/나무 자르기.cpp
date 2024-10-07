//문제 주소 : https://www.acmicpc.net/problem/2805

#include <iostream>
#include <vector>

long long TreeCount;
long long FindValue;
std::vector<long long> Trees;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> TreeCount >> FindValue;

	Trees.resize(TreeCount);

	long long MaxValue = 0;

	for (int i = 0; i < TreeCount; i++)
	{
		std::cin >> Trees[i];
		MaxValue = std::max(MaxValue, Trees[i]);
	}

	//Binary Search
	long long Left = 0;
	long long& Right = MaxValue;
	long long Answer = INT64_MIN;

	while (Left <= Right)
	{
		long long Mid = (Left + Right) / 2;
		long long Result = 0;
		
		//자른 나무 계산
		for (int i = 0; i < TreeCount; i++)
		{
			Result += std::max(0LL, Trees[i] - Mid);
		}

		if (Result >= FindValue)
		{
			Answer = std::max(Mid, Answer);
			Left = Mid + 1;
		}
		else if(Result < FindValue)
		{
			Right = Mid - 1;
		}
	}

	std::cout << Answer;

	return 0;
}