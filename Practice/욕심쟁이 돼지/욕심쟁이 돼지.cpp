#include <iostream>
#include <vector>

int main()
{
    int T, N;
    std::cin >> T;

    std::vector<int> CurFood(6, 0);
    std::vector<int> NextFood(6, 0);
    long long NextFoodSum = 0;
    std::vector<int> Answer(T, 1);

    for (int k = 0; k < T; k++)
    {
        std::cin >> N;

        NextFoodSum = 0;

        for (int i = 0; i < 6; i++)
        {
            std::cin >> CurFood[i];
            NextFoodSum += CurFood[i];
        }

        while (NextFoodSum <= N)
        {
            NextFoodSum = 0;
            ++Answer[k];
            for (int i = 0; i < 6; i++)
            {
                int AcrossIndex = i + 3;
                if (AcrossIndex >= 6)
                {
                    AcrossIndex -= 6;
                }

                int LeftIndex = i - 1;
                if (LeftIndex < 0)
                {
                    LeftIndex += 6;
                }

                int RightIndex = i + 1;
                if (RightIndex >= 6)
                {
                    RightIndex -= 6;
                }

                NextFood[i] = CurFood[i] + CurFood[LeftIndex] + CurFood[AcrossIndex] + CurFood[RightIndex];
                NextFoodSum += NextFood[i];
            }

            for (int i = 0; i < 6; i++)
            {
                CurFood[i] = NextFood[i];
            }
        }
    }

    for (size_t i = 0; i < T; i++)
    {
        std::cout << Answer[i] << "\n";
    }
}