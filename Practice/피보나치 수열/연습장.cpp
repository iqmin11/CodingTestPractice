#include <iostream>
#include <typeinfo>
#include <queue>
#include <set>

class Base {};
class Derived : public Base {};

struct Comp
{
    bool operator()(int* _Left, int* _Right)
    {
        return *_Left < *_Right;
    }
};

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
    std::priority_queue<int*, std::vector<int*>, Comp> pq;
    int A, B, C, D, E;
    A = 1;
    B = 2;
    C = 3;
    D = 4;
    E = 1;
    pq.push(&A);
    pq.push(&B);
    pq.push(&C);
    pq.push(&D);

    A = 5;
    pq.push(&E);
    pq.pop();

    std::set<int> Hwang;
    Hwang.insert(1);
    Hwang.insert(2);
    Hwang.insert(3);
    Hwang.insert(4);
    Hwang.insert(5);
    Hwang.insert(6);
    auto SSS = Hwang.find(4);
    auto RSSS = std::make_reverse_iterator(SSS);

    for (auto& CurIter = SSS; CurIter != Hwang.end(); ++CurIter)
    {
        std::cout << *CurIter;
    }
    std::cout << std::endl;

    for (auto& CurRIter = RSSS; CurRIter != Hwang.rend(); ++CurRIter)
    {
        std::cout << *CurRIter;
    }
    std::cout << std::endl;

    //if (RSSS == Hwang.rend())
    //{
    //    int a = 0;
    //}
    return 0;
}
