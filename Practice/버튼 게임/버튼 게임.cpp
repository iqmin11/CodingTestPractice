//문제 주소 : https://www.biko.kr/problem/1697

#include <iostream>

int main()
{
    int InitA = 1;
    int InitB = 0;

    int CurA, CurB;

    std::cin >> CurA >> CurB;

    CurA %= 99998111;
    CurB %= 99998111;

    while (true)
    {
        if (CurB == 0)
        {
            if (CurA == 1)
            {
                std::cout << "POSSIBLE";
            }
            else
            {
                std::cout << "IMPOSSIBLE";
            }

            break;
        }

        if (CurA == 0)
        {
            std::cout << "IMPOSSIBLE";
            break;
        }

        if (CurA > CurB)
        {
            CurA -= CurB;
        }
        else if (CurA < CurB)
        {
            CurB -= CurA;
        }
        else
        {
            //1, 1일때만 가능 나머지는 불가능
            if (CurA == 1 && CurB == 1)
            {
                std::cout << "POSSIBLE";
            }
            else
            {
                std::cout << "IMPOSSIBLE";
            }
            break;
        }
    }

    return 0;
}