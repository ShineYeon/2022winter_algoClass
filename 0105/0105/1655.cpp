#include <iostream>
#include <queue>
using namespace std;

/*
매번 sort하는 것은 결코 해법이 아니다.
heap을 두개 만듦 (maxheap, minheap)
숫자가 들어오면 처음에는 max heap에 넣음. (max heap에서 top은 가장 큰 값을 의미)
다음 숫자가 들어오면 min heap에 넣음.
3번째 숫자가 들어오면 두 heap 중 사이즈가 작은 곳에 넣음
숫자가 들어올 때마다 사이즈 체크해서 작은 곳에 넣음

우리가 하고싶은 거는 작은 수는 max heap, 큰 수는 min heap에 넣고 싶은 것!
top을 봐 -> max heap의 top보다 min heap의 top이 더 커야함.
만약에 max heap의 top이 더 크다면? 두개를 바꿔
*/

priority_queue<int> Min;
priority_queue<int> Max;



int main() {
	int minTop, maxTop, minSize, maxSize;

	int N; //외치는 정수의 개수
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