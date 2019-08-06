#include <stdio.h>

int arr[20];
int cnt;
int cnt2;
void f(int n, int k, int x);
void f2(int n, int k, int s, int x);

int main(void)
{
	int T;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int N, X;
		cnt = 0;
		cnt2 = 0;
		scanf("%d %d", &N, &X);
		//f(0, N, X);
		f2(0, N, 0, X);
		printf("#%d %d %d\n", tc, cnt, cnt2);
	}
}

void f2(int n, int k, int s, int x) // 백트래킹 추가
{
	cnt2++;
	if (s == x)
	{
		cnt++;
	}
	else if (n == k)
	{
		return;
	}
	else if (s > x)
	{
		return;
	}
	else
	{
		f2(n + 1, k, s, x);
		f2(n + 1, k, s + n + 1, x);
	}
}

void f(int n, int k, int x)
{
	cnt2++;
	if (n == k) // 
	{
		int s = 0;
		for (int i = 0; i < k; i++)
		{
			if (arr[i] == 1)
				s += i + 1;
		}
		if (s == x)
			cnt++;
	}
	else
	{
		arr[n] = 0;
		f(n + 1, k, x);
		arr[n] = 1;
		f(n + 1, k, x);
	}
}

