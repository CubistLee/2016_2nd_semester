#include<stdio.h>
void swap(int* a, int* b);
void quick_sort(int* array, int start, int end);
int main(void) {

	int num1[100000];
	int num2[100000];
	int quantity1;
	int quantity2;
	int input;
	int para1;
	int para2;
	int index_para=0;
	int count = 0;
	scanf("%d %d", &quantity1,&quantity2);/* 정렬변수 개수입력*/
	for (input = 0; input < quantity1; input++) {/*변수 입력 */
		scanf("%d", &num1[input]);
	}
	for (input = 0; input < quantity2; input++) {/*변수 입력 */
		scanf("%d", &num2[input]);
	}
	
	quick_sort(num1, 0, quantity1 -1);
	quick_sort(num2, 0, quantity2 -1);
	/*for (order = 1; order < quantity1; order++) {
		key = num1[order];
		turn = order - 1;
		while (turn >= 0 && key < num1[turn]) {

			num1[turn + 1] = num1[turn];

			turn--;
		}
		num1[turn + 1] = key;
	}
	for (order = 1; order < quantity2; order++) {
		key = num2[order];
		turn = order - 1;
		while (turn >= 0 && key < num2[turn]) {

			num2[turn + 1] = num2[turn];

			turn--;
		}
		num2[turn + 1] = key;
	}*/
	for (para1 = 0; para1 < quantity1; para1++) {
		for (para2 = index_para; para2 < quantity2; para2++) {
			if (num1[para1] > num2[para2]) {
				continue;
			}
			else if (num1[para1] < num2[para2]) {
				index_para = para2;
				break;
			}
			else if (num1[para1] == num2[para2]) {
				count++;
				index_para = para2 + 1;
				break;
			}
		}
	}
	printf("%d", count);
	printf("\n");
	/*for (input = quantity1 - 1; input >= 0; input--) {//변수 입력 
		printf("%d ", num1[input]);
	}
	printf("\n");
	for (input = quantity2 - 1; input >= 0; input--) {//변수 입력 
		printf("%d ", num2[input]);
	}*/
	return 0;
}
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void quick_sort(int* array, int start, int end) {

	if (start >= end) return;

	int mid = (start + end) / 2;
	int pivot = array[mid];

	swap(&array[start], &array[mid]);

	int p = start + 1, q = end;

	while (1) {
		while (array[p] <= pivot) { p++; }
		while (array[q]>pivot) { q--; }

		if (p>q) break;

		swap(&array[p], &array[q]);
	}

	swap(&array[start], &array[q]);

	quick_sort(array, start, q - 1);
	quick_sort(array, q + 1, end);

}