#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int w, h;
char maps[30][30];

int memo[30][1<<15];

int visited[30][30];
int adjmat[30][30];

vector< pair<int, int> > coord;

int bfs(pair<int, int> a, pair<int, int> b){
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
			visited[i][j] = 0;
	
	queue< pair<int, int> > q;
	q.push(make_pair(a.first, a.second));
	for (int moves = 0; q.size() > 0; moves++){
		int curq = q.size();
		for (int _ = 0; _ < curq; _++){
			pair<int, int> curpair = make_pair(q.front().first, q.front().second);
			q.pop();
			
			if (curpair.first == b.first && curpair.second == b.second) return moves;
			
			if (visited[curpair.first][curpair.second]) continue;
			visited[curpair.first][curpair.second] = 1;
			
			int dr[] = {+1, -1, +0, +0};
			int dc[] = {+0, +0, +1, -1};
			
			for (int i = 0; i < 4; i++){
				int nextx = curpair.first + dr[i];
				int nexty = curpair.second + dc[i];
				
				if (nextx >= w || nextx < 0) continue;
				if (nexty >= h || nexty < 0) continue;
				if (maps[nextx][nexty] == 'x') continue;
				if (visited[nextx][nexty]) continue;
				
				q.push(make_pair(nextx, nexty));	
			}
		}
	}
	
	return (1 << 30);
}

int tsp(int idx, int mask){
	
	if (memo[idx][mask] != -1) return memo[idx][mask];
	
	if (mask == (1 << coord.size()) - 1) return 0;
	
	int ans = (1<<29);
	for (int i = 0; i < coord.size(); i++){
		if (i == idx) continue;
		if (i < (1<<30)){
			if (!(mask&(1<<i))){
				ans = min(ans, tsp(i, mask|(1<<i)) + adjmat[idx][i]);
			}
		}
	
	}
	
	return memo[idx][mask] = ans;
}

int main (){
	while (cin >> h >> w){
		if (w == 0 && h == 0) break;
		
		coord.clear();
		for (int i = 0; i < 30; i++)
			for (int j = 0; j < (1<<15); j++)
				memo[i][j] = -1;
				
		int x, y;
		for (int i = 0; i < w; i++){
			for (int j = 0; j < h; j++){
				cin >> maps[i][j];
				if (maps[i][j] == 'o')
					coord.push_back(make_pair(i, j));
			}
		}
		
		for (int i = 0; i < w; i++){
			for (int j = 0; j < h; j++){
				if (maps[i][j] == '*')
					coord.push_back(make_pair(i, j));
			}
		}
		
		for (int i = 0; i < coord.size(); i++){
			for (int j = i + 1; j < coord.size(); j++){
				adjmat[i][j] = adjmat[j][i] = bfs(coord[i], coord[j]);
			}
		}
		
		int res = tsp(0, 0|(1<<0));
		if (res >= (1<<29)) cout << "-1" << endl;
		else cout << res << endl;
	}
	return 0;
}
