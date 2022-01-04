#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>


using namespace std;

#define MAXSIZE 200000000
#define MAXN 1000000



/*
lb를 위로, ub를 아래로 계속 옮기며 절단기 높이를 조정함 (binary 방법)
*/

int N, M;
int wood[MAXN];

bool fmax(int m) {
	long long h = 0;

	//나무를 size만큼 자르고 남은 나머지를 더한다.
	for (int i = 0; i < N; i++)
		h += max(0, wood[i] - m); 
	//0이랑 비교하는 이유는 절단기 높이가 나무보다 높을 경우를 대비
	
	if (h >= M) return true;
	return false;
	
}

int main() {
	//lb:lower bound, ub:upper bound (lb는 0이라는 것이 명백, ub는 제일 큰 나무)
	int lb = 0, ub = 0, m, ans;
	cin >> N >> M;


	//나무 사이즈를 받고 lb, ub 최종 선택
	for (int i = 0; i < N; i++) {
		cin >> wood[i];
		ub = max(ub, wood[i]);
	}

	//lb랑 ub가 차이 날때까지 루프
	while (lb + 1 < ub) {
		m = lb + (ub - lb) / 2;
		if (fmax(m)) lb = m;
		else ub = m;

		
	}

	printf("%d\n", lb);
	return 0;

}

