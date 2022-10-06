#pragma once

class Monster
{
public:
	int GetHP() { return _hp; }
	void SetHP(int hp) { _hp = hp; }

	int GetAttack() { return _attack; }
	void SetAttack(int att) { _attack = att; }

	int GetDefence() { return _defence; }
	void SetDefence(int def) { _defence = def; }

	void Attack(class Player& player);

public:
	void PrintInfo(Monster& info);

private:
	int _hp;
	int _attack;
	int _defence;
};

