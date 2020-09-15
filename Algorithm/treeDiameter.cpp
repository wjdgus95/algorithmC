#pragma warning(disable: 4996)
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;
const int MAX = 100010;

int n;
bool visitied[MAX];
vector<pair<int, int>> tree[MAX];
int diameter = 0, far = 0;

void DFS(int x, int cost) {

	visitied[x] = true;

	if (diameter < cost) {
		diameter = cost;
		far = x;
	}

	for (int i = 0; i < tree[x].size(); i++) {
		int next = tree[x][i].first;
		int next_cost = tree[x][i].second;

		if (!visitied[next]) {
			DFS(next, cost + next_cost);
		}
	}
}

int main() {

	scanf("%d", &n);

	while (n-- > 0) {
		int x;
		scanf("%d", &x);

		while (1) {
			int y, c;
			scanf("%d", &y);
			if (y == -1)break;

			scanf("%d", &c);
			tree[x].push_back(make_pair(y, c));
		}

	}//while

	DFS(1, 0);

	//for (int i = 1; i <= n; i++)visitied[i] = false;
	memset(visitied, false, sizeof(visitied));
	diameter = 0;
	DFS(far, 0);

	printf("%d", diameter);

	return 0;
}