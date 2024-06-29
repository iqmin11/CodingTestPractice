#include <iostream>
#include <stack>
#include <list>

class Monster
{
public:
    virtual void Attack() = 0;
};

class MeleeMonster : public Monster
{
public:
    void Attack()
    {
        std::cout << "MeleeMonster Attack" << std::endl;
    }
};

class RangedMonster : public Monster
{
public:
    void Attack()
    {
        std::cout << "RangedMonster Attack" << std::endl;
    }
};

int main()
{
    Monster* A = new MeleeMonster();
    Monster* B = new RangedMonster();

    A->Attack();
    B->Attack();

    return 0;
}