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

//동전 문제 // 느낌은 알겠지만 정확한 이해는 하지 못했다. 걍 외우자
//동전문제는 사용할 수 있는 동전의 종류와 만들어야 하는 금액이 주어진다
//만들 수 있는 경우의 수를 출력한다

std::vector<int> CoinCase = { 1,2,5 };
int MakeMoney = 10;
//Answer = 10;

int CoinProblem()
{
	std::vector<int> DP;
	DP.resize(MakeMoney + 1, 0); //해당 금액까지 DP
	DP[0] = 1; //DP[0]은 1이어야 한다

	//동전 종류를 돌면서
	for (int i = 0; i < CoinCase.size(); i++)
	{
		//동전 금액부터 최종 금액까지 돌면서
		for (int j = CoinCase[i]; j <= MakeMoney; j++)
		{
			//현재 금액까지 도달하는 경우의 수는
			//현재 금액에서 지금 체크하는 Coin을 뺀 금액의 경우의 수를 모두 더하는것이다;
			DP[j] += DP[j - CoinCase[i]];
		}
	}

	return DP[MakeMoney];
}

//외판원 순회
//외판원이 중복 없이 모든 노드를 방문하고 가장 처음 노드로 돌아갈 때, 최소비용 구하기
//비용 배열이 주어진다 Cost[a][b] -> a에서 b로 가는 비용
//DP[i][Visited] //i 노드에 있으며, 방문 상태가 Visited일때의 최소비용을 저장합니다.
//DFS를 통해 노드를 순회하며, Visited가 AllVisited일때 i에서 처음 노드로 돌아갈 수 있으면 된다

int NodeCount = 4;
std::vector<std::vector<int>> Cost = 
{
	{0,10,15,20},
	{5, 0, 9, 10},
	{6, 13, 0, 12},
	{8, 8, 9, 0}
};

std::vector<std::vector<int>> DP;
const int INF = 987654321; //가는것이 불가능하다는 의미의 INF
int AllVisit = 1; //모든 노드 방문 표시

void CirculInit()
{
	DP.resize(NodeCount);
	unsigned int Pow = 1 << NodeCount;
	for (int i = 0; i < NodeCount; i++)
	{
		DP[i].resize(Pow, -1);
	}

	AllVisit = (AllVisit << NodeCount) - 1;
}

int DFS(int CurNode, int Visited)
{
	if (AllVisit == Visited) //방문이 끝났다면
	{
		if (Cost[CurNode][0] == 0) //근데 순회가 불가능 하다면
		{
			return INF;
		}
		else
		{
			return Cost[CurNode][0]; //순회가 가능하다면 비용을 반환
		}
	}

	//DP를 갱신한 적이 있다면
	if (DP[CurNode][Visited] != -1)
	{
		return DP[CurNode][Visited]; //최소비용 반환
	}

	DP[CurNode][Visited] = INF; //아니라면 min을 하기위해 INF로 초기화

	for (int CheckNode = 0; CheckNode < NodeCount; CheckNode++) //CurNode로 부터 갈 수 있는 곳을 체크하며
	{
		if (Cost[CurNode][CheckNode] == 0) //단순히 연결이 안되어있다면
		{
			continue;
		}

		if (Visited >> CheckNode & 1) //이미 방문한 곳이라면
		{
			continue;
		}

		//현재 상태에서의 최소값은 결국 ...?
		DP[CurNode][Visited] = std::min(DP[CurNode][Visited], Cost[CurNode][CheckNode] + DFS(CheckNode, Visited | (1 << CheckNode)));
	}

	//최소값 반환
	return DP[CurNode][Visited];
}

int CirculSol()
{
	CirculInit();
	return DFS(0, 1);
}

int main()
{
	std::cout << BackpackProblem() << std::endl;
	std::cout << LIS() << std::endl;
	std::cout << LCPS() << std::endl;
	std::cout << CoinProblem() << std::endl;
	std::cout << CirculSol() << std::endl;
	return 0;
}