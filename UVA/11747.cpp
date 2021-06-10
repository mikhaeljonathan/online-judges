#include <stdio.h>

struct edge{
	int u;
	int v;
	int w;
	int partofmst;
};

void merge(struct edge edges[], int aleft, int aright, int bleft, int bright){
	int size = bright - aleft + 1;
	struct edge temp[size];
	int aindex = aleft;
	int bindex = bleft;
	int tindex = 0;
	
	while (aindex <= aright && bindex <= bright){
		if (edges[aindex].w <= edges[bindex].w) temp[tindex++] = edges[aindex++];
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
	int n, m;
	while(scanf("%d %d", &n, &m)){
		if (n == 0 && m == 0) break;
		struct edge edges[m];
		for (int i = 0; i < m; i++){
			scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
			edges[i].partofmst = 0;
		}
		int par[n];
		for (int i = 0; i < n; i++) par[i] = i;
		
		if (m != 0) mergesort(edges, 0, m - 1);
		
		for (int i = 0; i < m; i++){
			if (issameset(par, edges[i].u, edges[i].v)) continue;
			mergeset(par, edges[i].u, edges[i].v);
			edges[i].partofmst = 1;
		}
		
		int forest = 1;
		for (int i = 0; i < m; i++){
			if (edges[i].partofmst) continue;
			if (!forest) printf(" ");
			printf("%d", edges[i].w);
			forest = 0;
		}
		
		if (forest) puts("forest");
		else puts("");
	}
	return 0;
}
