#pragma warning(disable: 4996)
#include <stdio.h>

int flag = 1;
int chul[5][5];
int com[5][5];

void bingo() {
	int cnt = 0;
	int sum = 0;

	for (int i = 0; i < 5; i++) {
		if (chul[i][0] == 0 && chul[i][1] == 0 && chul[i][2] == 0 && chul[i][3] == 0 && chul[i][4] == 0) cnt++;
	}//for

	for (int i = 0; i < 5; i++) {
		if (chul[0][i] == 0 && chul[1][i] == 0 && chul[2][i] == 0 && chul[3][i] == 0 && chul[4][i] == 0) cnt++;
	}//for

	for (int i = 0; i < 5; i++)
		sum = sum + chul[i][i];

	if (sum == 0)cnt++;

	sum = 0;

	sum = 0;
	for (int i = 0; i < 5; i++)
		sum = sum + chul[i][4 - i];

	if (sum == 0)cnt++;

	if (cnt >= 3)flag = 0;
}

void change(int n) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (n == chul[i][j]) {
				chul[i][j] = 0;
				return;
			}
		}
	}
}

int main() {

	int target;
	int count = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &chul[i][j]);
		}
	}

	for (int i = 0; i < 25; i++) {
		scanf("%d", &target);

		change(target);
		bingo();
		if (flag == 0) {
			printf("%d", i+1);
			return 0;
		}
	}

	return 0;
}