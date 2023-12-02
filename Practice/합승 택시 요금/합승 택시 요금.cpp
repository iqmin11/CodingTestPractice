#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

//std::vector<bool> IsVisit;
//std::vector<std::map<int, int>> Links;
//std::vector<int> Stack;
//
//void DFS(int _Start, int _End, int& _minCost)
//{
//    IsVisit[_Start] = true;
//    Stack.push_back(_Start);
//
//    if (_Start == _End)
//    {
//        int CurCost = 0;
//        for (size_t i = 0; i < Stack.size()-1; i++)
//        {
//            CurCost += Links[Stack[i]][Stack[i + 1]];
//        }
//
//        _minCost = std::min(CurCost, _minCost);
//    }
//
//    for (auto& i : Links[_Start])
//    {
//        if (!IsVisit[i.first])
//        {
//            DFS(i.first, _End, _minCost);
//            IsVisit[i.first] = false;
//        }
//    }
//    Stack.pop_back();
//}
//
//int solutionDFS(int n, int s, int a, int b, vector<vector<int>> fares)
//{
//    Links.resize(n);
//    IsVisit.resize(n, false);
//
//    for (int i = 0; i < fares.size(); i++)
//    {
//        Links[fares[i][0]-1].insert(std::make_pair(fares[i][1]-1, fares[i][2]));
//        Links[fares[i][1]-1].insert(std::make_pair(fares[i][0]-1, fares[i][2]));
//    }
//
//    int answer = INT32_MAX;
//
//    for (size_t i = 0; i < n; i++)
//    {
//        int StoI = INT32_MAX;
//        int ItoA = INT32_MAX;
//        int ItoB = INT32_MAX;
//
//        DFS(s - 1, i, StoI);
//        for (auto i : IsVisit)
//        {
//            i = false;
//        }
//        DFS(i, a - 1, ItoA);
//        for (auto i : IsVisit)
//        {
//            i = false;
//        }
//        DFS(i, b - 1, ItoB);
//        for (auto i : IsVisit)
//        {
//            i = false;
//        }
//
//        answer = std::min(answer, StoI + ItoA + ItoB);
//    }
//    
//    return answer;
//}

//////////////////////////////////////////////////////////////////////////////////////////
std::vector<std::vector<std::pair<int, int>>> Links;

std::vector<int> Dijkstra(int _Start, int _n)
{
    std::vector<int> dist;
    dist.resize(_n, INT32_MAX);
    dist[_Start] = 0;

    std::priority_queue<std::pair<int, int>> pq;

    pq.push({ dist[_Start] , _Start});

    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (dist[here] < cost)
        {
            continue;
        }

        for (auto& i : Links[here])
        {
            int via_cost = cost + i.first;
            if (via_cost < dist[i.second])
            {
                dist[i.second] = via_cost;
                pq.push({ -dist[i.second], i.second });
            }
        }
    }

    return dist;
}

int solutionDijkstra(int n, int s, int a, int b, vector<vector<int>> fares)
{
    Links.resize(n);

    for (int i = 0; i < fares.size(); i++)
    {
        Links[fares[i][0]-1].emplace_back(std::make_pair(fares[i][2], fares[i][1] - 1));
        Links[fares[i][1]-1].emplace_back(std::make_pair(fares[i][2], fares[i][0] - 1));
    }

    //Mincost[a][b] = a에서 b로 가는 최소 코스트
    std::vector<std::vector<int>> Mincost;
    Mincost.resize(n);
    for (size_t i = 0; i < Mincost.size(); i++)
    {
        Mincost[i] = Dijkstra(i, n);
    }

    int answer = INT32_MAX;
    //Mincost[s-1][i] + Mincost[i][a-1] + Mincost[i][b-1]의 최소값
    for (size_t i = 0; i < n; i++)
    {
        answer = std::min(answer, Mincost[s - 1][i] + Mincost[i][a - 1] + Mincost[i][b - 1]);
    }

    return answer;
}


int solutionFW(int n, int s, int a, int b, vector<vector<int>> fares)
{
    std::vector<std::vector<int>> Dist;
    Dist.resize(n);
    for (size_t i = 0; i < Dist.size(); i++)
    {
        Dist[i].resize(n, 100001 * n);
    }

    for (size_t i = 0; i < n; i++)
    {
        for (size_t i = 0; i < n; i++)
        {
            Dist[i][i] = 0;
        }
    }

    for (size_t i = 0; i < fares.size(); i++)
    {
        Dist[fares[i][0] - 1][fares[i][1] - 1] = fares[i][2];
        Dist[fares[i][1] - 1][fares[i][0] - 1] = fares[i][2];
    }

    for (size_t k = 0; k < n; k++)
    {
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                Dist[i][j] = std::min(Dist[i][j], Dist[i][k] + Dist[k][j]);
            }
        }
    }

    int answer = INT32_MAX;
    for (size_t i = 0; i < n; i++)
    {
        answer = std::min(answer, Dist[s - 1][i] + Dist[i][a - 1] + Dist[i][b - 1]);
    }
    return answer;
}

int main()
{
    std::vector<std::vector<int>> Fa = { {4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25} };

    int a = solutionDijkstra(6,4,6,2, Fa);
    int b = solutionFW(6,4,6,2, Fa);
}