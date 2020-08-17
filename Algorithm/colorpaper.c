#pragma warning(disable: 4996)
#include<stdio.h>
int main() {

	int n;
	int a, b, c, d;
	int squ[101][101];
	int size[100] = { 0 };
	int cnt = 1;

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			squ[i][j] = 0;
		}
	}

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &a, &b, &c, &d);

		for (int j = a; j < a + c; j++) {
			for (int k = b; k < b + d; k++) {
				squ[j][k] = cnt;
			}
		}
		cnt++;
	}//for

	for (int k = 1; k <= n; k++) {

		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 101; j++) {
				if (squ[i][j] == k) size[k - 1]++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d\n", size[i]);
	}

	return 0;
}