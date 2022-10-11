/* new �� delete �� ��� */
#include <iostream>
using namespace std;
#include <stdlib.h>
// ���ƿ� ������

/*

����

- ����(struct Animal) �̶�� ����ü�� �����ؼ� �̸�(char name[30]), ����(int age),
ü��(int health), ��θ� ����(int food), ������ ������(int clean) ���� ������.

- ó���� ���� ����ü�� ������ �迭(struct Animal* list[30])�� ���� ����ڰ�
������ �߰��� �� ���� �ϳ��� �����Ѵ�.

- play ��� �Լ��� ���� ������ ���¸� �����ϰ� show_stat �Լ��� ���� �����ϴ�
������ ���¸� ����Ѵ�.

- 1 ���� ���� �� ���� ������ ���¸� �����Ѵ�.

*/

int animalCount = 0;

struct Animal
{
	char name[30];
	int age;
	int health;
	int food;
	int clean;
};

void CreateAnimal(Animal& animal)
{
	cout << "�̸�? " << endl;
	cin >> animal.name;

	cout << "����? " << endl;
	cin >> animal.age;

	animal.health = 100;
	animal.food = 100;
	animal.clean = 100;
}

void show_stat(Animal& animal)
{
	cout << endl;
	cout << "�̸� : " << animal.name << endl;
	cout << "���� : " << animal.age << endl;
	cout << "ü�� : " << animal.health << endl;
	cout << "������ : " << animal.food << endl;
	cout << "û�ᵵ : " << animal.clean << endl;
}

void Play(Animal& animal)
{
	animal.health -= 10;
	animal.food -= 10;
	animal.clean -= 10;

	if (animal.health <= 0)
	{
		cout << animal.name << "��(��) ���" << endl;
		cout << "GAME OVER" << endl;
		delete &animal;
		exit(0);
	}
}

enum
{
	CREATE_ANIMAL = 1,
	PLAY = 2,
	INFO = 3,
	END = 4,
};

void ShowAnimalList(Animal* list[])
{
	for (int i = 0; i < animalCount; i++)
		cout << i + 1<< "�� ���� : " << list[i]->name << endl;
}

int main()
{
	int turn = 0;

	struct Animal* list[30];

	while (true)
	{
		cout << endl << turn << "�� ° ��" << endl;

		cout << "�ൿ�� ���ض�" << endl << endl;
		cout << "1. ���� ����" << endl;
		cout << "2. ���" << endl;
		cout << "3. ����â (�� �߰� x)" << endl;
		cout << ">>";

		int input;
		cin >> input;

		switch (input)
		{
		case CREATE_ANIMAL:
			list[animalCount] = new Animal;
			
			CreateAnimal(*list[animalCount]);

			animalCount++;
			turn++;
			break;
		case PLAY:
			cout << "���� ����" << endl;

			ShowAnimalList(list);

			int input1;
			cin >> input1;

			Play(*list[input1 - 1]);

			show_stat(*list[input1 - 1]);
			cout << "������ ����־���!" << endl;

			turn++;
			break;
		case INFO:

			cout << "���� ����" << endl;

			ShowAnimalList(list);

			int input2;
			cin >> input2;

			show_stat(*list[input2 - 1]);

			break;
		case END:
			cout << "��� ������ ���̰� ���α׷��� �����Ѵ�..." << endl;
			for (int i = 0; i < animalCount; i++)
				delete list[i];
			return 0;
		}
	}

	return 0;
}

// new �� heap������ ����
