#include <stdio.h>

int maze[100][100];

int dfs(int r, int c);

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
		printf("#%d %d\n", tc, dfs(startR, startC));
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
