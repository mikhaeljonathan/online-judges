#include <stdio.h>

int findrep(int *par, int x){
	if (par[x] == x) return x;
	par[x] = findrep(par, par[x]);
	return par[x];
}

void join(int *par, int *owe, int a, int b){
	int repa = findrep(par, a);
	int repb = findrep(par, b);
	if (repa == repb) return;
	
	par[repa] = repb;
	owe[repb] += owe[repa];
}

int check(int *par, int *owe, int n){
	for (int i = 0; i < n; i++){
		if (owe[findrep(par, i)] != 0) return 0;
	}
	return 1;
}

int main (){
	int N;
	scanf("%d", &N);
	while (N--){
		int n, m;
		scanf("%d %d", &n, &m);
		int owe[n];
		int par[n];
		for (int i = 0; i < n; i++){
			scanf("%d", &owe[i]);
			par[i] = i;
		}
		while (m--){
			int a, b;
			scanf("%d %d", &a, &b);
			join(par, owe, a, b);
		}
		printf("%s\n", check(par, owe, n) ? "POSSIBLE" : "IMPOSSIBLE");
	}
	return 0;
}
