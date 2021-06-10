#include <stdio.h>

struct edge{
	int begin;
	int end;
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
	scanf("%d", &t);
	while (t--){
		int p, n, m;
		scanf("%d %d %d", &p, &n, &m);
		struct edge edges[m];
		for (int i = 0; i < m; i++) scanf("%d %d %d", &edges[i].begin, &edges[i].end, &edges[i].cost);
		int par[n + 1];
		for (int i = 0; i <= n; i++) par[i] = i;
		mergesort(edges, 0, m - 1);
		int ans = 0;
		for (int i = 0; i < m; i++){
			if (issameset(par, edges[i].begin, edges[i].end)) continue;
			mergeset(par, edges[i].begin, edges[i].end);
			ans += edges[i].cost;
		}
		ans *= p;
		printf("%d\n", ans);
	}
		
	return 0;
}
