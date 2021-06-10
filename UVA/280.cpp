#include <stdio.h>

struct tnode{
	int adjacent[105];
};

int n, countvisited;
int visited[105];

void dfs(struct tnode vertex[], int depth, int x){
//	printf("dfs %d\n", x);
	if (depth != 0) visited[x] = 1, countvisited++;
	for (int i = 1; i <= n; i++){
		if (vertex[x].adjacent[i]){
			if (visited[i]) continue;
			dfs(vertex, depth + 1, i);
		}
	}
}

int main (){
	while (scanf("%d", &n) && n != 0){
		struct tnode vertex[n + 1];
		for (int i = 0; i <= n; i++) for (int j = 0; j < 105; j++) vertex[i].adjacent[j] = 0;
		int curvtx;
		while (scanf("%d", &curvtx) && curvtx != 0){
			int adj;
			while (scanf("%d", &adj) && adj != 0){
				vertex[curvtx].adjacent[adj] = 1;
			}
		}
		int jmlh;
		scanf("%d", &jmlh);
		while (jmlh--){
			for (int i = 0; i < 105; i++) visited[i] = 0;
			countvisited = 0;
			int in;
			scanf("%d", &in);
//			printf("main %d\n", in);
			dfs(vertex, 0, in);
			printf("%d", n - countvisited);
			for (int i = 1; i <= n; i++){
				if (!visited[i]) printf(" %d", i);
			}
			puts("");
		}
//		puts("table");
//		for (int i = 1; i <= n; i++){
//			printf("%d", i);
//			for (int j = 1; j <= n; j++){
//				if (vertex[i].adjacent[j]) printf(" %d", j);
//			}
//			puts("");
//		}
	}
	return 0;
}
