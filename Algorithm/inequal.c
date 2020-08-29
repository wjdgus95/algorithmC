#pragma warning(disable: 4996)
#include<stdio.h>
#include<string.h>

int n;
char com[100000];
char max[100000];
char min[100000];
int checkMax[100000] = { 0, };
int checkMin[100000] = { 0, };
int printMax = 0;
int printMin = 0;

void inequalMax(int index) {

	if (printMax == 1) {
		return;
	}

	if (index > n) {
		for (int i = 0; i < n + 1; i++) {
			printf("%d", max[i]);
		}
		printf("\n");

		printMax = 1;
	}
	else {
		for (int i = 9; i >=0; i--) {
			max[index] = i;

			if (checkMax[i] != 1) {

				int flag = 0;
				if (index == 0)flag = 1;
				if (com[index - 1] == '>') {
					if (max[index - 1] > max[index])flag = 1;
				}
				else {
					if (max[index - 1] < max[index])flag = 1;
				}

				if (flag == 1) {
					checkMax[i] = 1;
					inequalMax(index + 1);
					checkMax[i] = 0;
				}
			}
		}
	}

}

void inequalMin(int index) {

	if (printMin == 1) {
		return;
	}

	if (index > n) {
		for (int i = 0; i < n + 1; i++) {
			printf("%d", min[i]);
		}
		printf("\n");

		printMin = 1;
	}
	else {
		for (int i = 0; i <10; i++) {
			min[index] = i;

			if (checkMin[i] != 1) {

				int flag = 0;
				if (index == 0)flag = 1;
				if (com[index - 1] == '>') {
					if (min[index - 1] > min[index])flag = 1;
				}
				else {
					if (min[index - 1] < min[index])flag = 1;
				}

				if (flag == 1) {
					checkMin[i] = 1;
					inequalMin(index + 1);
					checkMin[i] = 0;
				}
			}
		}
	}

}

int main() {

	scanf("%d", &n);
	scanf("%s", com);

	inequalMax(0);
	inequalMin(0);

	return 0;
}