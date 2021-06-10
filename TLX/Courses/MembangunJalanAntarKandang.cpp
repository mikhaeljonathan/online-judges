#include <stdio.h>

int findrep(int *par, int a){
	if (par[a] == a){
		return a;
	} else {
		par[a] = findrep(par, par[a]);
		return par[a];
	}
}

void join(int *par, int a, int b){
	int repa = findrep(par, a);
	int repb = findrep(par, b);
	par[repa] = repb;
}

int connected(int *par, int a, int b){
	return (findrep(par, a) == findrep(par, b));
}

int main (){
	int n, t;
	scanf("%d %d", &n, &t);
	int par[n + 1];
	for (int i = 1; i <= n; i++) par[i] = i;
	while (t--){
		int com, a, b;
		scanf("%d %d %d", &com, &a, &b);
		if (com == 1){
			join(par, a, b);
		} else {
			printf("%s\n", (connected(par, a, b)) ? "Y" : "T");
		}
	}
	return 0;
}
