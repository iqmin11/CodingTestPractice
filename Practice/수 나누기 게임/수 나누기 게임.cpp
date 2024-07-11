//문제 주소 : https://www.acmicpc.net/problem/27172

#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>

int N;
std::unordered_map<int, int> Scores;
std::vector<int> NumOrder;
int MaxNum = INT32_MIN;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		int Num;
		std::cin >> Num;
		Scores.insert(std::make_pair(Num, 0));
		NumOrder.push_back(Num);
		MaxNum = std::max(MaxNum, Num);
	}

	for (auto& i : Scores)
	{
		int Num = i.first;
		int MulMax = MaxNum / Num;

		for (int Mul = 2; Mul <= MulMax; ++Mul)
		{
			int MulResult = Num * Mul;

			if (Scores.find(MulResult) != Scores.end())
			{
				Scores[Num]++;
				Scores[MulResult]--;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		std::cout << Scores[NumOrder[i]] << ' ';
	}

	return 0;
}