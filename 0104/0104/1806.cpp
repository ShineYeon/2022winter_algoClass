#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

/*
for loop 시 실패 왜?
N^2 일 때 100초 -> 0.5초 안에 하라고 했으니까 당연히 실패

*/
int main() {
	int N; //N은 100,000
	int S; //S는 1억 -> integer로 ㄱㅊ

	cin >> N >> S;
	int num[100001] = { 0, };
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	int left = 0, right = 0, sum = 0, ans = N + 1;

	/*
	때에 따라서 right또는 left를 오른쪽으로 옮기면서 풀이
	*/
	while (true) {	//right가 끝에 도달하면 종료
		if (sum >= S) { //부분합이 S이상일 때
			ans = min(ans, right - left);
			//left를 빼주고 left 포인트를 오른쪽으로 옮긴다. ( S보다 크니까 앞의 수를 제외했을 경우도 확인)
			sum -= num[left++];
		}
		else if (right >= N) break;
		else {
			//부분합이 S미만일 경우 right를 더해주고 right 포인트를 오른쪽으로 옮긴다.
			sum += num[right++];
		}
	}

	printf("%d\n", ans == N + 1 ? 0 : ans);
	return 0;
}