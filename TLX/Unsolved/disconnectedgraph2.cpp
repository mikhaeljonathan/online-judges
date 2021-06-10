#include <stdio.h>
#include <utility>

long long combinatorics(int x){
	if (x % 2) return x * ((x - 1) / 2);
	else return (x / 2) * (x - 1);
}

int main (){
	int t;
	scanf("%d", &t);
	while (t--){
		int n, e, q, r;
		scanf("%d %d %d %d", &n, &e, &q, &r);
		int special[n + 1];
		int disconnected[e + 1];
		std::pair<int, int> edges[e + 1];
		
		for (int i = 0; i <= n; i++) special[i] = 0;
		for (int i = 0; i <= e; i++) disconnected[i] = 0;
		
		//connected nodes
		for (int i = 1; i <= e; i++) scanf("%d %d", &edges[i].first, &edges[i].second);
		
		//special nodes
		for (int i = 0; i < q; i++){
			int x;
			scanf("%d", &x);
			special[x] = 1;
		}
		
		//broken edges
		while(r--){
			int x;
			scanf("%d", &x);
			disconnected[x] = 1;
		}
		
		long long connectedspecial = 0;
		for (int i = 1; i <= e; i++){
			if (special[edges[i].first] && special[edges[i].second] && !disconnected[i]) connectedspecial++;
		}
		
		long long allspecialpairs = combinatorics(q);
		
		long long res = allspecialpairs - connectedspecial;
		
		printf("%lld\n", res);
	}
	return 0;
}
