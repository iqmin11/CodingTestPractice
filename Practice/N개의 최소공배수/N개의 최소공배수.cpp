#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> arr)
{
    //2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97
    std::map<int, int> Test;
    Test.insert(std::make_pair(2, 0));
    Test.insert(std::make_pair(3, 0));
    Test.insert(std::make_pair(5, 0));
    Test.insert(std::make_pair(7, 0));
    Test.insert(std::make_pair(11, 0));
    Test.insert(std::make_pair(13, 0));
    Test.insert(std::make_pair(17, 0));
    Test.insert(std::make_pair(19, 0));
    Test.insert(std::make_pair(23, 0));
    Test.insert(std::make_pair(29, 0));
    Test.insert(std::make_pair(31, 0));
    Test.insert(std::make_pair(41, 0));
    Test.insert(std::make_pair(43, 0));
    Test.insert(std::make_pair(47, 0));
    Test.insert(std::make_pair(53, 0));
    Test.insert(std::make_pair(59, 0));
    Test.insert(std::make_pair(61, 0));
    Test.insert(std::make_pair(67, 0));
    Test.insert(std::make_pair(71, 0));
    Test.insert(std::make_pair(73, 0));
    Test.insert(std::make_pair(79, 0));
    Test.insert(std::make_pair(83, 0));
    Test.insert(std::make_pair(89, 0));
    Test.insert(std::make_pair(97, 0));

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