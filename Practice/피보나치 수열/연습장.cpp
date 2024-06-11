#include <iostream>

static int a = 1;

int main()
{
    int* GlobalStaticPtr = &a;
    std::cout << (__int64)(GlobalStaticPtr) << std::endl;
    //140697527173120

    int& g_a = a;

    static int a = 2; 
    int* MainLocalStaticPtr = &a;
    std::cout << (__int64)(MainLocalStaticPtr) << std::endl;
    //140697527173124

    {
        static int a = 0;
        int* InnerLocalStaticPtr = &a;
        std::cout << (__int64)(InnerLocalStaticPtr) << std::endl;
        //140697527173632
    }

    MainLocalStaticPtr = &a;
    std::cout << (__int64)(MainLocalStaticPtr) << std::endl;
    //140697527173124

    GlobalStaticPtr = &g_a;
    std::cout << (__int64)(GlobalStaticPtr) << std::endl;
    //140697527173120

    return 0;
}