#include <stdio.h>

int maze[100][100];

void dfs(int r, int c);

int cnt;

int main(void)
{
	int T;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int N;
		int startR, startC;
		cnt = 0;
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
		dfs(startR, startC);
		printf("#%d %d\n", tc, cnt);

	}
}

void dfs(int r, int c)
{
	int dr[] = { 0, 1, 0, -1 };
	int dc[] = { 1, 0, -1, 0 };
	if (maze[r][c] == 3)
	{
		cnt++;
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
			dfs(nr, nc);
		}
		maze[r][c] = 0;
	}
}
