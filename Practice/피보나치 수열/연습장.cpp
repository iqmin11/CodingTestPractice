#include <iostream>
#include <typeinfo>
#include <queue>
#include <set>
#include <cmath>
#include <vector>

class Base
{
public:
    Base()
    {
        std::cout << "BaseConstructor" << std::endl;
    }
    
    virtual ~Base() {};

    virtual void Func()
    {
        std::cout << "BaseFunc" << std::endl;
        return;
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        std::cout << "DerivedConstructor" << std::endl;
    }

    ~Derived() override {};

    void Func() override
    {
        std::cout << "DerivedFunc" << std::endl;
        return;
    }

};

class A
{
    A(const char* str)
    {
        m_size = strlen(str) + 1;
        strcpy(m_str, str);
    }

    size_t m_size;
    char* m_str;
};

int main() 
{

    Base* basePtr = new Derived();
    Derived* DownCasts = dynamic_cast<Derived*>(basePtr);

    //basePtr->Func();
    //delete basePtr;

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
    
    return 0;
}
