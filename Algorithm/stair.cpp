#pragma warning(disable: 4996)
#include <cstdio>

using namespace std;

const int MAX = 310;

int n;
int stair[MAX];
int dp[MAX];

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &stair[i]);
	}

	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];

	for (int i = 3; i <= n; i++){
		dp[i] = max(dp[i - 3] + stair[i] + stair[i - 1], dp[i - 2] + stair[i]);
	}

	printf("%d", dp[n]);

	return 0;
}