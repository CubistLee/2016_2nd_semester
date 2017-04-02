#include<stdio.h>
#include<stdlib.h>

int nohuff(int n);
int Build_Heap(int *arr, int n);
int build_h(int *arr, int n, int now);
void heap(int *arr, int n);
void Build_up(int *arr, int n);
void swap(int *a, int *b);
int main()
{
	int n, all_f, tmp;
	int NH_code, H_code = 0;
	int *arr;
	char trash[5];

	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int)*(n + 1));
	for (int i = 1; i <= n; i++)
		scanf("%s%d", trash, arr + i);
	scanf("%d", &all_f);

	NH_code = nohuff(n) * all_f;
	Build_Heap(arr, n);

	while (1)
	{
		tmp = arr[1];
		heap(arr, n--);
		tmp += arr[1];
		heap(arr, n);
		H_code += tmp;
		arr[n] = tmp;
		if (n == 1) break;
		Build_up(arr, n);
	}

	printf("%d\n%d", NH_code, H_code);

	return 0;
}

int nohuff(int n)
{
	int t = 0;
	while (1)
	{
		n /= 2;
		t++;
		if (n == 0) break;
	}
	return t;
}
int Build_Heap(int *arr, int n)
{
	for (int i = 1; i <= n; i++)
		Build_up(arr, i);
	return 0;
}
int build_h(int *arr, int n, int now)
{
	if (n < now * 2)
		return 0;
	if (n == now * 2)
	{
		if (arr[n] < arr[now])
			swap(arr + n, arr + now);
	}
	else
	{
		if (arr[now * 2] < arr[now * 2 + 1])
		{
			if (arr[now * 2] < arr[now])
			{
				swap(arr + (now * 2), arr + now);
				build_h(arr, n, now * 2);
			}
		}
		else if (arr[now * 2 + 1] < arr[now])
		{
			swap(arr + (now * 2 + 1), arr + now);
			build_h(arr, n, now * 2 + 1);
		}
	}
	return 0;
}
void heap(int *arr, int n)
{
	swap(arr + 1, arr + n);
	build_h(arr, n - 1, 1);
}
void Build_up(int *arr, int n)
{
	if (n <= 1) return;
	if (arr[n] < arr[n / 2])
	{
		swap(arr + n, arr + (n / 2));
		Build_up(arr, n / 2);
	}
}
void swap(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}