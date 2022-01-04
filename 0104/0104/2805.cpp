#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>


using namespace std;

#define MAXSIZE 200000000
#define MAXN 1000000



/*
lb�� ����, ub�� �Ʒ��� ��� �ű�� ���ܱ� ���̸� ������ (binary ���)
*/

int N, M;
int wood[MAXN];

bool fmax(int m) {
	long long h = 0;

	//������ size��ŭ �ڸ��� ���� �������� ���Ѵ�.
	for (int i = 0; i < N; i++)
		h += max(0, wood[i] - m); 
	//0�̶� ���ϴ� ������ ���ܱ� ���̰� �������� ���� ��츦 ���
	
	if (h >= M) return true;
	return false;
	
}

int main() {
	//lb:lower bound, ub:upper bound (lb�� 0�̶�� ���� ���, ub�� ���� ū ����)
	int lb = 0, ub = 0, m, ans;
	cin >> N >> M;


	//���� ����� �ް� lb, ub ���� ����
	for (int i = 0; i < N; i++) {
		cin >> wood[i];
		ub = max(ub, wood[i]);
	}

	//lb�� ub�� ���� �������� ����
	while (lb + 1 < ub) {
		m = lb + (ub - lb) / 2;
		if (fmax(m)) lb = m;
		else ub = m;

		
	}

	printf("%d\n", lb);
	return 0;

}

