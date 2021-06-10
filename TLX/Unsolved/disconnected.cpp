#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <queue>

struct Adj{
	int val;
	struct Adj* next;
};

struct Node{
	int val;
	struct Adj* adjacent;
}nodes[50005];

int visited[50005];

void push(int a, int b){
	struct Adj* newAdj = (struct Adj*)malloc(sizeof(struct Adj));
	newAdj->val = b;
	newAdj->next = nodes[a].adjacent;
	nodes[a].adjacent = newAdj;
}

int connected(int a, int b){
	if (a == b) return 1;
	std::queue<int> Q;
	for (int i = 0; i < 50005; i++) visited[i] = 0;
	visited[a] = 1;
	
	struct Adj* curr = nodes[a].adjacent;
	while (curr != NULL){
		Q.push(curr->val);
		curr = curr->next;
	}
	
	while (!Q.empty()){
		int currsize = Q.size();
		for (int i = 0; i < currsize; i++){
			
			int current = Q.front();
			Q.pop();
			
			if (b == current) {
				Q.empty();
				return 1;
			}
			
			if (visited[current]) continue;
			
			visited[current] = 1;
			
			for (struct Adj* curr = nodes[current].adjacent; curr != NULL; curr = curr->next){
				if (visited[curr->val]) continue;
				Q.push(curr->val);
			}
			
		}
	}
	
	Q.empty();
	return 0;
}

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
		for (int i = 0; i < 50005; i++){
			while (nodes[i].adjacent != NULL){
				struct Adj* tobedeleted = nodes[i].adjacent;
				nodes[i].adjacent = nodes[i].adjacent->next;
				free(tobedeleted);
			}
		} 
		
		//connected nodes
		for (int i = 1; i <= e; i++) scanf("%d %d", &edges[i].first, &edges[i].second);
		
		//special nodes
		for (int i = 0; i < q; i++){
			int x;
			scanf("%d", &x);
			special[x] = 1;
		}
		
		//broken edges
		for (int i = 0; i < r; i++){
			int x;
			scanf("%d", &x);
			disconnected[x] = 1;
		}
		
		for (int i = 1; i <= e; i++){
			if (!disconnected[i]) {
				push(edges[i].first, edges[i].second);
				push(edges[i].second, edges[i].first);
			}
		}
		
//		for (int i = 1; i < 5; i++){
//			printf("%d : ", i);
//			struct Adj* curr = nodes[i].adjacent;
//			while (curr != NULL){
//				printf("%d ", curr->val);
//				curr = curr->next;
//			}
//			puts("");
//		}
		
		
		long long allspecialpairs = combinatorics(q);
		long long connectedspecial = 0;
		
		for (int i = 0; i < 50005; i++){
			struct Adj* curr = nodes[i].adjacent;
			while (curr != NULL){
				if (special[i] && special[curr->val] && i < curr->val && connected(i, curr->val)) {
					connectedspecial++;
				}
				curr = curr->next;
				
			}
		}
		
		long long res = allspecialpairs - connectedspecial;
		
		printf("%lld\n", res);
	}
	return 0;
}
