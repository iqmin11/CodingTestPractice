//문제 주소 : https://www.acmicpc.net/problem/3077

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;
	std::vector<std::vector<int>> Strs(2);
	std::map<std::string, int> Hashing;
	int Hash = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::string temp;
			std::cin >> temp;

			if (i == 0)
			{
				Hashing.insert(std::make_pair(temp, Hash));
				Strs[i].push_back(Hash++);
			}
			else
			{
				Strs[i].push_back(Hashing[temp]);
			}
		}
	}

	std::vector<int>& Correct = Strs[0];
	std::vector<int>& MyAnswer = Strs[1];

	std::vector<std::vector<bool>> CorrectAnswer(N);
	for (int i = 0; i < N; i++)
	{
		CorrectAnswer[i].resize(N, false);
	}


	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			CorrectAnswer[Correct[i]][Correct[j]] = true;
		}
	}

	int MyScore = 0;

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (CorrectAnswer[MyAnswer[i]][MyAnswer[j]])
			{
				MyScore++;
			}
		}
	}

	int MaxCase = N * (N - 1);
	MaxCase /= 2;

	std::cout << MyScore << '/' << MaxCase;

	return 0;
}