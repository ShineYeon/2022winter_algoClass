#include <iostream>
using namespace std;
#include <string>
#include <set>

#define MAXN 10

int n, k;
int card[MAXN];
bool visit[MAXN];
set<string> S;


void backtracking(int idx, string numStr) {
	if (idx == k) {
		S.insert(numStr);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			backtracking(idx + 1, numStr + to_string(card[i]));
			visit[i] = false;
		}
	}
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf(" %d", &card[i]);
	}

	backtracking(0, "");
	printf("%d\n", (int)S.size());

	return 0;
	
}