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

int cache[100];
vector<int> seq;

int LIS(int pos)
{
	// 기저 사항 (예외 처리)
	if (pos == seq.size() - 1)
		return 1;

	// 캐시 확인
	int& ret = cache[pos];
	if (ret != -1)
		return ret;

	// 구하기

	// Seq : 1 9 2 5 7
	// 1 9 = 2
	// 1 2 5 7 = 4
	// 1 5 7 = 3
	// 1 7 = 2

	// 최소 seq[pos]는 있으니 1부터 시작
	ret = 1;

	// 구하기
	for (int next = pos + 1; next < seq.size(); next++)
		if (seq[pos] < seq[next])
			ret = max(ret, 1 + LIS(next));

	return ret;
}

int main()
{
	::memset(cache, -1, sizeof(cache));

	seq = vector<int>{ 1, 9, 2, 5, 7 };

	int ret = 0;
	for (int pos = 0; pos < seq.size(); pos++)
		ret = max(ret, LIS(pos));
	return 0;
}

// 재귀
// 캐싱
// 루프로 베스트 케이스 찾기
