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
}edges[12000];

int par[105];

double getdist(int i , int j){
	double ret = sqrt(pow(table[i].x - table[j].x, 2) + pow(table[i].y - table[j].y, 2));
	return ret;
}

void merge(struct edge edges[], int aleft, int aright, int bleft, int bright){
	int size = bright - aleft + 1;
	struct edge temp[12000];
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
	return par[x] = findpar(par, par[x]);
}

int issameset(int par[], int a, int b){
	return (findpar(par, a) == findpar(par, b));
}

void mergeset(int par[], int a, int b){
	int para = findpar(par, a);
	int parb = findpar(par, b);
	if (para == parb) return;
	par[para] = parb;
}

int main (){
	int n;
	while (scanf("%d", &n) != EOF){
		for (int i = 0; i < n; i++){
			scanf("%lf %lf", &table[i].x, &table[i].y);
			par[i] = i;
		}
		
		int size = n * (n - 1) / 2;
		int idx = 0;
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				edges[idx].begin = i;
				edges[idx].end = j;
				edges[idx++].weight = getdist(i, j);
			}
		}
		
		if (idx != 0) mergesort(edges, 0, idx - 1);
		
		double ans = 0.0;
		for (int i = 0; i < idx; i++){
			if (issameset(par, edges[i].begin, edges[i].end)) continue;
			mergeset(par, edges[i].begin, edges[i].end);
			ans += edges[i].weight;
		}
		
		printf("%.2lf\n", ans);
	}
	
	return 0;
}
