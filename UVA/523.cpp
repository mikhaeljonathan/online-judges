#include <stdio.h>
#include <string.h>

struct heapnode{
	int vtx;
	int cost;
}heaparr[10005];

int size;
int totalcost;
int costs[1005][1005];
int taxes[1005];
int visited[1005];
int distance[1005];
int pred[1005];

void swap(struct heapnode* a, struct heapnode* b){
	struct heapnode temp = *a;
	*a = *b;
	*b = temp;
}

void upheap(int idx){
	if (idx == 1) return;
	
	int paridx = idx / 2;
	if (heaparr[paridx].cost < heaparr[idx].cost) return;
	
	swap(&heaparr[paridx], &heaparr[idx]);
	upheap(paridx);
}

void pushheap(int *n, int vtx, int cost){
	(*n)++;
	heaparr[*n].vtx = vtx;
	heaparr[*n].cost = cost;
	upheap(*n);
}

void downheap(int idx, int size){
	int toidx = idx;
	
	if (2 * idx <= size && heaparr[2 * idx].cost < heaparr[toidx].cost)
		toidx = 2 * idx;
	if (2 * idx + 1 <= size && heaparr[2 * idx + 1].cost < heaparr[toidx].cost)
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

void dijkstra(int begin, int end){
	for (int i = 1; i <= size; i++){
		visited[i] = 0;
		distance[i] = 1 << 30;
		pred[i] = -1;
	}
	distance[begin] = 0;
	
	int heapcountdata = 0;
	pushheap(&heapcountdata, begin, distance[begin]);
	
	while (heapcountdata > 0){
		struct heapnode top = heaparr[1];
		pop(&heapcountdata);
		int curvtx = top.vtx;
		
		if (visited[curvtx]) continue;
		visited[curvtx] = 1;
		
		if (curvtx == end) {
			totalcost = distance[end];
			if (end != begin) totalcost -= taxes[end];
			return;
		}
		
		for (int i = 1; i <= size; i++){
			if (costs[curvtx][i] == -1) continue;
			if (visited[i]) continue;
			
			if (distance[curvtx] + costs[curvtx][i] + taxes[i] < distance[i]){
				distance[i] = distance[curvtx] + costs[curvtx][i] + taxes[i];
				pred[i] = curvtx;
				pushheap(&heapcountdata, i, distance[i]);
			}
		}
	}
	
	totalcost = distance[end];
	if (end != begin) totalcost -= taxes[end];
	return;
}

void printpath(int x){
	if (pred[x] == -1){
		printf("%d", x);
		return;
	}
	printpath(pred[x]);
	printf("-->%d", x);
}

int main (){
	int m;
	scanf("%d", &m);
	getchar();
	getchar();
	while (m--){
		char temp[1005];
		size = 0;
		scanf("%[^\n]", temp);
		char* pch = strtok(temp, " ");
		while (pch != NULL){
			sscanf(pch, "%d", &costs[1][++size]);
			pch = strtok(NULL, " ");
		}
		
		int _ = size;
		_--;
		int index = 2;
		while (_--){
			getchar();
			int size2 = 0;
			scanf("%[^\n]", temp);
			char *pch = strtok(temp, " ");
			while (pch != NULL){
				sscanf(pch, "%d", &costs[index][++size2]);
				pch = strtok(NULL, " ");
			}
			index++;
		}
		
//		for (int i = 1; i <= size; i++){
//			for (int j = 1; j  <= size; j++){
//				printf("%d ", costs[i][j]);
//			}
//			puts("");
//		}
		
		for (int i = 1; i <= size; i++) scanf("%d", &taxes[i]);
		
		getchar();
		while (gets(temp) && strcmp(temp, "")){
			int x, y;
			sscanf(temp, "%d %d", &x, &y);
			strcpy(temp, "");
			
			dijkstra(x, y);
			printf("From %d to %d :\n", x, y);
			printf("Path: "); printpath(y); puts("");
			printf("Total cost : %d\n\n", totalcost);
		}
	}
	return 0;
}
