//문제 주소 : https://www.biko.kr/problem/1695

#include <iostream>

int main()
{
    double N;

    std::cin >> N;

    double SumOfX = 0;
    double SumOfY = 0;

    for (int i = 0; i < N; i++)
    {
        double tempX, tempY;
        std::cin >> tempX >> tempY;
        SumOfX += tempX;
        SumOfY += tempY;
    }

    double AnswerX = SumOfX / N;
    double AnswerY = SumOfY / N;

    std::cout << std::fixed;
    std::cout.precision(4);
    std::cout << AnswerX << " " << AnswerY << std::endl;
    return 0;
}