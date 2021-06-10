#include <stdio.h>
#include <stdlib.h>
#define SIZE 100005

struct adjnode{
	long long vtx;
	long long cost;
	struct adjnode* next;
}*adjhead[SIZE];

struct heapnode{
	long long vtx;
	long long cost;
}heaparr[10 * SIZE];

long long visited[SIZE];
long long distance[SIZE];
long long pred[SIZE];

void pushadj(long long a, long long b, long long w){
	struct adjnode* newadj = (struct adjnode*)malloc(sizeof(struct adjnode));
	newadj->vtx = b;
	newadj->cost = w;
	newadj->next = adjhead[a];
	adjhead[a] = newadj;
}

void swap(struct heapnode* a, struct heapnode* b){
	struct heapnode temp = *a;
	*a = *b;
	*b = temp;
}

void upheap(long long idx){
	if (idx == 1) return;
	
	long long paridx = idx / 2;
	
	if (heaparr[paridx].cost < heaparr[idx].cost) return;
	
	swap(&heaparr[paridx], &heaparr[idx]);
	upheap(paridx);
}

void pushheap(long long *n, long long vtx, long long cost){
	(*n)++;
	heaparr[*n].vtx = vtx;
	heaparr[*n].cost = cost;
	upheap(*n);
}

void downheap(long long idx, long long size){
	long long toidx = idx;
	
	if (2 * idx <= size && heaparr[2 * idx].cost < heaparr[toidx].cost)
		toidx = 2 * idx;
	if (2 * idx + 1 <= size && heaparr[2 * idx + 1].cost < heaparr[toidx].cost)
		toidx = 2*idx + 1;
	if (toidx == idx) return;
	
	swap(&heaparr[toidx], &heaparr[idx]);
	downheap(toidx, size);
}

void pop(long long *n){
	if (*n == 1){
		(*n)--;
		return;
	}
	
	heaparr[1] = heaparr[*n];
	(*n)--;
	downheap(1, *n);
}

void dijkstra(long long begin, long long end){
	for (long long i = 0; i < SIZE; i++){
		visited[i] = 0;
		long long temp = 1 << 30;
		distance[i] = temp << 30;
		pred[i] = -1;
	}
	distance[begin] = 0;
	
	long long heapcountdata = 0;
	pushheap(&heapcountdata, begin, distance[begin]);
	
	while (heapcountdata > 0){
		struct heapnode top = heaparr[1];
		pop(&heapcountdata);
		long long curvtx = top.vtx;
		
		
		if (visited[curvtx]) continue;
		visited[curvtx] = 1;
		if (curvtx == end) return;
		
		for (struct adjnode* curr = adjhead[curvtx]; curr; curr = curr->next){
			if (visited[curr->vtx]) continue;
			if (distance[curvtx] + curr->cost < distance[curr->vtx]){
				distance[curr->vtx] = distance[curvtx] + curr->cost;
				pred[curr->vtx] = curvtx;
				pushheap(&heapcountdata, curr->vtx, distance[curr->vtx]);
			}
		}
	}
	return;
}

void init(){
	for (long long i = 0; i < SIZE; i++) adjhead[i] = NULL;
}

void printorder(long long x){
	if (pred[x] == -1){
		printf("%lld", x);
		return;
	}
	printorder(pred[x]);
	printf(" %lld", x);
}

void freeall(){
	for (long long i = 0; i < SIZE; i++){
		struct adjnode* cur = adjhead[i];
		while (cur){
			struct adjnode* tobedel = cur;
			cur = cur->next;
			free(tobedel);
		}
	}
}

int main (){
	init();
	long long n, m;
	scanf("%lld %lld", &n, &m);
	while (m--){
		long long a, b, w;
		scanf("%lld %lld %lld", &a, &b, &w);
		pushadj(a, b, w);
		pushadj(b, a, w);
	}
	dijkstra(1, n);
	long long temp = 1 << 30;
	temp = temp << 30;
	if (distance[n] >= temp) printf("-1");
	else printorder(n);
	puts("");
	return 0;
}
