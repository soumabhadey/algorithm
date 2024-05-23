#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

int minkey(int key[], bool mst[], int n);
void mstprims(int n, int adj[][n], int parent[]);

int main(void)
{
	int n;
	int i;
	int j;
	
	printf("Enter number of vertices: ");
	scanf("%i", &n);
	
	int adj[n][n];
	printf("Enter adjacency matrix:-\n");
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%i", &adj[i][j]);
		}
	}
	
	int parent[n];
	mstprims(n, adj, parent);
	int total = 0;
	for (i = 1; i < n; ++i)
	{
		printf("%c---%c\n", 'A' + parent[i], 'A' + i);
		total += adj[parent[i]][i];
	}
	printf("Total weight = %d\n", total); 
	
	return 0;
}
	
int minkey(int key[], bool mst[], int n)
{
	int min;
	int pos;
	int i;

	min = INT_MAX;
	pos = -1;
	for (i = 0; i < n; ++i)
	{
		if 	(mst[i] == false && key[i] < min)
		{
			min = key[i];
			pos = i;
		}
	}
	
	return pos;
}
	
void mstprims(int n, int adj[][n], int parent[])
{
	bool mst[n];
	int key[n];
	int i;
	int k;
	int j;
	
	for (i = 0; i < n; ++i)
	{
		parent[i] = -1;
		key[i] = INT_MAX;
		mst[i] = false;
	}
	
	parent[0] = -1;
	key[0] = 0;
	
	for (i = 0; i < n; ++i)
	{
		k = minkey(key, mst, n);
		
		mst[k] = true;
		
		for (j = 0; j < n; ++j)
		{
			if (mst[j] == false && adj[k][j] != 0 && adj[k][j] < key[j])
			{
				key[j] = adj[k][j];
				parent[j] = k;
			}
		}
	}
}
		
