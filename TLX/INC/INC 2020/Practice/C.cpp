#include <iostream>
#include <vector>
using namespace std;

bool visited[100005][100005];

vector< vector<int> > road;
bool found;

void dfs(int u, int v){
	
	if (u == v) {
		found = true;
		return;
	}
	
	visited[u][v] = visited[v][u] = true;
	
	for (int i = 0; i < road[u].size(); i++){
		
		int nextnode = road[u][i];
		
		if (visited[u][nextnode]) continue;
		dfs(nextnode, v);
		if (found) return;
		visited[u][nextnode] = visited[nextnode][u] = false;
	}
	
}

bool can(int u, int v){
	found = false;
	
	dfs(u, v);
	
	if (!found) return false;
	return true;
}

int main (){
	int n, m, q;
	cin >> n >> m >> q;
	
	while (m--){
		int u, v;
		cin >> u >> v;
		
	}
	
	while (q--){
		
		for (int i = 0; i < 100005; i++)
			for (int j = 0; j < 100005; j++)
				visited[i][j] = false;
		
		int s, t;
		cin >> s >> t;
		if (can(s, t)){
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		
	}
	
	return 0;
}
