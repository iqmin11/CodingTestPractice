//https://school.programmers.co.kr/learn/courses/30/lessons/77885

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers)
{
    std::vector<long long> answer;
    answer.resize(numbers.size());

    //로직 자체는 간단함. 작은 자릿수 비트부터 체크하면서 0을 만나면 해당 비트와 하나 전 비트를 10으로 바꾸는것
    //문제는 그 연산이 왜 그렇게되는가를 이해하는것

    for (size_t i = 0; i < numbers.size(); i++)
    {
        long long Num = numbers[i];
        long long Index = 0;
        while (true)
        {
            if ((Num >> Index) & 1) // 해당자릿수 비트가 1이면 1, 0이면 0을 리턴해주는 연산
            {
                ++Index;
                continue;
            }

            //long long으로 64bit연산을 하기 떄문에 1LL로 상수의 자료형을 명시해줄 필요가 있었음. 안그러면 의도치 않은 연산이 일어남
            Num |= (1LL << Index); //해당 자릿수 비트를 1로 바꿔주는 연산
            Num &= ~(1LL << (Index - 1)); //해당 자릿수 비트르 0으로 바꿔주는 연산 (오버플로우가 나면 걍 상관 없는건가??? 예외처리를 해야될 것 같기도 함)
            break;
        }

        answer[i] = Num;
    }
    
    return answer;
}

int main()
{
    solution({ 1000000000000000 });

    return 0;
}