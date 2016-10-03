#include<stdio.h> // 2013011554 이새한	

int arr[100001] = { 0, };

int sub_heap(int *arr, int index, int thenum);
int range_up(int *arr, int thenum);
int range_down(int *arr, int index, int thenum);
int heap(int *arr, int index);
int swap(int *a, int *b);

int main()
{
	int number = 0;
	int	command; 
	int address, value;

	while (1){
		scanf("%d", &command);
		if (command == 1){
			scanf("%d", &value);
			number++;
			arr[number] = value;
			range_up(arr, number);
		}
		else if (command == 2){
			if (number > 0) {
				value = heap(arr, number);
				printf("%d ", value);
				number--;
			}
		}
		else if (command == 3){
			scanf("%d%d", &address, &value);
			arr[address] = value;
			sub_heap(arr, address, number);
		}
		else 
			break;
	}
	printf("\n");
	for (int i = 1; i <= number; i++)
		printf("%d ", arr[i]);
	return 0;
}
int sub_heap(int *arr, int index, int thenum)
{
	if (index == 1) range_down(arr, 1, thenum);
	else if (arr[index] > arr[index / 2]){
		range_up(arr, index);
	}
	else if (index* 2 <= thenum){
		range_down(arr, index, thenum);
	}
	return 0;
}
// 대체시 케이스에 따른 힙정렬 함수
int range_up(int *arr, int thenum)
{
	if (thenum == 1) return 0;
	if (arr[thenum / 2] < arr[thenum]){
		swap(arr + thenum / 2, arr + thenum);
		if (thenum > 1)
			range_up(arr,thenum / 2);
	}
	return 0;

}
//상향성 힙정렬함수
int range_down(int *arr, int index, int thenum){
	if (index * 2 > thenum)
		return 0;
	if (index * 2 + 1> thenum){
		if (arr[thenum] > arr[index])
			swap(arr + thenum, arr + index);
	}
	else{
		if (arr[index * 2] > arr[index * 2 + 1]){
			if (arr[index * 2] > arr[index]){
				swap(arr + (index * 2), arr + index);
				range_down(arr, index * 2, thenum);
			}
		}
		else if (arr[index * 2 + 1] > arr[index]){
			swap(arr + (index * 2 + 1), arr + index);
			range_down(arr, index * 2 +1, thenum);
		}
	}
	return 0;
}
//하향성 힙정렬 함수
int heap(int *arr, int index){
	int max = arr[1];
	swap(arr + 1, arr + index);
	range_down(arr, 1, index-1);
	return max;
}
// 최대값 추출함수
int swap(int *a, int *b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
	return 0;
}
// 스왑함수