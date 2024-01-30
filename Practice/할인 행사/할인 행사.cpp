#include <string>
#include <vector>
#include <map>

using namespace std;

bool Check(const std::map<std::string, int>& _Wants)
{
    for (auto& i : _Wants)
    {
        if (i.second != 0)
        {
            return false;
        }
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    std::map<std::string, int> Wants;
    for (int i = 0; i < want.size(); ++i)
    {
        Wants.insert(std::make_pair(want[i], number[i]));
    }

    int right = 0;
    int answer = 0;
    for (int left = 0; left < discount.size() - 9; ++left)
    {
        while (right < discount.size() && !(right - left == 10))
        {
            auto FindIter = Wants.find(discount[right]);
            if (FindIter != Wants.end())
            {
                FindIter->second -= 1;
            }
            ++right;
        }

        if (Check(Wants))
        {
            ++answer;
        }

        auto FindIter = Wants.find(discount[left]);
        if (FindIter != Wants.end())
        {
            FindIter->second += 1;
        }
    }


    return answer;

}

int main()
{
    solution({ "banana", "apple", "rice", "pork", "pot" },
        { 3, 2, 2, 2, 1 },
        { "chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana" });
}