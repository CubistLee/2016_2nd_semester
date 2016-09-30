#include<stdio.h>/*2013011554 �̻���*/

void range_heap(int* arr, int index, int max_heap);
void heap_swap(int* arr, int parent, int child);
void extract_max(int* arr, int the_number);
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
			extract_max(matrix, The_number);
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

void range_heap(int* arr, int index, int thenum) {/*������*/
	int maxheap = thenum / 2;
	//�ڽĳ�忡 ä���������� ä�����ִ� ������ �ִ밪 ����� ������0 �ڽĳ��� �������� ���ƾ��Ҷ� 
	
	if (thenum == index * 2 ) {
		if (arr[index] < arr[thenum]) {
			heap_swap(arr, index, thenum);
		}
		
		return;
	}
	
	//�������� ������ �����Ǿ��ִ�. 
	else if (arr[index] > arr[(2 * index)] && arr[index] > arr[(2 * index) + 1]) {
		return;
	}

	//�ٲ���ڰ� �����ڽĳ���϶� 
	else if (arr[2 * index] > arr[2 * index + 1]) {
		heap_swap(arr, index, index * 2);
		if (maxheap >= index * 2){
			range_heap(arr, index * 2, thenum);
		}
		return;
	}
	else {
		
		//�ٲ� ���ڰ� �������ڽĳ���϶�
		heap_swap(arr, index, index * 2 + 1);
		if (maxheap >= index * 2) {
			range_heap(arr, index * 2 + 1, thenum);
		}
		return;
	}
}

//�θ��ڽĳ�� ��ȯ �Լ� 
void heap_swap(int* arr, int parent, int child) {
	int temp = arr[parent];
	arr[parent] = arr[child];
	arr[child] = temp;
}
//�ִ밪 ���� �Լ� 
void extract_max(int* arr, int the_number) {
	int para;
	printf("%d ", arr[1]);
	heap_swap(arr, 1, the_number);
	arr[the_number] = 0;
	the_number = the_number - 1;
	for (para = the_number /2; para >= 1; para--) {
		range_heap(arr, para, the_number);
	}

}