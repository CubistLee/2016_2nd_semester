#include<stdio.h>

int main(void) {

	int num[30000];
	int quantity;
	int input;
	int order;
	int turn;
	int key;
	scanf("%d", &quantity);/* 정렬변수 개수입력*/
	for (input = 0; input < quantity; input++) {/*변수 입력 */
		scanf("%d", &num[input]);
	}
	for (order = 1; order < quantity; order++) {
		key = num[order];
		turn = order - 1;
		do {

			num[turn + 1] = num[turn];

			turn--;
		} while (turn > 0 && key < num[turn]);
		num[turn + 1] = key;
	}
	for (input = quantity-1; input >= 0; input--) {/*변수 입력 */
		printf("%d\n", num[input]);
	}

	return 0;
}