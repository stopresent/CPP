#include <iostream>
using namespace std;
#include <list>
#include<utility>

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

template<typename T>
class Node
{
public:
	Node() : _prev(nullptr), _next(nullptr), _data(T())
	{

	}

	Node(const T& value) : _prev(nullptr), _next(nullptr), _data(value)
	{

	}

public:
	Node*	_prev;
	Node*	_next;
	T		_data;
	T		_index;
};

template<typename T>
class Iterator
{
public:
	Iterator() : _node(nullptr)
	{

	}

	Iterator(Node<T>* node) : _node(node)
	{

	}

	// it++
	Iterator operator++(int)
	{
		Iterator<T> temp = *this;
		_node = _node->_next;
		return temp;
	}

	// it--
	Iterator operator--(int)
	{
		Iterator<T> temp = *this;
		_node = _node->_prev;
		return temp;
	}

	// *it
	T& operator*()
	{
		return _node->_data;
	}

	T& operator&()
	{
		return _node->_index;
	}

	bool operator==(const Iterator& other)
	{
		return _node == other._node;
	}

	bool operator!=(const Iterator& other)
	{
		return _node != other._node;
	}

public:
	Node<T>* _node;
};

template<typename T>
class List
{
public:
	List() : _size(0)
	{
		// [head] <-> ... <-> [tail]
		_head = new Node<T>();
		_tail = new Node<T>();
		_head->_next = _tail;
		_tail->_prev = _head;
	}

	~List()
	{
		while (_size > 0)
			pop_back();

		delete _head;
		delete _tail;
	}

	void push_back(const T& value, const T& indexValue)
	{
		AddNode(_tail, value, indexValue);
	}

	void pop_back()
	{
		RemoveNode(_tail->_prev);
	}

private:

	// [head] <-> [1] <-> [prevNode] <-> [before] <-> [tail]
	// [head] <-> [1] <-> [prevNode] <-> [newNode] <-> [before] <-> [tail]
	Node<T>* AddNode(Node<T>* before, const T& value, const T& indexValue)
	{
		Node<T>* newNode = new Node<T>(value);
		newNode->_index = indexValue;
		Node<T>* prevNode = before->_prev;

		prevNode->_next = newNode;
		newNode->_prev = prevNode;

		newNode->_next = before;
		before->_prev = newNode;

		_size++;

		return newNode;
	}

	// [head] <-> [prevNode] <-> [node] <-> [nextNode] <-> [tail]
	// [head] <-> [prevNode] <-> [nextNode] <-> [tail]
	Node<T>* RemoveNode(Node<T>* node)
	{
		Node<T>* prevNode = node->_prev;
		Node<T>* nextNode = node->_next;

		prevNode->_next = nextNode;
		nextNode->_prev = prevNode;

		delete node;

		_size--;

		return nextNode;
	}

public:

	int size() { return _size; }

	using iterator = Iterator<T>;

	iterator begin() { return iterator(_head->_next); }
	iterator end() { return iterator(_tail); }

	// it '�տ�' �߰�
	iterator insert(iterator it, const T& value, const T& indexValue)
	{
		Node<T>* node = AddNode(it._node, value, indexValue);
		return iterator(node);
	}

	iterator erase(iterator it)
	{
		Node<T>* node = RemoveNode(it._node);
		return iterator(node);
	}

private:
	Node<T>*	_head;
	Node<T>*	_tail;
	int			_size;
};

int idxCal = 1;
int N;

int main()
{
	cin >> N;

	List<int> li;

	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		pair<int, int> myPair = make_pair(i + 1, input);
		// pair�� list�� �ְ� ������ ����� �𸣰���
		li.push_back(input, i + 1);
	}

	List<int>::iterator it = li.begin();

	int num = *li.begin();

	while (true)
	{
		// ���
		cout << &it << ' ';
		
		if (li.size() == 1) break;

		// ����
		num = *it;
		it = li.erase(it);

		// �̵�
		if (num >= 0)
		{

			if (it == li.end())
				it = li.begin();
			for (int i = 1; i < num; i++)
			{
				if (it == li.end())
				{
					it = li.begin();
					continue;
				}
				it++;
			}
		}
		else
		{
			for (int i = 0; i > num; i--)
			{
				if (it == li.begin())
				{
					it = li.end();
					it--;
					continue;
				}
				it--;
			}
		}

	}


	return 0;
}