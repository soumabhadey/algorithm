#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void nqueens(bool *solved, int k, int n, int x[n]);
bool place(int k, int i, int n, int x[n]);

int main() {
	printf("Enter number of queens: ");
	int n;
	scanf("%d", &n);

	int x[n];

	bool solved = false;
	nqueens(&solved, 0, n, x);

	if (!solved) {
		printf("No solution");
	}

	return 0;
}

void nqueens(bool *solved, int k, int n, int x[n]) {
	for (int i = 0; i < n; ++i) {
		if (place(k, i, n, x)) {
			x[k] = i;
			if (k == n-1) {
				*solved = true;
				for (int j = 0; j < n; j++) {
					printf("%d ", x[j]);
				}
				printf("\n");
				return;
			}
			else {
				nqueens(solved, k+1, n, x);
			}
		}
	}
}

bool place(int k, int i, int n, int x[n]) {
	for (int j = 0; j < k; ++j) {
		if (x[j] == i || abs(j-k) == abs(x[j]-i)) {
			return false;
		}
	}
	return true;
}