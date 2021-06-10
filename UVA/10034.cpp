#include <stdio.h>
#include <math.h>

struct point{
	double x;
	double y;
}table[105];

struct edge {
	int begin;
	int end;
	double weight;
};

double getdist(int i , int j){
	return sqrt(pow(table[i].x - table[j].x, 2) + pow(table[i].y - table[j].y, 2));
}

void merge(struct edge edges[], int aleft, int aright, int bleft, int bright){
	int size = bright - aleft + 1;
	struct edge temp[size];
	int aindex = aleft;
	int bindex = bleft;
	int tindex = 0;
	
	while (aindex <= aright && bindex <= bright){
		if (edges[aindex].weight <= edges[bindex].weight) temp[tindex++] = edges[aindex++];
		else temp[tindex++] = edges[bindex++];
	}
	
	while (aindex <= aright) temp[tindex++] = edges[aindex++];
	
	while (bindex <= bright) temp[tindex++] = edges[bindex++];
	
	for (int i = 0; i < size; i++) edges[aleft + i] = temp[i];
}

void mergesort(struct edge edges[], int left, int right){
	if (left == right) return;
	
	int mid = (left +right) /2;
	mergesort(edges, left, mid);
	mergesort(edges, mid + 1, right);
	merge(edges, left, mid, mid + 1, right);
}

int findpar(int par[], int x){
	if (par[x] == x) return x;
	else return par[x] = findpar(par, par[x]);
}

int issameset(int par[], int a, int b){
	return (findpar(par, a) == findpar(par, b));
}

void mergeset(int par[], int a, int b){
	par[findpar(par, a)] = findpar(par, b);
}

int main (){
	int t;
	scanf("%d" ,&t);
	getchar();
	while (t--){
		int n;
		scanf("%d", &n);
		int par[n];
		for (int i = 0; i < n; i++){
			scanf("%lf %lf", &table[i].x, &table[i].y);
			par[i] = i;
		}
		
		int size = n * (n - 1) / 2;
		struct edge edges[size];
		int idx = 0;
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				edges[idx].begin = i;
				edges[idx].end = j;
				edges[idx++].weight = getdist(i, j);
			}
		}
		
		mergesort(edges, 0, idx - 1);
		
		double ans = 0.0;
		for (int i = 0; i < idx; i++){
			if (issameset(par, edges[i].begin, edges[i].end)) continue;
			mergeset(par, edges[i].begin, edges[i].end);
			ans += edges[i].weight;
		}
		
		printf("%.2lf\n", ans);
		if (t != 0) puts("");
	}
	return 0;
}
