#include <stdio.h>

struct point{
	int x;
	int y;
	int dist;
}arrheap[1000005];

int n, m;
int heapcountdata;
int map[1005][1005];
int visited[1005][1005];
int distance[1005][1005];

void swap (struct point *a, struct point *b){
	struct point temp = *a;
	*a = *b;
	*b = temp;
}

void upheap(int idx){
	if (idx == 1) return;
	int parentidx = idx / 2;
	
	if (arrheap[parentidx].dist < arrheap[idx].dist) return;
	
	swap(&arrheap[parentidx], &arrheap[idx]);
	
	upheap(parentidx);
}

void pushheap(struct point node){
	heapcountdata++;
	arrheap[heapcountdata].x = node.x;
	arrheap[heapcountdata].y = node.y;
	arrheap[heapcountdata].dist = node.dist;
	
	upheap(heapcountdata);
}

void downheap(int idx){
	int toidx = idx;
	if (idx * 2 <= heapcountdata && arrheap[idx * 2].dist < arrheap[toidx].dist)
		toidx = 2 * idx;
	
	if (idx * 2 + 1 <= heapcountdata && arrheap[idx * 2 + 1].dist < arrheap[toidx].dist)
		toidx = 2 * idx + 1;
	
	if (toidx == idx) return;
	
	swap(&arrheap[idx], &arrheap[toidx]);
	
	downheap(toidx);
}

void pop(){
	if (heapcountdata == 1){
		heapcountdata--;
		return;
	}
	
	arrheap[1] = arrheap[heapcountdata];
	
	heapcountdata--;
	
	downheap(1);
}

struct point makestruct(int x, int y, int dist){
	struct point newp;
	newp.x = x;
	newp.y = y;
	newp.dist = dist;
	return newp;
}

int dijkstra(){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			visited[i][j] = 0;
			distance[i][j] = 1 << 30;
		}
	}
	distance[0][0] = map[0][0];
	heapcountdata = 0;
	
	pushheap(makestruct(0, 0, map[0][0]));
	
	while (heapcountdata > 0){
		struct point top = arrheap[1];
		pop();
		int curx = top.x;
		int cury = top.y;
		int curdist = top.dist;
		
		if (visited[curx][cury]) continue;
		visited[curx][cury] = 1;
		
		int dr[4] = {+0, -0, +1, -1};
		int dc[4] = {-1, +1, -0, +0};
		for (int _ = 0; _ < 4; _++){
			int nextx = curx + dr[_];
			int nexty = cury + dc[_];
			if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m) continue;
			if (visited[nextx][nexty]) continue;
			
			if (curdist + map[nextx][nexty] < distance[nextx][nexty]){
				distance[nextx][nexty] = curdist + map[nextx][nexty];
				pushheap(makestruct(nextx, nexty, distance[nextx][nexty]));
			}
		}
	}
	
	return distance[n - 1][m - 1];
}

int main (){
	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &map[i][j]);
		
		printf("%d\n", dijkstra());
	}
	return 0;
}
