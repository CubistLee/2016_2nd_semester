#include<stdio.h>
#include<string.h>

int main()
{
	int R, C;
	int i, j;
	char A[500];
	char B[500];
	int sequ[500][500] = { 0 };
	scanf("%s", &B);
	scanf("%s", &A);
	//printf("%d", strlen(A));
	//printf("%d", strlen(B));
	R = strlen(A);
	C = strlen(B);
	for (i = 1; i <= R; i++)
	{
		for (j = 1; j <= C; j++)
		{
			if (A[i - 1] == B[j - 1])
			{
				sequ[i][j] = sequ[i - 1][j - 1] + 1;
				if (sequ[i][j] != sequ[i - 1][j] && sequ[i][j] != sequ[i][j - 1])
					printf("%c", A[i - 1]);
			}
			else if (sequ[i - 1][j] > sequ[i][j - 1])
				sequ[i][j] = sequ[i - 1][j];
			else
				sequ[i][j] = sequ[i][j - 1];
		}
	}

	//printf("complete");


}