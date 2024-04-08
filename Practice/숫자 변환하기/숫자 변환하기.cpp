//https://school.programmers.co.kr/learn/courses/30/lessons/154538

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int DP[1000001] = { INT32_MAX, }; //DP[a] = Y를 a번 계산했을때 갈 수 

int solution(int x, int y, int n)
{
    DP[0] = y;

    for (int i = 1; i <= y; ++i)
    {
        if (DP[i - 1] % 3 == 0)
        {
            DP[i] = DP[i - 1] / 3;
        }
        else if (DP[i - 1] % 2 == 0)
        {
            DP[i] = DP[i - 1] / 2;
        }

        DP[i] = std::min(DP[i], DP[i - 1] - n);

        if (DP[i] == x)
        {
            return i;
        }
        else if (DP[i] < x)
        {
            return -1;
        }
    }

    return -1;
}