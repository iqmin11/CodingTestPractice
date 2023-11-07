#include <iostream>
#include <vector>
#include <set>
#include <queue>

struct Node // �׷��� ���� �̷����� ������ ������
{
	std::set<int> LinkNodes = std::set<int>(); // �ߺ��� �ȵ������� �� ��� ����, �ڵ����� �������� ���ĵ� ��
	bool IsVisit = false; // �湮 ����
};

std::vector<Node> G = std::vector<Node>();

void DFS(int _StartIndex) // �Լ����� �˾ƾߵǴ°� ���������� �׷���
{
	int CurIndex = _StartIndex; // �ʱ�ȭ (�����ε����� StartIndex)

	if (!G[CurIndex].IsVisit) // ���� Ž���ϴ� �ε����� �湮�� ���� ���ٸ�
	{
		G[CurIndex].IsVisit = true; // �湮�ߴٰ� �ٲٰ�
		std::cout << CurIndex + 1 << " ";

		for (auto& i : G[CurIndex].LinkNodes) // ����� ��带 ���鼭
		{
			DFS(i); // ���� Ž�� ��带 StartIndex���� DFS
		}
	}
}

void BFS(int _StartIndex)
{
	std::queue<int> Q = std::queue<int>(); //ť�� ����
	
	//����(while�������� �ʼ�)
	Q.push(_StartIndex); 
	G[Q.front()].IsVisit = true;

	while (!Q.empty())
	{
		for (auto& LinkNode : G[Q.front()].LinkNodes) //�³׵��� ���� ��带 ���鼭 ����ֱ�
		{
			if (!G[LinkNode].IsVisit) //���� �湮������ ������
			{
				Q.push(LinkNode); //���� Ž���ϰ��ִ� ��ũ ��带 q�� Ǫ��
				G[LinkNode].IsVisit = true; //�湮�ߴٰ� �ٲ��ְ�
			}
		}
		std::cout << Q.front() + 1 << " ";
		Q.pop(); 
	}
}

//���������� �� ���� ���� 1.5�� ������
//void BFS(int _StartIndex)
//{
//	std::queue<int> Q = std::queue<int>(); //ť�� ����
//
//	int PopSize = 0; //���� ������ ����
//	int PushSize = 0; //Ǫ���� ������ ����
//
//	//����(while�������� �ʼ�)
//	Q.push(_StartIndex);
//	PushSize++;
//	G[Q.front()].IsVisit = true;
//
//	while (!Q.empty())
//	{
//		PopSize = PushSize; //�����ܰ迡�� Ǫ���Ѿִ� �̹��� ���ؾ���
//		PushSize = 0; //�ʱ�ȭ
//
//		for (size_t i = 0; i < PopSize; i++) //���ҳ༮��(������ Ǫ���� �༮��) ���鼭
//		{
//			for (auto& LinkNode : G[Q.front()].LinkNodes) //�³׵��� ���� ��带 ���鼭 ����ֱ�
//			{
//				if (!G[LinkNode].IsVisit) //���� �湮������ ������
//				{
//					Q.push(LinkNode); //���� Ž���ϰ��ִ� ��ũ ��带 q�� Ǫ��
//					G[LinkNode].IsVisit = true; //�湮�ߴٰ� �ٲ��ְ�
//					PushSize++;
//				}
//			}
//			std::cout << Q.front() + 1 << " ";
//			Q.pop(); //������ Ǫ���ѳ༮�� ���ϱ�
//		}
//	}
//}

int main()
{
	int N, M, V;
	
	std::cin >> N;
	std::cin >> M;
	std::cin >> V;
	
	G.resize(N);
	
	for (size_t i = 0; i < M; i++)
	{
		int first, second;
		std::cin >> first;
		std::cin >> second;

		G[first - 1].LinkNodes.insert(second - 1);
		G[second - 1].LinkNodes.insert(first - 1);
	}

	DFS(V - 1);
	for (size_t i = 0; i < G.size(); i++) // �ʱ�ȭ
	{
		G[i].IsVisit = false;
	}
	std::cout << std::endl;
	BFS(V - 1);

	return 0;
}