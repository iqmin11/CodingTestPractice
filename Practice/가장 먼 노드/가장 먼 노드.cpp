//문제 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/49189

#include <string>
#include <vector>
#include <queue>
#include <set>
#include <iostream>

using namespace std;

std::vector<std::set<std::pair<int, int>>> LinkNodes; //first->비용, second->연결노드

std::vector<int> Dijkstra(int _Start, int n)
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

int solution(int n, vector<vector<int>> edge)
{
    LinkNodes.resize(n);

    for (auto i : edge)
    {
        int Node1 = i[0];
        int Node2 = i[1];

        LinkNodes[Node1 - 1].insert(std::make_pair(1, Node2 - 1));
        LinkNodes[Node2 - 1].insert(std::make_pair(1, Node1 - 1));
    }

    std::vector<int> Result = Dijkstra(0, n);

    int answer = 1;
    int MaxCost = INT32_MIN;
    for (auto i : Result)
    {
        if (MaxCost < i)
        {
            answer = 1;
            MaxCost = i;
        }
        else if (MaxCost == i)
        {
            answer++;
        }
    }

    return answer;
}