#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool CompGreater(const std::string& Left, const std::string& Right)
{
    if (Left.size() != Right.size())
        return Left.size() > Right.size();
    return Left > Right;
}

const std::string& MyMax(const std::string& Left, const std::string& Right)
{
    return CompGreater(Left, Right) ? Left : Right;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, Money;
    std::cin >> N;

    std::vector<int> NumPrice(N);
    for (int i = 0; i < N; i++)
        std::cin >> NumPrice[i];

    std::cin >> Money;

    std::vector<std::string> DP(Money + 1, "");

    for (int m = 0; m <= Money; m++)
    {
        for (int i = 0; i < N; i++)
        {
            if (NumPrice[i] <= m)
            {
                std::string candidate = DP[m - NumPrice[i]] + std::to_string(i);
                if (candidate[0] != '0') // 숫자가 0으로 시작하지 않도록 체크
                    DP[m] = MyMax(DP[m], candidate);
            }
        }
    }

    if (!DP[Money].empty())
        std::cout << DP[Money] << "\n";
    else
        std::cout << "0\n";

    return 0;
}