#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

/*
for loop �� ���� ��?
N^2 �� �� 100�� -> 0.5�� �ȿ� �϶�� �����ϱ� �翬�� ����

*/
int main() {
	int N; //N�� 100,000
	int S; //S�� 1�� -> integer�� ����

	cin >> N >> S;
	int num[100001] = { 0, };
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	int left = 0, right = 0, sum = 0, ans = N + 1;

	/*
	���� ���� right�Ǵ� left�� ���������� �ű�鼭 Ǯ��
	*/
	while (true) {	//right�� ���� �����ϸ� ����
		if (sum >= S) { //�κ����� S�̻��� ��
			ans = min(ans, right - left);
			//left�� ���ְ� left ����Ʈ�� ���������� �ű��. ( S���� ũ�ϱ� ���� ���� �������� ��쵵 Ȯ��)
			sum -= num[left++];
		}
		else if (right >= N) break;
		else {
			//�κ����� S�̸��� ��� right�� �����ְ� right ����Ʈ�� ���������� �ű��.
			sum += num[right++];
		}
	}

	printf("%d\n", ans == N + 1 ? 0 : ans);
	return 0;
}