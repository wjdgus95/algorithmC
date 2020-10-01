#pragma warning(disable: 4996)
#include <cstdio>
#include <queue>

using namespace std;
const int MAX = 1010;

int m, n, h;
int cnt = 0;
int tomato[MAX][MAX];
int chk[MAX][MAX];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

queue<pair<int,int>> q;

void BFS() {

	while (!q.empty()) {

		int curX = q.front().first;
		int curY = q.front().second;

		q.pop();
		cnt = chk[curX][curY];

		for (int i = 0; i < 4; i++) {

			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (nx<0 || nx>n - 1 || ny<0 || ny>m - 1 )continue;

			if (chk[nx][ny] == 1 || tomato[nx][ny] == 1)continue;
			else if (chk[nx][ny] == 0) {
				chk[nx][ny] = chk[curX][curY] + 1;
				tomato[nx][ny] = 1;
				q.push(make_pair(nx,ny));
			}

		}//for

	}//while

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tomato[i][j] == 0) {
				printf("-1");
				return;
			}
		}
	}//for

	printf("%d", cnt - 1);

}

int main() {

	scanf("%d%d", &m, &n);

	bool zero = true;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
				scanf("%d", &tomato[i][j]);

				if (tomato[i][j] == 0)zero = false;

				if (tomato[i][j] == -1) {
					chk[i][j] = 1;
				}
				if (tomato[i][j] == 1) {
					q.push(make_pair(i,j));
					chk[i][j] = 1;
				}

			
		}
	}//for

	if(zero) {
		printf("0");
		return 0;
	}

	BFS();

	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", chk[i][j]);
		}
		printf("\n");
	}

	return 0;
}