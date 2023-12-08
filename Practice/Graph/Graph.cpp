#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <queue>

//그래프란 자료간 연결관계를 표현한 자료구조

struct Node
{
	//내가 set을 주로 사용하는 이유
	// 1. 중복 노드가 들어올 일이 없고
	// 2. 오름차순으로 정렬되며
	// 3. 몇개가 들어올 지 모르기 때문에 미리 reserve나 resize를 해야하는 vector보다는 set이 좋다고 생각(메모리 효율)
	// 그러나 중복된 자료가 들어올 일이 없고, 연결되는 노드의 양이 적을 경우 vector가 훨씬 빠름(메모리 단편화의 문제)
	std::set<int> LinkNodes; //여기에는 연결된 노드의 인덱스를 저장
	bool IsVisit = false;// BFS, DFS 탐색을 위한 방문 여부 체크
};

std::vector<Node> Graph; //인덱스 접근을 하기 쉬운 벡터로 표현
//여러개의 노드로 이루어져 있으며, 각 노드는 어떤 노드와 연결되어있는지 알아야함

//DFS(깊이 우선 탐색)
//시작지점으로부터의 완전탐색, 또는 목적지까지 가는 모든 경로를 구하고자 할 때 사용하면 유용
void DFS(int _Start) //DFS를 활용한 완전탐색
{
	Graph[_Start].IsVisit = true; //시작지점 방문
	std::cout << _Start << " ";
	for (auto& LinkNode : Graph[_Start].LinkNodes) //링크노드들 돌면서
	{
		if (Graph[LinkNode].IsVisit == false) // 해당 노드에 방문한 적이 없다면
		{
			DFS(LinkNode);//탐색
		}
	}
}

std::list<int> DFS_Path_Stack; //스택 역할을 할 리스트 생성(스택자료형은 순회가 안됨)
void DFS_StoE(int _Start, int _End) //시작점에서 목표로 가는 모든 경로를 구하고자 함
{
	Graph[_Start].IsVisit = true;
	DFS_Path_Stack.push_back(_Start); //DFS에 들어올때 경로를 Stack에 저장

	if (_Start == _End) //목적지에 다다랐다면
	{
		for (auto& Path : DFS_Path_Stack)
		{
			std::cout << Path << " "; //경로 출력
		}
		std::cout << std::endl;
	}
	
	for (auto& LinkNode : Graph[_Start].LinkNodes) 
	{
		if (Graph[LinkNode].IsVisit == false)
		{
			DFS(LinkNode);//탐색
		}
	}

	DFS_Path_Stack.pop_back(); //DFS에서 나갈때 경로 pop
	Graph[_Start].IsVisit = false; //나갈때 방문처리 되돌리기
}

//BFS(너비 우선 탐색)
//시작지점으로 부터 완전탐색, 최단경로, 목적지 도착가능 여부

void BFS(int _Start) //BFS를 활용한 완전 탐색
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

int BFS_SToE(int _Start, int _End) // 시작지점에서 도착지점까지 최단거리
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

	return Depth[_End]; //도달 불가능 시 INT32_MAX 리턴
}

//다익스트라 알고리즘 (Dijkstra)
//One To All, 최소 비용

//그래프 + 노드 이동시 들어가는 비용까지 있는경우
//이중배열로 저장 : Cost[a][b] = a에서 b로 가는 비용(a == b인경우 0, 인접하지 않은 경우 INT32_MAX)
std::vector<std::vector<int>> Cost =
{ {0,7,4,6,1}
, {UINT16_MAX, 0, UINT16_MAX, UINT16_MAX, UINT16_MAX}
, {UINT16_MAX, 2, 0, 5,UINT16_MAX}
, {UINT16_MAX, 3, UINT16_MAX, 0, UINT16_MAX}
, {UINT16_MAX, UINT16_MAX, UINT16_MAX, 1, 0} };

std::vector<int> Dijkstra(int _Start) //Start로부터 모든 노드로 향하는 최소비용을 구하는 것이기 때문에 인자로 Start만 받아도됨
{
	std::vector<int> Dist(Cost[_Start]); //Dist[a] = _Start에서 a로 향하는 최소비용, 초기화는 Cost[시작점]으로
	Graph[_Start].IsVisit = true; //방문처리

	for (int i = 0; i < Dist.size() - 1; i++)
	{
		int MinIndex = 0; //가장 작은 비용을 가진 인덱스 탐색
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

		//2. MinIndex방문
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
} //O(V^2) N-1번 돌면서 N번 탐색 -> 비효율적


//시간복잡도를 줄이기 위해 우선순위큐를 이용한 다익스트라 알고리즘

//연결 노드를 저장
std::vector<std::set<std::pair<int, int>>> LinkNodes; //LinkNodes[a] = a랑 연결된 노드들의 정보들 first->비용, second->연결노드
//pair의 비교 연산자때문에 first(비용) 오름차순 정렬된다(비용이 같으면 인덱스 오름차순)

std::vector<int> DijkstraPQ(int _Start)
{
	std::vector<int> Dist; //Dist[a] = _Start에서 a로 가는 최소 비용
	Dist.resize(Graph.size(), INT32_MAX); //모두 int_max로 초기화
	Dist[_Start] = 0; //시작지점의 비용은 0이죠 당연히

	std::priority_queue<std::pair<int, int>> pq; //링크노드 형태인 <비용, 인덱스>를 우선순위 큐에 저장
	pq.push({ -Dist[_Start] , _Start });//<비용 , 위치>로 넣는데, pq는 내림차순 정렬이기때문에 비용의 오름차순 정렬로 바꾸기 위해서
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
				pq.push({ -Dist[LinkNode.second], LinkNode.second });//시작할때한거랑 같죵? <-비용 , 위치>푸시
			}
		}
	}

	return Dist;
} //우선순위 큐를 활용하여 시간복잡도 효율을 올림

//플로이드 와샬 알고리즘(Floyd_Warshall)
//All To All, 최소 비용

std::vector<std::vector<int>> Floyd_Warshall()
{
	std::vector<std::vector<int>> Dist = Cost;//Dist[a][b] -> A에서B로 가는 최소비용

	size_t N = Dist.size();
	
	//k는 거쳐가는 노드, i는 시작노드, j는 도착노드
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

//위상 정렬(Topology sort)
//사이클이 발생하지 않는 그래프에서 사용

//얻을 수 있는것
//1. 사이클이 발생 여부
//2. 위상정렬 결과

//필요 정보
//1. 노드의 진입 차수(해당 노드로 올 수 있는 진입 경로의 수)
//2. 링크 노드 정보

//0~6이라고 합시다
std::vector<int> InDgree = {0, 1, 1, 1, 1, 2, 1}; //진입차수
std::vector<std::set<int>> TopologyLinkNodes; //연결 노드

bool TopologySort(std::vector<int>& _result)
{
	std::vector<int>& result = _result;

	std::queue<int> q; //큐를 만들고
	
	for (size_t i = 0; i < InDgree.size(); i++)
	{
		if (InDgree[i] == 0) //진입차수가 0인 애들을 q에 넣어
		{
			q.push(i);
		}
	}
	
	for (size_t i = 0; i < InDgree.size(); i++)
	{
		if (q.empty()) //반복문이 끝나기 전에 q가 비었다면
		{
			return false; //위상정렬 실패 (사이클이 존재)
		}

		int CheckIndex = q.front(); //프론트를 체크
		q.pop(); // 팝하고
		result.push_back(CheckIndex); //결과에 정렬값 넣기

		for (auto& LinkNode : TopologyLinkNodes[CheckIndex]) //체크노드의 연결노드 돌면서
		{
			if (--InDgree[LinkNode] == 0) //노드 연결 끊고(정확히는 진입차수를 깎고)
			{
				q.push(LinkNode); //진입차수가 0인 애들 q에 넣기
			}
		}
	}

	return true;
}

std::vector<std::set<int>> CaseLinkNodes = { {1,2,3}, {0,2,3}, {0,1,3}, {0,1,2} };
std::vector<bool> CaseIsVisit = { false, false, false, false };
std::vector<int> CasePrintStack;

void DFS_Combination(int _Start, int _r) // 순열
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

void DFS_Permutation(int _Start, int _r) // 순열
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