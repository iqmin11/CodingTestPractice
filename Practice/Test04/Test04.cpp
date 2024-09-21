//���� �ּ� : 

#include <iostream>
#include <vector>
#include <queue>

bool IsIncluded(const std::string& IsThereThisWord, const std::string& InThisWord)
{
    return InThisWord.find(IsThereThisWord) != std::string::npos;
    //�̰�... KMP�� �غ���.. �������͵��غ��� �ߴµ� �� �ȵƴ�.
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

        //�̹� ���ԵǾ��ִ�?
        bool ContainChecker = false;

        //�ܾ� ��ü �ߴ�? (����ȭ)
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