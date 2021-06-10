#include <stdio.h>

int n, m;
int par[100005];
int child[100005];
int sum[100005];

int findrep(int x){
	if (par[x] == x) return x;
	return par[x] = findrep(par[x]);
}

void join(int a, int b){
	int repa = findrep(a);
	int repb = findrep(b);
	if (repa == repb) return;
	
	par[repa] = repb;
	child[repb] += child[repa];
	sum[repb] += sum[repa	];
}

void move(int a, int b){
	int repa = findrep(a);
	int repb = findrep(b);
	if (repa == repb) return;
	
	par[a] = repb;
	child[repb]++;
	child[repa]--;
	sum[repb] += a;
	sum[repa] -= a;
}

void init(){
	for (int i = 1; i <= n; i++){
		par[i] = i + n;
		par[i + n] = i + n;
		child[i + n] = 1;
		sum[i + n] = i;
	}
}

int main (){
	while (scanf("%d %d", &n, &m) != EOF){
		init();
		while (m--){
			int com;
			scanf("%d", &com);
			if (com == 1){
				int a, b;
				scanf("%d %d", &a, &b);
				join(a, b);
			} else if (com == 2){
				int a, b;
				scanf("%d %d", &a, &b);
				move(a, b);
			} else {
				int x;
				scanf("%d", &x);
				int temp = findrep(x);
				printf("%d %d\n", child[temp], sum[temp]);
			}
		}
	}
	return 0;
}
