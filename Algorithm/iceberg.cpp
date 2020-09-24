#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;
const int MAX = 350;

int n, m;
int year = 0;
int cnt = 0;
int cntIce = 0;
int ice[MAX][MAX];
bool meltedIce[MAX][MAX];
bool chk[MAX][MAX];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int counting() {
	cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ice[i][j] != 0)cnt++;
		}
	}
	return cnt;
}

void BFS(int x, int y) {

	queue<pair<int, int>> q;
	// cntIce=0;

	q.push(make_pair(x, y));
	chk[x][y] = true;
	cntIce++;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx <= n - 1 && ny >= 0 && ny <= m - 1) {

				if (ice[nx][ny] != 0 && !chk[nx][ny]) {
					q.push(make_pair(nx, ny));
					chk[nx][ny] = true;
				}

				if (ice[nx][ny] == 0 && !meltedIce[nx][ny]) {
					if (ice[x][y] - 1 <= 0) {
						ice[x][y] = 0;
						meltedIce[x][y] = true;
					}
					else {
						ice[x][y]--;
					}
				}

			}//if
		}//for

	}

}

int main() {

	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &ice[i][j]);
		}
	}

	while (true) {
		cntIce = 0;
		if (counting() <= 0)break;

		memset(chk, false, sizeof(chk));
		memset(meltedIce, false, sizeof(meltedIce));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (ice[i][j] != 0 && !chk[i][j]) {
					BFS(i, j);



				}//if
			}
		}

		// for(int i=0;i<n;i++){
		//   for(int j=0;j<m;j++){
		//     printf("%d ",ice[i][j]);
		//   }
		//   printf("\n");
		// }
		// printf("\n");

		if (cntIce >= 2) {
			printf("%d", year);
			return 0;
		}

		year++;

	}//while

	printf("0");

	return 0;
}