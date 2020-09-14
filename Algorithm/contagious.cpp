#include <cstdio>
#include <queue>

using namespace std;
const int MAX = 100010;

int n, k;
int town[MAX];
int chk[MAX];

void BFS(int x) {

	queue<int> q;

	q.push(x);
	chk[x] = 1;

	while (!q.empty()) {

		int cur = q.front();
		q.pop();

		int a = cur * 2;
		int b = cur / 3;

		if (a > 0 && a <= n && chk[a] == 0) {
			q.push(a);
			chk[a] = 1;
		}

		if (b > 0 && b <= n && chk[b] == 0) {
			q.push(b);
			chk[b] = 1;
		}

	}//while

}
int main() {

	int cnt = 0;
	scanf("%d%d", &n, &k);
	BFS(k);

	for (int i = 1; i <= n; i++) {
		if (chk[i] == 0)cnt++;
	}
	printf("%d", cnt);

	return 0;
}