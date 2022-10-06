#include "Monster.h"
#include "Player.h"
#include <iostream>
using namespace std;

void Monster::Attack(Player& player)
{
	int damage = GetAttack() - player.GetDefence();
	if (damage <= 0) damage = 0;

	player.SetHP(player.GetHP() - damage);
	if (player.GetHP() <= 0) player.SetHP(0);
}

void Monster::PrintInfo(Monster& info)
{
	cout << "______________________________________" << endl;
	cout << "HP : " << info.GetHP() << " ATT : " << info.GetAttack() << " DEF : " << info.GetDefence() << endl;
	cout << "--------------------------------------" << endl;
}
