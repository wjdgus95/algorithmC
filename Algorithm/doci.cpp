#include <cstdio>
#include <queue>

using namespace std;
const int MAX = 60;

int r, c;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int startI, startJ, endI, endJ;
char map[MAX][MAX];
int chkWater[MAX][MAX];
int chkGo[MAX][MAX];

queue<pair<int, int>> q;

void BFSwater() {

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx <= r - 1 && ny >= 0 && ny <= c - 1) {
				if (chkWater[nx][ny] == 0 && map[nx][ny] != 'D') {
					chkWater[nx][ny] = chkWater[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}//for

	}

}

void BFSgo(int x, int y) {
	queue<pair<int, int>> q2;

	q2.push(make_pair(x, y));
	chkGo[x][y] = 1;

	while (!q2.empty()) {

		int x = q2.front().first;
		int y = q2.front().second;

		q2.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx <= r - 1 && ny >= 0 && ny <= c - 1) {
				if (chkGo[nx][ny] == 0) {
					if (chkWater[nx][ny] > chkGo[x][y] - 1 || chkWater[nx][ny] == 0) {
						chkGo[nx][ny] = chkGo[x][y] + 1;
						q2.push(make_pair(nx, ny));
					}
				}
			}

		}//for

	}//while
}

int main() {

	scanf("%d%d", &r, &c);

	// '*':¹° | 'X':µ¹ | 'D':ºñ¹ö±¼ | 'S':°í½¿µµÄ¡
	for (int i = 0; i < r; i++) {
		scanf("%s", &map[i]);
	}//for

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {

			if (map[i][j] == '*') {
				q.push(make_pair(i, j));
				chkWater[i][j] = 1;
			}
			else if (map[i][j] == 'X') {
				chkWater[i][j] = 1;
				chkGo[i][j] = 1;
			}
			else if (map[i][j] == 'S') {
				startI = i;
				startJ = j;
			}
			else if (map[i][j] == 'D') {
				endI = i;
				endJ = j;
				// chkWater[i][j]=1;
				// chkGo[i][j]=0;
			}

		}
	}

	BFSwater();
	BFSgo(startI, startJ);

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("%d ", chkWater[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("%d ", chkGo[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	if (chkGo[endI][endJ] == 0)printf("KAKTUS");
	else printf("%d", chkGo[endI][endJ] - 1);

	return 0;
}