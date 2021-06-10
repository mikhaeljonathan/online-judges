#include<stdio.h>
#include<queue>
#define INF (1 << 30)
using namespace std;

int v, e;
int color[205];
bool vis[205];
vector<int> adjList[205];

int min(int a, int b){
	return a < b ? a : b;
}

// ini BFS utk solve problemnya, mirip cek bipartide
pair<int, int> solve(int start){
	// inisialisasi Queue & color
	queue<int> Queue;
	Queue.push(start);
	color[start] = 0;
	
	// counter warna, saat ini a & b abstrak, blm ditentuin warna hitam/putih
	int a = 0, b = 0;
	while(Queue.empty() == false){
		int curNode = Queue.front(); Queue.pop();
		
		//cek visited
		if(vis[curNode] == true) continue;
		vis[curNode] = true;
		
		// tambahin counter
		if(color[curNode] == 0) a++;
		else b++;
		
		for(int i = 0; i < adjList[curNode].size(); i++){
			int nextNode = adjList[curNode][i];
			
			// kalo warnanya sama, brarti graphny ga bipartide
			if(color[curNode] == color[nextNode]){
				return make_pair(INF, INF);
			}
			
			color[nextNode] = !color[curNode];
			
			Queue.push(nextNode);
		}
	}
    return make_pair(a, b);
}

int main(){
    int ntc;
    scanf("%d", &ntc);
    while(ntc--){
    	scanf("%d %d", &v, &e);
    	
    	// scan adjacency list
    	for(int i = 0; i < e; i++){
    		int x, y;
    		scanf("%d %d", &x, &y);
    		adjList[x].push_back(y);
    		adjList[y].push_back(x);
		}
		
		// inisialisasi color & visited
		for(int i = 0; i < v; i++){
			color[i] = -1;
			vis[i] = false;
		}
	    
	    // kita jalanin BFS dari semua possible node
	    int finalAns = 0;
	    for(int i = 0; i < v; i++){
	    	// kalo node uda perna dikunjungi, sekip aja
	    	if(vis[i] == true) continue;
	    	
	    	pair<int, int> ans = solve(i);
	    	
	    	// validasi jwban
	    	if(ans.first == INF && ans.second == INF){ // kalo INF, brarti ga bipartide, makanya final answer kt set jd -1
	    		finalAns = -1;
			} else if(ans.first > 0 && ans.second > 0){ // kalo keduanya positif, kita cari yg plg kecil, krn kt cari minimum
	    		finalAns += min(ans.first, ans.second);
			} else { // kalo salah satu nilainya 0, di +1 aja
				finalAns++;
			}
		}
		
		printf("%d\n", finalAns);
	    
	    // reset adj list
	    for(int i = 0; i < v; i++){
	    	adjList[i].clear();
		}
	}
    return 0;
}

