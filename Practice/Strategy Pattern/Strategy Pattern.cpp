#include <iostream>

//Strategy
class Monster
{
public:
    virtual ~Monster() {}
    virtual void Attack() = 0;
};


//Concrete Strategies
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

//Context
int main()
{
    Monster* A = new MeleeMonster();
    Monster* B = new RangedMonster();

    A->Attack();
    B->Attack();

    delete A;
    delete B;

    return 0;
}