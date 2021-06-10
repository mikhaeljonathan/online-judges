#include <stdio.h>
#include <stdlib.h>
#define SIZE 105

struct adjnode{
	int vtx;
	double tmp;
	double dst;
	struct adjnode* next;
}*adjhead[SIZE];

int n, e;
int visited[SIZE];
int pred[SIZE];
double temperature[SIZE];
double distance[SIZE];

void init(){
	for (int i = 0; i < SIZE; i++) adjhead[i] = NULL;
}

void pushadj(struct adjnode** adjlocal, int vtx, double tmp, double dst){
	struct adjnode* newadj = (struct adjnode*)malloc(sizeof(struct adjnode));
	newadj->vtx = vtx;
	newadj->tmp = tmp;
	newadj->dst = dst;
	
	newadj->next = *adjlocal;
	*adjlocal = newadj;
}

void dijkstra(int begin, int end){
	for (int i = 0; i < SIZE; i++){
		visited[i] = 0;
		pred[i] = -1;
		int temp = 1 << 29;
		temperature[i] = 1.0 * temp;
		distance[i] = 1.0 * temp;
	}
	temperature[begin] = 0.0;
	distance[begin] = 0.0;
	
	for (int _ = 0; _ < n; _++){
		int curvtx = -1;
		int temp = 1 << 29;
		double curtemp = 1.0 * temp + 1;
		double curdist = 1.0 * temp + 1;
		for (int i = 1; i <= n; i++){
			if (visited[i]) continue;
			if (temperature[i] < curtemp){
				curvtx = i;
				curtemp = temperature[i];
				curdist = distance[i];
			}
		}
		
		if (visited[curvtx]) continue;
		visited[curvtx] = 1;
		
		if (curvtx == end) return;
		
		for (struct adjnode* cur = adjhead[curvtx]; cur; cur = cur->next){
			if (temperature[curvtx] + cur->tmp < temperature[cur->vtx]){
				temperature[cur->vtx] = temperature[curvtx] + cur->tmp;
				distance[cur->vtx] = distance[curvtx] + cur->dst;
				pred[cur->vtx] = curvtx;
				
			} else if (temperature[curvtx] + cur->tmp == temperature[cur->vtx]){
				
				if (distance[curvtx] + cur->dst < distance[cur->vtx]){
					temperature[cur->vtx] = temperature[curvtx] + cur->tmp;
					distance[cur->vtx] = distance[curvtx] + cur->dst;
					pred[cur->vtx] = curvtx;
				}
				
			}
		}
	}
	return;
}

void printstep(int x){
	if (pred[x] == -1){
		printf("%d", x);
		return;
	}
	printstep(pred[x]);
	printf(" %d", x);
}

void freeall(){
	for (int i = 0; i < SIZE; i++){
		struct adjnode* cur = adjhead[i];
		while (cur){
			struct adjnode* tobedel = cur;
			cur = cur->next;
			free(tobedel);
		}
	}
}

int main (){
	while (scanf("%d %d", &n, &e) != EOF){
		init();
		int s, t;
		scanf("%d %d", &s, &t);
		while (e--){
			int x, y;
			double r, d;
			scanf("%d %d %lf %lf", &x, &y, &r, &d);
			pushadj(&adjhead[x], y, r, d);
			pushadj(&adjhead[y], x, r, d);
		}
		dijkstra(s, t);
		printstep(t); puts("");
		printf("%.1lf %.1lf\n", temperature[t], distance[t]);
		freeall();
	}
	return 0;
}
