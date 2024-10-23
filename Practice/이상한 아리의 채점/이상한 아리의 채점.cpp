//문제 주소 : https://www.acmicpc.net/problem/25167

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <algorithm>

int Time2Int(const std::string& Time)
{
	std::string HH;
	std::string MM;

	int Offset = 0;
	for (int i = 0; i < Time.size(); i++)
	{
		if (Time[i] == ':')
		{
			Offset = i;
			break;
		}

		HH.push_back(Time[i]);
	}

	for (int i = Offset + 1; i < Time.size(); i++)
	{
		MM.push_back(Time[i]);
	}

	int TimeInt = std::stoi(HH) * 60 + std::stoi(MM);
	return TimeInt;
}


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M, P;
	std::cin >> N >> M >> P;

	std::vector<std::string> People;

	for (int i = 0; i < M; i++)
	{
		std::string temp;
		std::cin >> temp;
		People.push_back(temp);
	}

	//각 사람별 문제 시작 시간
	std::map<std::string, std::vector<int>> FirstTryTime;
	
	//각 사람별 문제 풀이에 걸린 시간
	std::map<std::string , std::vector<int>> TakeTime;

	//각 사람별 문제 풀이 성공 여부 (-1 : 첫트라이에 맞춤  / 0 : 시도하지 않음 / 1 : 시도는 했으나 맞추지 못함 / 2 : 맞춤)
	std::map<std::string, std::vector<int>> IsSuccess;

	//각 사람별 문제별 점수
	std::map<std::string, std::vector<int>> Score;

	for (int i = 0; i < M; i++)
	{
		FirstTryTime[People[i]] = std::vector<int>(N, -1);
		TakeTime[People[i]] = std::vector<int>(N, -1);
		IsSuccess[People[i]] = std::vector<int>(N, 0);
		Score[People[i]] = std::vector<int>(N, 0);
	}

	for (int i = 0; i < P; i++)
	{
		int QNum;
		std::string Time, Name, Result;
		std::cin >> QNum >> Time >> Name >> Result;
		--QNum;

		bool IsSolve = Result == "solve" ? true : false;

		if (IsSuccess[Name][QNum] == -1 || IsSuccess[Name][QNum] == 2)
		{
			continue;
		}

		//풀었고, 첫 트라이가 있고, 성공한적 없는 경우
		if (IsSolve && FirstTryTime[Name][QNum] != -1 && TakeTime[Name][QNum] == -1)
		{
			//성공
			IsSuccess[Name][QNum] = 2;

			//풀이시간 계산
			TakeTime[Name][QNum] = Time2Int(Time) - FirstTryTime[Name][QNum];
			continue;
		}

		if (IsSolve && FirstTryTime[Name][QNum] == -1)
		{
			//첫 트라이에 맞춤
			IsSuccess[Name][QNum] = -1;
			continue;
		}

		if (!IsSolve && FirstTryTime[Name][QNum] == -1)
		{
			IsSuccess[Name][QNum] = 1; //시도는 함
			FirstTryTime[Name][QNum] = Time2Int(Time);
			continue;
		}
	}

	//각 문제를 푼사람들 간의 랭킹
	std::vector<std::vector<std::string>> Rank(N);

	for (int i = 0; i < N; i++)
	{
		for (auto j : IsSuccess)
		{
			if (j.second[i] == 2)
			{
				Rank[i].push_back(j.first);
			}
			else if (j.second[i] == 1)
			{
				Score[j.first][i] = M;
			}
			else
			{
				Score[j.first][i] = M + 1;
			}
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		std::sort(Rank[i].begin(), Rank[i].end(), [&](const std::string& Left, const std::string& Right) 
			{
				return TakeTime[Left][i] == TakeTime[Right][i] ? Left < Right : TakeTime[Left][i] < TakeTime[Right][i];
			});
	}

	//문제별 점수를 입력
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < Rank[i].size(); j++)
		{
			Score[Rank[i][j]][i] = j + 1;
		}
	}

	std::sort(People.begin(), People.end(), [&](const std::string& Left, const std::string& Right)
		{
			int SumLeftScore = 0;
			int SumRightScore = 0;

			for (auto& i : Score[Left])
			{
				SumLeftScore += i;
			}

			for (auto& i : Score[Right])
			{
				SumRightScore += i;
			}

			return SumLeftScore == SumRightScore ? Left < Right : SumLeftScore < SumRightScore;
		});

	for (int i = 0; i < M; i++)
	{
		std::cout << People[i] << '\n';
	}
	
	return 0;
}