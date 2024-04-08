//https://school.programmers.co.kr/learn/courses/30/lessons/140107

#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(int k, int d)
{
    long long result = 0;
    long long dd = static_cast<long long>(std::pow(d, 2));
    for (long long x = 0; x <= d; x += k)
    {
        long long xx = static_cast<long long>(std::pow(x, 2));
        long long yMax = static_cast<long long>(std::sqrt(static_cast<double>(dd - xx)));
        result += (yMax / k) + 1;
    }

    long long answer = result;
    return answer;
}