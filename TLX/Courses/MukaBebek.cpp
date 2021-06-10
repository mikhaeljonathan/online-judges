#include <stdio.h>

struct edge{
	int x;
	int y;
	int cost;
};

void merge(struct edge edges[], int aleft, int aright, int bleft, int bright){
	int size = bright - aleft + 1;
	struct edge temp[size];
	int aindex = aleft;
	int bindex = bleft;
	int tindex = 0;
	
	while (aindex <= aright && bindex <= bright){
		if (edges[aindex].cost <= edges[bindex].cost) temp[tindex++] = edges[aindex++];
		else temp[tindex++] = edges[bindex++];
	}
	
	while (aindex <= aright) temp[tindex++] = edges[aindex++];
	
	while (bindex <= bright) temp[tindex++] = edges[bindex++];
	
	for (int i = 0; i < size; i++) edges[aleft + i] = temp[i];
}

void mergesort(struct edge edges[], int left, int right){
	if (left == right) return;
	
	int mid = (left + right) / 2;
	mergesort(edges, left, mid);
	mergesort(edges, mid + 1, right);
	merge(edges, left, mid, mid + 1, right);
}

int findpar(int par[], int x){
	if (par[x] == x) return x;
	return par[x] = findpar(par, par[x]);
}

int same (int par[], int a, int b){
	int t = findpar(par, a);
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
	scanf("%d", &n);
	struct edge edges[n * n];
	int idx = 0;
	int par[n];
	
	int in;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++){
			scanf("%d", &in);
			if (j > i){
				edges[idx].x = i;
				edges[idx].y = j;
				edges[idx].cost = in;
				idx++;
			}
		}
		par[i] = i;
	}
	mergesort(edges, 0, idx - 1);
	 
	int res = 0;
	for (int i = 0; i < idx; i++){
		if (same(par, edges[i].x, edges[i].y)) continue;
		mergeset(par, edges[i].x, edges[i].y);
		res += edges[i].cost;
	}
	
	printf("%d\n", res);
	
	return 0;
}
