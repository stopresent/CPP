/* new 와 delete 의 사용 */
#include <iostream>
using namespace std;
#include <stdlib.h>
// 돌아온 마이펫

/*

조건

- 동물(struct Animal) 이라는 구조체를 정의해서 이름(char name[30]), 나이(int age),
체력(int health), 배부른 정도(int food), 깨끗한 정도의(int clean) 값을 가진다.

- 처음에 동물 구조체의 포인터 배열(struct Animal* list[30])을 만들어서 사용자가
동물을 추가할 때 마다 하나씩 생성한다.

- play 라는 함수를 만들어서 동물의 상태를 변경하고 show_stat 함수를 만들어서 지정하는
동물의 상태를 출력한다.

- 1 턴이 지날 때 마다 동물의 상태를 변경한다.

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
	cout << "이름? " << endl;
	cin >> animal.name;

	cout << "나이? " << endl;
	cin >> animal.age;

	animal.health = 100;
	animal.food = 100;
	animal.clean = 100;
}

void show_stat(Animal& animal)
{
	cout << endl;
	cout << "이름 : " << animal.name << endl;
	cout << "나이 : " << animal.age << endl;
	cout << "체력 : " << animal.health << endl;
	cout << "포만도 : " << animal.food << endl;
	cout << "청결도 : " << animal.clean << endl;
}

void Play(Animal& animal)
{
	animal.health -= 10;
	animal.food -= 10;
	animal.clean -= 10;

	if (animal.health <= 0)
	{
		cout << animal.name << "이(가) 사망" << endl;
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
		cout << i + 1<< "번 동물 : " << list[i]->name << endl;
}

int main()
{
	int turn = 0;

	struct Animal* list[30];

	while (true)
	{
		cout << endl << turn << "번 째 턴" << endl;

		cout << "행동을 정해라" << endl << endl;
		cout << "1. 동물 생성" << endl;
		cout << "2. 놀기" << endl;
		cout << "3. 상태창 (턴 추가 x)" << endl;
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
			cout << "동물 정해" << endl;

			ShowAnimalList(list);

			int input1;
			cin >> input1;

			Play(*list[input1 - 1]);

			show_stat(*list[input1 - 1]);
			cout << "동물을 놀아주었다!" << endl;

			turn++;
			break;
		case INFO:

			cout << "동물 정해" << endl;

			ShowAnimalList(list);

			int input2;
			cin >> input2;

			show_stat(*list[input2 - 1]);

			break;
		case END:
			cout << "모든 동물을 죽이고 프로그램을 종료한다..." << endl;
			for (int i = 0; i < animalCount; i++)
				delete list[i];
			return 0;
		}
	}

	return 0;
}

// new 는 heap영역에 생김
