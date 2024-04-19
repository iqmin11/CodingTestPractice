//https://school.programmers.co.kr/learn/courses/30/lessons/42747

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations)
{
    std::sort(citations.begin(), citations.end(), std::greater<int>());

    int MaxHIndex = 0;

    for (int i = 0; i < citations.size(); ++i)
    {
        MaxHIndex = std::max(MaxHIndex, std::min(citations[i], i + 1));
    }

    return MaxHIndex;
}