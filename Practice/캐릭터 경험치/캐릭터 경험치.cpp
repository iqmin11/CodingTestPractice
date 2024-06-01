//문제 주소 : https://www.biko.kr/problem/1699

#include <iostream>
#include <vector>
#include <list>

int N, E;
std::pair<int, std::vector<int>> DP[1001][10001] = {};

int main()
{
    std::cin >> E >> N;

    std::vector<std::pair<int, int>> Load;

    Load.resize(N + 1);

    for (int i = 1; i <= N; i++)
    {
        std::cin >> Load[i].first >> Load[i].second;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int w = 1; w <= E; w++)
        {
            if (Load[i].first > w)
            {
                DP[i][w].first = DP[i - 1][w].first;
                DP[i][w].second = DP[i - 1][w].second;
            }
            else
            {
                if (DP[i - 1][w].first > DP[i - 1][w - Load[i].first].first + Load[i].second)
                {
                    DP[i][w].first = DP[i - 1][w].first;
                    DP[i][w].second = DP[i - 1][w].second;
                }
                else
                {
                    DP[i][w].first = DP[i - 1][w - Load[i].first].first + Load[i].second;
                    DP[i][w].second = DP[i - 1][w - Load[i].first].second;
                    DP[i][w].second.push_back(i);
                }
            }
        }
    }

    std::cout << DP[N][E].first << std::endl;
    std::cout << DP[N][E].second.size() << std::endl;
    for (auto i : DP[N][E].second)
    {
        std::cout << i << " ";
    }


    return 0;
}