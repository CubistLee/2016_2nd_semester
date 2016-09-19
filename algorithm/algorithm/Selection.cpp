#include<stdio.h>
void swap(int* arr, int left,int right);
int main(void) {
	int matrix[30000];
	int num, repeat;/*행렬개수와 시행횟수*/
	int para;/*매개변수*/
	int left_para, right_para;
	int min_para;
	scanf( "%d %d",&num, &repeat );
	for (para = 0; para < num; para++) {
		scanf("%d", &matrix[para]);
	}
	/*for (para = 0; para < num; para++) {
		printf("%d\n", matrix[para]);
	}*/
	/*printf("\n");*/
	for (left_para = 0; left_para < repeat; left_para++) {
		 min_para = left_para;
		for (right_para = left_para + 1; right_para < num; right_para++) {
			if (/*matrix[left_para] > matrix[right_para]&&*/matrix[min_para]> matrix[right_para]) {
				min_para = right_para;
			}
			}
		swap(matrix, left_para, min_para);
		/*for (para = 0; para < num; para++) {
			printf("%d ", matrix[para]);
		}
		printf("\n");*/
	}
	for (para = 0; para < num; para++) {
		printf("%d\n", matrix[para]);
	}
	return 0;
}

void swap(int* arr, int left, int right) {
	int temp_num;
	temp_num = arr[left];
	arr[left] = arr[right];
	arr[right] = temp_num;
} 