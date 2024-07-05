#include <iostream>
#include <vector>

//�賶 ����
//�⺻������ �賶������ ���� ���Կ� ��ġ�� �־�����.
//�� ������ ���ѵ� ���� �ȿ��� �ִ��� ��ġ�� ������ ���� �״� ����̴�.

struct Load
{
	Load(int _Weight, int _Worth)
		:Weight(_Weight), Worth(_Worth)
	{

	}

	int Weight = 0; //��������
	int Worth = 0; //��ġ ����
};

int LoadCount = 4; // ���� ����
int BackPack = 7; // �賶�� ���� �� �ִ� �ִ� ����
std::vector<Load> LoadsInfo = { { 0,0 }, //dummy
	{6, 13}, //1����
	{4, 8}, //2����
	{3, 6}, //3����
	{5, 12} //4����
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
		for (int w = 1; w <= BackPack; w++) //���� ����
		{
			if (LoadsInfo[i].Weight > w) //���� ���Կ� ���ؼ� ���� ���԰� ���ſ� ��
			{
				DP[i][w] = DP[i - 1][w];
			}
			else
			{
				int DontLoad = DP[i - 1][w];// ���� �� ���� ���;
				int AddLoad = DP[i - 1][w - LoadsInfo[i].Weight] + LoadsInfo[i].Worth;// ���� ���� ���;

				DP[i][w] = std::max(DontLoad, AddLoad); //�� �� ��ġ�� ���� ���
			}
		}
	}

	return DP[LoadCount][BackPack];
}

//���� �� �����ϴ� �κм��� 
//���빮���δ� �ټ���Ⱑ �ִ�.
//�ش� ������ ������, �ұ�Ģ�� ������ �־�����
std::vector<int> Arr = { 12,3,4,5,22,15,2,16,17,1,50,6 };
//Answer : 7

int LIS()
{
	//DP�迭�� �����, Arr�� �� ���ڵ�� ũ�� �񱳸� �Ѵ�
	std::vector<int> DP(Arr.size(), 1);

	for (size_t CurIndex = 0; CurIndex < Arr.size(); CurIndex++)
	{
		for (size_t PrevIndex = 0; PrevIndex < CurIndex; PrevIndex++)
		{
			//�� ���ڸ� ���ؼ� ���������̶��
			if (Arr[CurIndex] > Arr[PrevIndex])
			{
				//���� �� ���� �񱳸� �ϰ�, �� �� ��츦 �����Ѵ�
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

//���� �κ� ���ڿ�
//�ش� ������ �ΰ��� ���ڿ��� �־�����, ���ӵ� �κй��ڿ� �� ���� �� ���� �κй��ڿ��� ã�� ���̴�.

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

//���� ���� // ������ �˰����� ��Ȯ�� ���ش� ���� ���ߴ�. �� �ܿ���
//���������� ����� �� �ִ� ������ ������ ������ �ϴ� �ݾ��� �־�����
//���� �� �ִ� ����� ���� ����Ѵ�

std::vector<int> CoinCase = { 1,2,5 };
int MakeMoney = 10;
//Answer = 10;

int CoinProblem()
{
	std::vector<int> DP;
	DP.resize(MakeMoney + 1, 0); //�ش� �ݾױ��� DP
	DP[0] = 1; //DP[0]�� 1�̾�� �Ѵ�

	//���� ������ ���鼭
	for (int i = 0; i < CoinCase.size(); i++)
	{
		//���� �ݾ׺��� ���� �ݾױ��� ���鼭
		for (int j = CoinCase[i]; j <= MakeMoney; j++)
		{
			//���� �ݾױ��� �����ϴ� ����� ����
			//���� �ݾ׿��� ���� üũ�ϴ� Coin�� �� �ݾ��� ����� ���� ��� ���ϴ°��̴�;
			DP[j] += DP[j - CoinCase[i]];
		}
	}

	return DP[MakeMoney];
}

//���ǿ� ��ȸ
//���ǿ��� �ߺ� ���� ��� ��带 �湮�ϰ� ���� ó�� ���� ���ư� ��, �ּҺ�� ���ϱ�
//��� �迭�� �־����� Cost[a][b] -> a���� b�� ���� ���
//DP[i][Visited] //i ��忡 ������, �湮 ���°� Visited�϶��� �ּҺ���� �����մϴ�.
//DFS�� ���� ��带 ��ȸ�ϸ�, Visited�� AllVisited�϶� i���� ó�� ���� ���ư� �� ������ �ȴ�

int NodeCount = 4;
std::vector<std::vector<int>> Cost = 
{
	{0,10,15,20},
	{5, 0, 9, 10},
	{6, 13, 0, 12},
	{8, 8, 9, 0}
};

std::vector<std::vector<int>> DP;
const int INF = 987654321; //���°��� �Ұ����ϴٴ� �ǹ��� INF
int AllVisit = 1; //��� ��� �湮 ǥ��

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
	if (AllVisit == Visited) //�湮�� �����ٸ�
	{
		if (Cost[CurNode][0] == 0) //�ٵ� ��ȸ�� �Ұ��� �ϴٸ�
		{
			return INF;
		}
		else
		{
			return Cost[CurNode][0]; //��ȸ�� �����ϴٸ� ����� ��ȯ
		}
	}

	//DP�� ������ ���� �ִٸ�
	if (DP[CurNode][Visited] != -1)
	{
		return DP[CurNode][Visited]; //�ּҺ�� ��ȯ
	}

	DP[CurNode][Visited] = INF; //�ƴ϶�� min�� �ϱ����� INF�� �ʱ�ȭ

	for (int CheckNode = 0; CheckNode < NodeCount; CheckNode++) //CurNode�� ���� �� �� �ִ� ���� üũ�ϸ�
	{
		if (Cost[CurNode][CheckNode] == 0) //�ܼ��� ������ �ȵǾ��ִٸ�
		{
			continue;
		}

		if (Visited >> CheckNode & 1) //�̹� �湮�� ���̶��
		{
			continue;
		}

		//���� ���¿����� �ּҰ��� �ᱹ ...?
		DP[CurNode][Visited] = std::min(DP[CurNode][Visited], Cost[CurNode][CheckNode] + DFS(CheckNode, Visited | (1 << CheckNode)));
	}

	//�ּҰ� ��ȯ
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