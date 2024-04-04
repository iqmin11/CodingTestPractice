//https://school.programmers.co.kr/learn/courses/30/lessons/12900

#include <string>
#include <vector>

using namespace std;

int DP[60001] = { 0, };

int solution(int n)
{
    DP[1] = 1;
    DP[2] = 2;

    for (int i = 3; i <= n; ++i)
    {
        DP[i] = (DP[i - 1] + DP[i - 2]) % 1000000007;
    }

    return DP[n];
}