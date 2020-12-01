#pragma warning(disable: 4996)

#include<stdio.h>

const int MAX = 10010;

int cnt[MAX];
int n, num;

int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		cnt[num]++;
	}

	for (int i = 0; i < MAX; i++) {
		if (cnt[i] == 0)continue;

		for (int j = 0; j < cnt[i]; j++)printf("%d\n", i);

	}

	return 0;
}
