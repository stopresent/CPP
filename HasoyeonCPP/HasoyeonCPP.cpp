#include <iostream>
using namespace std;

int main()
{
	int a = 1;
	int* ptr = &a;

	int b = 2;
	int& ref = b;

	cout << a << *ptr << endl;
	cout << b << ref << endl;

	return 0;
}