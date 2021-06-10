#include <stdio.h>
#include <algorithm> 

struct edge{
	int begin;
	int end;
	int dist;
}edges[3000000];

int d(char a[], char b[]){
	int ret = 0;
	for (int i = 0; i < 7; i++)
		if (a[i] != b[i]) 
			ret++;
	return ret;
}

bool comparator(edge a, edge b){
	return (a.dist < b.dist);
}

int findpar(int par[], int x){
	if (par[x] == x) return x;
	return par[x] = findpar(par, par[x]);
}

void mergeset(int par[], int a, int b){
	par[findpar(par, a)] = findpar(par, b);
}

bool issameset(int par[], int a, int b){
	return (findpar(par, a) == findpar(par, b));
}

int kruskal(edge e[], int n, int idx){
	std::sort(e, e + idx, comparator);
	
	int par[2005];
	for (int i = 0; i < n; i++) par[i] = i;
	
	int ret = 0;
	for (int i = 0; i < idx; i++){
		if (issameset(par, e[i].begin, e[i].end)) continue;
		mergeset(par, e[i].begin, e[i].end);
		ret += e[i].dist;
	}
	
	return ret;
}

int main (){
	int n;
	while(scanf("%d", &n)){
		getchar();
		if (n == 0) break;
		char in[2000][10];
		for (int i = 0; i < n; i++){
			scanf("%s", in[i]);
		}
		
		int idx = 0;
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				edges[idx].begin = i;
				edges[idx].end = j;
				edges[idx].dist = d(in[i], in[j]);
				idx++;
			}
		}
		
		printf("The highest possible quality is 1/%d.\n", kruskal(edges, n, idx));
	}
	
	return 0;
}
