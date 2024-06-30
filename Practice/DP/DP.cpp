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
//Answer : 14

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
			if (LoadsInfo[i].Weight > w) //남은 무게에 비해서 짐의 무게가 무거울 때
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
//응용문제로는 줄세우기가 있다.
//해당 유형의 문제는, 불규칙한 수열이 주어진다
std::vector<int> Arr = { 12,3,4,5,22,15,2,16,17,1,50,6 };
//Answer : 7

int LIS()
{
	//DP배열을 만들고, Arr상 앞 숫자들과 크기 비교를 한다
	std::vector<int> DP(Arr.size(), 1);

	for (size_t CurIndex = 0; CurIndex < Arr.size(); CurIndex++)
	{
		for (size_t PrevIndex = 0; PrevIndex < CurIndex; PrevIndex++)
		{
			//두 숫자를 비교해서 오름차순이라면
			if (Arr[CurIndex] > Arr[PrevIndex])
			{
				//누가 더 긴지 비교를 하고, 더 긴 경우를 저장한다
				DP[CurIndex] = std::max(DP[CurIndex], DP[PrevIndex] + 1);
			}
		}
	}

	int Answer = INT32_MIN;
	for (auto i : DP)
	{
		Answer = std::max(Answer, i);
	}

	return Answer;
}

//공통 부분 문자열
//해당 유형은 두개의 문자열이 주어지고, 연속된 부분문자열 중 가장 긴 공통 부분문자열을 찾는 것이다.

std::string Str1 = "aaaaabbbcccdd";
std::string Str2 = "asdasdabbbccasdasd"; 
//Answer : 6

int LCPS()
{
	//Init
	std::vector<std::vector<int>> DP;
	DP.resize(Str1.size());
	for (size_t i = 0; i < Str1.size(); i++)
	{
		DP[i].resize(Str2.size(), 0);
	}
	
	//Sol
	int Answer = INT32_MIN;

	for (int y = 0; y < DP.size(); y++)
	{
		for (int x = 0; x < DP[y].size(); x++)
		{
			if (Str1[y] == Str2[x])
			{
				if (x == 0 || y == 0)
				{
					DP[y][x] = 1;
				}
				else
				{
					DP[y][x] = DP[y - 1][x - 1] + 1;
				}

				Answer = std::max(Answer, DP[y][x]);
			}
		}
	}

	return Answer;
}

//동전 문제

int main()
{
	std::cout << BackpackProblem() << std::endl;
	std::cout << LIS() << std::endl;
	std::cout << LCPS() << std::endl;
	return 0;
}