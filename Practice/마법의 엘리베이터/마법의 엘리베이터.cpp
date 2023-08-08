#include <string>
#include <vector>

using namespace std;

std::vector<int> TransVec(int _storey)
{
    std::vector<int> result;
    std::string storey_str = std::to_string(_storey);
    int len = storey_str.length();
    result.resize(len);
    for (int i = 0; i < result.size(); i++)
    {
        char temp = storey_str[i];
        result[i] = std::atoi(&temp);
    }
    return result;
}

int MagicStoneCount(std::vector<int> _storeyVec)
{
    auto StartIter = _storeyVec.rbegin();
    auto EndIter = _storeyVec.rend();
    auto NextIter = StartIter;
    int result = 0;

    for (; StartIter != EndIter; StartIter++)
    {
        NextIter++;
        if (*StartIter > 5)
        {
            result += 10 - *StartIter;
            if (NextIter != EndIter)
            {
                *NextIter += 1;
            }
            else
            {
                result += 1;
            }
        }
        else if (*StartIter == 5)
        {
            if (NextIter != EndIter)
            {
                if (*NextIter >= 5) 
                {
                    result += 10 - *StartIter;
                    *NextIter += 1;
                }
                else
                {
                    result += *StartIter;
                }
            }
            else
            {
                result += *StartIter;
            }
        }
        else
        {
            result += *StartIter;
        }
    }

    return result;
}

int solution(int storey)
{
    int answer = 0;

    answer  = MagicStoneCount(TransVec(storey));

    return answer;
}

//1111 4
//2222 8
//3333 12
//4444 16
//5555 20
//6666 4333
//7777
//8888
//9999

int main()
{
    int a = 16;
    //655
    //5+4+3+1 = 13
    //14
    solution(a);
}

