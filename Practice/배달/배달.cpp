//https://school.programmers.co.kr/learn/courses/30/lessons/12978

#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

std::vector<std::set<std::pair<int, int>>> LinkNodes;

int n;

std::vector<int> Dijkstra(int _Start)
{
    std::vector<int> Dist;
    Dist.resize(n, INT32_MAX);
    Dist[_Start] = 0;

    std::priority_queue<std::pair<int, int>> pq;
    pq.push({ -Dist[_Start] , _Start });

    while (!pq.empty())
    {
        int CurCost = -pq.top().first;
        int CurIndex = pq.top().second;

        pq.pop();

        if (Dist[CurIndex] < CurCost)
        {
            continue;
        }

        for (auto& LinkNode : LinkNodes[CurIndex])
        {
            int ViaCost = CurCost + LinkNode.first;
            if (Dist[LinkNode.second] > ViaCost)
            {
                Dist[LinkNode.second] = ViaCost;
                pq.push({ -Dist[LinkNode.second], LinkNode.second });
            }
        }
    }

    return Dist;
}

int solution(int N, vector<vector<int>> road, int K)
{
    n = N;

    LinkNodes.resize(N);

    for (auto& i : road)
    {
        int FirstNode = i[0] - 1;
        int SecondNode = i[1] - 1;
        int Cost = i[2];

        LinkNodes[FirstNode].insert(std::make_pair(Cost, SecondNode));
        LinkNodes[SecondNode].insert(std::make_pair(Cost, FirstNode));
    }

    std::vector<int> result = Dijkstra(0);

    int answer = 0;
    for (int i = 0; i < result.size(); ++i)
    {
        if (result[i] <= K)
        {
            ++answer;
        }
    }

    return answer;
}