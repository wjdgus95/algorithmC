#include <cstdio>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

const int MAX = 30;

int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, 1, -1, 0 };
int n;
int Map[MAX][MAX];
int chk[MAX][MAX];
vector <int> result;

int getGroup(int x, int y) {

	queue<pair<int, int>> q;

	q.push(make_pair(x, y));

	int cnt = 0;

	Map[x][y] = 0;
	cnt++;

	while (!q.empty()) {
		pair<int, int> p;
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int xx = x + dx[k];
			int yy = y + dy[k];

			if (Map[xx][yy] == 1) {
				cnt++;
				Map[xx][yy] = 0;
				q.push(make_pair(xx, yy));
			}
		}
	}
	return cnt;
}

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &Map[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (Map[i][j]) {
				result.push_back(getGroup(i, j));
			}
		}
	}

	sort(result.begin(), result.end());

	printf("%d\n", result.size());

	for (int i = 0; i < result.size(); i++) printf("%d\n", result[i]);

	return 0;
}