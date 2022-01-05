#include <iostream>
#include <queue>
using namespace std;

/*
�Ź� sort�ϴ� ���� ���� �ع��� �ƴϴ�.
heap�� �ΰ� ���� (maxheap, minheap)
���ڰ� ������ ó������ max heap�� ����. (max heap���� top�� ���� ū ���� �ǹ�)
���� ���ڰ� ������ min heap�� ����.
3��° ���ڰ� ������ �� heap �� ����� ���� ���� ����
���ڰ� ���� ������ ������ üũ�ؼ� ���� ���� ����

�츮�� �ϰ���� �Ŵ� ���� ���� max heap, ū ���� min heap�� �ְ� ���� ��!
top�� �� -> max heap�� top���� min heap�� top�� �� Ŀ����.
���࿡ max heap�� top�� �� ũ�ٸ�? �ΰ��� �ٲ�
*/

priority_queue<int> Min;
priority_queue<int> Max;



int main() {
	int minTop, maxTop, minSize, maxSize;

	int N; //��ġ�� ������ ����
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);

		if (Max.size() > Min.size())
			Min.push(-x);
		else
			Max.push(x);

		if (Max.size() > 0 && Min.size() > 0) {
			if (Max.top() > -Min.top()) {
				maxTop = Max.top();
				minTop = -Min.top();
				Max.pop();
				Min.pop();
				Max.push(minTop);
				Min.push(-maxTop);

			}
		}


		printf("%d\n", Max.top());

	}
}