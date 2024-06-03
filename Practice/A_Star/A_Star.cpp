//Data
//10 19
//0 1 10
//0 2 17
//0 3 30
//0 4 25
//0 5 23
//1 2 20
//2 4 17
//3 1 19
//3 6 24
//4 7 25
//4 8 39
//5 3 16
//5 4 28
//5 6 18
//6 9 20
//7 8 29
//8 5 20
//8 9 28
//9 7 40
//�޸���ƽ ����ġ
//9
//0 9 52
//1 9 61
//2 9 68
//3 9 40
//4 9 52
//5 9 34
//6 9 19
//7 9 39
//8 9 19

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>

int V, E; //���� ����, ������ ����
std::vector<std::set<std::pair<int, int>>> LinkNodes; // LinkNodes[A_node] = {cost, B_node} 
std::vector<int> Heuristics; //Heuristics[a] = Cost// a ��忡�� ���� ����(9)������ ���� �Ÿ�

std::vector<int> Dijkstra(int Start)
{
	std::vector<int> Dist; // Dist[a] = Mincost // Start���� a�� ���� �ּ� ����� ����
	Dist.resize(V, INT32_MAX);
	Dist[Start] = 0; //�������� ����� �翬�� 0;

	std::vector<int> ByPass; //ByPass[a] = PathInfo // Start���� a�� ���� ��� ������ ����, Union - Find �˰��򿡼�, Find �Լ� ���� 
	ByPass.resize(V, -1);
	ByPass[Start] = Start;

	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
	pq.push(std::make_pair(Dist[Start], Start));

	while (!pq.empty())
	{
		int CurCost = pq.top().first;
		int CurIndex = pq.top().second;

		pq.pop();

		if (Dist[CurIndex] < CurCost)
		{
			continue;
		}

		for (auto& LinkNode : LinkNodes[CurIndex])
		{
			int ViaCost = CurCost + LinkNode.first;
			if (Dist[LinkNode.second] < ViaCost)
			{
				continue;
			}

			Dist[LinkNode.second] = ViaCost;
			ByPass[LinkNode.second] = CurIndex;
			pq.push(std::make_pair(Dist[LinkNode.second], LinkNode.second));
		}
	}

	return ByPass;
}

//����������� �������� ��θ� ã�� �Լ�, Path�� ����
std::stack<int> Path;
int FindParent(int FindValue, std::vector<int>& Data)
{
	Path.push(FindValue);

	if (Data[FindValue] == FindValue)
	{
		return FindValue;
	}

	Data[FindValue] = FindParent(Data[FindValue], Data);
	return Data[FindValue];
}

int main()
{
	std::cin >> V >> E;

	LinkNodes.resize(V, std::set<std::pair<int, int>>());

	for (int i = 0; i < E; i++)
	{
		int ANode, BNode, Cost;
		std::cin >> ANode >> BNode >> Cost;

		LinkNodes[ANode].insert(std::make_pair(Cost, BNode));
		LinkNodes[BNode].insert(std::make_pair(Cost, ANode));
	}

	int EndNode;
	std::cin >> EndNode;
	Heuristics.resize(EndNode);

	for (int i = 0; i < V - 1; i++)
	{

	}

	int StartNode = 0;
	std::vector<int> Result = Dijkstra(StartNode);

	FindParent(EndNode, Result);

	int a = 0;
	return 0;
}

