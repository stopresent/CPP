#include <iostream>
using namespace std;

/*

배정훈 님 문제

아래는 2차원 평면상에서의 좌표를 표현할 수 있는 구조체를 정의했다.

```cpp
typedef struct __Point
{
	int xpos;
	int ypos;
} Point;
```

위의 구조체를 기반으로 두 점의 합을 계산하는 함수를 다음의 형태로 정의하며 덧셈결과는 함수의 반환을 통해 얻고

```cpp
Point& PntAdder(const Point &p1, const Point &p2);
```

임의의 두 점을 선언하여 위 함수를 이용한 덧셈연산을 진행하는 main함수를 정의해보자.

단 구조체 Point 관련 변수의 선언은 무조건 new 연산자를 이용해서 진행하며, 할당된 메모리 공간의 소멸도 빼먹지 말자.

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
