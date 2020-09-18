#pragma warning(disable: 4996)
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;
const int MAX = 110;

int n, m;
int arr[MAX][MAX];
bool chk[MAX][MAX];
int cheeze[10050];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int cnt = 0;
int hour = 0;

int counting() {
	cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1)cnt++;
		}
	}

	return cnt;
}

void BFS(int x, int y) {
	queue<pair<int, int>> q;
	// chk[x][y] ={0,};

	q.push(make_pair(x, y));
	chk[x][y] = true;

	while (!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (arr[nx][ny] == 0 && !chk[nx][ny]) {
					// arr[nx][ny] = -1;
					chk[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
				if (arr[nx][ny] == 1) {
					arr[nx][ny] = -1;
				}
			}

		}//for

	}//while

}

void melt() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == -1) {
				arr[i][j] = 0;
			}
		}
	}

}

int main() {

	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	int index = 0;
	while (true) {
		if (counting() <= 0)break;

		cheeze[index] = counting();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				chk[i][j] = false;
			}
		}

		BFS(0, 0);
		melt();

		index++;
		hour++;
		// printf("%d %d\n",index,hour);
	}

	// printf("%d\n",hour);
	// for(int i=0;i<index;i++){
	//   printf("%d ",cheeze[i]);
	// }

	printf("%d\n%d\n", hour, cheeze[index - 1]);
	return 0;
}