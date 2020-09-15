#pragma warning(disable: 4996)
#include <stdio.h>

//const int MAX = 100;

struct Tree {

	char left;
	char right;

};

Tree tree[50];

void preorder(char x) {

	if (x == '.') {
		printf("%c ", x);
	}
	else {

		printf("%c ", x);

		if (tree[x-'A'].left != '.') {
			preorder(tree[x - 'A'].left);
		}

		if (tree[x - 'A'].right != '.') {
			preorder(tree[x - 'A'].right);
		}

	}

}

void inorder(char x) {

	if (x == '.') {
		printf("%c ", x);
	}
	else {

		if (tree[x - 'A'].left != '.') {
			inorder(tree[x - 'A'].left);
		}

		printf("%c ", x);

		if (tree[x - 'A'].right != '.') {
			inorder(tree[x - 'A'].right);
		}

	}

}


void postorder(char x) {

	if (x == '.') {
		printf("%c ", x);
	}
	else {

		if (tree[x - 'A'].left != '.') {
			postorder(tree[x - 'A'].left);
		}

		if (tree[x - 'A'].right != '.') {
			postorder(tree[x - 'A'].right);
		}

		printf("%c ", x);

	}

}
int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		char a, b, c;

		scanf("%c%c%c", &a, &b, &c);

		tree[a-'A'].left = b;
		tree[a - 'A'].right = c;
	}

	preorder('A');
	printf("\n");
	inorder('A');
	printf("\n");
	postorder('A');
	printf("\n");

	return 0;
}