#include <stdio.h>

int adj[6][6];
int visited[6];

void bfs(int n, int k); // k 마지막 노드

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
	bfs(1, V);
}

void bfs(int n, int k)
{
	int q[5];
	int front = -1;
	int rear = -1;
	
	q[++rear] = n; //enqueue()
	visited[n] = 1;
	while (front != rear) // 큐가 비어있지 않으면 진입
	{
		n = q[++front]; // dequeue()
		printf("%d ", n);
		for (int i = 1; i <= k; i++)
		{
			if (adj[n][i] != 0 && visited[i] == 0)
			{
				q[++rear] = i;
				visited[i] = visited[n] + 1;
			}
		}
	}

}
