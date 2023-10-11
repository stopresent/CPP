# Graph 기초

---

### 🚀 그래프

**그래프의 개념**

현실 세계의 사물이나 추상적인 개념 간의 연결 관계를 표현

정점(Vertex) : 데이터를 표현 (사물, 개념 등)

간선(Edge) : 정점 들을 연결하는데 사용

**그래프의 예시**

![Untitled](https://github.com/stopresent/CPP/assets/86364202/865d7aa4-d990-461e-8696-4ebfd655c943)

**가중치 그래프(WEIGHTED GRAPH)**

![Untitled 1](https://github.com/stopresent/CPP/assets/86364202/d2a9724c-0c74-434e-b2e0-855724423d1b)

연결 관계에서 간선의 숫자가 가중치를 나타낸다.

ex ) 노선의 길이

**방향 그래프(DIRECTED GRAPH)**

![Untitled 2](https://github.com/stopresent/CPP/assets/86364202/65f0a78b-267f-4608-b7c1-010ec1d87deb)

**그래프를 코드로 표현하기**

```cpp
void CreateGraph_1()
{
	struct Vertex
	{
		vector<Vertex*> edges;
		// int data;
	};

	vector<Vertex> v;
	v.resize(6);

	v[0].edges.push_back(&v[1]);
	v[0].edges.push_back(&v[3]);
	v[1].edges.push_back(&v[0]);
	v[1].edges.push_back(&v[2]);
	v[1].edges.push_back(&v[3]);
	v[3].edges.push_back(&v[4]);
	v[5].edges.push_back(&v[4]);

	// Q) 0번 -> 3번 이 만족하나요?
	bool conected = false;
	for (Vertex* edge : v[0].edges)
	{
		if (edge == &v[3])
		{
			conected = true;
			break;
		}
	}

}
```

```cpp
void CreateGraph_2()
{
	struct Vertex
	{

	};

	vector<Vertex> v;
	v.resize(6);

	// 연결된 목록을 따로 관리
	// adjacent[n] -> n번째 정점과 연결된 정점 목록
	vector<vector<int>> adjacent(6);
	adjacent[0] = { 1, 3 };
	adjacent[1] = { 0 , 2, 3 };
	adjacent[3] = { 4 };
	adjacent[5] = { 4 };

	// Q) 0번 -> 3번 이 만족하나요?
	bool conected = false;
	for (int vertex : adjacent[0])
	{
		if (vertex == 3)
		{
			conected = true;
			break;
		}
	}

	// Q) 0번 -> 3번 이 만족하나요?
	// STL
	vector<int>& adj = adjacent[0];
	bool conected2 = (std::find(adjacent[0].begin(), adjacent[0].end(), 3) != adjacent[0].end());
}
```

지하철 노선도 같이 서로 드문 드문 연결되어 있다면 → 효율이 좋다.

페이스북 친구 같이 서로 빽빽하게 연결되어 있다면 → 효율이 안 좋다.

```cpp
void CreateGraph_3()
{
	struct Vertex
	{

	};

	vector<Vertex> v;
	v.resize(6);

	// 연결된 목록을 따로 관리
	// [X][O][X][O][X][X]
	// [O][X][O][O][X][X]
	// [X][X][X][X][X][X]
	// [X][X][X][X][O][X]
	// [X][X][X][X][X][X]
	// [X][X][X][X][O][X]

	// 읽는 방법 : adjacent[from][to]
	// 2차원 배열을 통한 방법
	// 메모리 소비가 심하지만 빠르게 접근 가능
	// 간선이 빽빽할 때 효율이 좋다.
	vector<vector<bool>> adjacent(6, vector<bool>(6, false));
	adjacent[0][1] = true;
	adjacent[0][3] = true;
	adjacent[1][0] = true;
	adjacent[1][2] = true;
	adjacent[1][3] = true;
	adjacent[3][4] = true;
	adjacent[5][4] = true;

	// Q) 0번 -> 3번 이 만족하나요?
	bool conected = adjacent[0][3];

	// 가중치 그래프
	vector<vector<int>> adjacent2 =
	{
		{ -1, 15, -1, 35, -1, -1},
		{ 15, -1, 05, 10, -1, -1},
		{ -1, -1, -1, -1, -1, -1},
		{ -1, -1, -1, -1, 05, -1},
		{ -1, -1, -1, -1, -1, -1},
		{ -1, -1, -1, -1, 05, -1},
	};
}
```

메모리를 많이 쓰지만 빨리 접근 할 수 있는 방식이다. (for문을 사용 안 함!)

---

### 🚀 DFS (깊이 우선 탐색)

Depth First Search

**linked list version**

```cpp
#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

struct Vertex
{
	// int data;
};

vector<Vertex> vertices;
vector<vector<int>> adjacent;
vector<bool> visited;

void CreateGraph()
{
	vertices.resize(6);
	adjacent = vector<vector<int>>(6);
	adjacent[0].push_back(1);
	adjacent[0].push_back(3);
	adjacent[1].push_back(0);
	adjacent[1].push_back(1);
	adjacent[1].push_back(2);
	adjacent[3].push_back(4);
	adjacent[5].push_back(4);

}

void DFS(int here)
{
	// 방문!
	visited[here] = true;
	cout << "Visited : " << here << endl;

	for (int i = 0; i < adjacent[here].size(); i++)
	{
		int there = adjacent[here][i];
		if (visited[there] == false)
			DFS(there);
	}
}

void DFSAll()
{
	for (int i = 0; i < 6; i++)
	{
		if (visited[i] == false)
			DFS(i);
	}
}

int main()
{
	CreateGraph();

	visited = vector<bool>(6, false);

	DFSAll();
}
```

**adjacent matrix version**

```cpp
#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

struct Vertex
{
	// int data;
};

vector<Vertex> vertices;
vector<vector<int>> adjacent;
vector<bool> visited;

void CreateGraph()
{
	vertices.resize(6);

	adjacent = vector<vector<int>>
	{
		{ 0, 1, 0, 1, 0, 0},
		{ 1, 0, 1, 1, 0, 0},
		{ 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 1, 0},
		{ 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 1, 0},
	};

}

void DFS(int here)
{
	// 방문!
	visited[here] = true;
	cout << "Visited : " << here << endl;

	for (int there = 0; there < 6; there++)
	{
		if (adjacent[here][there] == 0)
			continue;

		if (visited[there] == false)
			DFS(there);
	}
}

void DFSAll()
{
	for (int i = 0; i < 6; i++)
	{
		if (visited[i] == false)
			DFS(i);
	}
}

int main()
{
	CreateGraph();

	visited = vector<bool>(6, false);

	DFSAll();
}
```

---

### 🚀 BFS (너비 우선 탐색)

Breadth First Search

**linked list version**

```cpp
#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

struct Vertex
{
	// int data;
};

vector<Vertex> vertices;
vector<vector<int>> adjacent;
vector<bool> discorverd;

void CreateGraph()
{
	vertices.resize(6);
	adjacent = vector<vector<int>>(6);
	adjacent[0].push_back(1);
	adjacent[0].push_back(3);
	adjacent[1].push_back(0);
	adjacent[1].push_back(1);
	adjacent[1].push_back(2);
	adjacent[3].push_back(4);
	adjacent[5].push_back(4);

}

void BFS(int here)
{
	queue<int> q;
	q.push(here);
	discorverd[here] = true;

	while (q.empty() == false)
	{
		here = q.front();
		q.pop();
		cout << "Visited : " << here << endl;

		for (int there : adjacent[here])
		{
			if (discorverd[there])
				continue;

			q.push(there);
			discorverd[there] = true;
		}

	}
}

void BFSAll()
{

	for (int i = 0; i < 6; i++)
		if (discorverd[i] == false)
			BFS(i);
}

int main()
{
	CreateGraph();

	discorverd = vector<bool>(6, false);

	BFSAll();
}
```

어떤 점에 의해 발견 되었는가?

시작 위치에서 몇 칸 이동 되었는가?

를 추가 한 버전

```cpp
#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

struct Vertex
{
	// int data;
};

vector<Vertex> vertices;
vector<vector<int>> adjacent;
vector<bool> discorverd;

void CreateGraph()
{
	vertices.resize(6);
	adjacent = vector<vector<int>>(6);
	adjacent[0].push_back(1);
	adjacent[0].push_back(3);
	adjacent[1].push_back(0);
	adjacent[1].push_back(1);
	adjacent[1].push_back(2);
	adjacent[3].push_back(4);
	adjacent[5].push_back(4);

}

void BFS(int here)
{
	// 어떤 점에 의해 발견 되었는가?
	vector<int> parent(6, -1);
	// 시작 위치로 부터 몇 칸 떨어져있는가?
	vector<int> distance(6, -1);

	queue<int> q;
	q.push(here);
	discorverd[here] = true;

	parent[here] = here;
	distance[here] = 0;

	while (q.empty() == false)
	{
		here = q.front();
		q.pop();
		cout << "Visited : " << here << endl;
		cout << "Parent : " << parent[here] << endl;
		cout << "Distance : " << distance[here] << endl;

		for (int there : adjacent[here])
		{
			if (discorverd[there])
				continue;

			q.push(there);
			discorverd[there] = true;

			parent[there] = here;
			distance[there] = distance[here] + 1;
		}

	}
}

void BFSAll()
{

	for (int i = 0; i < 6; i++)
		if (discorverd[i] == false)
			BFS(i);
}

int main()
{
	CreateGraph();

	discorverd = vector<bool>(6, false);

	BFSAll();
}
```

![Untitled 3](https://github.com/stopresent/CPP/assets/86364202/bd0adf7c-fea8-4f58-8e74-797fc5aa0994)

![Untitled 4](https://github.com/stopresent/CPP/assets/86364202/56305542-b1f8-41b8-8680-c26a3d287de4)

**adjacent matrix version**

```cpp
#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

struct Vertex
{
	// int data;
};

vector<Vertex> vertices;
vector<vector<int>> adjacent;
vector<bool> discorverd;

void CreateGraph()
{
	vertices.resize(6);
	adjacent = vector<vector<int>>(6);

	adjacent = vector<vector<int>>
	{
		{ 0, 1, 0, 1, 0, 0},
		{ 1, 0, 1, 1, 0, 0},
		{ 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 1, 0},
		{ 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 1, 0},
	};

}

void BFS(int here)
{
	// 어떤 점에 의해 발견 되었는가?
	vector<int> parent(6, -1);
	// 시작 위치로 부터 몇 칸 떨어져있는가?
	vector<int> distance(6, -1);

	queue<int> q;
	q.push(here);
	discorverd[here] = true;

	parent[here] = here;
	distance[here] = 0;

	while (q.empty() == false)
	{
		here = q.front();
		q.pop();
		cout << "Visited : " << here << endl;
		cout << "Parent : " << parent[here] << endl;
		cout << "Distance : " << distance[here] << endl;

		for (int there = 0; there < 6; there++)
		{
			if (adjacent[here][there] == 0)
				continue;

			if (discorverd[there])
				continue;

			q.push(there);
			discorverd[there] = true;

			parent[there] = here;
			distance[there] = distance[here] + 1;
		}

	}
}

void BFSAll()
{

	for (int i = 0; i < 6; i++)
		if (discorverd[i] == false)
			BFS(i);
}

int main()
{
	CreateGraph();

	discorverd = vector<bool>(6, false);

	BFSAll();
}
```