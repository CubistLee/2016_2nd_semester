#include<stdio.h>/*2013011554 이새한*/

void range_heap(int* arr, int index, int max_heap);
void range_up(int*arr, int n);
void range_updown(int *arr, int n, int thenum, int value);
void heap_swap(int* arr, int parent, int child);
int extract_max(int* arr, int the_number);

int main(void) {
	int The_number = 0;
	//int The_number_const;
	int repeat_maximum;
	int para1; //반복문 매개변수
	int matrix[100001] = { 0, };
	int maximum_heap_index = 0;
	int command_para;
	int max[10001];
	int max_count = 0;
	int sub_index, sub_integer;
	while (1) {
		scanf("%d", &command_para);
		if (command_para == 1) {
			scanf("%d", &matrix[++The_number]);
			range_up(matrix, The_number);
		}
		else if (command_para == 2) {
			max[max_count] = extract_max(matrix, The_number);
			The_number--;
			max_count++;
		}
		else if (command_para == 3) {
			scanf("%d %d", &sub_index, &sub_integer);
			range_updown(matrix, sub_index, The_number, sub_integer);
		}
		else break;
	}
	for (para1 = 0; para1 < max_count; para1++) {
		printf("%d ", max[para1]);
	}
	printf("\n");
	for (para1 = 1; para1 <= The_number; para1++) {
		printf("%d ", matrix[para1]);
	}
	return 0;
}

void range_heap(int* arr, int index, int thenum) {/*힙정렬*/
	int maxheap = thenum / 2;
	//자식노드에 채워져있으나 채워져있는 값들이 최대값 추출된 값으로0 자식노드로 간주하지 말아야할때 

	if (thenum == index * 2) {
		if (arr[index] < arr[thenum]) {
			heap_swap(arr, index, thenum);
		}


		return;
	}

	//힙정렬이 완전히 구현되어있다. 
	else if (arr[index] > arr[(2 * index)] && arr[index] > arr[(2 * index) + 1]) {
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
	else {

		//바뀔 숫자가 오른쪽자식노드일때
		heap_swap(arr, index, index * 2 + 1);
		if (maxheap >= index * 2 + 1) {
			range_heap(arr, index * 2 + 1, thenum);
		}
		return;
	}
}
// 부모노드값 변경시 하향성 힙정렬 함수
void range_up(int *arr, int n) {
	if (n == 1) return;
	if (arr[n / 2] < arr[n]) {
		heap_swap(arr, n / 2, n);
		if (n > 1)
			range_up(arr, n / 2);
	}
	return;
}
// 상향성 힙정렬 함수
void range_updown(int *arr, int n, int thenum, int value) {
	if (n == 1) {
		arr[n] = value;
		range_heap(arr, n, thenum);
	}
	else if (arr[n] == value)
		return;

	else if (arr[n] > value) {
		arr[n] = value;
		range_heap(arr, n, thenum);
	}
	else if (arr[n] < value) {
		arr[n] = value;
		range_up(arr, n);
	}
}
// 대체시 케이스에 따른 힙정렬 함수

void heap_swap(int* arr, int parent, int child) {
	int temp = arr[parent];
	arr[parent] = arr[child];
	arr[child] = temp;
}
//부모자식노드 교환 함수 
int extract_max(int* arr, int the_number) {
	//printf("%d ", arr[1]);
	heap_swap(arr, 1, the_number);
	//arr[the_number] = 0;
	the_number = the_number - 1;
	range_heap(arr, 1, the_number);
	return arr[the_number + 1];

}
//최대값 추출 함수 