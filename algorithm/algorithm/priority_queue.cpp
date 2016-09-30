#include<stdio.h>/*2013011554 이새한*/

void range_heap(int* arr, int index, int max_heap);
void heap_swap(int* arr, int parent, int child);
void extract_max(int* arr, int the_number);
int main(void) {
	int The_number =0;
	//int The_number_const;
	int repeat_maximum;
	int para1; //반복문 매개변수
	int matrix[100001];
	int maximum_heap_index=0;
	int command_para;
	int max[10001];
	int max_count=0;
	int sub_index, sub_integer;

	scanf("%d ", &command_para/*,&sub_index, sub_integer*/);
	
	while (command_para != 0) {
		switch (command_para) {
		case 1: // 첫번째 숫자 1일시 노드 추가 구현
			The_number++;
			maximum_heap_index = The_number / 2;
			scanf("%d", &matrix[The_number]);
			//matrix[The_number] = sub_index;
			if (The_number > 1) {
				for (para1 = (The_number / 2); para1 >= 1; para1--) {
					range_heap(matrix, para1, The_number);
				}
			}
				break;
		case 2: // 첫번째 숫자 2일시 최대값 추출
			if (The_number > 0) {
				
				extract_max(matrix, The_number);
				max[max_count++] = matrix[The_number--];
				maximum_heap_index = The_number / 2;
			}
			break;
		case 3: // 3일때 숫자 변경및 힙정렬을 다시 한다
			scanf("%d %d", &sub_index, &sub_integer);
			if (matrix[sub_index] == sub_integer)
				break;
			else if (matrix[sub_index] > sub_integer) {
				matrix[sub_index] = sub_integer;
				range_heap(matrix, sub_index, The_number);
				break;
			}
			else {
				matrix[sub_index] = sub_integer;
				if (sub_index == 1)
					break;
				else if (matrix[sub_index / 2] < matrix[sub_index]) {
					for (para1 = sub_index/2; para1 >= 1; para1--) {
						range_heap(matrix, para1, The_number);
					}
					
				}
				break;
			}
		}
		scanf("%d", &command_para);
	}
	/*for (para1 = maximum_heap_index; para1 >= 1; para1--) {
		range_heap(matrix, para1, The_number);
	}*/ // 배열 힙정렬
	
	/*for (para1 = 1; para1 <= repeat_maximum; para1++) {
		if (para1 <= The_number_const) {
			extract_max(matrix, The_number, maximum_heap_index);
			The_number = The_number - 1;
			maximum_heap_index = The_number / 2;
		}
	}*/ // 배열 최대 추출
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
		if (maxheap >= index * 2) {
			range_heap(arr, index * 2 + 1, thenum);
		}
		return;
	}
}

//부모자식노드 교환 함수 
void heap_swap(int* arr, int parent, int child) {
	int temp = arr[parent];
	arr[parent] = arr[child];
	arr[child] = temp;
}
//최대값 추출 함수 
void extract_max(int* arr, int the_number) {
	int para;
	//printf("%d ", arr[1]);
	heap_swap(arr, 1, the_number);
	//arr[the_number] = 0;
	the_number = the_number - 1;
	for (para = the_number/2; para >= 1; para--) {
		range_heap(arr, para, the_number);
	}

}