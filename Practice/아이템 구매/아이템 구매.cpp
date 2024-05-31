//문제 주소 : https://www.biko.kr/problem/1692

#include <iostream>

int main()
{
    int P, Q, W;
    std::cin >> P >> Q >> W;

    bool IsSwap = false;
    if (P < Q)
    {
        IsSwap = true;
        std::swap(P, Q);
    }

    int MaxCountP = W / P;
    std::pair<int, int> Answer;

    for (int i = 0; i <= MaxCountP; ++i)
    {
        //P를 0개 1개 .. MAX개 사보는거임
        int RestMoney = W - P * i;
        int Q_Mod = RestMoney % Q;
        if (Q_Mod == 0)
        {
            if (IsSwap)
            {
                Answer.first = RestMoney / Q;
                Answer.second = i;
            }
            else
            {
                Answer.first = i;
                Answer.second = RestMoney / Q;
            }
            break;
        }
    }

    std::cout << Answer.first << " " << Answer.second << std::endl;
    return 0;
}