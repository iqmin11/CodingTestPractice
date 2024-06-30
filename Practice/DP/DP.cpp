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
			//���� ���Կ� ���ؼ� ���� ���԰� ���ſ� ��
			if (LoadsInfo[i].Weight > w)
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

//���� �κ� ���ڿ�

//���� ����

int main()
{
	std::cout << BackpackProblem() << std::endl;
	return 0;
}