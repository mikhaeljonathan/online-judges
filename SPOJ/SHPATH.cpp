#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 200003
#define BASE 31

struct city{
	int num;
	int cost;
	struct city* next;
}*adjhead[SIZE];

struct nodeheap{
	int num;
	int dist;
}heaparr[SIZE];

int idx[SIZE];
char name[SIZE][15];
int visited[SIZE];
int distance[SIZE];
int n;

int gethash(char x[]){
	int key = 0;
	int len = strlen(x);
	for (int i = 0; i < len; i++){
		key = ((key * BASE) + x[i] - 'a' + 1) % SIZE;
	}
	key %= SIZE;
	
	for (int i = key; i + 1 != key; i = (i + 1) % SIZE){
		if (!strcmp(name[i], "")) return i;
		if (!strcmp(name[i], x)) return i;
	}
}

void pushadj(struct city** adj, int nr, int cost){
	struct city* newcity = (struct city*)malloc(sizeof(struct city));
	newcity->num = nr;
	newcity->cost = cost;
	
	newcity->next = *adj;
	*adj = newcity;
}

struct nodeheap makestruct(int v, int dist){
	struct nodeheap newnode;
	newnode.num = v;
	newnode.dist = dist;
	return newnode;
}

void swap(struct nodeheap* a, struct nodeheap* b){
	struct nodeheap temp = *a;
	*a = *b;
	*b = temp;
}

void downheap(int idx, int size){
	int toidx = idx;
	
	if (2 * idx <= size && heaparr[2 * idx].dist < heaparr[toidx].dist) {
		toidx = 2 * idx;
	}
	if (2 * idx + 1 <= size && heaparr[2 * idx + 1].dist < heaparr[toidx].dist){
		toidx = 2 * idx + 1;
	}
	
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

void upheap(int idx){
	if (idx == 1) return;
	
	int paridx = idx / 2;
	if (heaparr[paridx].dist < heaparr[idx].dist) return;
	
	swap(&heaparr[paridx], &heaparr[idx]);
	upheap(paridx);
}

void pushheap(int *n, struct nodeheap newnode){
	(*n)++;
	heaparr[*n] = newnode;
	upheap(*n);
}

int dijkstra(int a, int b){
	for (int i = 1; i <= n; i++){
		visited[i] = 0;
		distance[i] = 1 << 30;
	}
	distance[a] = 0;
	
	int heapcount = 0;
	pushheap(&heapcount, makestruct(a, distance[a]));
	
	while (heapcount > 0){
		struct nodeheap top = heaparr[1];
		pop(&heapcount);
		int curvertex = top.num;
		int curdist = top.dist;
		
		if (visited[curvertex]) continue;
		visited[curvertex] = 1;
		
		if (curvertex == b) return distance[b];
		
		for (struct city* cur = adjhead[curvertex]; cur; cur = cur->next){
			if (visited[cur->num]) continue;
			if (distance[curvertex] + cur->cost < distance[cur->num]){
				distance[cur->num] = distance[curvertex] + cur->cost;
				pushheap(&heapcount, makestruct(cur->num, distance[cur->num]));
			}
		}
	}
	
	return distance[b];
}

void init(){
	for (int i = 0; i < SIZE; i++) {
		idx[i] = -1;
		strcpy(name[i], "");
		adjhead[i] = NULL;
	}
}

int main (){
	int s;
	scanf("%d", &s);
	while (s--){
		init();
		scanf("%d", &n);
		for (int i = 1; i <= n; i++){
			getchar();
			char NAME[15];
			scanf("%s", NAME);
			idx[gethash(NAME)] = i;
			strcpy(name[gethash(NAME)], NAME);
			
			int p;
			scanf("%d", &p);
			while (p--){
				int nr, cost;
				scanf("%d %d", &nr, &cost);
				pushadj(&adjhead[i], nr, cost);
			}
		}
		
		int r;
		scanf("%d", &r);
		while (r--){
			getchar();
			char NAME1[15], NAME2[15];
			scanf("%s %s", NAME1, NAME2);
			int cost = dijkstra(idx[gethash(NAME1)], idx[gethash(NAME2)]);
			printf("%d\n", cost);
		}
	}
	return 0;
}
