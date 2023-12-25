#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

int IsAllGem = 0;

vector<int> solution(vector<string> gems)
{
    std::set<std::string> type;
    int N = gems.size();

    for (int i = 0; i < N; i++)
    {
        type.insert(gems[i]);
    }

    int TypeCount = type.size();

    int right = 0;
    int Minlength = INT32_MAX;
    std::unordered_map<std::string, int> PartSum;
    int AllSum = 0;
    vector<int> answer;
    answer.resize(2);
    answer[0] = 0;
    answer[1] = 0;

    for (auto& i : type)
    {
        PartSum.insert(std::make_pair(i, 0));
    }

    for (int left = 0; left < N; left++)
    {
        while (right < N && IsAllGem != TypeCount)
        {
            int& RCount = PartSum.find(gems[right])->second;
            RCount++;

            if (RCount == 1)
            {
                IsAllGem++;
            }

            right++;
            AllSum++;
        }

        if (IsAllGem == TypeCount)
        {
            if (Minlength > AllSum)
            {
                Minlength = AllSum;
                answer[0] = left + 1;
                answer[1] = right;
            }
        }

        int& LCount = PartSum.find(gems[left])->second;
        LCount--;
        AllSum--;

        if (LCount == 0)
        {
            IsAllGem--;
        }
    }

    return answer;
}

int main()
{

    std::vector<int> result = solution({ "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" });

    return 0;
}
