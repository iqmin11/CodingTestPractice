//문제 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/42895

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

std::map<int, std::set<int>> DP; // DP[a] = 숫자 N a개로 표현 가능한 숫자들의 모음

int solution(int N, int number)
{
    if (N == number)
    {
        return 1;
    }
    
    DP.insert(std::make_pair(1, std::set<int>()));
    DP[1].insert(N);

    int i = 2;
    while (i <= 8)
    {
        std::string NumStr;
        NumStr.resize(i);

        for (auto& l : NumStr)
        {
            l = N + '0';
        }

        int NoOper = std::stoi(NumStr);
        DP[i].insert(NoOper);

        if (NoOper == number)
        {
            return i;
        }
        
        //DP[i] = DP[i - n] 사칙연산 DP[n]
        for (int n = 1; n < i / 2 + 2; n++)
        {
            for (auto k : DP[i - n])
            {
                for (auto j : DP[n])
                {
                    int Add = k + j;
                    int Sub = k - j;
                    int Mul = k * j;
                    int Div = 0;
                    if (j != 0)
                    {
                        Div = k / j;
                    }

                    if (Add == number
                        || Sub == number
                        || Mul == number
                        || Div == number)
                    {
                        return i;
                    }

                    DP[i].insert(Add);
                    DP[i].insert(Sub);
                    DP[i].insert(Mul);
                    DP[i].insert(Div);
                }
            }
        }

        i++;
    }

    return -1;
}


int main()
{
    std::cout << solution(5, 12);
	return 0;
}