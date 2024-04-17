//https://school.programmers.co.kr/learn/courses/30/lessons/12913

#include <iostream>
#include <vector>
using namespace std;

int DP[100001][4];

int solution(vector<vector<int>> land)
{
    int Answer = 0;
    for (int i = 1; i <= land[0].size(); ++i)
    {
        DP[1][i] = land[0][i - 1];
    }

    for (int y = 2; y <= land.size(); ++y)
    {
        for (int x = 1; x <= 4; ++x)
        {
            for (int k = 1; k <= 4; ++k)
            {
                if (x == k)
                {
                    continue;
                }

                DP[y][x] = std::max(DP[y - 1][k], DP[y][x]);
            }

            DP[y][x] += land[y - 1][x - 1];
            Answer = std::max(Answer, DP[y][x]);
        }
    }

    return Answer;
}