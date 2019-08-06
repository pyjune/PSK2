#include <stdio.h>

int A[] = { 1,2,3 };
int p[3];
int used[3];

void f(int n, int k);

int main(void)
{
	f(0, 3);

	return 0;
}


void f(int n, int k)
{
	if (n == k)
	{
		for (int i = 0; i < k; i++)
			printf("%d ", p[i]);
		printf("\n");
	}
	else
	{
		for (int i = 0; i < k; i++)
		{
			if (used[i] == 0)
			{
				used[i] = 1;
				p[n] = A[i];
				f(n + 1, k);
				used[i] = 0;
			}
		}
	}
}
