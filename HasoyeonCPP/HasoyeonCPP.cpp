#include <iostream>
using namespace std;
#include <list>
#include<utility>
#include <vector>

/*
LIS (Longest Increasing Sequence)

동적 계획법 (DP)

Seq : 1 9 2 5 7

부분 수열 : 일부(0개 이상) 숫자를 지우고 남은 수열

ex) 1 2 5

ex) 1 9 5 7

순 증가 부분 수열

ex) 1 2 5

LIS : 제일 긴 [순 증가 부분 수열]의 길이

ex) 1 2 5 7 = 길이 4

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