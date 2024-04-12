//https://school.programmers.co.kr/learn/courses/30/lessons/12923

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(long long begin, long long end)
{
    //자기 자신을 제외한 가장 큰 약수, 짝수는  나누기 2한 수
    //홀수는?
    vector<int> Indexs;
    Indexs.resize(end - begin + 1);
    for (int i = 0; begin != end + 1; ++begin)
    {
        Indexs[i++] = begin;
    }


    for (auto& i : Indexs)
    {
        int result = 1;
        if (i == 1)
        {
            i = 0;
            continue;
        }
        int sq = static_cast<int>(std::sqrt(i));
        for (int j = 2; j <= sq; ++j)
        {
            if (i % j == 0)
            {
                result = j;
                if (i / j <= 10000000)
                {
                    result = i / j;
                    break;
                }
            }
        }

        i = result;
    }

    return Indexs;
}