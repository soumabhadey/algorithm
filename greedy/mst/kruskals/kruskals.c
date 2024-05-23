#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct edge
{
	int u;
	int v;
	int w;
} edge;

int edgecompare(const void *a, const void *b);
int findset(int x, int p[]);
void link(int x, int y, int p[], int rank[]);
void makeset(int x, int p[], int rank[]);
int mstkruskal(int n, int g[][n], int ne, edge e[], edge a[]);
void unify(int x, int y, int p[], int rank[]);

int main()
{
	int n;
	int i;
	int j;
	int ne;
	int totalweight;

	scanf("%i", &n);

	int g[n][n];
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			scanf("%i", &g[i][j]);
			if (i == j)
			{
				g[i][j] = 0;
			}
			else if (g[i][j] == 0)
			{
				g[i][j] = INT_MAX;
			}
		}
	}

	edge e[n * (n - 1) / 2];
	ne = 0;
	for (i = 0; i < n; ++i)
	{
		for (j = i + 1; j < n; ++j)
		{
			e[ne].u = i;
			e[ne].v = j;
			e[ne].w = g[i][j];
			++ne;
		}
	}

	edge a[n - 1];
	totalweight = mstkruskal(n, g, ne, e, a);

	for (i = 0; i < n - 1; ++i)
	{
		printf("%c---%c\n", 'A' + a[i].u, 'A' + a[i].v);
	}

	printf("Total weight: %i\n", totalweight);

	return 0;
}

int edgecompare(const void *a, const void *b)
{
	edge *e1 = (edge *) a;
	edge *e2 = (edge *) b;

	if (e1->w > e2->w)
	{
		return 1;
	}
	else if (e1->w < e2->w)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int findset(int x, int p[])
{
	if (p[x] == x)
	{
		return x;
	}
	else
	{
		return findset(p[x], p);
	}
}

void link(int x, int y, int p[], int rank[])
{
	if (rank[x] > rank[y])
	{
		p[y] = x;
	}
	else
	{
		p[x] = y;

		if (rank[x] == rank[y])
		{
			++rank[y];
		}
	}
}

void makeset(int x, int p[], int rank[])
{
	p[x] = x;
	rank[x] = 0;
}

int mstkruskal(int n, int g[][n], int ne, edge e[], edge a[])
{
	int i;
	int p[n];
	int rank[n];
	int k;
	int totalweight;

	for (i = 0; i < n; ++i)
	{
		makeset(i, p, rank);
	}

	qsort(e, ne, sizeof(edge), edgecompare);

	k = 0;
	totalweight = 0;
	for (i = 0; i < ne; ++i)
	{
		if (k == n - 1)
		{
			break;
		}
		if (findset(e[i].u, p) != findset(e[i].v, p))
		{
			a[k] = e[i];
			++k;
			totalweight = totalweight + e[i].w;

			unify(e[i].u, e[i].v, p, rank);
		}
	}

	return totalweight;
}

void unify(int x, int y, int p[], int rank[])
{
	link(findset(x, p), findset(y, p), p, rank);
}
