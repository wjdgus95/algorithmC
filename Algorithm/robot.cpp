#pragma warning(disable: 4996)
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;
const int MAX = 110;

int n, m;
int d[2];
int dx[5] = { 0,0,0,1,-1 };
int dy[5] = { 0,1,-1,0,0 };
int cnt = 0;
int startX, startY, startD;
int endX, endY, endD;
int map[MAX][MAX];
int chk[MAX][MAX][4];

struct info {
	int x;
	int y;
	int dir;
};

void direction(int n) {
	if (n == 1) {
		d[0] = 3;
		d[1] = 4;
	}
	else if (n == 2) {
		d[0] = 3;
		d[1] = 4;
	}
	else if (n == 3) {
		d[0] = 1;
		d[1] = 2;
	}
	else if (n == 4) {
		d[0] = 1;
		d[1] = 2;
	}
}

void BFS(int x, int y, int dir) {
	queue<info> q;

	q.push({ x,y,dir });
	chk[x][y][dir] = 1;

	while (!q.empty()) {
		int curX = q.front().x;
		int curY = q.front().y;
		int curD = q.front().dir;

		q.pop();

		if (curX == endX && curY == endY && curD == endD) {
			// printf("%d %d %d\n", curX, curY, curD);
			printf("%d", chk[curX][curY][curD] - 1);
			return;
		}

		for (int i = 1; i <= 3; i++) {

			int nx = curX + dx[curD] * i;
			int ny = curY + dy[curD] * i;

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				break;
			}

			if (map[nx][ny] == 1) {
				break;
			}
			else if (chk[nx][ny][curD] == 0) {
				chk[nx][ny][curD] = chk[curX][curY][curD] + 1;
				q.push({ nx,ny,curD });
			}

		}//for

		direction(curD);
		for (int i = 0; i < 2; i++) {
			int nd = d[i];

			if (chk[curX][curY][nd] == 0) {
				chk[curX][curY][nd] = chk[curX][curY][curD] + 1;
				q.push({ curX,curY,nd });
			}

		}//for

	}//while

}
int main() {

	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	scanf("%d%d%d", &startX, &startY, &startD);

	scanf("%d%d%d", &endX, &endY, &endD);

	startX--;
	startY--;
	endX--;
	endY--;

	BFS(startX, startY, startD);

	return 0;
}