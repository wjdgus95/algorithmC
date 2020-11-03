#pragma warning(disable: 4996)

#include<stdio.h>

int main() {

	int i, n, m = 0, k;
	int coin[11];

	scanf("%d%d", &n, &k);

	for (i = 1; i <= n; i++) scanf("%d", &coin[i]);


	for (i = n; i > 0; i--) {
		m += k / coin[i];
		k %= coin[i];
	}

	printf("%d", m);

	return 0;
}