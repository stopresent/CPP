#include <iostream>
using namespace std;
#include <list>

/*

풍선 터뜨리기

문제
1번부터 N번까지 N개의 풍선이 원형으로 놓여 있고. i번 풍선의 오른쪽에는 i+1번 풍선이 있고, 왼쪽에는 i-1번 풍선이 있다.
단, 1번 풍선의 왼쪽에 N번 풍선이 있고, N번 풍선의 오른쪽에 1번 풍선이 있다.
각 풍선 안에는 종이가 하나 들어있고, 종이에는 -N보다 크거나 같고, N보다 작거나 같은 정수가 하나 적혀있다. 이 풍선들을 다음과 같은 규칙으로 터뜨린다.

우선, 제일 처음에는 1번 풍선을 터뜨린다. 다음에는 풍선 안에 있는 종이를 꺼내어 그 종이에 적혀있는 값만큼 이동하여 다음 풍선을 터뜨린다.
양수가 적혀 있을 경우에는 오른쪽으로, 음수가 적혀 있을 때는 왼쪽으로 이동한다. 이동할 때에는 이미 터진 풍선은 빼고 이동한다.

예를 들어 다섯 개의 풍선 안에 차례로 3, 2, 1, -3, -1이 적혀 있었다고 하자.
이 경우 3이 적혀 있는 1번 풍선, -3이 적혀 있는 4번 풍선, -1이 적혀 있는 5번 풍선, 1이 적혀 있는 3번 풍선, 2가 적혀 있는 2번 풍선의 순서대로 터지게 된다.

입력
첫째 줄에 자연수 N(1 ≤ N ≤ 1,000)이 주어진다. 다음 줄에는 차례로 각 풍선 안의 종이에 적혀 있는 수가 주어진다. 종이에 0은 적혀있지 않다.

출력
첫째 줄에 터진 풍선의 번호를 차례로 나열한다.

예제 입력 1
5
3 2 1 -3 -1

예제 출력 1
1 4 5 3 2

*/

int idxCal = 1;
int N;

template<typename T>
class Node
{
public:
	Node() : _prev(nullptr), _next(nullptr), _index(T()), _num(T())
	{

	}

	Node(const T& indexVlaue, const T& numValue) : _prev(nullptr), _next(nullptr), _index(indexVlaue), _num(numValue)
	{

	}

public:
	Node<int>*	_prev;
	Node<int>*	_next;
	int			_index;
	int			_num;
};

template<typename T>
class LinkedList
{
public:
	LinkedList() : _size(0)
	{
		_head = new Node<T>();
		_tail = new Node<T>();
		_head->_next = _tail;
		_tail->_prev = _head;
	}

	~LinkedList()
	{
		delete _head;
		delete _tail;
	}

public:

	Node<T>* AddNode(Node<T>* before, const T& indexVlaue, const T& numValue)
	{
		Node<T>* newNode = new Node<T>(indexVlaue, numValue);
		newNode->_index = indexVlaue;
		newNode->_num = numValue;
		Node<T>* prevNode = before->_prev;

		prevNode->_next = newNode;
		newNode->_prev = prevNode;

		newNode->_next = before;
		before->_prev = newNode;

		_size++;

		return newNode;
	}

	void RemoveNode(Node<T>* node, int index)
	{
		if (_size == 0) return;
		cout << node->_index;
		for (int i = 0; i < N; i++)
		{
			if (index == node->_index)
			{

				cout << node->_index;

				Node<T>* prevNode = node->_prev;
				Node<T>* nextNode = node->_next;

				prevNode->_next = nextNode;
				nextNode->_prev = prevNode;

				delete node;

				_size--;

				idxCal += node->_num;

				RemoveNode(node, idxCal);

			}
		}
		
	}

public:

	void push_back(const T& indexVlaue, const T& numValue)
	{
		AddNode(_tail, indexVlaue, numValue);
	}

	int size() { return _size; }

public:
	Node<T>*	_head;
	Node<T>*	_tail;
	int			_size;

};

int main()
{
	cin >> N;

	LinkedList<int> linkdedList;

	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		linkdedList.push_back(i + 1,input);
	}

	linkdedList.RemoveNode(linkdedList._head, 1);

	return 0;
}