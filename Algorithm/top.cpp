#pragma warning(disable: 4996)
#include<stdio.h>
#include<stack>
#include<utility>

using namespace std;

int main() {

	int n, m;

	stack<pair<int, int>> s;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &m);

		while (!s.empty()) {
			if (s.top().second > m) {
				printf("%d ", s.top().first + 1);
				break;
			}


			s.pop();
		}

		if (s.empty()) {
			printf("0 ");
		}

		s.push(make_pair(i, m));
	}//for



	return 0;
}