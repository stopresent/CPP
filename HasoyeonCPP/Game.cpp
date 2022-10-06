#include "Game.h"
#include <iostream>
using namespace std;
#include "Player.h"
#include "Monster.h"
#include <random>

void Game::Init()
{
	Player player;
	EnterLobby(player);
}

void Game::Update()
{
}

void Game::EnterLobby(Player& player)
{
	cout << endl << "로비에 오신 것을 환영합니다!" << endl;
	cout << "캐릭터를 선택해주세요" << endl;
	cout << "1.[기사] 2.[궁수] 3.[마법사]" << endl;
	cout << ">>";

	int input;
	cin >> input;

	bool flag = false;

	while (true)
	{
		if (flag == true) break;

		switch (input)
		{
		case KNIGHT:
			player.SetHP(100);
			player.SetAttack(10);
			player.SetDefence(5);

			flag = true;
			break;
		case ARCHOR:
			player.SetHP(100);
			player.SetAttack(12);
			player.SetDefence(3);

			flag = true;
			break;
		case MAGE:
			player.SetHP(100);
			player.SetAttack(17);
			player.SetDefence(2);

			flag = true;
			break;
		default:
			cout << "다시 선택해주세요 (1 ~ 3)" << endl;
			Init();

			flag = false;

			break;
		}
	}

	player.PrintInfo(player);
	EnterTown(player);
}

void Game::EnterTown(Player& player)
{
	cout << endl << "마을에 입장했습니다!" << endl;
	cout << "1. [로비로 돌아가기] 2. [던전 들어가기]" << endl;
	cout << ">>";

	int input;
	cin >> input;

	while (true)
	{
		if (input == 1)
		{
			EnterLobby(player);
		}
		else if (input == 2)
		{
			EnterDungeon(player);
		}
		else
		{
			cout << "잘못된 입력 값입니다.(1 ~ 2)" << endl;
			EnterLobby(player);
		}
	}

}

void Game::EnterDungeon(Player& player)
{
	Monster monster = CreateMonster();
	cout << "1. [싸운다!] 2. [도망친다!]" << endl;
	cout << ">>";

	int input;
	cin >> input;
	cout << endl;

	if (input == 1)
	{
		bool victory = Fight(player, monster);
		if (victory == true)
		{
			EnterDungeon(player);
		}
		else
		{
			EnterLobby(player);
		}
	}
	else if (input == 2)
	{
		cout << "강한 상대였다.." << endl;
		cout << "마을로 돌아가자..." << endl << endl;
		EnterTown(player);
	}
	else
	{
		cout << "잘못된 입력 값입니다. 마을로 돌아갑니다." << endl;
		EnterTown(player);
	}
	
}

Monster Game::CreateMonster()
{
	Monster monster;

	// TODO 랜덤 시드 생성
	int ranValue = rand() % 3 + 1;

	switch (ranValue)
	{
	case SLIME:
		monster.SetHP(10);
		monster.SetAttack(2);
		monster.SetDefence(0);
		cout << endl << "슬라임 출현!!!" << endl;
		break;
	case SKELETON:
		monster.SetHP(12);
		monster.SetAttack(3);
		monster.SetDefence(1);
		cout << endl << "스켈레톤 출현!!!" << endl;
		break;
	case ORC:
		monster.SetHP(30);
		monster.SetAttack(5);
		monster.SetDefence(3);
		cout << endl << "오크 출현!!!" << endl;
		break;
	default:
		break;
	}

	return monster;
}

bool Game::Fight(Player& player, Monster& monster)
{
	while (true)
	{
		player.Attack(monster);
		cout << "**몬스터의 남은 체력**" << endl;
		cout << "**" << monster.GetHP() << "**" << endl;
		if (monster.GetHP() == 0)
		{
			cout << endl << "전투에서 승리했다!!" << endl;
			cout << "힘든 전투였다." << endl;
			return true;
		}

		monster.Attack(player);
		cout << "**플레이어의 남은 체력**" << endl;
		cout << "**" << player.GetHP() << "**" << endl;
		if (player.GetHP() == 0)
		{
			cout << endl << "전투에서 패배했다..." << endl;
			cout << "로비로 돌아갑니다." << endl;
			return false;
		}
	}
}
