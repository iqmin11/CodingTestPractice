#include <iostream>
#include <string>
#include <algorithm>

int Reverse(int Value)
{
    std::string StrNum = std::to_string(Value);
    std::reverse(StrNum.begin(), StrNum.end());
    int Result = std::stoi(StrNum);
    return Result;
}


int main()
{
    std::cout << Reverse(12975837) << std::endl;
    return 0;
}