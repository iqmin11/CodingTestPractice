//https://www.acmicpc.net/problem/19941

#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, K;

	std::cin >> N >> K;

	std::string Table;

	std::cin >> Table;

	int Answer = 0;

	for (int i = 0; i < N; i++)
	{
		if (Table[i] != 'P')
		{
			continue;
		}

		for (int j = -K; j <= K; j++)
		{
			int CheckIndex = i + j;
			if (CheckIndex < 0 || CheckIndex >= N)
			{
				continue;
			}

			if (Table[CheckIndex] != 'H')
			{
				continue;
			}

			Table[CheckIndex] = 'E';
			++Answer;
			break;
		}
	}

	std::cout << Answer;
}