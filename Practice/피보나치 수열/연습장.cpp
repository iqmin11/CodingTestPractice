#include <iostream>
#include <typeinfo>
#include <queue>
#include <set>
#include <cmath>
#include <vector>

class Base {};
class Derived : public Base {};

struct Comp
{
    bool operator()(int* _Left, int* _Right)
    {
        return *_Left < *_Right;
    }
};

std::vector<bool> IsVisit;
std::vector<std::set<int>> LinkNodes;
std::vector<int> RecordPath;

int main() 
{
    //Base* basePtr = new Derived();

    //// typeid 연산자를 사용하여 객체의 형식을 얻음
    //const std::type_info& typeInfo = typeid(*basePtr);
    //if (typeInfo == typeid(Base)) 
    //{
    //    std::cout << "Object is of type Base." << std::endl;
    //}
    //else if (typeInfo == typeid(Derived)) 
    //{
    //    std::cout << "Object is of type Derived." << std::endl;
    //}

    //delete basePtr;
    int a = std::log10(10);

    std::vector<int> numbers = {6,10,2};
    std::sort(numbers.begin(), numbers.end(), [&](int _left, int _right)
        {
            for (int i = 0; i < numbers.size(); i++)
            {
                std::cout << numbers[i] << ",";
            }
            std::cout << std::endl;

            int LeftLog = static_cast<int>(std::log10(_left));
            int RightLog = static_cast<int>(std::log10(_right));
            int Differ = RightLog - LeftLog;

            for (int i = 0; i < Differ; ++i)
            {
                if (_left < _right)
                {
                    _left *= 10;
                }
                else
                {
                    _right *= 10;
                }
            }

            if (_left == _right)
            {
                return LeftLog > RightLog;
            }

            return _left > _right;
        });

    //if (RSSS == Hwang.rend())
    //{
    //    int a = 0;
    //}
    return 0;
}
