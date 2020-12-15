#pragma warning(disable: 4996)
#include<cstdio>
#include<algorithm>

using namespace std;

int n, m;
int arr[100010];
int num;

int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + n);

	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		scanf("%d", &num);

		printf("%d\n", binary_search(arr, arr+n, num));
	}

	return 0;
}