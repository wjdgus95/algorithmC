#include <cstdio>
#include <utility>
#include <queue>

using namespace std;
const int MAX = 1010;

int n, m;
int map[MAX][MAX];
int chk[MAX][MAX];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int BFS(int x, int y) {
	queue<pair<int, int>> q;
	int dis = 1;

	q.push(make_pair(x, y));
	chk[x][y] = dis;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx >= 0 && xx <= n - 1 && yy >= 0 && y <= m - 1) {
				if (map[xx][yy] == 0 && chk[xx][yy] == 0) {
					chk[xx][yy] = chk[x][y] + 1;
					q.push(make_pair(xx, yy));
				}
			}

		}//for

	}//while

	return chk[0][m - 1];
}
int main() {

	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	printf("%d\n", BFS(n - 1, 0) - 1);

	// for(int i=0;i<n;i++){
	//   for(int j=0;j<m;j++){
	//     printf("%d ",chk[i][j]);
	//   }
	//   printf("\n");
	// }

	return 0;
}