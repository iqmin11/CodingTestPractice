#include <iostream>
#include <typeinfo>

class Base {};
class Derived : public Base {};

int main() 
{
    Base* basePtr = new Derived();

    // typeid �����ڸ� ����Ͽ� ��ü�� ������ ����
    const std::type_info& typeInfo = typeid(*basePtr);
    if (typeInfo == typeid(Base)) 
    {
        std::cout << "Object is of type Base." << std::endl;
    }
    else if (typeInfo == typeid(Derived)) 
    {
        std::cout << "Object is of type Derived." << std::endl;
    }

    delete basePtr;
    return 0;
}
