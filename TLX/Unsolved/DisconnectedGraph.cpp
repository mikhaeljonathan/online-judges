#include <stdio.h>
#include <utility>

int main (){
	int t;
	scanf("%d", &t);
	while (t--){
		int n, e, q, r;
		scanf("%d %d %d %d", &n, &e, &q, &r);
		int graph[n + 1][n + 1];
		int special[n + 1];
		std::pair<int, int> edges[e + 1];
		long long res = 0;
		
		for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) graph[i][j] = 0;
		for (int i = 0; i <= n; i++) special[i] = 0;
		
		for (int i = 1; i <= e; i++){
			scanf("%d %d", &edges[i].first, &edges[i].second);
			graph[edges[i].first][edges[i].second] = 1;
		}
		
		while (q--){
			int x;
			scanf("%d", &x);
			special[x] = 1;
		}
		
		while (r--){
			int x;
			scanf("%d", &x);
			graph[edges[x].first][edges[x].second] = 0;
		}
		
		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++){
				if (special[i] && special[j] && graph[i][j] == 0){
					res++;
				}
			}
		}
		
		printf("%lld\n", res);
	}
	return 0;
}
