#pragma warning(disable: 4996)
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int tree[1000001];
int N, M;
long long sum, ans;
long long HIGH = 1000000000;

void getTree(long long s, int e) {
	if (s <= e) {
		long long mid = (s + e) / 2;
		sum = 0;
		for (int i = 1; i <= N; i++) {
			if (tree[i] > mid) {
				sum += tree[i] - mid;
			}
		}

		if (sum >= M) {
			ans = mid;
			getTree(mid + 1, e);
		}
		else {
			getTree(s, mid - 1);
		}
	}
}


int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &tree[i]);
	}

	sort(tree + 1, tree + 1 + N);
	getTree(0, HIGH);
	printf("%lld", ans);

	return 0;

}