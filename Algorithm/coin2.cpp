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
			//�־��� ������ k���� ū�� ������ �־��� ���� �� ���� ū ���� ����
			if (k >= coin[i] && i == n) {
				k = k - coin[i];
				m++;
				break;
			}
			//�־��� ������ k���� Ŀ�� �� ���� ��
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