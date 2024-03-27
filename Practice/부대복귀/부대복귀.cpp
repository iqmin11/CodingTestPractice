#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {

    std::vector<std::vector<int>> Cost;
    Cost.resize(n);
    for (int i = 0; i < n; ++i)
    {
        Cost[i].resize(n, 500001);
    }

    for (int i = 0; i < n; i++)
    {
        Cost[i][i] = 0;
    }

    for (int i = 0; i < roads.size(); ++i)
    {
        Cost[roads[i][0] - 1][roads[i][1] - 1] = 1;
        Cost[roads[i][1] - 1][roads[i][0] - 1] = 1;
    }

    std::vector<std::vector<int>> Dist = Cost;

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
    vector<int> answer;
    answer.reserve(sources.size());

    for (int i = 0; i < answer.capacity(); i++)
    {
        if (Dist[sources[i] - 1][destination - 1] == 500001)
        {
            Dist[sources[i] - 1][destination - 1] = -1;
        }
        answer.push_back(Dist[sources[i] - 1][destination - 1]);
    }

    return answer;
}