#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool putcolor(int u, int i, int n, int g[n][n], int color[n]) {
	for (int v = 0; v < n; v++) {
		if (g[u][v] != 0 && color[v] != -1 && color[v] == i) {
			return false;
		}
	}
	return true;
}

void graphcoloring(int u, int n, int g[n][n], int color[n]) {
	for (int i = 0; i < n; i++) {
		if (putcolor(u, i, n, g, color)) {
			color[u] = i;
			if (u == n-1) {
				for (int j = 0; j < n; j++) {
					printf("vertex %d colored c%d\n", j, color[j]);
				}
				exit(0);
			} else {
				graphcoloring(u+1, n, g, color);
			}
		}
	}
	color[u] = -1;
}

int main() {
	int n;
	scanf("%d", &n);
	int g[n][n];
	for (int u = 0; u < n; u++) {
		for (int v = 0; v < n; v++) {
			scanf("%d", &g[u][v]);
		}
	}
	int color[n];
	for (int u = 0; u < n; u++) {
		color[u] = -1;
	}
	graphcoloring(0, n, g, color);
	return 0;
}