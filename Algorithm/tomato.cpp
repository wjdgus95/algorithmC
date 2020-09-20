#pragma warning(disable: 4996)
#include <cstdio>
#include <queue>

using namespace std;
const int MAX = 110;

int m, n, h;
int cnt = 0;
int tomato[MAX][MAX][MAX];
int chk[MAX][MAX][MAX];
int dx[6] = { 0,0,0,0,1,-1 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 1,-1,0,0,0,0 };

struct info {
	int x;
	int y;
	int z;
};

queue<info> q;

void BFS() {

	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		int curZ = q.front().z;

		q.pop();
		cnt = chk[curX][curY][curZ];

		for (int i = 0; i < 6; i++) {

			int nx = curX + dx[i];
			int ny = curY + dy[i];
			int nz = curZ + dz[i];

			if (nx<0 || nx>m - 1 || ny<0 || ny>n - 1 || nz<0 || nz> h - 1)continue;

			if (chk[nx][ny][nz] == 1 || tomato[nx][ny][nz] == 1)continue;
			else if (chk[nx][ny][nz] == 0) {
				chk[nx][ny][nz] = chk[curX][curY][curZ] + 1;
				tomato[nx][ny][nz] = 1;
				q.push({ nx,ny,nz });
			}

		}//for

	}//while

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (tomato[k][j][i] == 0) {
					printf("-1");
					return;
				}
			}
		}
	}//for

	printf("%d", cnt - 1);

}

int main() {

	scanf("%d%d%d", &m, &n, &h);

	bool zero = true;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				scanf("%d", &tomato[k][j][i]);

				if (tomato[k][j][i] == 0)zero = false;

				if (tomato[k][j][i] == -1) {
					chk[k][j][i] = 1;
				}
				if (tomato[k][j][i] == 1) {
					q.push({ k,j,i });
					chk[k][j][i] = 1;
				}

			}
		}
	}//for

	if (zero) {
		printf("0");
		return 0;
	}

	BFS();

	return 0;
}