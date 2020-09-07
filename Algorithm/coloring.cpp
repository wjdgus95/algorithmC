#include <cstdio>
#include <vector>
#include <stdbool.h>

using namespace std;
const int MAX = 100010;

int n, m;
vector<int> graph[MAX];
int visited[MAX] = { 0, };
bool flag = true;

void DFS(int x, int color) {

	visited[x] = color;

	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];

		if (visited[y] == color) {
			flag = false;
			return;
		}
		else if (visited[y] == 0) {
			DFS(y, color * -1);
		}

	}//for

}

int main() {

	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	DFS(0, 1);

	if (!flag) {
		printf("NO");
	}
	else {
		printf("YES");
	}

	return 0;
}