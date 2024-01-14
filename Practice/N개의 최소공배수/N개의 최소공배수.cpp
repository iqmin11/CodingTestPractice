#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> arr)
{
    //2,3,5,7,11,13
    std::map<int, int> Test;
    Test.insert(std::make_pair(2, 0));
    Test.insert(std::make_pair(3, 0));
    Test.insert(std::make_pair(5, 0));
    Test.insert(std::make_pair(7, 0));
    Test.insert(std::make_pair(11, 0));
    Test.insert(std::make_pair(13, 0));

    for (int i = 0; i < arr.size(); ++i)
    {
        for (auto& j : Test)
        {
            int Count = 0;
            while (arr[i] % j.first == 0)
            {
                Count++;
                arr[i] /= j.first;
            }
            j.second = std::max(j.second, Count);
        }
    }

    int answer = 1;

    for (auto& i : Test)
    {
        while (i.second-- != 0)
        {
            answer *= i.first;
        }
    }

    return answer;
}

int main()
{
    solution({ 4,4 });
}