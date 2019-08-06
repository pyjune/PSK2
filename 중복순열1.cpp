// 1,2,3으로 3자리수 만들기

#include <stdio.h>

int arr[3];

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
			printf("%d", arr[i]);
		printf("\n");
	}
	else
	{
		for (int i = 1; i <=3; i++)
		{
			arr[n] = i;
			f(n + 1, k);
		}
	}
}
