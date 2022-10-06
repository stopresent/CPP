#include "Player.h"
#include "Monster.h"
#include "Game.h"
#include <iostream>
using namespace std;

void Player::Attack(Monster& monster)
{
	int damage = GetAttack() - monster.GetDefence();
	if (damage <= 0) damage = 0;
	
	monster.SetHP(monster.GetHP() - damage);
	if (monster.GetHP() <= 0) monster.SetHP(0);


}

void Player::PrintInfo(Player& info)
{
	cout << "______________________________________" << endl;
	cout << "HP : " << info.GetHP() << " ATT : " << info.GetAttack() << " DEF : " << info.GetDefence() << endl;
	cout << "--------------------------------------" << endl;
}

