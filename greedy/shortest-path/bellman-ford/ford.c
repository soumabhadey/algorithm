// Belman Ford

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool ford(int source, int n, int g[n][n], int parent[n]);

int main(void)
{
	int n;
	int i;
	int j;
	
	printf("Enter number of vertices: ");
	scanf("%i", &n);
	
	int g[n][n];
	printf("Enter adjacency matrix:-\n");
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; j++) {
			scanf("%i", &g[i][j]);
			if (g[i][j] == 0) {
				g[i][j] = INT_MAX;
			}
		}
	}

	printf("Enter source: ");
	int source;
	scanf("%d", &source);

	printf ("Enter destination: ");
	int destination;
	scanf("%d", &destination);
	
	int parent[n];
	if (!ford(source, n, g, parent)) {
		printf("Negative weight cycle\n");
		return 0;
	}

	if (parent[destination] == -1) {
		printf("No path exists from source to destination.\n");
		return 0;
	}

	int ans[n];
	int k = n - 1;
	ans[k] = destination;
	int total = 0;
	while (parent[destination] != -1) {
		total += g[parent[destination]][destination];
		k--;
		ans[k] = parent[destination];
		destination = parent[destination];
	}

	printf("Path: %d", ans[k]);
	for (int i = k + 1; i < n; i++) {
		printf(" --> %d", ans[i]);
	}
	printf("\n");

	printf("Total Cost = %d\n", total);
	
	return 0;
}

bool ford(int source, int n, int g[n][n], int parent[n]) {
	int distance[n];

	for (int i = 0; i < n; i++) {
		parent[i] = -1;
		distance[i] = INT_MAX;
	}

	distance[source] = 0;
	parent[source] = -1;

	for (int i = 0; i < n - 1; ++i) {
		for (int u = 0; u < n; u++) {
			for (int v = 0; v < n; v++) {
				if (g[u][v] != INT_MAX && distance[u] != INT_MAX && distance[v] > distance[u] + g[u][v]) {
					distance[v] = distance[u] + g[u][v];
					parent[v] = u;
				}
			}
		}
	}

	for (int i = 0; i < n - 1; ++i) {
		for (int u = 0; u < n; u++) {
			for (int v = 0; v < n; v++) {
				if (g[u][v] != INT_MAX && distance[u] != INT_MAX && distance[v] > distance[u] + g[u][v]) {
					return false;
				}
			}
		}
	}

	return true;
}