#include <stdio.h>
#include <stdlib.h>
#define SIZE 7500

struct adj{
	int vtx;
	int cost;
	struct adj* next;
}*adjhead[SIZE];

struct heapnode{
	int vtx;
	int dist;
}heaparr[SIZE];

int v;
int visited[SIZE];
int distance[SIZE];

void init(){
	for (int i = 0; i < SIZE; i++) adjhead[i] = NULL;
}

void pushadj(struct adj** adjhead, int vtx, int cost){
	struct adj* newadj = (struct adj*)malloc(sizeof(struct adj));
	newadj->vtx = vtx;
	newadj->cost = cost;
	
	newadj->next = *adjhead;
	*adjhead = newadj;
}

void swap(struct heapnode* a, struct heapnode* b){
	struct heapnode temp = *a;
	*a = *b;
	*b = temp;
}

void upheap(int idx){
	if (idx == 1) return;
	
	int paridx = idx / 2;
	if (heaparr[paridx].dist < heaparr[idx].dist) return;
	
	swap(&heaparr[paridx], &heaparr[idx]);
	upheap(paridx);
}

void pushheap(int *n, int vtx, int dist){
	(*n)++;
	heaparr[*n].vtx = vtx;
	heaparr[*n].dist = dist;
	upheap(*n);
}

void downheap(int idx, int size){
	int toidx = idx;
	
	if (2 * idx <= size && heaparr[2 * idx].dist < heaparr[toidx].dist)
		toidx = 2 * idx;
	if (2 * idx + 1 <= size && heaparr[2 * idx + 1].dist < heaparr[toidx].dist)
		toidx = 2 * idx + 1;
	if (toidx == idx) return;
	
	swap(&heaparr[toidx], &heaparr[idx]);
	downheap(toidx, size);
}

void pop(int *n){
	if (*n == 1){
		(*n)--;
		return;
	}
	
	heaparr[1] = heaparr[*n];
	(*n)--;
	downheap(1, *n);
}

int dijkstra(int begin, int end){
	for (int i = 0; i < SIZE; i++){
		visited[i] = 0;
		distance[i] = 1 << 30;
	}
	distance[begin] = 0;
	
	int heapcountdata = 0;
	pushheap(&heapcountdata, begin, distance[begin]);
	
	while (heapcountdata > 0){
		struct heapnode top = heaparr[1];
		pop(&heapcountdata);
		int curvtx = top.vtx;
		int curdist = top.dist;
		
		if (visited[curvtx]) continue;
		visited[curvtx] = 1;
		
		if (curvtx == end) return distance[end];
		
		for (struct adj* curr = adjhead[curvtx]; curr; curr = curr->next){
			if (visited[curr->vtx]) continue;
			if (distance[curvtx] + curr->cost < distance[curr->vtx]){
				distance[curr->vtx] = distance[curvtx] + curr->cost;
				pushheap(&heapcountdata, curr->vtx, distance[curr->vtx]);
			}
		}
	}
	
	return distance[end];
}

void freeall(){
	for (int i = 0; i < SIZE; i++){
		struct adj* cur = adjhead[i];
		while (cur){
			struct adj* temp = cur;
			cur = cur->next;
			free(temp);
		}
	}
}

int main (){
	init();
	int e, a, b;
	scanf("%d %d %d %d", &v, &e, &a, &b);
	while (e--){
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		pushadj(&adjhead[x], y, z);
		pushadj(&adjhead[y], x, z);
	}
	printf("%d\n", dijkstra(a, b));
	freeall();
	return 0;
}
