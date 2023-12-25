#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
    std::vector<int> P = people;
    std::sort(P.begin(), P.end());

    int left = 0;
    int right = P.size() - 1;
    int answer = 0;

    while (left <= right)
    {
        if (P[left] + P[right] <= limit)
        {
            left++;
        }

        right--;
        answer++;
    }
    return answer;
}

int main()
{
    int a = solution({ 70,80, 50 }, 100);


    return 0;
}