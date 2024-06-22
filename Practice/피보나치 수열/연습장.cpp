#include <iostream>
#include <stack>

std::stack<int> St1;
std::stack<int> St2;

void Push(int Value)
{
    St1.push(Value);
}

void Pop()
{
    while (!St1.empty())
    {
        St2.push(St1.top());
        St1.pop();
    }

    St2.pop();

    while (!St2.empty())
    {
        St1.push(St2.top());
        St2.pop();
    }
}

int main()
{
    //1 2 3 4 5
    Push(1);
    Push(2);
    Pop();
    Push(3);
    Push(4);
    Pop();
    Push(5);
    Pop();
    Pop();
    Pop();
    return 0;
}