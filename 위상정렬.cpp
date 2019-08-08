#include <stdio.h>

int adj[7][7]; // 
int ind[7]; // 진입차수
int coin[7];

int tsort(int v);
int tsort2(int v);

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
		ind[n2]++; // 진입차수. 도착으로 언급된 횟수
	}
	printf("%d\n", tsort2(V));
}

int tsort(int v)
{
	int q[6];
	int front = -1;
	int rear = -1;
	int maxV = 0;
	for (int i = 1; i <= v; i++) // 진입차수가 0인 모든 노드 인큐
	{
		if (ind[i] == 0)
		{
			q[++rear] = i;
			coin[i] = 1;
		}
	}
	while (front != rear)
	{
		int n = q[++front];
		int maxCoin = 0;
		for (int i = 1; i <= v; i++)
		{
			if (adj[i][n] != 0)
			{
				if (maxCoin < coin[i])
					maxCoin = coin[i];
			}
		}
		coin[n] = maxCoin + 1;
		for (int i = 1; i <= v; i++)// n에 인접인 사람의 진입차수 1감소
		{
			if (adj[n][i] != 0)
			{
				ind[i]--; // n에 인접인 i의 진입차수 1감소
				if (ind[i] == 0)
					q[++rear] = i;
			}
		}
	}
	// 가장 많은 동전의 개수
	for (int i = 1; i <= v; i++)
	{
		if (maxV < coin[i])
			maxV = coin[i];
	}
	return maxV;
}

int tsort2(int v)
{
	int q[6];
	int front = -1;
	int rear = -1;
	int maxV = 0;
	for (int i = 1; i <= v; i++) // 진입차수가 0인 모든 노드 인큐
	{
		if (ind[i] == 0)
		{
			q[++rear] = i;
			coin[i] = 1;
		}
	}
	while (front != rear)
	{
		int n = q[++front];

		for (int i = 1; i <= v; i++)// n에 인접인 사람의 진입차수 1감소
		{
			if (adj[n][i] != 0)
			{
				ind[i]--; // n에 인접인 i의 진입차수 1감소
				if (ind[i] == 0)
				{
					q[++rear] = i;
					coin[i] = coin[n] + 1;
					maxV = coin[i];
				}
			}
		}
	}
	return maxV;
}
