#include <cstdio>
#include <cstring> // memset
#include <queue>
#include <utility>

using namespace std;
const int MAX = 1050;

int n, m;
int Map[MAX][MAX];
bool check[MAX][MAX];
int c1[MAX][MAX], c2[MAX][MAX];
int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, -1, 1, 0 };
int result;

void getResult(int x, int y, int cost[MAX][MAX]) {

	queue<pair<int, int>> q;

	q.push(make_pair(x, y));
	check[x][y] = true;

	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {

			int xx = curX + dx[k];
			int yy = curY + dy[k];

			if (0 <= xx && xx < n && 0 <= yy && yy < m && !check[xx][yy]) {
				check[xx][yy] = true;
				cost[xx][yy] = cost[curX][curY] + 1;

				if (Map[xx][yy] == 0)
					q.push(make_pair(xx, yy));
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			scanf("%d", &Map[i][j]);
	}

	getResult(n - 1, 0, c1);

	memset(check, 0, sizeof(check));

	getResult(0, m - 1, c2);

	result = 987987987;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (Map[i][j] && c1[i][j] > 0 && c2[i][j] > 0)
				result = min(result, c1[i][j] + c2[i][j]);
		}
	}
	printf("%d\n", result);

	return 0;
}