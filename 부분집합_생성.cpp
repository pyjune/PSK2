void f(int n, int k, int x)
{
	if (n == k) // 
	{
		for (int i = 0; i < k; i++)
		{
			if(arr[i]==1)
				printf("%d ", A[i]);
		}
		printf("\n");
	}
	else
	{
		arr[n] = 0;
		f(n + 1, k);
		arr[n] = 1;
		f(n + 1, k);
	}
}
