#include <iostream>
#include <typeinfo>
#include <queue>

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
    return 0;
}
