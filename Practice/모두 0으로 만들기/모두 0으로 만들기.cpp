//���� �ּ� : https://school.programmers.co.kr/learn/courses/30/lessons/76503

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

//������� ���� 0���� ���������, ��Ʈ ��尡 0�̸� �˴ϴ�

std::vector<bool> IsVisit;
std::vector<std::set<int>> LinkedNodes;
std::vector<long long> CurWeightData;

long long Count = 0;

long long DFS(int CurNode)
{
    IsVisit[CurNode] = true;

    for (auto& LinkNode : LinkedNodes[CurNode])
    {
        if (IsVisit[LinkNode])
        {
            continue;
        }

        CurWeightData[CurNode] += DFS(LinkNode);
    }

    //���� ��ȸ, ���� ��� ���� 0���� �����
    long long Result = CurWeightData[CurNode];
    CurWeightData[CurNode] = 0;
    Count += std::abs(Result);

    //��Ʈ��尡 ��ȯ�ؾ��� ���� 0
    return Result;
}

long long solution(vector<int> a, vector<vector<int>> edges)
{
    IsVisit.resize(a.size(), false);
    LinkedNodes.resize(a.size(), std::set<int>());

    for (int i = 0; i < edges.size(); i++)
    {
        LinkedNodes[edges[i][0]].insert(edges[i][1]);
        LinkedNodes[edges[i][1]].insert(edges[i][0]);
    }

    CurWeightData.resize(a.size());
    for (int i = 0; i < a.size(); i++)
    {
        CurWeightData[i] = static_cast<long long>(a[i]);
    }

    int Result = DFS(0);
    if (Result == 0)
    {
        return Count;
        //ī��Ʈ�� ��ȯ
    }

    return -1;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

    solution({ -5, 0, 2, 1, 2 }, { {0, 1}, {3, 4}, {2, 3}, {0, 3} });

	return 0;
}