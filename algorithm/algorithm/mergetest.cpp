#include <stdio.h>



void merge_sort(int array[], int left, int right);   //���� �Լ�

void merge(int num[], int left, int mid, int right);   //���� �Լ�



const int ITEMSIZE = 100000;

int result[ITEMSIZE];



int main(void)

{
int matrix[10000];/*������*/
	int num;/* ��������*/
	int a; /*�Ű�����*/
	scanf("%d", &num);/*���� ���� ���� �ʱ�ȭ*/
	for (a = 0; a < num; a++) {
		scanf("%d", &matrix[a]);/*��� �ʱ�ȭ */
		
	}
	for (a = 0; a < num; a++) {
		printf("%d", matrix[a]); /*��� Ȯ�ΰ�*/

	}

	merge_sort(matrix, 0, num - 1);
	printf("\n");
	for (a = 0; a < num; a++) {
		printf("%d", matrix[a]); /*��� Ȯ�ΰ�*/

	}
	return 0;
}



void merge_sort(int array[], int left, int right) {

	int mid;



	// ������ �� ���� �ʾ��� ��� if �� ����  

	if (left < right) {

		mid = (left + right) / 2;



		merge_sort(array, left, mid);      //���� ��� ����

		merge_sort(array, mid + 1, right);  //������ ��� ����

		merge(array, left, mid, right);   //���ҵ� ��� ����

	}
}



	void merge(int array[], int left, int mid, int right){

		int i, j, k, m;



		i = left;

		j = mid + 1;

		k = left;    //��� �迭�� �ε���



		int tempArray[ITEMSIZE];



		//left���� mid ������ ��ϰ� mid+1���� right������ ����� ���� ���ϴ� �κ�

		while (i <= mid && j <= right) {

			if (array[i] < array[j]) {   //left index ���� right index ������ ������ left index ���� ��� result�� ����

				tempArray[k] = array[i];

				i++;

			}
			else {        //�ƴ϶�� right index ���� ��� result�� ����

				tempArray[k] = array[j];

				j++;

			}

			k++;

		}



		// left ����� ���� �� ó���Ǿ��µ� right ����� index�� ���� �������� ���

		// right index�� ���������� ��� result�� ����

		if (i > mid) {

			for (m = j; m <= right; m++) {

				tempArray[k] = array[m];

				k++;

			}

		}
		else {                    // left ����� index�� ���� �������� ��� left index�� ���������� ��� result�� ���� 

			for (m = i; m <= mid; m++) {

				tempArray[k] = array[m];

				k++;

			}

		}



		for (m = left; m <= right; m++) {

			array[m] = tempArray[m];

		}

	}