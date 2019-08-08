#include <stdio.h>

int arr[10][10];
int minV;

void f(int i, int j, int n, int m, int s);

int main(void)
{
	int T;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int N, M;
		minV = 1000000;
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				scanf("%d", &arr[i][j]);
			}
		}
		f(0, 0, N, M, 0);
		if (minV == 1000000)
			minV = 0;
		printf("#%d %d\n", tc, minV);
	}
}

void f(int i, int j, int n, int m, int s)
{
	if (arr[i][j] == 0)
		return;
	else if (i == n - 1 && j == m - 1)
	{
		if (minV > s + arr[i][j])
			minV = s + arr[i][j];
	}
	else
	{
		if (i + 1 < n)
			f(i + 1, j, n, m, s + arr[i][j]);
		if (j + 1 < m)
			f(i, j + 1, n, m, s + arr[i][j]);
	}
}
