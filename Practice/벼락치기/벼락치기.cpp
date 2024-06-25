//���� �ּ� : https://www.acmicpc.net/problem/14728

#include <iostream>
#include <vector>

int DP[101][10001]; //DP[a][w] ���� a���� �Ǵ������� �ִ빫�԰� w�� ���濡�� ���� �� �ִ� �ִ� ��ġ
std::vector<std::pair<int, int>> LoadInfo; //����, ��ġ
int LoadCount, MaxWeight;

int main()
{
	std::cin >> LoadCount >> MaxWeight;

	LoadInfo.resize(LoadCount + 1);

	for (int i = 1; i <= LoadCount; i++)
	{
		std::cin >> LoadInfo[i].first >> LoadInfo[i].second;
	}

	for (int i = 1; i <= LoadCount; i++)
	{
		for (int w = 1; w <= MaxWeight; w++)
		{
			if (LoadInfo[i].first > w)
			{
				DP[i][w] = DP[i - 1][w];
			}
			else
			{
				DP[i][w] = std::max(DP[i - 1][w], DP[i - 1][w - LoadInfo[i].first] + LoadInfo[i].second);
			}
		}
	}

	std::cout << DP[LoadCount][MaxWeight];

	return 0;
}