#include <stdio.h>

//5 6
//1 2 1 3 3 2 2 5 5 4 3 4

int adj[1001][1001];
int visited[1001];
int s[1000];
int top = -1;



void dfs(int n, int k);
void bfs(int n, int k);

int main(void)
{
	int V, E, S;
	freopen("Text.txt", "r", stdin);
	scanf("%d %d %d", &V, &E, &S);
	for (int i = 0; i < E; i++)
	{
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		adj[n1][n2] = 1;
		adj[n2][n1] = 1; // 무방향인 경우
	}
	dfs(S, V);
	printf("\n");
	bfs(S, V);
}


void dfs(int n, int k)
{
	visited[n] = 1;
	printf("%d ", n); // visit(n)
	for (int i = 1; i <= k; i++)
	{
		if (adj[n][i] != 0 && visited[i] == 0)
		{
			dfs(i, k);
		}
	}
}
void bfs(int n, int k)
{
	int queue[1000];
	int visited[1001] = { 0, };
	int front = -1;
	int rear = -1;
	queue[++rear] = n; // enqueue(n)
	visited[n] = 1;
	while (front != rear) // 큐가 비어있지 않으면 반복
	{
		n = queue[++front]; // dequeue()
		printf("%d ", n);
		for (int i = 1; i <= k; i++)
		{
			if (adj[n][i] != 0 && visited[i] == 0)
			{
				queue[++rear] = i;
				visited[i] = visited[n] + 1;
			}
		}
	}
}
