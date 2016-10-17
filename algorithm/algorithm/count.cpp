#include<stdio.h>
#include<stdlib.h>


int main(void)
{
	int *input;
	int max;
	int input_num, query_num; //각 인풋 개수의 매개변수
	int parameter;// 매개변수
	int parameter2;
	int i;
	int* A;
	int* B;
	int* count;
	scanf("%d %d %d", &input_num, &max, &query_num);
	input = (int*)malloc(sizeof(int)*input_num);
	A = (int *)malloc(sizeof(int)*query_num);
	B = (int *)malloc(sizeof(int)*query_num);
	count = (int*)malloc(sizeof(int)*(max + 1));
	for (i = 0; i < max + 1; i++) {
		count[i] = 0;
	}
	for(parameter=0;query_num>parameter;parameter++)
	{
		scanf("%d %d", &A[parameter], &B[parameter]);
	}

	for (parameter = 0;input_num>parameter; parameter++)
	{
		scanf("%d", &input[parameter]);
	}
	// 인풋 변수 완료
	/*printf("%d\n", A[0]);
	printf("%d\n", A[1]);
	printf("%d\n", A[2]);*/
	for (parameter = 0; input_num > parameter; parameter++) {
		count[input[parameter]]++;
	}
	for (parameter = 0; max  > parameter; parameter++) {
		count[parameter + 1] = count[parameter] + count[parameter + 1];
	}
	for (i = 0; i < query_num; i++) {
		printf("%d\n", (count[B[i]] - count[A[i] - 1]));
	}

	free(input);
	free(A);
	free(B);
}
