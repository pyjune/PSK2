#include <stdio.h>

// 5 4
// 1 2 1 3 3 4 3 5

int ch1[6]; // 부모를 인덱스로 자식저장
int ch2[6];
int par[6]; // 자식을 인덱스로 부모저장

void dlr(int n);
void ldr(int n);
void lrd(int n);
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

	//find(5);
	dlr(1);
	printf("\n");
	ldr(1);
	printf("\n");
	lrd(1);


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

void dlr(int n) // 전위 순회
{
	if (n > 0)
	{
		printf("%d ", n);
		dlr(ch1[n]);
		dlr(ch2[n]);
	}
}

void ldr(int n) // 중위 순회
{
	if (n > 0)
	{
		ldr(ch1[n]);
		printf("%d ", n); // 왼쪽자식에서 리턴 후 처리
		ldr(ch2[n]);
	}
}

void lrd(int n) // 후위 순회
{
	if (n > 0)
	{
		lrd(ch1[n]);
		lrd(ch2[n]);
		printf("%d ", n); // 오른쪽자식에서 리턴 후 처리
	}
}
