#include <stdio.h>
#include <stdlib.h>
#define SIZE 20005

int n, m, s, t;

struct node{
	int v;
	int cost;
	struct node* next;
}*adjhead[SIZE];

struct heapnode{
	int v;
	int dist;
}heaparr[SIZE * 2];

int visited[SIZE];
int distance[SIZE];

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

void pushheap(int *n, int v, int dist){
	(*n)++;
	heaparr[*n].v = v;
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
	for (int i = 0; i < n; i++){
		visited[i] = 0;
		distance[i] = 1 << 30;
	}
	distance[begin] = 0;
	
	int heapcountdata = 0;
	pushheap(&heapcountdata, begin, distance[begin]);
	
	while (heapcountdata > 0){
		struct heapnode top = heaparr[1];
		pop(&heapcountdata);
		int curv = top.v;
		int curdist = top.dist;
		
		if (visited[curv]) continue;
		visited[curv] = 1;
		
		if (curv == end) return distance[end];
		
		for (struct node* curr = adjhead[curv]; curr; curr = curr->next){
			if (visited[curr->v]) continue;
			if (distance[curv] + curr->cost < distance[curr->v]){
				distance[curr->v] = distance[curv] + curr->cost;
				pushheap(&heapcountdata, curr->v, distance[curr->v]);
			}
		}
	}
	
	return distance[end];
}

void pushadj(struct node** adj, int v, int cost){
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->v = v;
	newnode->cost = cost;
	
	newnode->next = *adj;
	(*adj) = newnode;
}

void init(){
	for (int i = 0; i < SIZE; i++) adjhead[i] = NULL;
}

int main (){
	int N;
	scanf("%d", &N);
	for(int tc = 1; tc <= N; tc++){
		init();
		scanf("%d %d %d %d", &n, &m, &s, &t);
		while (m--){
			int a, b ,w;
			scanf("%d %d %d", &a, &b, &w);
			pushadj(&adjhead[a], b, w);
			pushadj(&adjhead[b], a, w);
		}
		int cost = dijkstra(s, t);
		printf("Case #%d: ", tc);
		if (cost >= (1 << 30)) puts("unreachable");
		else printf("%d\n", cost);
	}
	return 0;
}
