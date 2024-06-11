//문제 주소 : https://www.acmicpc.net/problem/17404

#include <iostream>
#include <vector>

int RedDP[1001][3]; //DP[a][b] 시작을 빨간색으로 하고 a번째 집의 색 b, 
int GreenDP[1001][3]; //DP[a][b] 시작을 초록색으로 하고 a번째 집의 색 b,
int BlueDP[1001][3]; //DP[a][b] 시작을 파랑색으로 하고 a번째 집의 색 b,

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	std::vector<std::vector<int>> HouseColorPrice;
	HouseColorPrice.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		HouseColorPrice[i].resize(3);

		for (int j = 0; j < 3; j++)
		{
			std::cin >> HouseColorPrice[i][j];
		}
	}

	RedDP[2][0] = 1000001;
	RedDP[2][1] = HouseColorPrice[1][0] + HouseColorPrice[2][1];
	RedDP[2][2] = HouseColorPrice[1][0] + HouseColorPrice[2][2];

	GreenDP[2][0] = HouseColorPrice[1][1] + HouseColorPrice[2][0];
	GreenDP[2][1] = 1000001;
	GreenDP[2][2] = HouseColorPrice[1][1] + HouseColorPrice[2][2];
	
	BlueDP[2][0] = HouseColorPrice[1][2] + HouseColorPrice[2][0];
	BlueDP[2][1] = HouseColorPrice[1][2] + HouseColorPrice[2][1];
	BlueDP[2][2] = 1000001;

	for (int i = 3; i <= N; i++)
	{
		RedDP[i][0] = std::min(RedDP[i - 1][1], RedDP[i - 1][2]) + HouseColorPrice[i][0];
		RedDP[i][1] = std::min(RedDP[i - 1][0], RedDP[i - 1][2]) + HouseColorPrice[i][1];
		RedDP[i][2] = std::min(RedDP[i - 1][0], RedDP[i - 1][1]) + HouseColorPrice[i][2];

		GreenDP[i][0] = std::min(GreenDP[i - 1][1], GreenDP[i - 1][2]) + HouseColorPrice[i][0];
		GreenDP[i][1] = std::min(GreenDP[i - 1][0], GreenDP[i - 1][2]) + HouseColorPrice[i][1];
		GreenDP[i][2] = std::min(GreenDP[i - 1][0], GreenDP[i - 1][1]) + HouseColorPrice[i][2];

		BlueDP[i][0] = std::min(BlueDP[i - 1][1], BlueDP[i - 1][2]) + HouseColorPrice[i][0];
		BlueDP[i][1] = std::min(BlueDP[i - 1][0], BlueDP[i - 1][2]) + HouseColorPrice[i][1];
		BlueDP[i][2] = std::min(BlueDP[i - 1][0], BlueDP[i - 1][1]) + HouseColorPrice[i][2];
	}

	int MinValue = INT32_MAX;
	MinValue = std::min(RedDP[N][1], MinValue);
	MinValue = std::min(RedDP[N][2], MinValue);
	MinValue = std::min(GreenDP[N][0], MinValue);
	MinValue = std::min(GreenDP[N][2], MinValue);
	MinValue = std::min(BlueDP[N][0], MinValue);
	MinValue = std::min(BlueDP[N][1], MinValue);

	std::cout << MinValue;

	return 0;
}