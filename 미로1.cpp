#include <stdio.h>

int maze[100][100];

int dfs(int r, int c);
int bfs(int r, int c);

int main(void)
{
	int T;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int N;
		int startR, startC;
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
		//printf("#%d %d\n", tc, dfs(startR, startC));
		printf("#%d %d\n", tc, bfs(startR, startC));
	}
}

int dfs(int r, int c)
{
	int dr[] = { 0, 1, 0, -1 };
	int dc[] = { 1, 0, -1, 0 };
	if (maze[r][c] == 3)
	{
		return 1;
	}
	else if (maze[r][c] == 1)
		return 0;
	else
	{
		maze[r][c] = 1;
		for (int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (dfs(nr, nc) == 1)
				return 1;
		}
		return 0;
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
			return 1;
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
