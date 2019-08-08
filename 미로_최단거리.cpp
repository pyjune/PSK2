#include <stdio.h>

int maze[100][100];

void dfs(int r, int c, int e);
int bfs(int r, int c);
int minV;

int main(void)
{
	int T;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int N;
		int startR, startC;
		minV = 10000;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%1d", &maze[i][j]);
				if (maze[i][j] == 2)
				{
					startR = i;
					startC = j;
				}
			}
		}
		/*dfs(startR, startC, 0);
		if (minV == 10000)
			minV = 1;
		printf("#%d %d\n", tc, minV - 1);*/
		printf("#%d %d\n", tc, bfs(startR, startC));

	}
}

void dfs(int r, int c, int e)
{
	int dr[] = { 0, 1, 0, -1 };
	int dc[] = { 1, 0, -1, 0 };
	if (maze[r][c] == 3)
	{
		if (minV > e)
			minV = e;
	}
	else if (maze[r][c] == 1)
		return;
	else
	{
		maze[r][c] = 1;
		for (int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			dfs(nr, nc, e+1);
		}
		maze[r][c] = 0;
	}
}

int bfs(int r, int c)
{
	int dr[] = { 0, 1, 0, -1 };
	int dc[] = { 1, 0, -1, 0 };
	int q[20000];
	int front = -1;
	int rear = -1;
	int visited[100][100] = { 0, };
	q[++rear] = r;
	q[++rear] = c;
	visited[r][c] = 1;
	while (front != rear)
	{
		r = q[++front];
		c = q[++front];
		if (maze[r][c] == 3)
			return visited[r][c] - 2;
		for (int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (maze[nr][nc] != 1 && visited[nr][nc] == 0)
			{
				q[++rear] = nr;
				q[++rear] = nc;
				visited[nr][nc] = visited[r][c] + 1;
			}
		}
	}
	return 0;
}
