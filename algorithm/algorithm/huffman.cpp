//2013011554 ¿Ãªı«—
#include<stdio.h>
#include<stdlib.h>

struct Element {
	int f;
	Element *L, *R;
};
struct Node {
	Element *add;
};

Element *makeUpElement(Element *L, Element *R);
Element *makeElement(int f);
void Build_UP(Node *arr, int n);
void Build_DOWN(Node *arr, int n, int max);
void Build_Heap(Node *arr, int n);
void Heap(Node *arr, int n);
int sum_H_Tree(Element *node, int depth);
int nohuff(int n);
void swap(Node *a, Node *b);

int main()
{
	int n, all_f, f;
	int NH_code, H_code = 0;
	Node *arr;
	char string[5];

	scanf("%d", &n);
	arr = (Node*)malloc(sizeof(Node)*(n + 1));
	for (int i = 1; i <= n; i++)
	{
		scanf("%s%d", string, &f);
		arr[i].add = makeElement(f);
	}
	scanf("%d", &all_f);

	if (n == 1)
	{
		printf("%d\n%d", all_f, all_f);
		return 0;
	}
	NH_code = nohuff(n) * all_f;
	Build_Heap(arr, n);

	while (n>1)
	{
		Element *tmp1, *tmp2;
		tmp1 = arr[1].add;
		Heap(arr, n--);
		tmp2 = arr[1].add;
		Heap(arr, n);
		arr[n].add = makeUpElement(tmp1, tmp2);

		Build_UP(arr, n);
	}

	H_code = sum_H_Tree(arr[1].add, 0);

	printf("%d\n%d", NH_code, H_code);

	return 0;
}

Element *makeElement(int f)
{
	Element *New = (Element*)malloc(sizeof(Element));
	New->f = f;
	New->L = New->R = NULL;
	return New;
}
Element *makeUpElement(Element *L, Element *R)
{
	Element *New = (Element*)malloc(sizeof(Element));

	New->L = L;
	New->R = R;
	New->f = L->f + R->f;

	return New;
}
void Build_UP(Node *arr, int n)
{
	if (n <= 1)
		return;
	if (arr[n].add->f < arr[n / 2].add->f)
	{
		swap(&arr[n], &arr[n / 2]);
		Build_UP(arr, n / 2);
	}
}
void Build_DOWN(Node *arr, int n, int max)
{
	if (n * 2 > max) return;
	if (n * 2 == max)
	{
		if (arr[n * 2].add->f < arr[n].add->f)
			swap(&arr[n * 2], &arr[n]);
		return;
	}
	else
	{
		if (arr[n * 2].add->f < arr[n * 2 + 1].add->f)
		{
			if (arr[n * 2].add->f < arr[n].add->f)
			{
				swap(&arr[n * 2], &arr[n]);
				Build_DOWN(arr, n * 2, max);
			}
		}
		else if (arr[n * 2 + 1].add->f < arr[n].add->f)
		{
			swap(&arr[n * 2 + 1], &arr[n]);
			Build_DOWN(arr, n * 2 + 1, max);
		}
	}

}
void Build_Heap(Node *arr, int n)
{
	for (int i = 1; i <= n; i++)
		Build_UP(arr, i);
}
void Heap(Node *arr, int n)
{
	swap(&arr[1], &arr[n]);
	Build_DOWN(arr, 1, n - 1);
}
int sum_H_Tree(Element *node, int depth)
{
	if (node == NULL) return 0;
	if (node->L == NULL && node->R == NULL)
		return depth * node->f;
	return sum_H_Tree(node->L, depth + 1) + sum_H_Tree(node->R, depth + 1);
}
int nohuff(int n)
{
	int t = 0;
	while (1)
	{
		n /= 2;
		t++;
		if (n == 0) break;
	}
	return t;
}
void swap(Node *a, Node *b)
{
	Element *t;
	t = a->add;
	a->add = b->add;
	b->add = t;
}