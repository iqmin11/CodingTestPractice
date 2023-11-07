#include <iostream>
#include <vector>
#include <set>
#include <queue>

struct Node // 그래프 노드는 이런식이 좋은것 같은데
{
	std::set<int> LinkNodes = std::set<int>(); // 중복이 안들어오도록 한 노드 구조, 자동으로 오름차순 정렬도 됨
	bool IsVisit = false; // 방문 여부
};

std::vector<Node> G = std::vector<Node>();

void DFS(int _StartIndex) // 함수에서 알아야되는건 시작지점과 그래프
{
	int CurIndex = _StartIndex; // 초기화 (현재인덱스는 StartIndex)

	if (!G[CurIndex].IsVisit) // 현재 탐색하는 인덱스에 방문한 적이 없다면
	{
		G[CurIndex].IsVisit = true; // 방문했다고 바꾸고
		std::cout << CurIndex + 1 << " ";

		for (auto& i : G[CurIndex].LinkNodes) // 연결된 노드를 돌면서
		{
			DFS(i); // 현재 탐색 노드를 StartIndex로한 DFS
		}
	}
}

void BFS(int _StartIndex)
{
	std::queue<int> Q = std::queue<int>(); //큐를 생성
	
	//초항(while문에서는 필수)
	Q.push(_StartIndex); 
	G[Q.front()].IsVisit = true;

	while (!Q.empty())
	{
		for (auto& LinkNode : G[Q.front()].LinkNodes) //걔네들의 연결 노드를 돌면서 집어넣기
		{
			if (!G[LinkNode].IsVisit) //만약 방문한적이 없으면
			{
				Q.push(LinkNode); //현재 탐색하고있는 링크 노드를 q에 푸시
				G[LinkNode].IsVisit = true; //방문했다고 바꿔주고
			}
		}
		std::cout << Q.front() + 1 << " ";
		Q.pop(); 
	}
}

//복잡하지만 좀 빠른 버전 1.5배 빨랐음
//void BFS(int _StartIndex)
//{
//	std::queue<int> Q = std::queue<int>(); //큐를 생성
//
//	int PopSize = 0; //팝할 사이즈 저장
//	int PushSize = 0; //푸쉬한 사이즈 저장
//
//	//초항(while문에서는 필수)
//	Q.push(_StartIndex);
//	PushSize++;
//	G[Q.front()].IsVisit = true;
//
//	while (!Q.empty())
//	{
//		PopSize = PushSize; //이전단계에서 푸쉬한애는 이번에 팝해야함
//		PushSize = 0; //초기화
//
//		for (size_t i = 0; i < PopSize; i++) //팝할녀석들(이전에 푸쉬한 녀석들) 돌면서
//		{
//			for (auto& LinkNode : G[Q.front()].LinkNodes) //걔네들의 연결 노드를 돌면서 집어넣기
//			{
//				if (!G[LinkNode].IsVisit) //만약 방문한적이 없으면
//				{
//					Q.push(LinkNode); //현재 탐색하고있는 링크 노드를 q에 푸시
//					G[LinkNode].IsVisit = true; //방문했다고 바꿔주고
//					PushSize++;
//				}
//			}
//			std::cout << Q.front() + 1 << " ";
//			Q.pop(); //이전에 푸쉬한녀석들 팝하기
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
	for (size_t i = 0; i < G.size(); i++) // 초기화
	{
		G[i].IsVisit = false;
	}
	std::cout << std::endl;
	BFS(V - 1);

	return 0;
}