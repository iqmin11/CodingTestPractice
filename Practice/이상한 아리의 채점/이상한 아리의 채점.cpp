//���� �ּ� : https://www.acmicpc.net/problem/25167

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

	//�� ����� ���� ���� �ð�
	std::map<std::string, std::vector<int>> FirstTryTime;
	
	//�� ����� ���� Ǯ�̿� �ɸ� �ð�
	std::map<std::string , std::vector<int>> TakeTime;

	//�� ����� ���� Ǯ�� ���� ���� (-1 : ùƮ���̿� ����  / 0 : �õ����� ���� / 1 : �õ��� ������ ������ ���� / 2 : ����)
	std::map<std::string, std::vector<int>> IsSuccess;

	//�� ����� ������ ����
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

		//Ǯ����, ù Ʈ���̰� �ְ�, �������� ���� ���
		if (IsSolve && FirstTryTime[Name][QNum] != -1 && TakeTime[Name][QNum] == -1)
		{
			//����
			IsSuccess[Name][QNum] = 2;

			//Ǯ�̽ð� ���
			TakeTime[Name][QNum] = Time2Int(Time) - FirstTryTime[Name][QNum];
			continue;
		}

		if (IsSolve && FirstTryTime[Name][QNum] == -1)
		{
			//ù Ʈ���̿� ����
			IsSuccess[Name][QNum] = -1;
			continue;
		}

		if (!IsSolve && FirstTryTime[Name][QNum] == -1)
		{
			IsSuccess[Name][QNum] = 1; //�õ��� ��
			FirstTryTime[Name][QNum] = Time2Int(Time);
			continue;
		}
	}

	//�� ������ Ǭ����� ���� ��ŷ
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

	//������ ������ �Է�
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