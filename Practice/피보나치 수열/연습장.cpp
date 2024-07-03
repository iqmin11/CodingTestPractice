#include <iostream>

class Base
{
public:
    int a = 0;
};

class Derived : public Base
{
public:
    int b = 0;
};

int main()
{
    Base* B = new Derived();
    Derived* Test = static_cast<Derived*>(B);
    
    int a = 10;
    int* aPtr = &a;
    char* Test = reinterpret_cast<char*>(aPtr);

    return 0;
}