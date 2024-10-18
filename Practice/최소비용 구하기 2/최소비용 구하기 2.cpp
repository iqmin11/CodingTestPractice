//���� �ּ� : https://www.acmicpc.net/problem/11779

#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <stack>

int V, E;
int Start, Dest;
std::vector<std::set<std::pair<int, int>>> LinkNodes; //LinkNodes[a] = a�� ����� ������ ������ first->���, second->������

int Dijkstra(std::vector<int>& Path)
{
	std::vector<int> Dist; //Dist[a] = Start���� a�� ���� �ּ� ���
	Dist.resize(V, INT32_MAX); //��� int_max�� �ʱ�ȭ
	Dist[Start] = 0; //���������� ����� 0���� �翬��
	Path.resize(V, -1); // ���� ����

	std::priority_queue<std::pair<int, int>> pq; //��ũ��� ������ <���, �ε���>�� �켱���� ť�� ����
	pq.push({ -Dist[Start] , Start });//<��� , ��ġ>�� �ִµ�, pq�� �������� �����̱⶧���� ����� �������� ���ķ� �ٲٱ� ���ؼ�
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
				Path[LinkNode.second] = CurIndex; // ��� ���� �Դ��� ��� ����
				pq.push({ -Dist[LinkNode.second], LinkNode.second });//�����Ҷ��ѰŶ� ����? <-��� , ��ġ>Ǫ��
			}
		}
	}

	return Dist[Dest];
} //�켱���� ť�� Ȱ���Ͽ� �ð����⵵ ȿ���� �ø�

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> V >> E;
	LinkNodes.resize(V);

	for (int i = 0; i < E; i++)
	{
		int From, To, Cost;
		std::cin >> From >> To >> Cost;
		From--;
		To--;
		LinkNodes[From].insert(std::make_pair(Cost, To));
	}

	std::cin >> Start >> Dest;
	Start--;
	Dest--;

	std::vector<int> Path;
	std::cout << Dijkstra(Path) << '\n';

	int InDepth = Dest;
	std::stack<int> PathStack;
	while (InDepth != -1)
	{
		PathStack.push(InDepth);
		InDepth = Path[InDepth];
	}

	std::cout << PathStack.size() << '\n';

	while (!PathStack.empty())
	{
		std::cout << PathStack.top() + 1 << ' ';
		PathStack.pop();
	}

	return 0;
}