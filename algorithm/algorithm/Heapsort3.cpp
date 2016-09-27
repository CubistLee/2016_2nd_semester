/*
* Heap Sorting 
*
* 2013011554 이새한
*/

#include<stdio.h>

void heap_swap(int* arr, int parent, int child);
void extract_max(int* arr, int the_number, int max_heap);
void range_heap(int* arr, int index, int max_heap);

//부모 자식노드 교환 함수
void heap_swap(int* arr, int parent, int child) {
	int temp = arr[parent];
	arr[parent] = arr[child];
	arr[child] = temp;
}

//최대값 추출 함수
void extract_max(int* arr, int the_number, int max_heap) {
	int para;
	printf("%d ", arr[1]);
	heap_swap(arr, 1, the_number);
	the_number = the_number - 1;
	max_heap = the_number / 2;
	for (para = max_heap; para >= 1; para--) {
		range_heap(arr, para, the_number);
	}
}
//힙정렬
void range_heap(int* arr, int index, int thenum) {
	int maxheap = thenum / 2;

	//자식노드에 채워져있으나 채워져있는 값들이 최대값 추출된 값으로0 자식노드로 간주하지 말아야할때
	if ((thenum < index * 2 + 1) || (thenum < index * 2)) {
		return;
	}

	//힙정렬 구현 완료
	else if (arr[index] >= arr[(2 * index)] && arr[index] >= arr[(2 * index) + 1]) {
		return;
	}

	//바뀔숫자가 왼쪽자식노드일때
	else if (arr[2 * index] > arr[2 * index + 1]) {
		heap_swap(arr, index, index * 2);
		if (maxheap >= index * 2) {
			range_heap(arr, index * 2, thenum);
		}
		return;
	}

	//바뀔 숫자가 오른쪽자식노드일때
	else {
		heap_swap(arr, index, index * 2 + 1);
		if (maxheap >= index * 2) {
			range_heap(arr, index * 2 + 1, thenum);
		}
		return;
	}
}
int main(void) {
	int The_number;
	int The_number_const;
	int repeat_maximum;
	int para1;
	int matrix[100001];
	int maximum_heap_index;
	scanf("%d %d", &The_number, &repeat_maximum);
	The_number_const = The_number;
	maximum_heap_index = The_number / 2;
	for (para1 = 1; para1 <= The_number; para1++) {
		scanf("%d", &matrix[para1]);
	}
	for (para1 = maximum_heap_index; para1 >= 1; para1--) {
	range_heap(matrix, para1, The_number);
	}
	for (para1 = 1; para1 <= repeat_maximum; para1++) {
		if (para1 <= The_number_const) {
			extract_max(matrix, The_number, maximum_heap_index);
			The_number = The_number - 1;
			maximum_heap_index = The_number / 2;
		}
	}
	printf("\n");
	for (para1 = 1; para1 <= The_number; para1++) {
		printf("%d ", matrix[para1]);
	}
	return 0;

}