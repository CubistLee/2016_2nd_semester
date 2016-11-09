void radix_sort(int *arr, int max, int size)
{
	int *que[10], top[10];
	int i, j, k, a, radix = 1;
	for (i = 0; i < 10; i++)
	{
		que[i] = (int *)malloc(sizeof(int) * size);
		top[i] = -1;
	}

	do
	{
		radix *= 10;
	} while (radix <= max);

	for (i = 1; i <= radix; i *= 10)
	{
		for (j = 0; j < size; j++)
		{
			k = (arr[j] / i) % (i * 10);
			que[k][++top[k]] = arr[j];
		}
		a = 0;
		for (j = 0; j < 10; j++)
		{
			for (k = 0; k <= top[j]; k++)
			{
				arr[a++] = que[j][k];
			}
			top[j] = -1;
		}
	}
	for (i = 0; i < 10; i++)
	{
		free(que[i]);
	}
}