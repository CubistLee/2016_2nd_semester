#include<stdio.h>

void mergesort(int *array, int left, int right);
void merge(int arr[], int left, int mid, int right);

int main(void) {
	int matrix[100000];/*행렬잡기*/
	int num;/* 변수개수*/
	int a; /*매개변수*/
	scanf("%d", &num);/*넣을 변수 개수 초기화*/
	for (a = 0; a < num; a++) {
		scanf("%d", &matrix[a]);/*행렬 초기화 */
		
	}
	/*for (a = 0; a < num; a++) {
		printf("%d", matrix[a]); /*출력 확인값*/

	/*}*/

	mergesort(matrix, 0, num - 1);
	/*printf("\n");*/
	for (a = 0; a < num; a++) {
		printf("%d\n", matrix[a]); /*출력 확인값*/

	}
	return 0;

}
void mergesort(int *array, int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		mergesort(array, left, mid);
		mergesort(array, mid + 1, right);
		merge(array, left, mid, right);
	}
}
void merge(int arr[], int left, int mid, int right) {
	int leftnum =left;/*좌배열 표시숫자*/
	int rightnum = mid + 1; /*우배열 표시숫자*/
	int resultnum =0;/*첫째 숫자*/
	int restnum;
	int size = right - left + 1;
	int temparr[100000];
	while (leftnum <= mid && rightnum <= right) {
		if (arr[leftnum] < arr[rightnum]) {
			
			temparr[resultnum++] = arr[rightnum++];

		}
		else {
			
			temparr[resultnum++] = arr[leftnum++];
		}
		
	}
		if (leftnum > mid) {
			for (restnum = rightnum; restnum <= right; restnum++) {
				temparr[resultnum++] = arr[restnum];
				;
			}
		}
		else {
			for (restnum = leftnum; restnum <= mid; restnum++) {
				temparr[resultnum++] = arr[restnum];
				;
			}
		}
		for (resultnum = 0; resultnum < size; resultnum++) {
			arr[left + resultnum] = temparr[resultnum];
		}

}

