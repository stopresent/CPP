#pragma once

class Monster;
class Player;

enum PlayerClass
{
	KNIGHT = 1,
	ARCHOR = 2, 
	MAGE = 3,
};

enum MonsterClass
{
	SLIME = 1,
	SKELETON = 2,
	ORC = 3,
};

class Game
{
public:
	void Init();
	void Update();
	
public:
	void EnterLobby(Player& player);
	void EnterTown(Player& player);
	void EnterDungeon(Player& player);

private:
	Monster CreateMonster();
	bool Fight(Player& player, Monster& monster);
};

