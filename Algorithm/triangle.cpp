#pragma warning(disable: 4996)
#include <cstdio>

using namespace std;

int n;
int tri[510][510];

int max(int a, int b) {

	return a > b ? a : b;
}

int main() {

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &tri[i][j]);
		}
	}//for

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) {
				tri[i][j] = tri[i][j] + tri[i - 1][j];
			}
			else if (j == n) {
				tri[i][j] = tri[i][j] + tri[i - 1][j-1];
			}
			else {
				tri[i][j] = tri[i][j] + max(tri[i - 1][j], tri[i - 1][j - 1]);
			}
		}//
	}//for

	int maxNum = -1000;

	for (int i = 1; i <= n; i++) {
		maxNum = max(maxNum, tri[n][i]);
	}

	printf("%d", maxNum);

	return 0;
}