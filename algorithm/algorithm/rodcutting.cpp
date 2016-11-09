#include<stdio.h>
#include<malloc.h>

int main()
{
	int the_number;
	int p;
	int* unit_price;
	int* max_price;
	int* trace;

	scanf("%d", &the_number);

	unit_price = (int *)calloc(the_number + 1,sizeof(int));
	max_price = (int *)calloc(the_number + 1, sizeof(int));
	trace = (int *)calloc(the_number + 1, sizeof(int));
	// 배열 초기화
	for(p=1;p<=the_number;p++)
	{
		scanf("%d", &unit_price[p]);
	}
}