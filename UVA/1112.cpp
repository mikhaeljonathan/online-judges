#include <stdio.h>
#include <stdlib.h>

struct node{
	int cells;
	int time;
	struct node* next;
}*adjhead[105];
 
struct heapdata{
	int cells;
	int dist;
}heaparr[1005];
 
int n, t, e;
int visited[105];
int distance[105];
 
void swap(struct heapdata* a, struct heapdata* b){
	struct heapdata temp = *a;
	*a = *b;
	*b = temp;
}
 
void upheap(int idx){
	if (idx == 1) return;
	int paridx = idx / 2;
	if (heaparr[paridx].dist < heaparr[idx].dist) return;
	swap (&heaparr[paridx], &heaparr[idx]);
	upheap(paridx);
}
 
void pushheap(int *n, int cells, int dist){
	(*n)++;
	heaparr[*n].cells = cells;
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
 
void dijkstra(int e, int n){
	for (int i = 1; i <= n; i++){
		visited[i] = 0;
		distance[i] = 1 << 30;
	}
	distance[e] = 0;
 
	int heapcountdata = 0;
	pushheap(&heapcountdata, e, distance[e]);
 
	while (heapcountdata > 0){
		struct heapdata top = heaparr[1];
		pop(&heapcountdata);
		int curcells = top.cells;
		int curdist = top.dist;
 
		if (visited[curcells]) continue;
		visited[curcells] = 1;
 
		for (struct node* cur = adjhead[curcells]; cur; cur = cur->next){
			if (visited[cur->cells]) continue;
			if (distance[curcells] + cur->time < distance[cur->cells]){
				distance[cur->cells] = distance[curcells] + cur->time;
				pushheap(&heapcountdata, cur->cells, distance[cur->cells]);
			}
		}
	}
}
 
void pushadj(struct node** adj, int b, int time){
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->cells = b;
	newnode->time = time;
 
	newnode->next = *adj;
	*adj = newnode;
}
 
void init(){
	for (int i = 0; i < 105; i++) adjhead[i] = NULL;
}
 
int main (){
	int tc;
	scanf("%d", &tc);
	while (tc--){
		getchar();
		getchar();
		init();
		scanf("%d %d %d", &n, &e, &t);
		int m;
		scanf("%d", &m);
		while (m--){
			int a, b, time;
			scanf("%d %d %d", &a, &b, &time);
			pushadj(&adjhead[a], b, time);
			pushadj(&adjhead[b], a, time);
		}
		dijkstra(e, n);
		int res = 0;
		for (int i = 1; i <= n; i++) if (distance[i] <= t) res++;
		printf("%d\n", res);
		if (tc != 0) puts("");
	}
	return 0;
}
