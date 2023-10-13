
**BFS를 이용한 길찾기 구현**

---


핵심 코드
```cpp
void Player::BFS()
{
	Pos pos = _pos;

	// 목적지 도착하기 전에는 계속 실행
	Pos dest = _board->GetExitPos();

	Pos front[4] =
	{
		Pos {-1, 0},	// UP
		Pos {0, -1},	// LEFT
		Pos {1, 0},		// DOWN
		Pos {0, 1}		// RIGHT
	};

	queue<Pos> q;
	const int32 size = _board->GetSize();

	// parent[A] = B; -> A는 B로인해 발견함.
	map<Pos, Pos> parent;
	vector<vector<bool>> discovered(size, vector<bool>(size, false));
	q.push(pos);
	discovered[pos.y][pos.x] = true;
	parent[pos] = pos;

	while (q.empty() == false)
	{
		Pos pos = q.front();
		q.pop();

		if (pos == dest)
			break;

		for (int dir = 0; dir < 4; dir++)
		{
			Pos nextPos = pos + front[dir];

			if (CanGo(nextPos) == false)
				continue;
			if (discovered[nextPos.y][nextPos.x])
				continue;

			q.push(nextPos);
			discovered[nextPos.y][nextPos.x] = true;
			parent[nextPos] = pos;
		}
	}

	_path.clear();

	pos = dest;
	while (true)
	{
		_path.push_back(pos);

		if (parent[pos] == pos)
			break;

		pos = parent[pos];
	}

	std::reverse(_path.begin(), _path.end());
}
```