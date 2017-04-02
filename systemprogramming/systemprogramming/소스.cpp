#include <stdio.h>
#define MAX_STR_SIZE 100
int main()
{
	char str_read[MAX_STR_SIZE];

	fgets(str_read, MAX_STR_SIZE, stdin);

	printf("읽어들인 문자열 : %s \n", str_read);

	return 0;
}