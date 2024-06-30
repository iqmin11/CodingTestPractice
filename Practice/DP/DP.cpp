#include <iostream>
#include <vector>

//배낭 문제
//기본적으로 배낭문제는 짐의 무게와 가치가 주어진다.
//내 가방의 제한된 무게 안에서 최대한 가치가 높도록 짐을 쌓는 방식이다.

struct Load
{
	Load(int _Weight, int _Worth)
		:Weight(_Weight), Worth(_Worth)
	{

	}

	int Weight = 0; //무게정보
	int Worth = 0; //가치 정보
};

int LoadCount = 4; // 짐의 갯수
int BackPack = 7; // 배낭에 담을 수 있는 최대 무게
std::vector<Load> LoadsInfo = { { 0,0 }, //dummy
	{6, 13}, //1번짐
	{4, 8}, //2번짐
	{3, 6}, //3번짐
	{5, 12} //4번짐
}; 

int BackpackProblem()
{
	//Init
	std::vector<std::vector<int>> DP; //DP[LoadCount][Weight]
	DP.resize(LoadCount + 1);
	for (int i = 0; i <= LoadCount; i++)
	{
		DP[i].resize(BackPack + 1);
	}

	//Sol
	for (int i = 1; i <= LoadCount; i++)
	{
		for (int w = 1; w <= BackPack; w++) //남은 무게
		{
			//남은 무게에 비해서 짐의 무게가 무거울 때
			if (LoadsInfo[i].Weight > w)
			{
				DP[i][w] = DP[i - 1][w];
			}
			else
			{
				int DontLoad = DP[i - 1][w];// 짐을 안 넣을 경우;
				int AddLoad = DP[i - 1][w - LoadsInfo[i].Weight] + LoadsInfo[i].Worth;// 짐을 넣을 경우;

				DP[i][w] = std::max(DontLoad, AddLoad); //둘 중 가치가 높은 경우
			}
		}
	}

	return DP[LoadCount][BackPack];
}

//가장 긴 증가하는 부분수열

//공통 부분 문자열

//동전 문제

int main()
{
	std::cout << BackpackProblem() << std::endl;
	return 0;
}