// 0104.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	long long dp[91] = { 0, };
	dp[0] = 0;
	dp[1] = 1;
	int n;
	cin >> n;
	
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n] << "\n";
	return 0;
	
}

