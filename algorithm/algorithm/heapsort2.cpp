#include<stdio.h>/*2013011554 ÀÌ»õÇÑ*/

void range_heap(int* arr, int index);
void heap_swap(int* arr, int parent, int child);

int main(void) {
	int The_number;
	int repeat_maximum;
	int para1;
	int matrix[100000];
	int maximum_heap_index;
	scanf("%d %d", &The_number, &repeat_maximum);
	maximum_heap_index = The_number / 2;
	for (para1 = 0; para1 < The_number; para1++) {
		scanf("%d", &matrix[para1]);
	}
	for (para1 = maximum_heap_index; para1 > 0; para1--) {
		range_heap(matrix, para1);
	}
	printf("\n");
	for (para1 = 0; para1 < The_number; para1++) {
		printf("%d\n", matrix[para1]);
	}
}

void range_heap(int* arr, int index) {
	if (arr[index] > arr[(2 * index)] && arr[index] > arr[(2 * index) + 1]) {
		return;
	}
	else if (arr[2 * index] > arr[2 * index + 1]) {
		heap_swap(arr, index, index * 2);
		range_heap(arr, index * 2);
		return;
	}
	else {
		heap_swap(arr, index, index * 2 + 1);
		range_heap(arr, index * 2 + 1);
		return;
	}
}


void heap_swap(int* arr, int parent, int child) {
	int temp = arr[parent];
	arr[parent] = arr[child];
	arr[child] = temp;
}