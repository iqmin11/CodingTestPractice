#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <queue>

//�׷����� �ڷᰣ ������踦 ǥ���� �ڷᱸ��

struct Node
{
	//���� set�� �ַ� ����ϴ� ����
	// 1. �ߺ� ��尡 ���� ���� ����
	// 2. ������������ ���ĵǸ�
	// 3. ��� ���� �� �𸣱� ������ �̸� reserve�� resize�� �ؾ��ϴ� vector���ٴ� set�� ���ٰ� ����(�޸� ȿ��)
	// �׷��� �ߺ��� �ڷᰡ ���� ���� ����, ����Ǵ� ����� ���� ���� ��� vector�� �ξ� ����(�޸� ����ȭ�� ����)
	std::set<int> LinkNodes; //���⿡�� ����� ����� �ε����� ����
	bool IsVisit = false;// BFS, DFS Ž���� ���� �湮 ���� üũ
};

std::vector<Node> Graph; //�ε��� ������ �ϱ� ���� ���ͷ� ǥ��
//�������� ���� �̷���� ������, �� ���� � ���� ����Ǿ��ִ��� �˾ƾ���

//DFS(���� �켱 Ž��)
//�����������κ����� ����Ž��, �Ǵ� ���������� ���� ��� ��θ� ���ϰ��� �� �� ����ϸ� ����
void DFS(int _Start) //DFS�� Ȱ���� ����Ž��
{
	Graph[_Start].IsVisit = true; //�������� �湮
	std::cout << _Start << " ";
	for (auto& LinkNode : Graph[_Start].LinkNodes) //��ũ���� ���鼭
	{
		if (Graph[LinkNode].IsVisit == false) // �ش� ��忡 �湮�� ���� ���ٸ�
		{
			DFS(LinkNode);//Ž��
		}
	}
}

std::list<int> DFS_Path_Stack; //���� ������ �� ����Ʈ ����(�����ڷ����� ��ȸ�� �ȵ�)
void DFS_StoE(int _Start, int _End) //���������� ��ǥ�� ���� ��� ��θ� ���ϰ��� ��
{
	Graph[_Start].IsVisit = true;
	DFS_Path_Stack.push_back(_Start); //DFS�� ���ö� ��θ� Stack�� ����

	if (_Start == _End) //�������� �ٴٶ��ٸ�
	{
		for (auto& Path : DFS_Path_Stack)
		{
			std::cout << Path << " "; //��� ���
		}
		std::cout << std::endl;
	}
	
	for (auto& LinkNode : Graph[_Start].LinkNodes) 
	{
		if (Graph[LinkNode].IsVisit == false)
		{
			DFS(LinkNode);//Ž��
		}
	}

	DFS_Path_Stack.pop_back(); //DFS���� ������ ��� pop
	Graph[_Start].IsVisit = false; //������ �湮ó�� �ǵ�����
}

//BFS(�ʺ� �켱 Ž��)
//������������ ���� ����Ž��, �ִܰ��, ������ �������� ����

void BFS(int _Start) //BFS�� Ȱ���� ���� Ž��
{
	std::queue<int> q;

	Graph[_Start].IsVisit = true;
	q.push(_Start);
	std::cout << _Start << " ";

	while (!q.empty())
	{
		int CheckNode = q.front();
		q.pop();

		for (auto& LinkNode : Graph[CheckNode].LinkNodes)
		{
			if (!Graph[LinkNode].IsVisit)
			{
				Graph[LinkNode].IsVisit = true;
				q.push(LinkNode);
				std::cout << LinkNode << " ";
			}
		}
	}
}

int BFS_SToE(int _Start, int _End) // ������������ ������������ �ִܰŸ�
{
	std::queue<int> q;
	std::vector<int> Depth;
	Depth.resize(Graph.size(), INT32_MAX);

	Graph[_Start].IsVisit = true;
	q.push(_Start);
	Depth[_Start] = 0;

	while (!q.empty())
	{
		int CheckNode = q.front();
		q.pop();
		for (auto& LinkNode : Graph[CheckNode].LinkNodes)
		{
			if (!Graph[LinkNode].IsVisit)
			{
				Depth[LinkNode] = Depth[CheckNode] + 1;
				Graph[LinkNode].IsVisit = true;
				q.push(LinkNode);
			}
		}
	}

	return Depth[_End]; //���� �Ұ��� �� INT32_MAX ����
}

//���ͽ�Ʈ�� �˰��� (Dijkstra)
//One To All, �ּ� ���

//�׷��� + ��� �̵��� ���� ������ �ִ°��
//���߹迭�� ���� : Cost[a][b] = a���� b�� ���� ���(a == b�ΰ�� 0, �������� ���� ��� INT32_MAX)
std::vector<std::vector<int>> Cost =
{ {0,7,4,6,1}
, {UINT16_MAX, 0, UINT16_MAX, UINT16_MAX, UINT16_MAX}
, {UINT16_MAX, 2, 0, 5,UINT16_MAX}
, {UINT16_MAX, 3, UINT16_MAX, 0, UINT16_MAX}
, {UINT16_MAX, UINT16_MAX, UINT16_MAX, 1, 0} };

std::vector<int> Dijkstra(int _Start) //Start�κ��� ��� ���� ���ϴ� �ּҺ���� ���ϴ� ���̱� ������ ���ڷ� Start�� �޾Ƶ���
{
	std::vector<int> Dist(Cost[_Start]); //Dist[a] = _Start���� a�� ���ϴ� �ּҺ��, �ʱ�ȭ�� Cost[������]����
	Graph[_Start].IsVisit = true; //�湮ó��

	for (int i = 0; i < Dist.size() - 1; i++)
	{
		int MinIndex = 0; //���� ���� ����� ���� �ε��� Ž��
		int MinValue = INT32_MAX; 
		for (int j = 0; j < Dist.size(); j++)
		{
			if (Graph[j].IsVisit == true)
			{
				continue;
			}

			if (Dist[j] < MinValue)
			{
				MinIndex = j;
				MinValue = Dist[j];
			}
		}

		//2. MinIndex�湮
		Graph[MinIndex].IsVisit = true;
		for (int j = 0; j < Dist.size(); j++)
		{
			if (Graph[j].IsVisit == true)
			{
				continue;
			}

			if (Dist[j] > Cost[MinIndex][j] + Dist[MinIndex])
			{
				Dist[j] = Cost[MinIndex][j] + Dist[MinIndex];
			}
		}
	}

	return Dist;
} //O(V^2) N-1�� ���鼭 N�� Ž�� -> ��ȿ����


//�ð����⵵�� ���̱� ���� �켱����ť�� �̿��� ���ͽ�Ʈ�� �˰���

//���� ��带 ����
std::vector<std::set<std::pair<int, int>>> LinkNodes; //LinkNodes[a] = a�� ����� ������ ������ first->���, second->������
//pair�� �� �����ڶ����� first(���) �������� ���ĵȴ�(����� ������ �ε��� ��������)

std::vector<int> DijkstraPQ(int _Start)
{
	std::vector<int> Dist; //Dist[a] = _Start���� a�� ���� �ּ� ���
	Dist.resize(Graph.size(), INT32_MAX); //��� int_max�� �ʱ�ȭ
	Dist[_Start] = 0; //���������� ����� 0���� �翬��

	std::priority_queue<std::pair<int, int>> pq; //��ũ��� ������ <���, �ε���>�� �켱���� ť�� ����
	pq.push({ -Dist[_Start] , _Start });//<��� , ��ġ>�� �ִµ�, pq�� �������� �����̱⶧���� ����� �������� ���ķ� �ٲٱ� ���ؼ�
										//-������� �����ϰ�, �������� �ٽ� -�� ������ ����� ���
	while (!pq.empty())
	{
		//���� �տ��ִ¾�(pq�� ����� ��� �� �̵� ����� ���� ������)�� ���� üũ�� ���̰���?
		int CurCost = -pq.top().first; //CurNode�� ���� ��� , -�� ���ؼ� ���������� ���
		int CurIndex = pq.top().second;//CurNode�� �ε���

		pq.pop();//�b�ϰ�

		//1. Dist[CurIndex] => ���� ����� CurIndex�� ���� �ּҺ��� CurCost�� ���ؼ�
		//	Dist[CurIndex] < CurCost�� ��Ƽ��(������ via = curcost + LinkNodecost�ε� curcost�� �̹� ũ�� �Ʒ� ������ �ʿ䰡 ����)
		if (Dist[CurIndex] < CurCost)
		{
			continue;
		}

		//2. ���⼱ �ּҰ� ������ ������ ���ľ߰���?
		for (auto& LinkNode : LinkNodes[CurIndex])//���� üũ�ϴ� �ε����� ����Ǿ��ִ� ������ ���鼭
		{
			int ViaCost = CurCost + LinkNode.first;//CurNode�� �� ��� + CurNode���� LinkNode�� ���� ��� cf)via : ~�� ����
			if (Dist[LinkNode.second] > ViaCost) //���� üũ�� �ּҺ���̶� ��
			{
				Dist[LinkNode.second] = ViaCost; //via�� �� ������ ����
				pq.push({ -Dist[LinkNode.second], LinkNode.second });//�����Ҷ��ѰŶ� ����? <-��� , ��ġ>Ǫ��
			}
		}
	}

	return Dist;
} //�켱���� ť�� Ȱ���Ͽ� �ð����⵵ ȿ���� �ø�

//�÷��̵� �ͼ� �˰���(Floyd_Warshall)
//All To All, �ּ� ���

std::vector<std::vector<int>> Floyd_Warshall()
{
	std::vector<std::vector<int>> Dist = Cost;//Dist[a][b] -> A����B�� ���� �ּҺ��

	size_t N = Dist.size();
	
	//k�� ���İ��� ���, i�� ���۳��, j�� �������
	for (size_t k = 0; k < N; k++)
	{
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				Dist[i][j] = std::min(Dist[i][j], Dist[i][k] + Dist[k][j]);
			}
		}
	}

	return Dist;
}

//���� ����(Topology sort)
//����Ŭ�� �߻����� �ʴ� �׷������� ���

//���� �� �ִ°�
//1. ����Ŭ�� �߻� ����
//2. �������� ���

//�ʿ� ����
//1. ����� ���� ����(�ش� ���� �� �� �ִ� ���� ����� ��)
//2. ��ũ ��� ����

//0~6�̶�� �սô�
std::vector<int> InDgree = {0, 1, 1, 1, 1, 2, 1}; //��������
std::vector<std::set<int>> TopologyLinkNodes; //���� ���

bool TopologySort(std::vector<int>& _result)
{
	std::vector<int>& result = _result;

	std::queue<int> q; //ť�� �����
	
	for (size_t i = 0; i < InDgree.size(); i++)
	{
		if (InDgree[i] == 0) //���������� 0�� �ֵ��� q�� �־�
		{
			q.push(i);
		}
	}
	
	for (size_t i = 0; i < InDgree.size(); i++)
	{
		if (q.empty()) //�ݺ����� ������ ���� q�� ����ٸ�
		{
			return false; //�������� ���� (����Ŭ�� ����)
		}

		int CheckIndex = q.front(); //����Ʈ�� üũ
		q.pop(); // ���ϰ�
		result.push_back(CheckIndex); //����� ���İ� �ֱ�

		for (auto& LinkNode : TopologyLinkNodes[CheckIndex]) //üũ����� ������ ���鼭
		{
			if (--InDgree[LinkNode] == 0) //��� ���� ����(��Ȯ���� ���������� ���)
			{
				q.push(LinkNode); //���������� 0�� �ֵ� q�� �ֱ�
			}
		}
	}

	return true;
}

std::vector<std::set<int>> CaseLinkNodes = { {1,2,3}, {0,2,3}, {0,1,3}, {0,1,2} };
std::vector<bool> CaseIsVisit = { false, false, false, false };
std::vector<int> CasePrintStack;

void DFS_Combination(int _Start, int _r) // ����
{
	CaseIsVisit[_Start] = true;
	CasePrintStack.push_back(_Start);

	if (CasePrintStack.size() == _r)
	{
		for (size_t i = 0; i < CasePrintStack.size(); i++)
		{
			std::cout << CasePrintStack[i] << ' ';
		}
		std::cout << std::endl;

		CasePrintStack.pop_back();
		CaseIsVisit[_Start] = false;
		return;
	}

	for (auto& LinkNode : CaseLinkNodes[_Start])
	{
		if (!CaseIsVisit[LinkNode] && LinkNode > CasePrintStack.back())
		{
			DFS_Combination(LinkNode, _r);
		}
	}

	CasePrintStack.pop_back();
	CaseIsVisit[_Start] = false;
}

void Combination(int _n, int _r)
{
	for (size_t i = 0; i < _n; i++)
	{
		DFS_Combination(i, _r);
	}
}

void DFS_Permutation(int _Start, int _r) // ����
{
	CaseIsVisit[_Start] = true;
	CasePrintStack.push_back(_Start);

	if (CasePrintStack.size() == _r)
	{
		for (size_t i = 0; i < CasePrintStack.size(); i++)
		{
			std::cout << CasePrintStack[i] << ' ';
		}
		std::cout << std::endl;

		CasePrintStack.pop_back();
		CaseIsVisit[_Start] = false;
		return;
	}

	for (auto& LinkNode : CaseLinkNodes[_Start])
	{
		if (!CaseIsVisit[LinkNode])
		{
			DFS_Combination(LinkNode, _r);
		}
	}

	CasePrintStack.pop_back();
	CaseIsVisit[_Start] = false;
}

void Permutation(int _n, int _r)
{
	for (size_t i = 0; i < _n; i++)
	{
		DFS_Permutation(i, _r);
	}
}

int main()
{
	Graph.resize(5);
	std::vector<int> a = Dijkstra(0);

	LinkNodes.resize(Graph.size());
	for (size_t y = 0; y < Cost.size(); y++)
	{
		for (size_t x = 0; x < Cost[y].size(); x++)
		{
			if (Cost[y][x] == UINT16_MAX || Cost[y][x] == 0)
			{
				continue;
			}

			LinkNodes[y].insert(std::make_pair(Cost[y][x], x));
		}
	}

	std::vector<int> c = DijkstraPQ(4);
	std::vector<std::vector<int>> d = Floyd_Warshall();

	TopologyLinkNodes.resize(7);
	
	TopologyLinkNodes[0].insert(1);
	TopologyLinkNodes[0].insert(4);
	TopologyLinkNodes[1].insert(2);
	TopologyLinkNodes[2].insert(3);
	TopologyLinkNodes[3].insert(5);
	TopologyLinkNodes[4].insert(5);
	TopologyLinkNodes[5].insert(6);

	std::vector<int> Result;
	bool AAA = TopologySort(Result);

	int k = 0;
}