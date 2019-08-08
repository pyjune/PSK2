#include <stdio.h>

int box[1000][1000];
int q[2000000];
int v[1000][1000];

int bfs(int N, int M);

int main(void)
{
	int T;
	freopen("Text.txt", "r", stdin);

	int N, M;
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &box[i][j]);
		}
	}
	printf("%d\n", bfs(N, M));

}


int bfs(int N, int M)
{
	int di[] = { 0, 1, 0, -1 };
	int dj[] = { 1, 0, -1, 0 };
	int front = -1;
	int rear = -1;
	int zeroCnt = 0;
	int oneCnt = 0;
	int last = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (box[i][j] == 1)
			{
				q[++rear] = i;
				q[++rear] = j;
				v[i][j] = 1;
			}
			if (box[i][j] == 0)
				zeroCnt++;
		}
	}
	while (front != rear)
	{
		int i = q[++front];
		int j = q[++front];
		if (zeroCnt == oneCnt)
			return last - 1;
		for (int k = 0; k < 4; k++)
		{
			int ni = i + di[k];
			int nj = j + dj[k];
			if (ni >= 0 && ni < N && nj >= 0 && nj < M)
			{
				if (box[ni][nj] == 0 && v[ni][nj] == 0)
				{
					q[++rear] = ni;
					q[++rear] = nj;
					v[ni][nj] = v[i][j] + 1;
					last = v[ni][nj];
					oneCnt++;
				}
			}
		}
	}
	return -1;
}
