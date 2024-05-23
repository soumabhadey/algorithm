#include <stdio.h>

void toh(int n, char x, char y, char z, int *c)
{
	if (n >= 1)
	{
		toh(n - 1, x, z, y, c);
		printf("\nmove top disk from tower %c to top of tower %c", x, y);
		*c += 1;
		toh(n - 1, z, y, x, c);
	}
}

int main()
{
	int n;
	int count;

	printf("\nenter number of disks");
	scanf("%d", &n);
	
	count = 0;
	toh(n, 'X', 'Y', 'Z', &count);
	
	printf("\nsteps %d", count);
}