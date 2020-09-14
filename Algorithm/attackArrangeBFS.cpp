#include <cstdio>
#include <queue>

using namespace std;
const int MAX = 110;

int n;
int a, b, c;
int map[MAX][MAX];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void BFS(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	map[x][y] = 0;

	while (!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (map[nx][ny] == 0) {
					if (map[x][y] == c) {
						return;
					}
					else {
						map[nx][ny] = map[x][y] + 1;
						q.push(make_pair(nx, ny));
					}
				}
			}

		}
	}

}

int main() {

	scanf("%d", &n);
	scanf("%d%d%d", &a, &b, &c);

	BFS(a - 1, b - 1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == (a - 1) && j == (b - 1))printf("x ");
			else printf("%d ", map[i][j]);
		}
		printf("\n");
	}

	return 0;
}