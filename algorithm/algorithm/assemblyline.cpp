#include<stdio.h>
int min(int a, int b);
int main() {
	int e[3] = { 0 };
	int x[3] = { 0 };
	int a1[101] = { 0 };
	int a2[101] = { 0 };
	int t1[100] = { 0 };
	int t2[100] = { 0 };
	int l1[101] = { 0 };
	int l2[101] = { 0 };
	int f1[101] = { 0 };
	int f2[101] = { 0 };
	int number;
	int p;
	scanf("%d", &number);
	scanf("%d %d", &e[1], &e[2]);
	scanf("%d %d", &x[1], &x[2]);
	
	for (p = 1; p <= number; p++) {
		scanf("%d", &a1[p]);
	}

	for (p = 1; p <= number; p++) {
		scanf("%d", &a2[p]);
	}
	
	for (p = 1; p < number; p++) {
		scanf("%d", &t1[p]);
	}

	for (p = 1; p < number; p++) {
		scanf("%d", &t2[p]);
	}
	f1[1] = e[1] + a1[1];
	f2[1] = e[2] + a2[1];
	for (p = 2; p <= number; p++) {
		int a, b;
		a = f1[p - 1] + a1[p];
		b = f2[p - 1] + t2[p - 1] + a1[p];
		f1[p] = min(a, b);
		if (f1[p] == a)l1[p] = 1;
		else l1[p] = 2;
		a = f2[p - 1] + a2[p];
		b = f1[p - 1] + t1[p - 1] + a2[p];
		f2[p] = min(a, b);
		if (f2[p] == a)l2[p] = 2;
		else l2[p] = 1;

	
	}
	printf("abc");
}
int min(int a, int b) {
	if (a > b)
		return b;
	else return a;
}