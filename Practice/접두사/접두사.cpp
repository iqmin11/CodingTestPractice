//문제 주소 : https://www.acmicpc.net/problem/1141

#include <iostream>
#include <vector>
#include <algorithm>

bool IsPrefix(const std::string& Left, const std::string& Right)
{
	if (Left.size() > Right.size())
	{
		return false;
	}
	
	for (int i = 0; i < Left.size(); i++)
	{
		if (Left[i] != Right[i])
		{
			return false;
		}
	}

	return true;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	std::vector<std::string> StrArr;
	StrArr.resize(N);
	for (int i = 0; i < N; i++)
	{
		std::cin >> StrArr[i];
	}

	std::sort(StrArr.begin(), StrArr.end());
	int Answer = N;

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (IsPrefix(StrArr[i], StrArr[j]))
			{
				--Answer;
				break;
			}
		}
	}

	std::cout << Answer;

	return 0;
}