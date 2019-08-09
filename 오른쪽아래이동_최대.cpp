#include <stdio.h>

int main(void)
{
	int N, M;
	int d[101][101] = { 0, }; // 3<=N, M<=100 인 경우..
	int arr[101][101];
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%d", &arr[i][j]);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) // 위와 왼쪽까지의 최대합 중 큰 것을 택해 현재칸의 값을 더함.
			d[i][j] = (d[i - 1][j] > d[i][j - 1] ? d[i - 1][j] : d[i][j - 1]) + arr[i][j];
	printf("%d\n", d[N][M]);
}
