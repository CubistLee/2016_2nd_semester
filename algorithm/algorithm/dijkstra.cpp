#include <stdio.h>
#include <malloc.h>
#define UNADJACENCY 0
#define INF   9999
#define UNDEFINED -1
void malloc_arry(int, int);
void release_arry(int);
void dijkstra(int, int);
void enqueue(int);
void relax(int, int);
void print_path(int);
int queue_empty();
int extract_min(void);
struct queue {
	int *data;
	int front;
	int rear;
}Q;
int **w; // variable for memorizing weights between edges.
int *d; // it saves information of the shortest direction.
int *pre; // it is necessary to back track the root.
		  /*
		  5 1 5
		  10
		  1 2 10
		  1 3 5
		  2 4 1
		  2 3 2
		  3 2 3
		  3 4 9
		  3 5 2
		  4 5 4
		  5 4 6
		  5 1 7
		  */
int main(void)
{
	int nov = 0; // the number of vertexe
	int startv = 0; // starting vertex.
	int endv = 0; // the vertext of the end.
	int noe = 0; // the number of edges
	int i;
	int v = 0, n = 0, weight = 0;
	scanf("%d%d%d", &nov, &startv, &endv);
	scanf("%d", &noe);
	malloc_arry(nov, noe);
	for (i = 0; i < noe; i++)
	{
		scanf("%d%d%d", &v, &n, &weight);
		w[v - 1][n - 1] = weight;
	}
	dijkstra(nov, startv - 1);
	printf("%d에서 %d까지의 최단 거리는 %d입니다.\n경로는", startv, endv, d[endv - 1]);
	print_path(endv - 1);
	printf("%d 입니다.\n", endv);
	release_arry(nov);
	return 0;
}
/*
allocate the memory to double point variable.
- we need nov * nov array.
- we will allocate the memory as much as we need.
*/
void malloc_arry(int nov, int noe)
{
	int i, j;

	// it means that allocating the memory as much as the column of the array
	w = (int**)malloc(sizeof(int*) * nov);
	// allocate the memory as much as the number of edges.
	d = (int*)malloc(sizeof(int*) * nov);
	pre = (int*)malloc(sizeof(int*) * nov);
	// allocate the memory for the queue.
	Q.data = (int*)malloc(sizeof(int*) * nov);
	// allocate the memory as much as the row of the array
	for (i = 0; i < nov; i++)
	{
		*(w + i) = (int *)malloc(sizeof(int) * nov);
		// we have to init elements in the array with 0(zero).
		for (j = 0; j < nov; j++)
		{
			*(*(w + i) + j) = 0;
		}
	}
}
/*
release the memory that we allocated the array.
*/
void release_arry(int nov)
{
	int i;
	// Firstly. release the memory that related to the row
	for (i = 0; i < nov; i++)
	{
		free(*(w + i));
	}
	// release the memory that related to directions.
	free(d); free(pre); free(Q.data);
	// Lastly, release the memory that related to the column
	free(w);
}
/*
insert the vertext into the queue.
*/
void enqueue(int v)
{
	Q.data[Q.rear++] = v;
}
/*
examine whether the queue is empty or not
*/
int queue_empty()
{
	return Q.front == Q.rear;
}
void print_path(int v)
{
	if (pre[v] == UNDEFINED) return;
	print_path(pre[v]);
	printf(" %d >", pre[v] + 1);
}
/*
find the nearest vertical
*/
int extract_min()
{
	int i, min = INF;
	int j = 0;
	int v = 0;
	int pre, temp;
	// search for the vertical in the queue.
	for (i = Q.front; i < Q.rear; i++)
	{
		// update the information about the vertical.
		if (d[Q.data[i]] < min)
		{
			min = d[Q.data[i]];
			v = Q.data[i];
			j = i;
		}
	}
	// remove the element from the queue.
	Q.data[j] = Q.data[Q.front];

	Q.front++;

	return v;
}
/*
updates the distances of each edge with more shorter than previous distance.
*/
void relax(int u, int v)
{
	if (d[v] > (d[u] + w[u][v]))
	{
		d[v] = d[u] + w[u][v];
		pre[v] = u;
	}
}
/*
Dijkstra's Algorithms
- it find the shortest distances of each edge.
*/
void dijkstra(int nov, int s)
{
	int i = 0;
	int u = 0;
	// set the distance of other edges with INF.
	for (i = 0; i < nov; i++)
	{
		d[i] = INF;
		// it is necessary to do back tracking
		pre[i] = UNDEFINED;
	}
	d[s] = 0; // set the distance of starting point.
			  // insert vertexs into the queue except starting edge.
	for (i = 0; i < nov; i++)
	{
		enqueue(i);
	}
	while (!queue_empty())
	{
		u = extract_min(); // find the nearest edge.
		for (i = 0; i < nov; i++)
		{
			// find a adjacency vertical.
			if (w[u][i] != UNADJACENCY)
			{
				relax(u, i);
			}
		}
	}
}