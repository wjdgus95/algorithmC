#pragma warning(disable: 4996)
#include<stdio.h>

int binarySearch(int arr[], int myStart, int myEnd, int value) {

	int start, end;
	int mid;

	if (arr[myStart] > value) {
		return -1;
	}

	if (arr[myEnd] < value) {
		return -1;
	}

	if (arr[myStart] == value)return myStart;
	if (arr[myEnd] == value)return myEnd;

	start = myStart;
	end = myEnd;

	while (start + 1 < end) {
		mid = (start + end) / 2;

		if (arr[mid] == value)return mid;
		else if (arr[mid] < value) {
			end = mid;
		}
		else if (arr[mid] > value) {
			start = mid;
		}

	}//while

	return -1;

}


int main() {

	int n, m;
	int arr[100];

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	scanf("%d", &m);

	int index = binarySearch(arr, 0, n - 1, m);

	if (index == -1)printf("X");
	else printf("%d", index);

	return 0;
}