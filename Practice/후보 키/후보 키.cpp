#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int solution(vector<vector<string>> relation) 
{
    //목차 1개 선택 -> 중복 체크
    //목차 2개 선택 -> 조합 구성, 중복 체크
    //목차 3개 선택 -> 조합 구성, 중복 체크
    int N = relation[0].size(); //목차 개수
    int M = relation.size(); //사람 수
    std::vector<int> Select;
    Select.reserve(N);
    
    for (size_t k = 1; k <= N; k++)
    {
        Select.clear();
        for (size_t i = 0; i < k; i++)
        {
            Select.emplace_back(0);
        }

        for (size_t i = k; i < N; i++)
        {
            Select.emplace_back(1);
        }

        std::set<std::vector<std::string>> CheckDuplication;
        std::vector<std::string> TempVector;
        TempVector.reserve(8);

        do
        {
            while (M-- != 0)
            {
                for (size_t i = 0; i < N; i++)
                {
                    if (Select[i] == 0)
                    {
                        continue;
                    }
                    TempVector.emplace_back(relation[][i]);
                }

                CheckDuplication.insert(TempVector);
            }

        } while (std::next_permutation(Select.begin(), Select.end()));
    }

    int answer = 0;
    return answer;
}