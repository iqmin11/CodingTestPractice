//https://school.programmers.co.kr/learn/courses/30/lessons/12936

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long k)
{
    vector<int> answer;
    answer.resize(n);
    for (int i = 0; i < n; ++i)
    {
        answer[i] = i + 1;
    }

    return answer;
}