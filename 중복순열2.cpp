#include <stdio.h>

int arr[3];

void f(int n, int k, int m);


int main(void)
{
	f(0, 3, 5);

	return 0;
}

void f(int n, int k, int m)
{
	if (n == k)
	{
		for (int i = 0; i < k; i++)
			printf("%d", arr[i]);
		printf("\n");
	}
	else
	{
		for (int i = 1; i <=m; i++)
		{
			arr[n] = i;
			f(n + 1, k, m);
		}
	}
}
