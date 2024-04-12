//https://school.programmers.co.kr/learn/courses/30/lessons/43238

#include <string>
#include <vector>

using namespace std;

long long ConditionCheck(const vector<int>& times, int mid)
{
    long long Answer = 0;
    for (auto& i : times)
    {
        Answer += mid / i;
    }

    return Answer;
}

long long solution(int n, vector<int> times)
{
    //시간 기준
    long long left = 1;
    long long right = 1e18;
    long long answer = INT64_MAX;

    while (left <= right)
    {
        long long mid = (right + left) / 2;
        long long Check = ConditionCheck(times, mid);

        if (Check < n)
        {
            left = mid + 1;
            //시간을 더 많이
        }
        else if (Check >= n)
        {
            answer = std::min(mid, answer);
            right = mid - 1;
            //시간을 더 적게
        }
    }

    return answer;
}

int main()
{
    solution(6, {7,10});
}