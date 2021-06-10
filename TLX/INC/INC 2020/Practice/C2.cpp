#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector< int > road[100005]; //roadnya
map< pair<int, int> , bool > visited; //visited roadnya
bool visitedNode[100005]; //visited junctionnya
bool found;

void dfs(int u, int v){
	
//	cout << u << endl;

	if (u == v) {
		found = true;
		return;
	}
	
	if (visitedNode[u]) return;
	
	visitedNode[u] = true;
	
	for (int i = 0; i < road[u].size(); i++){
		
		int nextnode = road[u][i];
		
		if (visited[pair<int, int>(u, nextnode)] || visited[pair<int, int>(nextnode, u)]) continue;
		if (visitedNode[nextnode]) continue;
		
		visited[pair<int, int>(u, nextnode)] = visited[pair<int, int>(nextnode, u)] = true;
//		cout << u << " " << nextnode << endl;
		
		dfs(nextnode, v);
		if (found) return;
		
		visited[pair<int, int>(u, nextnode)] = visited[pair<int, int>(nextnode, u)] = false;
		
	}
	
}

bool can(int s, int t){
	
	// pertama cari apakah ada jalan ke t
	found = false;
	for (int i = 0; i < 100005; i++) visitedNode[i] = false;
	dfs(s, t);
	if (!found) return false;
	
//	for (int i = 0; i < 100005; i++){
//		if (road[i].empty()) continue;
//		for (int j = 0; j < road[i].size(); j++){
//			cout << i << " " << road[i][j] << " visited " << visited[pair<int, int>(i, road[i][j])] << endl;
//		}
//	}	
//	
//	cout << "half" << endl;	
	
	// kedua cari apakah ada jalan lain, road ny udh visited dr sblmnya
	found = false;
	for (int i = 0; i < 100005; i++) visitedNode[i] = false;
	dfs(s, t);
	if (!found) return false;
	
	return true;
	
}

int main (){
	
	int n, m, q;
	cin >> n >> m >> q;
	
	while (m--){
		int u, v;
		cin >> u >> v;
		
		// masukin ke jalan
		road[u].push_back(v);
		road[v].push_back(u);
		
		// bikin visited
		visited.insert(pair< pair<int, int>, bool>(pair<int,int>(u, v), false));
		visited.insert(pair< pair<int, int>, bool>(pair<int,int>(v, u), false));
	}
	
	while (q--){
		
		// reset visitedroad jadi 0 semua
		for (map< pair<int, int>, bool>::iterator it = visited.begin(); it != visited.end(); ++it){
			it->second = false;
		}
		
		int s, t;
		cin >> s >> t;
		
		if (can(s, t)) cout << "YES" << endl;
		else cout << "NO" << endl;
		
//		for (int i = 0; i < 100005; i++){
//			if (road[i].empty()) continue;
//			for (int j = 0; j < road[i].size(); j++){
//				cout << i << " " << road[i][j] << " visited " << visited[pair<int, int>(i, road[i][j])] << endl;
//			}
//		}	

	}
	
	return 0;
}
