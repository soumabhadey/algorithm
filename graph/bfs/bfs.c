#include <stdio.h>
#include <limits.h>

void enque(int n, int queue[n], int *front, int *rear, int v) {
	if (*front == -1 && *rear == -1) {
		*front = *rear = 1;
	} else {
		*rear = *rear + 1;
	}
	queue[*rear] = v;
}

int deque(int n, int queue[n], int *front, int *rear) {
	int v = queue[*front];
	if (*front == *rear) {
		*front = *rear = -1;
	} else {
		*front = *front + 1;
	}
	return v;
}

void bfs(int n, int g[n][n], int source) {
	char color[n];
	int distance[n];
	int parent[n];
	for (int i = 0; i < n; i++) {
		color[i] = 'w';
		distance[i] = INT_MAX;
		parent[i] = -1;
	}
	int queue[n];
	int front = -1, rear = -1;
	
	color[source] = 'g';
	distance[source] = 0;
	parent[source] = -1;
	enque(n, queue, &front, &rear, source);

	printf("BFS: ");
	while(front != -1 && rear != -1) {
		int u = deque(n, queue, &front, &rear);
		color[u] = 'b';
		printf("%d ", u);

		for (int v = 0; v < n; v++) {
			if (g[u][v] != 0 && color[v] == 'w') {
				color[v] = 'g';
				distance[v] = distance[u] + 1;
				parent[v] = u;
				enque(n, queue, &front, &rear, v);
			}
		}
	}
	printf("\n");
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

	int source;
	scanf("%d", &source);

	bfs(n, g, source);

	return 0;
}