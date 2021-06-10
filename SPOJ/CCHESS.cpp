#include <stdio.h>

struct heapnode{
	int x;
	int y;
	int dist;
}heaparr[1000];

int visited[10][10];
int distance[10][10];

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

void pushheap(int *n, int x, int y, int dist){
	(*n)++;
	heaparr[*n].x = x;
	heaparr[*n].y = y;
	heaparr[*n].dist = dist;
	upheap(*n);
}

void downheap(int idx, int size){
	int toidx = idx;
	
	if (2 * idx <= size && heaparr[2 * idx].dist < heaparr[toidx].dist) 
		toidx = idx * 2;
	if (2 * idx + 1 <= size && heaparr[2 * idx + 1].dist < heaparr[toidx].dist)
		toidx = idx * 2 + 1;
		
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

int dijkstra(int beginx, int beginy, int endx, int endy){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			visited[i][j] = 0;
			distance[i][j] = 1 << 30;
		}
	}
	distance[beginx][beginy] = 0;
	
	int heapcountdata = 0;
	pushheap(&heapcountdata, beginx, beginy, distance[beginx][beginy]);
	
	while (heapcountdata > 0){
		struct heapnode top = heaparr[1];
		pop(&heapcountdata);
		int curx = top.x;
		int cury = top.y;
		
		if (visited[curx][cury]) continue;
		visited[curx][cury] = 1;
		
		if (curx == endx && cury == endy) return distance[curx][cury];
		
		int dr[8] = {+2, -2, +2, -2, +1, -1, +1, -1};
		int dc[8] = {+1, +1, -1, -1, -2, -2, +2, +2};
		
		
		for (int i = 0; i < 8; i++){
			int deltax = dr[i];
			int deltay = dc[i];
			if (curx + deltax < 0 || curx + deltax > 7 || cury + deltay < 0 || cury + deltay > 7) continue;
			if (visited[curx + deltax][cury + deltay]) continue;
			if (distance[curx][cury] + (curx * (curx + deltax) + cury * (cury + deltay)) < distance[curx + deltax][cury + deltay]){
				distance[curx + deltax][cury + deltay] = distance[curx][cury] + (curx * (curx + deltax) + cury * (cury + deltay));
				pushheap(&heapcountdata, curx + deltax, cury + deltay, distance[curx + deltax][cury + deltay]);
			}
		}
	}
	
	return distance[endx][endy];
}

int main (){
	int a, b, c, d;
	while (scanf("%d %d %d %d", &a, &b, &c, &d) != EOF){
		int cost = dijkstra(a, b, c, d);
		if (cost >= (1 << 30)) printf("-1\n");
		else printf("%d\n", cost);
	}
	return 0;
}
