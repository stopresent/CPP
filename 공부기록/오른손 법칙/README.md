배운 우아한 방법

switch (_dir)
{
case DIR_UP:
	_dir = DIR_LEFT;
	break;
case DIR_LEFT:
	_dir = DIR_DOWN;
case DIR_DOWN:
	_dir = DIR_RIGHT;
	break;
case DIR_RIGHT:
	_dir = DIR_UP;
	break;
}

이렇게 규칙적인 순회를 할 떄
이렇게 해보자

_dir = (_dir + 1) % DIR_COUNT;

우수법에서 앞으로간다는 것을 표현할 때

Pos front[4] =
{
	Pos {-1, 0},	// UP
	Pos {0, -1},	// LEFT
	Pos {1, 0},		// DOWN
	Pos {0, 1}		// RIGHT
};
이렇게 배열을 잡고, 새로운 방향을 더해준다. -> CanGo(pos + front[newDir])