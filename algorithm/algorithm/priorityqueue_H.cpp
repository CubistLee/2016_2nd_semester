//2013011907_김형남_알고리즘508
#include<stdio.h>

int arr[300001] = { 0, };

int BUILD_HEAP(int *arr, int n, int now);
int BUILD_UP(int *arr, int n);
int build_h(int *arr, int n, int now);
int heap(int *arr, int n, int now);
int swap(int *a, int *b);

int main()
{
	int n = 0, k, address, t;

	while (1)
	{
		scanf("%d", &k);
		if (k == 1)
		{
			scanf("%d", &t);
			n++;
			arr[n] = t;
			BUILD_UP(arr, n);
		}
		else if (k == 2)
		{
			t = heap(arr, n, n);
			printf("%d ", t);
			if (n>0)
				n--;
		}
		else if (k == 3)
		{
			scanf("%d%d", &address, &t);
			arr[address] = t;
			BUILD_HEAP(arr, n, address);
		}
		else break;
	}
	printf("\n");
	for (int i = 1; i <= n; i++)
		printf("%d ", arr[i]);
	return 0;
}
int BUILD_HEAP(int *arr, int n, int now)
{
	if (now == 1) build_h(arr, n, 1);
	else if (arr[now] > arr[now / 2])
	{
		BUILD_UP(arr, now);
	}
	else if (now * 2 <= n)
	{
		build_h(arr, n, now);
	}
	return 0;
}
// 대체시 케이스에 따른 힙정렬 함수
int BUILD_UP(int *arr, int n)
{
	if (n == 1) return 0;
	if (arr[n / 2] < arr[n])
	{
		swap(arr + n / 2, arr + n);
		if (n > 1)
			BUILD_UP(arr, n / 2);
	}
	return 0;

}
//상향성 힙정렬함수
int build_h(int *arr, int n, int now)
{
	if (now * 2> n)
		return 0;
	if ( now * 2 + 1> n)
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
//하향성 힙정렬 함수
int heap(int *arr, int n, int now)
{
	int max = arr[1];
	swap(arr + 1, arr + now);
	build_h(arr, now - 1, 1);
	return max;
}
// 최대값 추출함수
int swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
	return 0;
}
// 스왑함수