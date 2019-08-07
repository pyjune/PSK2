#include <stdio.h>

// 5 4
// 1 2 1 3 3 4 3 5

int ch1[6]; // 부모를 인덱스로 자식저장
int ch2[6];
int par[6]; // 자식을 인덱스로 부모저장

void f(int n);
void find(int n);

int main(void)
{
	int V, E;
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++)
	{
		int p, c;
		scanf("%d %d", &p, &c);
		if (ch1[p] == 0)
			ch1[p] = c;
		else
			ch2[p] = c;

		par[c] = p;
	}

	//f(1);
	find(5);

	return 0;
}

void find(int n) // 조상찾기
{
	while (par[n] != 0)
	{
		printf("%d ", par[n]);
		n = par[n];
	}
}

void f(int n) // 기본 순회
{
	if (n > 0)
	{
		printf("%d ", n);
		f(ch1[n]);
		f(ch2[n]);
	}
}
