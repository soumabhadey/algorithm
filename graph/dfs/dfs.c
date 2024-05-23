#include <stdio.h>
#include <limits.h>

void dfsvisit(int u, int *time, int n, int g[n][n], char color[n], int start[n], int finish[n], int parent[n]) {
	color[u] = 'g';
	start[u] = *time = *time + 1;
	printf("%d ", u);

	for (int v = 0; v < n; v++) {
		if (g[u][v] != 0 && color[v] == 'w') {
			parent[v] = u;
			dfsvisit(v, time, n, g, color, start, finish, parent);
		}
	}
	color[u] = 'b';
	finish[u] = *time = *time + 1;
}

void dfs(int n, int g[n][n]) {
	int time = 0;
	char color[n];
	int start[n];
	int finish[n];
	int parent[n];

	for (int i = 0; i < n; i++) {
		color[i] = 'w';
		parent[i] = -1;
	}
	int k = 0;
	for (int u = 0; u < n; u++) {
		if (color[u] == 'w') {
			k++;
			printf("Tree %d: ", k);
			dfsvisit(u, &time, n, g, color, start, finish, parent);
			printf("\n");
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);

	int g[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &g[i][j]);
		}
	}

	dfs(n, g);

	return 0;
}