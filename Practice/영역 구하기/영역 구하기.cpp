#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <list>
//DFS �׸��� ����� �ٸ��ٳ�, �ٸ���ĵ� ����߰ڴ�
//�����θ���ϱ� ������������
//ȥ�ڼ� 2�߹迭�� ������

int M = 0;
int N = 0;

struct Node
{
	Node(){} // �̰� �־�� map []���۷����� ��� ����

	Node(std::pair<int, int> _Pos)
		: Pos(_Pos)
	{
		SetLinkNodes();
	}

	void SetLinkNodes()
	{
		if (Pos.first + 1 < N)
			LinkNodes.insert(std::make_pair(Pos.first + 1, Pos.second));
		if (Pos.first - 1 >= 0)
			LinkNodes.insert(std::make_pair(Pos.first - 1, Pos.second));
		if (Pos.second + 1 < M)
			LinkNodes.insert(std::make_pair(Pos.first, Pos.second + 1));
		if (Pos.second - 1 >= 0)
			LinkNodes.insert(std::make_pair(Pos.first, Pos.second - 1));
	}

	std::pair<int, int> Pos = std::pair<int, int>(); // x,y int2���� ������->���۷����͸� ���� ���� �ʿ䰡 ����->key������ ��� ����
	std::set<std::pair<int, int>> LinkNodes = std::set<std::pair<int, int>>();
	bool IsVisit = false;
};

std::map<std::pair<int, int>, Node> Grid = std::map<std::pair<int, int>, Node>();

int DFS(std::pair<int, int> _StartPos)
{
	int Count = 0;
	if (!Grid[_StartPos].IsVisit) // ���� Ž���ϴ� �ε����� �湮�� ���� ���ٸ�
	{
		Count++;
		Grid[_StartPos].IsVisit = true; // �湮�ߴٰ� �ٲٰ�

		for (auto& i : Grid[_StartPos].LinkNodes) // ����� ��带 ���鼭
		{
			Count += DFS(i); // ���� Ž�� ��带 StartIndex���� DFS
		}
	}
	return Count;
}

int main()
{
	std::cin >> M >> N;

	//�׸��� ����
	for (int y = 0; y < M; y++)
	{
		for (int x = 0; x < N; x++)
		{
			std::pair<int, int> tempPos = std::make_pair(x, y);
			Grid.insert(std::make_pair(tempPos, Node(tempPos)));
		}
	}

	//���� ��ĥ
	int K;
	std::cin >> K;
	for (int i = 0; i < K; i++)
	{
		std::pair<int, int> tempMin;
		std::pair<int, int> tempMax;
		std::cin >> tempMin.first >> tempMin.second;
		std::cin >> tempMax.first >> tempMax.second;
		
		for (int y = tempMin.second; y < tempMax.second; y++)
		{
			for (int x = tempMin.first; x < tempMax.first; x++)
			{
				std::pair<int, int> tempPos = std::make_pair(x,y);
				Grid.find(tempPos)->second.IsVisit = true;
			}
		}
	}
	
	int CountTerra = 0;
	std::list<int> Sizes = std::list<int>(); //�������������

	//��� ��忡�� DFS����
	for (int y = 0; y < M; y++)
	{
		for (int x = 0; x < N; x++)
		{
			int SizeOfTerra = 0; //����ȳ��� ���� �������� ī��Ʈ�� �ö󰡴³� (������ ũ��)
			std::pair<int, int> StartPos = std::make_pair(x, y);
			bool StartVisitValue = Grid[StartPos].IsVisit; // ���������� false�������� ����

			if (!StartVisitValue) //DFS ó�� �����ϴ°��� ���� IsVisit false�� ���� �ϳ���
			{
				CountTerra++;
			}
			SizeOfTerra = DFS(StartPos);
			if (!StartVisitValue) //DFS ó�� �����ϴ°��� IsVisit false���� ��쿡�� ��������� Ǫ�ù�
			{
				Sizes.push_back(SizeOfTerra);
			}
		}
	}

	std::vector<int> Sizes_vec = std::vector<int>(Sizes.begin(), Sizes.end()); //�������������
	std::sort(Sizes_vec.begin(), Sizes_vec.end()); // �������� ����

	// ���
	std::cout << CountTerra << std::endl;
	for (int i = 0; i < Sizes_vec.size(); i++)
	{
		std::cout << Sizes_vec[i] << " ";
	}

	return 0;
}