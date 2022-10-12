#include <iostream>
using namespace std;
#include <list>

/*

ǳ�� �Ͷ߸���

����
1������ N������ N���� ǳ���� �������� ���� �ְ�. i�� ǳ���� �����ʿ��� i+1�� ǳ���� �ְ�, ���ʿ��� i-1�� ǳ���� �ִ�.
��, 1�� ǳ���� ���ʿ� N�� ǳ���� �ְ�, N�� ǳ���� �����ʿ� 1�� ǳ���� �ִ�.
�� ǳ�� �ȿ��� ���̰� �ϳ� ����ְ�, ���̿��� -N���� ũ�ų� ����, N���� �۰ų� ���� ������ �ϳ� �����ִ�. �� ǳ������ ������ ���� ��Ģ���� �Ͷ߸���.

�켱, ���� ó������ 1�� ǳ���� �Ͷ߸���. �������� ǳ�� �ȿ� �ִ� ���̸� ������ �� ���̿� �����ִ� ����ŭ �̵��Ͽ� ���� ǳ���� �Ͷ߸���.
����� ���� ���� ��쿡�� ����������, ������ ���� ���� ���� �������� �̵��Ѵ�. �̵��� ������ �̹� ���� ǳ���� ���� �̵��Ѵ�.

���� ��� �ټ� ���� ǳ�� �ȿ� ���ʷ� 3, 2, 1, -3, -1�� ���� �־��ٰ� ����.
�� ��� 3�� ���� �ִ� 1�� ǳ��, -3�� ���� �ִ� 4�� ǳ��, -1�� ���� �ִ� 5�� ǳ��, 1�� ���� �ִ� 3�� ǳ��, 2�� ���� �ִ� 2�� ǳ���� ������� ������ �ȴ�.

�Է�
ù° �ٿ� �ڿ��� N(1 �� N �� 1,000)�� �־�����. ���� �ٿ��� ���ʷ� �� ǳ�� ���� ���̿� ���� �ִ� ���� �־�����. ���̿� 0�� �������� �ʴ�.

���
ù° �ٿ� ���� ǳ���� ��ȣ�� ���ʷ� �����Ѵ�.

���� �Է� 1
5
3 2 1 -3 -1

���� ��� 1
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