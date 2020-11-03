#pragma warning(disable: 4996)
#include<stdio.h>

int main() {

	int n, m = 0;
	int k;
	int coin[15];

	scanf("%d%d", &n, &k);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &coin[i]);
	}

	while (k > 0) {
		
		for (int i = n; i >= 1; i--) {
			//주어진 동전이 k보다 큰게 없을때 주어진 동전 중 가장 큰 동전 선택
			if (k >= coin[i] && i == n) {
				k = k - coin[i];
				m++;
				break;
			}
			//주어진 동전이 k보다 커질 수 있을 때
			if (coin[i] <= k) {
				k = k - coin[i];
				m++;
				break;
			}
		}
	}//while

	printf("%d", m);

	return 0;
}