/* new 와 delete 의 사용 */
#include <iostream>
using namespace std;

int CreateNewArray()
{
	int arr_size;

	std::cout << "array size : ";
	std::cin >> arr_size;

	int* list = new int[arr_size];

	for (int i = 0; i < arr_size; i++)
		std::cin >> list[i];

	for (int i = 0; i < arr_size; i++)
		std::cout << i << "th element of list : " << list[i] << std::endl;
	
	delete[] list;
	return 0;
}

int CreateNew()
{
	int* p = new int;
	*p = 10;

	std::cout << *p << std::endl;

	delete p;

	return 0;
}

int main()
{
	CreateNew();
	CreateNewArray();

	return 0;
}

// new 는 heap영역에 생김
