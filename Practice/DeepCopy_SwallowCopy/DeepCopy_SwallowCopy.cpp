#include <iostream>

class weapon
{
public:
	int Case = 0;// 0 = sword, 1 = gun
};

class fighter
{
public:
	fighter(int _Att, int _Def, int _HP, weapon* Equip)
		: Att(_Att), Def(_Def), HP(_HP), MyWeapon(Equip)
	{

	}

	~fighter()
	{
		if (MyWeapon != nullptr)
		{
			delete MyWeapon;
		}
	}

	////SwallowCopy
	//fighter(const fighter& Other)
	//{
	//	Att = Other.Att;
	//	Def = Other.Def;
	//	HP = Other.HP;

	//	MyWeapon = Other.MyWeapon;
	//}

	//DeepCopy
	fighter(const fighter& Other)
	{
		Att = Other.Att;
		Def = Other.Def;
		HP = Other.HP;

		MyWeapon = new weapon;
		*MyWeapon = *(Other.MyWeapon);
	}

	int Att;
	int Def;
	int HP;
	weapon* MyWeapon = nullptr;
};

int main()
{
	weapon* AWeapon = new weapon;
	AWeapon->Case = 0;
	fighter A(10, 20, 30, AWeapon);
	fighter B = A;
	return 0;
}