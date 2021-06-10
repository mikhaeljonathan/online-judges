#include <stdio.h>

int findrep(int *par, int x){
	if (par[x] == x) return x;
	par[x] = findrep(par, par[x]);
	return par[x];
}

void join(int *par, int a, int b){
	int repa = findrep(par, a);
	int repb = findrep(par, b);
	if (repa == repb) return;
	par[repa] = repb;
}

int main (){
	int x, j;
	int cases = 1;
	while (scanf("%d %d", &x, &j)){
		if (x == 0 && j == 0) break;
		
		int par[x + 5];
		for (int i = 1; i <= x; i++) par[i] = i;
		while (j--){
			int a, b;
			scanf("%d %d", &a, &b);
			join(par, a, b);
		}
		int visited[x + 5];
		int res = 0;
		for (int i = 1; i <= x; i++) visited[i] = 0;
		for (int i = 1; i <= x; i++){
			if (!visited[findrep(par, i)]) {
				res++;
				visited[findrep(par, i)] = 1;
			}
		}
		printf("Case %d: %d\n", cases++, res);
	}
	
	
	return 0;
}
