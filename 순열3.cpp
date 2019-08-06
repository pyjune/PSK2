#include <stdio.h>


int p[] = { 1, 2, 3, 4, 5 };


void f(int n, int k, int m);

int main(void)
{
	f(0, 3,5);

	return 0;
}

void f(int n, int k, int m)
{
	if (n == k)
	{
		for (int i = 0; i < k; i++)
			printf("%d ", p[i]);
		printf("\n");
	}
	else
	{
		for (int i = n; i <m ; i++)
		{
			int tmp = p[n];
			p[n] = p[i];
			p[i] = tmp;
			f(n + 1, k, m);
			tmp = p[n];
			p[n] = p[i];
			p[i] = tmp;

		}
	}
}
