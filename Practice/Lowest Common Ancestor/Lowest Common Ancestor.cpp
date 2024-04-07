//https://www.acmicpc.net/problem/11438

#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> Depth;
std::vector<std::vector<int>> Parent; // Parent[a][b] a로부터 2^b번째 위에 있는 조상 
std::vector<std::vector<int>> LinkNodes;
int Max = INT32_MIN;
int N, M;

void DFS(int _CurNode, int _Parent = -1) // DFS를 통한 그래프의 완전탐색으로, 노드간의 관계를 기록
{
	Parent[_CurNode][0] = _Parent; // 2^0번째 부모만체크

	if (_Parent == -1)
	{
		Depth[_CurNode] = 0;
	}
	else
	{
		Depth[_CurNode] = Depth[_Parent] + 1;
	}

	for (auto& NextNode : LinkNodes[_CurNode])
	{
		if (Depth[NextNode] != -1)
		{
			continue;
		}

		DFS(NextNode, _CurNode);
	}
}

void Connection() // 해당 함수를 통해 모든 노드를 돌면서 Parent 배열을 완성
{
	for (int i = 1; i < Max; i++) //Parent[0]은 이미 채워져있기 때문에 1부터
	{
		for (int Node = 1; Node <= N; Node++) //RootNode는 1, Node0은 사실상 유효하지 않은 노드기 때문에 1부터 N까지
		{
			if (Parent[Node][i - 1] == -1)
			{
				continue;
			}
			Parent[Node][i] = Parent[Parent[Node][i - 1]][i - 1];
		}
	}
}

int LCA(int Node1, int Node2) //깊이 체크를 통한 공통 부모 찾기
{
	if (Depth[Node1] < Depth[Node2])
	{
		std::swap(Node1, Node2);
	}

	int Differ = Depth[Node1] - Depth[Node2];

	for (int i = 0; Differ != 0; i++)
	{
		if (Differ & 1) //비트연산을 통한 홀수체크, 홀수라면
		{
			Node1 = Parent[Node1][i]; //깊이가 깊은 노드의 2^i번째 부모로 올라감
		}
		Differ >>= 1; //깊이의 차이는 나누기 2를 통해서 갱신
	}

	//같은 깊이의 상태
	if (Node1 != Node2) //노드가 다르면
	{
		for (int i = Max - 1; i >= 0; --i) //더 상위 부모부터 체크
		{
			if (Parent[Node1][i] != -1 && Parent[Node1][i] != Parent[Node2][i])
			{
				Node1 = Parent[Node1][i];
				Node2 = Parent[Node2][i];
			}
		}

		Node1 = Parent[Node1][0];
	}

	return Node1; 
}

int main()
{
	std::cin >> N;
	Max = static_cast<int>(std::ceil(std::log2(N))); //모든 노드가 일렬로 위치해있다고 가정했을시, 한 노드가 가져야 할 최대 부모 배열의 크기

	Depth.resize(N + 1, -1); // 노드의 이름을 그대로 쓰기위해 N+1을 해줬다는것을 항상 기억
	Parent.resize(N + 1);
	for (int i = 0; i < N + 1; i++)
	{
		Parent[i].resize(Max, -1);
	}
	LinkNodes.resize(N + 1);

	for (int i = 0; i < N - 1; i++)
	{
		int Node1, Node2;

		std::cin >> Node1 >> Node2;

		LinkNodes[Node1].push_back(Node2);
		LinkNodes[Node2].push_back(Node1);
	}

	DFS(1); //1번 노드부터 0번 노드는 더미노드
	Connection();

	std::cin >> M;
	std::vector<int> CommonParent;
	CommonParent.reserve(M);
	for (int i = 0; i < M; i++)
	{
		int Node1;
		int Node2;

		std::cin >> Node1 >> Node2;
		CommonParent.push_back(LCA(Node1, Node2));
	}

	for (auto i : CommonParent)
	{
		std::cout << i << '\n';
	}
}