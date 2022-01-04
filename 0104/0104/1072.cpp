#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

#define MAXSIZE 1000000000

long long X, Y; // 숫자범위는 10억이지만 100을 곱해야 하므로 long으로 잡음

bool sol(int m) {
	if (Y * 100 / X < (Y + m) * 100 / (X + m)) return true;
	else return false;
}

/*
ub는 10억번임
*/
int main() {
	int lb = 0, ub = MAXSIZE, m;
	cin >> X >> Y;

	if (Y * 100 / X >= 99) {
		printf("-1");
		return 0;
	}
	
	while (lb+1<ub) {
		m = lb + (ub - lb) / 2;
		if (sol(m)) ub = m;
		else lb = m;

		
	}

	cout << ub << "\n";
	return 0;
}