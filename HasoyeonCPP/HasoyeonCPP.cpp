#include <iostream>
using namespace std;

/*

������ �� ����

�Ʒ��� 2���� ���󿡼��� ��ǥ�� ǥ���� �� �ִ� ����ü�� �����ߴ�.

```cpp
typedef struct __Point
{
	int xpos;
	int ypos;
} Point;
```

���� ����ü�� ������� �� ���� ���� ����ϴ� �Լ��� ������ ���·� �����ϸ� ��������� �Լ��� ��ȯ�� ���� ���

```cpp
Point& PntAdder(const Point &p1, const Point &p2);
```

������ �� ���� �����Ͽ� �� �Լ��� �̿��� ���������� �����ϴ� main�Լ��� �����غ���.

�� ����ü Point ���� ������ ������ ������ new �����ڸ� �̿��ؼ� �����ϸ�, �Ҵ�� �޸� ������ �Ҹ굵 ������ ����.

*/

struct Pos
{
	int posX;
	int posY;

	Pos& operator+=(Pos& other)
	{
		posX += other.posX;
		posY += other.posY;
		return *this;
	}

	Pos operator+ (Pos& other)
	{
		Pos* ret = new Pos;
		posX += other.posX;
		posY += other.posY;
		return *ret;
	}
};

Pos& PntAdder(const Pos& p1, const Pos& p2)
{
	Pos* ret = new Pos;
	ret->posX = p1.posX + p2.posX;
	ret->posY = p1.posY + p2.posY;
	return *ret;
}

int main()
{
	Pos* p1 = new Pos;
	p1->posX = 10;
	p1->posY = 20;
	Pos* p2 = new Pos;
	p2->posX = 30;
	p2->posY = 40;

	*p1 += *p2;

	Pos p3 = *p1 + *p2;

	PntAdder(*p1, *p2);

	delete p1;
	delete p2;
	delete &p3;
}
