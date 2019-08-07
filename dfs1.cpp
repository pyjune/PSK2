#include <stdio.h>

int adj[6][6];
int visited[6];
int cnt;

void dfs(int n, int k);
void dfs2(int n, int k, int m); // k 목적지, m 노드개수

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
		//adj[n2][n1] = 1; // 방향이 없는 경우
	}
	//dfs(1, V);
	dfs2(1, 4, V);
	printf("%d\n", cnt);
}

void dfs2(int n, int k, int m)
{
	if (n == k)
		cnt++;
	else
	{
		visited[n] = 1; // n번 노드에 방문 표시
		for (int i = 1; i <= m; i++)
		{
			if (adj[n][i] != 0 && visited[i] == 0)
			{
				dfs2(i, k, m);
			}
		}
		visited[n] = 0;
	}
}

void dfs(int n, int k)
{
	visited[n] = 1; // n번 노드에 방문 표시
	printf("%d ", n);
	for (int i = 1; i <= k; i++)
	{
		if (adj[n][i] != 0 && visited[i] == 0)
		{
			dfs(i, k);
		}
	}
}
