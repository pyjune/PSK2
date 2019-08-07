// 스택을 사용한 반복 구조 dfs
#include <stdio.h>

//5 6
//1 2 1 3 3 2 2 5 5 4 3 4

int adj[6][6];
int visited[6];
int s[6];
int top = -1;

void dfs2(int n, int k);

int main(void)
{
	int V, E;
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++)
	{
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		adj[n1][n2] = 1;
		//adj[n2][n1] = 1; // 무방향인 경우
	}
	dfs2(1, V);
}

void dfs2(int n, int k)
{
	s[++top] = n; //push()
	visited[n] = 1;
	while (top != -1) // stack_is_not_empty
	{
		n = s[top--]; // pop()
		printf("%d ", n); // visit(n)
		for (int i = 1; i <= k; i++)
		{
			if (adj[n][i] != 0 && visited[i] == 0)
			{
				s[++top] = i; // push()
				visited[i] = 1;
			}
		}
	}
}
