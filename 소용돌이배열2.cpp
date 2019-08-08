// 다음과 같이 include를 사용할 수 있습니다.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
	// 여기에 코드를 작성해주세요.
	// 1 2 3
	// 8 9 4
	// 7 6 5
	int di[] = { 0, 1, 0, -1 };
	int dj[] = { 1, 0, -1, 0 };
	int answer = 0;
	int arr[100][100] = { 0, };
	int k = 1;
	int dir = 0; // 오른쪽
	int i = 0;
	int j = -1;
	int ni = 0;
	int nj = 0;
	while (k<=n*n)
	{
		ni = i + di[dir];
		nj = j + dj[dir];
		if(ni>=0 && ni<n && nj>=0 && nj<n && arr[ni][nj]==0)
		{
			arr[ni][nj] = k++;
			i = ni;
			j = nj;
		}
		else
		{
			dir = (dir + 1) % 4;
		}
	}
	for (int i = 0; i < n; i++)
		answer += arr[i][i];
	return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
	int n1 = 3;
	int ret1 = solution(n1);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	printf("solution 함수의 반환 값은 %d 입니다.\n", ret1);

	int n2 = 2;
	int ret2 = solution(n2);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	printf("solution 함수의 반환 값은 %d 입니다.\n", ret2);
}
