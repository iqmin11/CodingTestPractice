//https://school.programmers.co.kr/learn/courses/30/lessons/42898

#include <string>
#include <vector>

using namespace std;

std::vector<std::vector<int>> DP;

int solution(int m, int n, vector<vector<int>> puddles)
{
    DP.resize(n);
    for (int i = 0; i < n; ++i)
    {
        DP[i].resize(m, 0);
    }

    for (int i = 0; i < puddles.size(); ++i)
    {
        DP[puddles[i][1] - 1][puddles[i][0] - 1] = -1;
    }

    for (int i = 0; i < m; ++i)
    {
        if (DP[0][i] == -1)
        {
            DP[0][i] = 0;
            break;
        }
        else
        {
            DP[0][i] = 1;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (DP[i][0] == -1)
        {
            DP[i][0] = 0;
            break;
        }
        else
        {
            DP[i][0] = 1;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (DP[i][j] == -1)
            {
                DP[i][j] = 0;
                continue;
            }

            if (DP[i - 1][j] == -1)
            {
                DP[i - 1][j] = 0;
            }

            if (DP[i][j - 1] == -1)
            {
                DP[i][j - 1] = 0;
            }

            DP[i][j] = (DP[i - 1][j] + DP[i][j - 1]) % 1000000007;
        }
    }

    return DP[n - 1][m - 1];
}