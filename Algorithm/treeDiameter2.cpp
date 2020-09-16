#pragma warning(disable: 4996)
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;
const int MAX = 100010;

int n;
bool visited[MAX];
vector<pair<int, int>> tree[MAX];
int diameter = 0, far = 0;

void DFS(int x, int cost) {

	visited[x] = true;

	if (diameter < cost) {
		diameter = cost;
		far = x;
	}

	for (int i = 0; i < tree[x].size(); i++) {
		int next = tree[x][i].first;
		int next_cost = tree[x][i].second;

		if (!visited[next]) {
			DFS(next, cost + next_cost);
		}
	}
}

int main() {

	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++) {
		int x, y, cost;
		scanf("%d%d%d", &x, &y, &cost);

		tree[x].push_back(make_pair(y, cost));
		tree[y].push_back(make_pair(x, cost));
	}

	DFS(1, 0);

	memset(visited, false, sizeof(visited));
	diameter = 0;
	DFS(far, 0);

	printf("%d", diameter);

	return 0;
}