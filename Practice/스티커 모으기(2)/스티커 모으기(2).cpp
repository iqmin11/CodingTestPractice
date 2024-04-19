//https://school.programmers.co.kr/learn/courses/30/lessons/12971

#include <iostream>
#include <vector>
using namespace std;

int DP[2][100001] = { {0,},{0,} }; // DP[n] -> n번째 스티커를 뜯었을 때의 최댓값
//DP[n] = std::max(DP[n - 2] + sticker[n], DP[n - 1]);

int solution(vector<int> sticker)
{
    int answer = sticker[0];
    int N = static_cast<int>(sticker.size());

    DP[0][1] = sticker[0];

    for (int i = 2; i < N; ++i)
    {
        DP[0][i] = std::max(DP[0][i - 2] + sticker[i - 1], DP[0][i - 1]);
    }

    answer = std::max(DP[0][N - 1], answer);

    DP[1][1] = 0;

    for (int i = 2; i <= N; ++i)
    {
        DP[1][i] = std::max(DP[1][i - 2] + sticker[i - 1], DP[1][i - 1]);
    }

    answer = std::max(answer, DP[1][N]);

    return answer;
}