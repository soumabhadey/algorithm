#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

void dijkstra(int source, int n, int g[n][n], int parent[n]);
int extractmin(int n, int distance[n], bool path[n]);

int main(void)
{
	int n;
	int i;
	int j;
	
	printf("Enter number of vertices: ");
	scanf("%i", &n);
	
	int g[n][n];
	printf("Enter adjacency matrix:-\n");
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%i", &g[i][j]);
		}
	}

	printf("Enter source: ");
	int source;
	scanf("%d", &source);
	
	int parent[n];
	dijkstra(source, n, g, parent);
	
	printf ("Enter destination: ");
	int destination;
	scanf("%d", &destination);

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

void dijkstra(int source, int n, int g[n][n], int parent[n]) {
	int distance[n];
	bool path[n];

	for (int i = 0; i < n; i++) {
		parent[i] = -1;
		distance[i] = INT_MAX;
		path[i] = false;
	}

	distance[source] = 0;

	for (int i = 0; i < n; ++i) {
		int u = extractmin(n, distance, path);

		path[u] = true;

		for (int j = 0; j < n; j++) {
			if (g[u][j] != 0 && path[j] == false && distance[j] > distance[u] + g[u][j]) {
				distance[j] = distance[u] + g[u][j];
				parent[j] = u;
			}
		}
	}
}

int extractmin(int n, int distance[n], bool path[n]) {
	int min = INT_MAX;
	int pos = -1;

	for (int i = 0; i < n; i++) {
		if (path[i] == false && min > distance[i]) {
			min = distance[i];
			pos = i;
		}
	}

	return pos;
}