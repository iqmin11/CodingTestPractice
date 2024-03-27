//https://school.programmers.co.kr/learn/courses/30/lessons/178870

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k)
{
    vector<int> answer;
    answer.resize(2, -1000000);
    answer[1] = 100000;

    int right = 0;
    int PartAdd = 0;
    int count = 0;

    size_t N = sequence.size();

    for (size_t left = 0; left < N; left++)
    {
        while (PartAdd < k && right < N)
        {
            PartAdd += sequence[right];
            right++;
        }

        if (PartAdd == k)
        {
            int CurCheckLenth = right - left;
            int PrevLenth = answer[1] - answer[0];

            if (CurCheckLenth <= PrevLenth)
            {
                answer[0] = left;
                answer[1] = right - 1;
            }
        }

        PartAdd -= sequence[left];
    }

    return answer;
}