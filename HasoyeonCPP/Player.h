#pragma once

class Player
{
public:
	int GetHP() { return _hp; }
	void SetHP(int hp) { _hp = hp; }

	int GetAttack() { return _attack; }
	void SetAttack(int att) { _attack = att; }

	int GetDefence() { return _defence; }
	void SetDefence(int def) { _defence = def; }

	void Attack(class Monster& monster);

public:
	void PrintInfo(Player& info);
private:
	int _hp;
	int _attack;
	int _defence;

};

