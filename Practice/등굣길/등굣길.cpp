#include <string>
#include <vector>

using namespace std;

std::vector<std::vector<int>> DP;

int solution(int m, int n, vector<vector<int>> puddles)
{
    N = n;
    M = m;

    DP.resize(n);
    for (int i = 0; i < n; ++i)
    {
        DP[i].resize(m, 1);
    }

    for (int i = 0; i < puddles.size(); ++i)
    {
        DP[puddles[i][1]][puddles[i][0]] = 0;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (DP[i][j] == 0)
            {
                continue;
            }
            DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
        }
    }

    int answer = DP[n - 1][m - 1];
    return answer;
}