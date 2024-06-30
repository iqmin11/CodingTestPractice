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

//���� ����

int main()
{
	std::cout << BackpackProblem() << std::endl;
	std::cout << LIS() << std::endl;
	std::cout << LCPS() << std::endl;
	return 0;
}