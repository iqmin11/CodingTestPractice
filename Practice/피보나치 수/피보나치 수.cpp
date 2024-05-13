//문제 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/12945

#include <string>
#include <vector>

using namespace std;

int DP[100001] = { 0, };

int solution(int n)
{
    DP[0] = 0;
    DP[1] = 1;
    int M = 1234567;
    for (int i = 2; i <= n; i++)
    {
        DP[i] = (DP[i - 1] % M + DP[i - 2] % M) % M;
    }
    return DP[n];
}