#pragma warning(disable: 4996)
#include <stdio.h>

int n, r;
char arr[100];
int check[100] = { 0, };

void print(int inx) {
	char start = 'a';

	if (inx >= r) {
		for (int i = 0; i < r; i++) {
			printf("%c", arr[i]);
		}
		printf("\n");
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (check[i] == 0) {
				arr[inx] = 'a' + i;

				check[i] = 1;
				print(inx + 1);
				check[i] = 0;
			}
		}


	}//if
}

int main() {

	scanf("%d%d", &n, &r);

	print(0);

	return 0;
}