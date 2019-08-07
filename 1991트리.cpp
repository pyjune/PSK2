#include <stdio.h>

int ch1[27];
int ch2[27];

void f1(int n);
void f2(int n);
void f3(int n);

int main(void)
{
	int N;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		char p, c1, c2;
		scanf(" %c %c %c", &p, &c1, &c2);
		if (c1 != '.')
			ch1[p - 'A' + 1] = c1 - 'A' + 1;
		if (c2 != '.')
			ch2[p - 'A' + 1] = c2 - 'A' + 1;
	}
	f1(1);
	printf("\n");
	f2(1);
	printf("\n");
	f3(1);

	return 0;
}

void f1(int n)
{
	if (n > 0)
	{
		printf("%c", n - 1 + 'A');
		f1(ch1[n]);
		f1(ch2[n]);
	}
}
void f2(int n)
{
	if (n > 0)
	{
		f2(ch1[n]);
		printf("%c", n - 1 + 'A');
		f2(ch2[n]);
	}
}
void f3(int n)
{
	if (n > 0)
	{
		f3(ch1[n]);
		f3(ch2[n]);
		printf("%c", n - 1 + 'A');
	}
}
