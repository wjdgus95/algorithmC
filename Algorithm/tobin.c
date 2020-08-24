#pragma warning(disable: 4996)
#include<stdio.h>

int n, k;
int arr[35];

void tobin(int index, int cnt) {

	if (index >= n) {
		if (cnt == k) {
			for (int i = 0; i < n; i++) {
				printf("%d", arr[i]);
			}
			printf("\n");
		}
		return;
	}
	else {
		if (cnt < k) {
			arr[index] = 1;
			tobin(index + 1, cnt + 1);
		}

		arr[index] = 0;
		tobin(index + 1, cnt);
	}

}

int main() {
	scanf("%d%d", &n, &k);
	tobin(0, 0);

	return 0;
}