//문제 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/12938

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s)
{
    if (n > s)
    {
        return { -1 };
    }

    int Quo = s / n;
    int Mod = s % n;

    vector<int> answer;
    answer.resize(n);

    for (int i = 0; i < n; i++)
    {
        answer[i] = Quo;
        if (Mod-- > 0)
        {
            ++answer[i];
        }
    }

    std::sort(answer.begin(), answer.end());

    return answer;
}