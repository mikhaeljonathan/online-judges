#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

struct adjnode{
	int station;
	int cost;
	struct adjnode* next;
}*adjhead[2][SIZE];

struct heapnode{
	int station;
	int distance;
	int commercial;
	int ticket;
}heaparr[1000 * SIZE];

struct point{
	int x;
	int y;
};

int n, s, e;
int visited[2][SIZE];
int distance[2][SIZE];
struct point pred[2][SIZE];
int globalticket;

void init(){
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < SIZE; j++) 
			adjhead[i][j] = NULL;
}

void pushadj(struct adjnode** adjlocal, int station, int cost){
	struct adjnode* newadj = (struct adjnode*)malloc(sizeof(struct adjnode));
	newadj->station = station;
	newadj->cost = cost;
	
	newadj->next = *adjlocal;
	*adjlocal = newadj;
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

void pushheap(int *n, int commercial, int station, int distance, int ticket){
	(*n)++;
	heaparr[*n].station = station;
	heaparr[*n].distance = distance;
	heaparr[*n].commercial = commercial;
	heaparr[*n].ticket = ticket;
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

int dijkstra(int begin, int end){
	for (int i = 0; i < 2; i++){
		for (int j = 1; j <= n; j++){
			visited[i][j] = 0;
			distance[i][j] = 1 << 30;
			pred[i][j].x = pred[i][j].y = -1;
		}
	}
	
	distance[0][begin] = 0;
	
	int heapcountdata = 0;
	pushheap(&heapcountdata, 0, begin, distance[0][begin], 0);
	
	while (heapcountdata > 0){
		struct heapnode top = heaparr[1];
		pop(&heapcountdata);
		int curstation = top.station;
		int curdistance = top.distance;
		int curcommercial = top.commercial;
		int curticket = top.ticket;
		
		if (curstation == end){
			globalticket = top.ticket;
			return curdistance;
		}
		
		if (visited[curcommercial][curstation]) continue;
		visited[curcommercial][curstation] = 1;
		
		for (int i = 0; i < 2; i++){
			if (curcommercial && i) continue;
			for (struct adjnode* cur = adjhead[i][curstation]; cur; cur = cur->next){
				int nexti = i || curcommercial;
				
				if (visited[nexti][cur->station]) continue;
				if (distance[curcommercial][curstation] + cur->cost < distance[nexti][cur->station]){
					distance[nexti][cur->station] = distance[curcommercial][curstation] + cur->cost;
					
					pred[nexti][cur->station].x = curcommercial;
					pred[nexti][cur->station].y = curstation;
					
					int ticket = (i == 1) ? curstation : curticket;
					pushheap(&heapcountdata, nexti, cur->station, distance[nexti][cur->station], ticket);
				}
			}
		}
	}
}

struct point makepoint(int x, int y){
	struct point newpoint;
	newpoint.x = x;
	newpoint.y = y;
	return newpoint;
}

void printorder(struct point x){
	if (pred[x.x][x.y].x == -1 && pred[x.x][x.y].y == -1){
		printf("%d", x.y);
		return;
	}
	printorder(pred[x.x][x.y]);
	printf(" %d", x.y);
}

void freeall(){
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < SIZE; j++){
			struct adjnode* cur = adjhead[i][j];
			while (cur){
				struct adjnode* temp = cur;
				cur = cur->next;
				free(temp);
			}
		}
	}
	
}

int main (){
	int beginning = 1;
	while (scanf("%d %d %d", &n, &s, &e) != EOF){
		if (beginning) beginning = 0;
		else puts("");
		init();
		int m;
		scanf("%d", &m);
		while (m--){
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			pushadj(&adjhead[0][x], y, z);
			pushadj(&adjhead[0][y], x, z);
		}
		int k;
		scanf("%d", &k);
		while (k--){
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			pushadj(&adjhead[1][x], y, z);
			pushadj(&adjhead[1][y], x, z);
		}
		
		int cost = dijkstra(s, e);
		
		printorder(makepoint((globalticket) ? 1 : 0, e));
		puts("");
		
		if (globalticket == 0) puts("Ticket Not Used");
		else printf("%d\n", globalticket);
		
		printf("%d\n", cost);
		
		freeall();
		getchar(); getchar();
	}
	
	return 0;
}
