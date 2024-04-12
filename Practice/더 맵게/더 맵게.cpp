//https://school.programmers.co.kr/learn/courses/30/lessons/42626

#include <string>
#include <vector>
#include <queue>

using namespace std;

std::priority_queue<int> ScovilePQ;

int solution(vector<int> scoville, int K)
{
    for (auto i : scoville)
    {
        ScovilePQ.push(-i);
    }

    int Count = 0;
    while (-ScovilePQ.top() < K)
    {
        if (ScovilePQ.size() == 1)
        {
            return -1;
        }

        ++Count;
        int Lowest = -ScovilePQ.top();
        ScovilePQ.pop();

        int SecondLowest = -ScovilePQ.top();
        ScovilePQ.pop();

        int NewFood = Lowest + (2 * SecondLowest);
        ScovilePQ.push(-NewFood);
    }

    return Count;
}