//https://www.acmicpc.net/problem/3758

#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>

struct LogStruct
{
	//점수, 제출 횟수, 제출 순서
	//팀 ID
	int TeamID = -1;
	std::vector<int> Scores = std::vector<int>();
	int SumOfScore = 0;
	int Count = 0;
	int Order = 0;
};

int main()
{
	int T;
	std::cin >> T;

	std::vector<int> Answer;
	Answer.reserve(T);

	for (int y = 0; y < T; y++)
	{
		std::map<int, LogStruct> TeamLog; //팀 ID, 문제 점수

		int n, k, t, m;
		std::cin >> n >> k >> t >> m;
		for (int x = 0; x < n; x++)
		{
			TeamLog.insert(std::make_pair(x + 1, LogStruct()));
			TeamLog[x + 1].Scores.resize(k + 1, 0);
			TeamLog[x + 1].TeamID = x + 1;
		}

		for (int x = 0; x < m; x++)
		{
			int i, j, s;
			std::cin >> i >> j >> s;
			TeamLog[i].Scores[j] = std::max(TeamLog[i].Scores[j], s);
			TeamLog[i].Count++;
			TeamLog[i].Order = x;
		}

		std::vector<LogStruct> Rank;

		for (auto& Log : TeamLog)
		{
			Log.second.SumOfScore = std::accumulate(Log.second.Scores.begin(), Log.second.Scores.end(), 0);
			Rank.push_back(Log.second);
		}

		std::sort(Rank.begin(), Rank.end(), [](const LogStruct& _Left, const LogStruct& _Right)
			{
				if (_Left.SumOfScore != _Right.SumOfScore)
				{
					return _Left.SumOfScore > _Right.SumOfScore;
				}

				if (_Left.Count != _Right.Count)
				{
					return _Left.Count < _Right.Count;
				}

				return _Left.Order < _Right.Order;
			});

		for (int RankNum = 0; RankNum < Rank.size(); ++RankNum)
		{
			if (Rank[RankNum].TeamID == t)
			{
				Answer.push_back(RankNum + 1);
			}
		}
	}

	for (int i = 0; i < T; i++)
	{
		std::cout << Answer[i] << '\n';
	}
}