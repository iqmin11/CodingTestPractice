#include <iostream>
#include <string>

class Base
{
public:
    
    operator int()
    {
        std::cout << "intOper" << std::endl;
        return 10;
    }

    virtual void Func()
    {
        std::cout << "Base" << std::endl;
    }

    int Value;
};

class Derived : public Base
{
public:
    void Func() override
    {
        std::cout << "Derived" << std::endl;
    }
};

void F(Base _AAA)
{
    std::cout << _AAA.Value << std::endl;
}

int main()
{
    Base testmp();
    Derived temp;
    F(temp);
    

    //int a = Func1();
    

    return 0;
}