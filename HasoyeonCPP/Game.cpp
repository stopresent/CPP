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
	cout << endl << "�κ� ���� ���� ȯ���մϴ�!" << endl;
	cout << "ĳ���͸� �������ּ���" << endl;
	cout << "1.[���] 2.[�ü�] 3.[������]" << endl;
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
			cout << "�ٽ� �������ּ��� (1 ~ 3)" << endl;
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
	cout << endl << "������ �����߽��ϴ�!" << endl;
	cout << "1. [�κ�� ���ư���] 2. [���� ����]" << endl;
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
			cout << "�߸��� �Է� ���Դϴ�.(1 ~ 2)" << endl;
			EnterLobby(player);
		}
	}

}

void Game::EnterDungeon(Player& player)
{
	Monster monster = CreateMonster();
	cout << "1. [�ο��!] 2. [����ģ��!]" << endl;
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
		cout << "���� ��뿴��.." << endl;
		cout << "������ ���ư���..." << endl << endl;
		EnterTown(player);
	}
	else
	{
		cout << "�߸��� �Է� ���Դϴ�. ������ ���ư��ϴ�." << endl;
		EnterTown(player);
	}
	
}

Monster Game::CreateMonster()
{
	Monster monster;

	// TODO ���� �õ� ����
	int ranValue = rand() % 3 + 1;

	switch (ranValue)
	{
	case SLIME:
		monster.SetHP(10);
		monster.SetAttack(2);
		monster.SetDefence(0);
		cout << endl << "������ ����!!!" << endl;
		break;
	case SKELETON:
		monster.SetHP(12);
		monster.SetAttack(3);
		monster.SetDefence(1);
		cout << endl << "���̷��� ����!!!" << endl;
		break;
	case ORC:
		monster.SetHP(30);
		monster.SetAttack(5);
		monster.SetDefence(3);
		cout << endl << "��ũ ����!!!" << endl;
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
		cout << "**������ ���� ü��**" << endl;
		cout << "**" << monster.GetHP() << "**" << endl;
		if (monster.GetHP() == 0)
		{
			cout << endl << "�������� �¸��ߴ�!!" << endl;
			cout << "���� ��������." << endl;
			return true;
		}

		monster.Attack(player);
		cout << "**�÷��̾��� ���� ü��**" << endl;
		cout << "**" << player.GetHP() << "**" << endl;
		if (player.GetHP() == 0)
		{
			cout << endl << "�������� �й��ߴ�..." << endl;
			cout << "�κ�� ���ư��ϴ�." << endl;
			return false;
		}
	}
}
