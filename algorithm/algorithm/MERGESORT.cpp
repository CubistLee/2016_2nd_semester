#include<stdio.h>

void mergesort(int *array, int left, int right);
void merge(int arr[], int left, int mid, int right);

int main(void) {
	int matrix[100000];/*������*/
	int num;/* ��������*/
	int a; /*�Ű�����*/
	scanf("%d", &num);/*���� ���� ���� �ʱ�ȭ*/
	for (a = 0; a < num; a++) {
		scanf("%d", &matrix[a]);/*��� �ʱ�ȭ */
		
	}
	/*for (a = 0; a < num; a++) {
		printf("%d", matrix[a]); /*��� Ȯ�ΰ�*/

	/*}*/

	mergesort(matrix, 0, num - 1);
	/*printf("\n");*/
	for (a = 0; a < num; a++) {
		printf("%d\n", matrix[a]); /*��� Ȯ�ΰ�*/

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
	int leftnum =left;/*�¹迭 ǥ�ü���*/
	int rightnum = mid + 1; /*��迭 ǥ�ü���*/
	int resultnum =0;/*ù° ����*/
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

