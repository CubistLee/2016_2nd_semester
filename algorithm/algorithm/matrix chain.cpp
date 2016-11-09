#include <stdio.h>
#include <malloc.h>

int minmult(int n, int d[], int *P[]);  // �ּ� ���� �˰���
void order(int i, int j, int *P[]);     // ���� ���� ���
int* input_array_number(int n);     // dx�� �Է� ����
int** make_array(int n);    // P ��� ���� �Ҵ�

int main()
{
	int *d, **P;
	int number, result;

	
	scanf("%d", &number);  // ������ ���� �Է� ����

	d = input_array_number(number); // �˰����� �Է��� �Ǵ� d ���
	P = make_array(number);     // ���� ���� ����� ���� P ��� ����

	result = minmult(number, d, P); // �˰����� ������� result�� ����
	printf("%d\n", result);
	order(1, number, P);   // ��� ���� ���� ���� ���

						   //free(d);
						   //free(P);
	return 0;
}

int** make_array(int n) // P ����� ���� �޸� �Ҵ����� ����
{
	int i;
	int **P = (int**)malloc(sizeof(int) * 1);
	for (i = 0; i < n; i++)
		P[i] = (int*)malloc(sizeof(int)*(n + 1));
	return P;
}

int* input_array_number(int n)  // �Է� ���� number ��ŭ dx�� �Է� ����
{
	int i, *d;

	d = (int*)malloc(sizeof(int)*n + 1);
	for (i = 0; i <= n; i++) {

		scanf("%d", &d[i]);
	}
	return d;
}

void order(int i, int j, int *P[])  // ������ ���� ���
{
	int k;
	if (i == j)
		printf("%d", i);
	else {
		k = P[i][j];
		printf("(");
		order(i, k, P);
		order(k + 1, j, P);
		printf(")");
	}
}

int minmult(int n, int d[], int *P[])   // �ּ� ���� �˰���
{
	int i, j, k, diagnonal, min_k = 0;
	int **M, temp = 0;
	M = make_array(n + 1);
	for (i = 1; i <= n; i++)
		M[i][i] = 0;
	for (diagnonal = 1; diagnonal <= n - 1; diagnonal++)  // diagonal���� 1�̸�
		for (i = 1; i <= n - diagnonal; i++) {          // �ִ밢���� �ٷ� ����
			j = i + diagnonal;                          // �ִ� �밢���� �ǹ��Ѵ�.
														// for(k~~~)�� �Ʒ��� �ش��Ѵ�.
														// M[i][j] = minimum(M[i][k] + M[k+1][j] + d[i-1] * d[k] * d[j]);
														//           i<= k <= j-1                   
			for (k = i; k <= j - 1; k++) {
				temp = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
				if (i == k) {
					M[i][j] = temp;
					min_k = k;
				}
				else if (M[i][j] > temp) {
					M[i][j] = temp;
					min_k = k;
				}

			}
			P[i][j] = min_k;    // �ּҰ��� �ִ� k�� ��
		}
	return M[1][n];    // �ּ� ���� �� ����
}