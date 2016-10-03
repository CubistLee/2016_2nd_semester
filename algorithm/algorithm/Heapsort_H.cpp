//2013011907_김형남_알고리즘508
#include<stdio.h>

int arr[100001] = { 0, };

int BUILD_HEAP(int *arr, int n);
int build_h(int *arr, int n, int now);
int heap(int *arr, int n, int now);
int swap(int *a, int *b);

int main()
{
	int n, k, t;

	scanf("%d%d", &n, &k);

	for (int i = 1; i <= n; i++)
		scanf("%d", arr + i);

	BUILD_HEAP(arr, n);

	for (int i = 0; i < k; i++)
	{
		t = heap(arr, n, n - i);
		printf("%d ", t);
	}
	printf("\n");
	for (int i = k; i < n; i++)
	{
		t = heap(arr, n, n - i);
		printf("%d ", t);
	}
	return 0;
}

int BUILD_HEAP(int *arr, int n)
{
	for (int i = n / 2; i > 0; i--)
		build_h(arr, n, i);
	return 0;
}
//배열 힙구조화 함수
int build_h(int *arr, int n, int now)
{
	if (n < now * 2)
		return 0;
	if (n < now * 2 + 1)
	{
		if (arr[n] > arr[now])
			swap(arr + n, arr + now);
	}
	else
	{
		if (arr[now * 2] > arr[now * 2 + 1])
		{
			if (arr[now * 2] > arr[now])
			{
				swap(arr + (now * 2), arr + now);
				build_h(arr, n, now * 2);
			}
		}
		else if (arr[now * 2 + 1] > arr[now])
		{
			swap(arr + (now * 2 + 1), arr + now);
			build_h(arr, n, now * 2 + 1);
		}
	}
	return 0;
}
// 하향성 힙 재정렬
int heap(int *arr, int n, int now)
{
	int max = arr[1];
	swap(arr + 1, arr + now);
	build_h(arr, now - 1, 1);
	return max;
}
//최대 추출함수
int swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
	return 0;
}