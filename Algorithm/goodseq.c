#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdbool.h>

int n;
int result[100];
int resultlen;
bool finish = false;

bool isPossible(int x, int length) {
	//result[x]�� ������ ��, ���� length�� �ߺ��� �ִ��� �Ǻ�

	for (int i = 0; i < length; i++) {
		if (result[x - i] != result[x - i - length])
			return true;
	}

	return false;
}

void getRes(int x) {
	//result[x] �����ϰ� res[x+1]���� �����س��� (res[x]~res[n-1])

	if (finish == true)return;

	if (x >= n) {
		for (int i = 0; i < n; i++) {
			printf("%d", result[i]);
		}
		printf("\n");

		finish = true;
		return;
	}
	for (int i = 1; i <= 3; i++) {
		result[x] = i;

		bool flag = false;

		for (int j = 1; j <= (x + 1) / 2; j++) {
			if (!isPossible(x, j)) {
				flag = true;
				break;
			}
		}

		if (flag == false) {
			getRes(x + 1);
		}
	}//for

}
int main() {

	scanf("%d", &n);
	getRes(0);

	return 0;
}