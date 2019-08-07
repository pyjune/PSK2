#include <stdio.h>

int bfs(int n, int k);

int main(void)
{
	int N, K;
	scanf("%d %d", &N, &K);
	printf("%d\n", bfs(N, K));
}

int bfs(int n, int k)
{
	int q[100001];
	int front = -1;
	int rear = -1;
	int visited[100001] = { 0, };

	q[++rear] = n;
	visited[n] = 1;

	while (front != rear)
	{
		n = q[++front];
		if (n == k)
			return visited[k] - 1;
		// n에 인접하고, 방문하지 않은 곳이면...
		// n-1
		if (n - 1 >= 0 && visited[n - 1] == 0)
		{
			q[++rear] = n - 1;
			visited[n - 1] = visited[n] + 1;
		}
		// n+1
		if (n + 1 <= 100000 && visited[n + 1] == 0)
		{
			q[++rear] = n + 1;
			visited[n + 1] = visited[n] + 1;
		}
		// n*2
		if (n * 2 <= 100000 && visited[n * 2] == 0)
		{
			q[++rear] = n * 2;
			visited[n * 2] = visited[n] + 1;
		}
	}
	return 0;
}
