#include <iostream>
using namespace std;

int n, A, B, C;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %d", &A);
		if (A == 1)
			scanf(" %d", &B); //B:»çÅÁÀÇ ¼øÀ§
		else
			scanf(" %d %d", &B, &C); //B:»çÅÁÀÇ ¸À, C:»çÅÁ ¼ö
	}
}
