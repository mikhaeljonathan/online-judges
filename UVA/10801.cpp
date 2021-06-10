#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1005

struct adjnode{
	int floor;
	int cost;
	struct adjnode* next;
}*adjhead[10][SIZE];

struct heapnode{
	int lift;
	int floor;
	int distance;
}heaparr[SIZE];

int visited[10][SIZE];
int distance[10][SIZE];
int n, k;

void pushadj(struct adjnode** adj, int floor, int cost){
	struct adjnode* newn = (struct adjnode*)malloc(sizeof(struct adjnode));
	newn->floor = floor;
	newn->cost = cost;
	
	newn->next = *adj;
	(*adj) = newn;
}

void init(){
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < SIZE; j++)
			adjhead[i][j] = NULL;
}

void swap(struct heapnode* a, struct heapnode* b){
	struct heapnode temp = *a;
	*a = *b;
	*b = temp;
}

void upheap(int idx){
	if (idx == 1) return;
	
	int paridx = idx / 2;
	if (heaparr[paridx].distance < heaparr[idx].distance) return;
	
	swap(&heaparr[paridx], &heaparr[idx]);
	upheap(paridx);
}

void pushheap(int *n, int lift, int floor, int dist){
	(*n)++;
	heaparr[*n].lift = lift;
	heaparr[*n].floor = floor;
	heaparr[*n].distance = dist;
	
	upheap(*n);
}

void downheap(int idx, int size){
	int toidx = idx;
	
	if (2 * idx <= size && heaparr[2 * idx].distance < heaparr[toidx].distance)
		toidx = 2 * idx;
	if (2 * idx + 1 <= size && heaparr[2 * idx + 1].distance < heaparr[toidx].distance)
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

int abs(int x){
	return (x < 0) ? -x : x;
}

int dijkstra(int begin, int end){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < SIZE; j++){
			visited[i][j] = 0;
			distance[i][j] = 1 << 30;
		}
	}
	
	int heapcountdata = 0;
	for (int i = 0; i < n; i++) {
		if (adjhead[i][0]){
			distance[i][0] = 0;
			pushheap(&heapcountdata, i, 0, distance[i][0]);
		}
	}
	
	while (heapcountdata > 0){
		struct heapnode top = heaparr[1];
		pop(&heapcountdata);
		int curlift = top.lift;
		int curfloor = top.floor;
		int curdist = top.distance;
		
		if (visited[curlift][curfloor]) continue;
		visited[curlift][curfloor] = 1;
		
		for (struct adjnode* cur = adjhead[curlift][curfloor]; cur; cur = cur->next){
			if (visited[curlift][cur->floor]) continue;
			if (distance[curlift][curfloor] + abs(cur->floor - curfloor)*cur->cost < distance[curlift][cur->floor]){
				distance[curlift][cur->floor] = distance[curlift][curfloor] + abs(cur->floor - curfloor)*cur->cost;
				pushheap(&heapcountdata, curlift, cur->floor, distance[curlift][cur->floor]);
			}
		}
		
		for (int i = 0; i < n; i++){
			if (i == curlift) continue;
			if (!adjhead[i][curfloor]) continue;
			if (visited[i][curfloor]) continue;
			if (distance[curlift][curfloor] + 60 < distance[i][curfloor]){
				distance[i][curfloor] = distance[curlift][curfloor] + 60;
				pushheap(&heapcountdata, i, curfloor, distance[i][curfloor]);
			}
		}
	}
	
	int ret = 1 << 30;
	
	for (int i = 0; i < n; i++){
		if (distance[i][end] < ret)
			ret = distance[i][end];
	}
	
	return ret;
}

void freeall(){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < SIZE; j++){
			struct adjnode* cur = adjhead[i][j];
			while (cur){
				struct adjnode* temp = cur;
				cur = cur->next;
				free(temp);
			}
			adjhead[i][j] = NULL;
		}
	}
}

int main (){
	while (scanf("%d %d", &n, &k) != EOF){
		init();
		int T[n];
		for (int i = 0; i < n; i++) scanf("%d", &T[i]);
		
		for (int i = 0; i < n; i++){
			getchar();
			char in[1000];
			scanf("%[^\n]", in);
			
			int first = 1;
			int bfore;
			char* pch = strtok(in, " ");
			while (pch != NULL){
				int temp;
				sscanf(pch, "%d", &temp);
				if (first) first = 0;
				else {
					pushadj(&adjhead[i][temp], bfore, T[i]);
					pushadj(&adjhead[i][bfore], temp, T[i]);
				}
				bfore = temp;
				pch = strtok(NULL, " ");
			}
		}

		int cost = dijkstra(0, k);
		if (cost >= (1 << 30)) puts("IMPOSSIBLE");
		else printf("%d\n", cost);

		freeall();
	}
	return 0;
}
