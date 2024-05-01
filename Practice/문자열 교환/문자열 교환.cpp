//문제 주소 : https://www.acmicpc.net/problem/1522

#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::string Str;
	std::cin >> Str;

	int CheckSize = 0;
	for (int i = 0; i < Str.size(); i++)
	{
		if (Str[i] == 'a')
		{
			++CheckSize;
		}
	}

	std::vector<int> CountAB(2, 0); //Index 0 == A / Index 1 == B;
	int N = Str.size();
	int right = 0;
	int count = 0;
	int Answer = INT32_MAX;

	for (size_t left = 0; left < N; left++)
	{
		while (right - left < CheckSize)
		{
			CountAB[Str[right % N] - 'a']++;
			right++;
		}

		if (right - left == CheckSize)
		{
			Answer = std::min(Answer, CountAB[1]);
		}

		CountAB[Str[left] - 'a']--;
	}

	std::cout << Answer;

	return 0;
}