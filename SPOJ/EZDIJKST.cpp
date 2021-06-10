#include <stdio.h>
#include <stdlib.h>
#define SIZE 10005

struct tdata{
	int vertex;
	int cost;
	struct tdata* next;
}*adjhead[SIZE];

struct theap{
	int vertex;
	int dist;
}heaparr[SIZE];

int distance[SIZE];
int visited[SIZE];
int v, k;

void swap(struct theap* a, struct theap* b){
	struct theap temp = *a;
	*a = *b;
	*b = temp;
}

void downheap(int idx, int size){
	int toidx = idx;
	
	if (2 * idx <= size && heaparr[2 * idx].dist < heaparr[toidx].dist)
		toidx = 2 * idx;
	if (2 * idx + 1 <= size && heaparr[2 * idx + 1].dist < heaparr[toidx].dist)
		toidx = 2 * idx + 1;
	if (idx == toidx) return;
	
	swap(&heaparr[idx], &heaparr[toidx]);
	
	downheap(toidx, size);
}

void popheap(int *n){
	if (*n == 1){
		(*n)--;
		return;
	}
	
	heaparr[1] = heaparr[*n];
	(*n)--;
	downheap(1, *n);
}

void upheap(int idx){
	if (idx == 1) return;
	
	int paridx = idx / 2;
	if (heaparr[paridx].dist < heaparr[idx].dist) return;
	
	swap(&heaparr[paridx], &heaparr[idx]);
	upheap(paridx);
}

void pushheap(int *n, int dist, int vertex){
	(*n)++;
	heaparr[*n].dist = dist;
	heaparr[*n].vertex = vertex;
	
	upheap(*n);
}

int dijkstra(int begin, int end){
	for (int i = 1; i <= v; i++){
		visited[i] = 0;
		distance[i] = 1 << 30;
	}
	distance[begin] = 0;
	
	int heapcountdata = 0;
	pushheap(&heapcountdata, distance[begin], begin);
	
	while (heapcountdata > 0){
		struct theap top = heaparr[1];
		popheap(&heapcountdata);
		int curvertex = top.vertex;
		int curdist = top.dist;
		
		if (visited[curvertex]) continue;
		visited[curvertex] = 1;
		
		if (curvertex == end) return distance[end];
		
		for (struct tdata* current = adjhead[curvertex]; current; current = current->next){
			if (visited[current->vertex]) continue;
			if (distance[curvertex] + current->cost < distance[current->vertex]){
				distance[current->vertex] = distance[curvertex] + current->cost;
				pushheap(&heapcountdata, distance[current->vertex], current->vertex);
			}
		}
	}
	
	return distance[end];
}

void pushlist(struct tdata** adjheadlocal, int vertex, int cost){
	struct tdata* newt = (struct tdata*)malloc(sizeof(struct tdata));
	newt->vertex = vertex;
	newt->cost = cost;
	
	newt->next = *adjheadlocal;
	*adjheadlocal = newt;
}

void init(){
	for (int i = 0; i < SIZE; i++) {
		free(adjhead[i]);
		adjhead[i] = NULL;
	}
}

int main (){
	int t;
	scanf("%d", &t);
	while (t--){
		init();
		scanf("%d %d", &v, &k);
		while (k--){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			pushlist(&adjhead[a], b, c);
		}
		
		int begin, end;
		scanf("%d %d", &begin, &end);
		
		int cost = dijkstra(begin, end);
		if (cost >= (1 << 30)) puts("NO");
		else printf("%d\n", cost);
	}
	return 0;
}
