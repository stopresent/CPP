#include <iostream>
using namespace std;
#include <list>
#include<utility>
#include <vector>

/*
LIS (Longest Increasing Sequence)

���� ��ȹ�� (DP)

Seq : 1 9 2 5 7

�κ� ���� : �Ϻ�(0�� �̻�) ���ڸ� ����� ���� ����

ex) 1 2 5

ex) 1 9 5 7

�� ���� �κ� ����

ex) 1 2 5

LIS : ���� �� [�� ���� �κ� ����]�� ����

ex) 1 2 5 7 = ���� 4

*/

vector<int> seq;

int LIS()
{

}

int main()
{
	seq = vector<int>{ 1, 9, 2, 5, 7 };

	return 0;
}