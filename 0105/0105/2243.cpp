#include <iostream>
using namespace std;

int n, A, B, C;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %d", &A);
		if (A == 1)
			scanf(" %d", &B); //B:������ ����
		else
			scanf(" %d %d", &B, &C); //B:������ ��, C:���� ��
	}
}
