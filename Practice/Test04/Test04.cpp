//문제 주소 : 

#include <iostream>
#include <vector>
#include <queue>

bool IsIncluded(const std::string& IsThereThisWord, const std::string& InThisWord)
{
    return InThisWord.find(IsThereThisWord) != std::string::npos;
    //이걸... KMP도 해보고.. 투포인터도해보고 했는데 잘 안됐다.
}

int main()
{
    int N = 12;
    std::vector<std::string> BadWords 
        = {"abc", "a", "abcd", "abcde", "sdkfkkoxcc", "dkfuds", "kdgugs", "dkfdu", "dsf", "dkjfgusdgg", "dkdkfdufd", "kkoxcc"};

    std::queue<std::string> BadWordsQ;
    for (int i = 0; i < N; i++)
    {
        BadWordsQ.push(BadWords[i]);
    }

    std::vector<std::string> Comps;

    while (!BadWordsQ.empty())
    {
        std::string CurCheckStr = std::move(BadWordsQ.front());
        BadWordsQ.pop();

        //이미 포함되어있니?
        bool ContainChecker = false;

        //단어 교체 했니? (최적화)
        bool IsChange = false;

        for (int i = 0; i < Comps.size(); i++)
        {
            if (CurCheckStr.size() >= Comps[i].size())
            {
                if (IsIncluded(Comps[i], CurCheckStr))
                {
                    ContainChecker = true;
                    break;
                }
            }
            else
            {
                if (IsIncluded(CurCheckStr, Comps[i]))
                {
                    Comps[i] = CurCheckStr;
                    IsChange = true;
                    break;
                }
            }
        }
        
        if (ContainChecker)
        {
            std::cout << CurCheckStr << '\n';
            continue;
        }

        if (IsChange)
        {
            continue;
        }

        Comps.push_back(CurCheckStr);
    }

    return 0;
}