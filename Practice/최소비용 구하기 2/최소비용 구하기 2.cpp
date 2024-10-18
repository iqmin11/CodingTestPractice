//문제 주소 : https://www.acmicpc.net/problem/11779

#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <stack>

int V, E;
int Start, Dest;
std::vector<std::set<std::pair<int, int>>> LinkNodes; //LinkNodes[a] = a랑 연결된 노드들의 정보들 first->비용, second->연결노드

int Dijkstra(std::vector<int>& Path)
{
	std::vector<int> Dist; //Dist[a] = Start에서 a로 가는 최소 비용
	Dist.resize(V, INT32_MAX); //모두 int_max로 초기화
	Dist[Start] = 0; //시작지점의 비용은 0이죠 당연히
	Path.resize(V, -1); // 직전 저장

	std::priority_queue<std::pair<int, int>> pq; //링크노드 형태인 <비용, 인덱스>를 우선순위 큐에 저장
	pq.push({ -Dist[Start] , Start });//<비용 , 위치>로 넣는데, pq는 내림차순 정렬이기때문에 비용의 오름차순 정렬로 바꾸기 위해서
	//-비용으로 저장하고, 꺼냈을때 다시 -를 곱해줘 양수로 사용
	while (!pq.empty())
	{
		//가장 앞에있는애(pq에 저장된 노드 중 이동 비용이 가장 작은놈)가 이제 체크할 놈이겠죠?
		int CurCost = -pq.top().first; //CurNode로 가는 비용 , -를 곱해서 원래값으로 사용
		int CurIndex = pq.top().second;//CurNode의 인덱스

		pq.pop();//팦하고

		//1. Dist[CurIndex] => 현재 기록한 CurIndex로 가는 최소비용과 CurCost를 비교해서
		//	Dist[CurIndex] < CurCost면 컨티뉴(어차피 via = curcost + LinkNodecost인데 curcost가 이미 크면 아래 과정이 필요가 없음)
		if (Dist[CurIndex] < CurCost)
		{
			continue;
		}

		//2. 여기선 최소값 갱신의 과정을 거쳐야겠죠?
		for (auto& LinkNode : LinkNodes[CurIndex])//현재 체크하는 인덱스랑 연결되어있는 노드들을 돌면서
		{
			int ViaCost = CurCost + LinkNode.first;//CurNode로 간 비용 + CurNode에서 LinkNode로 가는 비용 cf)via : ~를 통해
			if (Dist[LinkNode.second] > ViaCost) //현재 체크한 최소비용이랑 비교
			{
				Dist[LinkNode.second] = ViaCost; //via가 더 작으면 갱신
				Path[LinkNode.second] = CurIndex; // 어디서 부터 왔는지 경로 저장
				pq.push({ -Dist[LinkNode.second], LinkNode.second });//시작할때한거랑 같죵? <-비용 , 위치>푸시
			}
		}
	}

	return Dist[Dest];
} //우선순위 큐를 활용하여 시간복잡도 효율을 올림

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