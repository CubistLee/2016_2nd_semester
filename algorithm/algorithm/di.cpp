#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct vertex {
	int parent, child;
	int weigh;
};
struct Node {
	vertex *ptr;
	int weigh, num;
	bool check;
};


void Check_Edge(int *Dij, Node *arr, int v, int n);

int main()
{
	int n, v, e, c, w;
	Node *arr;
	int *Dij;
	int Max = 0;

	scanf("%d", &n);
	arr = new Node[n + 1];
	Dij = new int[n + 1];

	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &v, &e);
		arr[v].ptr = new vertex[e];
		arr[v].weigh = 0x0FFFFFFF;
		arr[v].check = false;
		arr[v].num = e;
		Dij[v] = 0x0FFFFFFF;
		for (int j = 0; j < e; j++)
		{
			scanf("%d%d", &c, &w);
			arr[v].ptr[j].parent = v;
			arr[v].ptr[j].child = c;
			arr[v].ptr[j].weigh = w;
		}
	}
	arr[1].weigh = 0;
	arr[1].check = true;
	Dij[1] = 0;
	Check_Edge(Dij, arr, 1, n);

	for (int i = 0; i <= n; i++)
	{
		if (Max < Dij[i])
			Max = Dij[i];
	}
	cout << Max << endl;

	return 0;
}

void Check_Edge(int *Dij, Node *arr, int v, int n)
{
	int add, min = 0x0FFFFFFF;
	int c, w;

	for (int i = 1; i <= n; i++)
	{
		if (!arr[i].check) break;
		if (i == n) return;
	}

	for (int i = 0; i < arr[v].num; i++)
	{
		c = arr[v].ptr[i].child;
		w = arr[v].ptr[i].weigh;
		if (!arr[c].check && arr[c].weigh > arr[v].weigh + w)
			arr[c].weigh = arr[v].weigh + w;
	}
	for (int i = 1; i <= n; i++)
	{
		Dij[i] = arr[i].weigh;
		if (!arr[i].check && min > Dij[i])
		{
			min = Dij[i];
			add = i;
		}
	}
	arr[add].check = true;
	Check_Edge(Dij, arr, add, n);
}