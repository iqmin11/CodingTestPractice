//문제 주소 : https://www.acmicpc.net/problem/27172

#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>

int N;
std::unordered_map<int, int> Scores;
std::vector<int> NumOrder;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	//약수를 구하고, 그 약수가 존재하면 -1점 상대 +1점

	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		int Num;
		std::cin >> Num;
		Scores.insert(std::make_pair(Num, 0));
		NumOrder.push_back(Num);
	}

	for (auto& i : Scores)
	{
		int Num = i.first;
		int Root = std::sqrt(Num);

		for (int Div = 1; Div <= Root; Div++)
		{
			int Mod = Num % Div;

			if (Mod != 0)
			{
				continue;
			}

			int Quo = Num / Div;

			if (Scores.find(Div) != Scores.end())
			{
				Scores[Div]++;
				Scores[Num]--;
			}

			if (Div == Quo)
			{
				continue;
			}

			if (Scores.find(Quo) != Scores.end())
			{
				Scores[Quo]++;
				Scores[Num]--;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		std::cout << Scores[NumOrder[i]] << ' ';
	}

	return 0;
}