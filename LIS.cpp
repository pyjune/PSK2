#include <stdio.h>



int main(void)
{
	int a[] = { 3,1,2,7,6,4,5 };
	int d[7];
	int maxV = 1;
	for (int i = 0; i < 7; i++)
		d[i] = 1;

	for (int i = 1; i < 7; i++) //
	{
		for (int j = 0; j <= i - 1; j++)
		{
			if (a[j] < a[i]) // j번 원소로 끝나는 증가수열의 뒤에 i번 원소를 놓아볼 수 있음
			{
				d[i] = d[j] + 1 > d[i] ? d[j] + 1 : d[i]; // i번 원소를 놓아서 더 길어지면 갱신
				
			}
		}
		if (maxV < d[i])
			maxV = d[i];
	}

	printf("%d\n", maxV);
}
