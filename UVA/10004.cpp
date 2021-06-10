#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int graph[250][250];

int main (){
	int n;
	while (cin >> n){
		if (n == 0) break;
		
		for (int i = 0; i < 250; i++)
			for (int j = 0; j < 250; j++)
				graph[i][j] = 0;
				
		int l;
		cin >> l;
		while (l--){
			int a, b;
			cin >> a >> b;
			graph[a][b] = graph[b][a] = 1;
		}
		
		priority_queue< pair<int, int> > pq;
		int color[n + 5];
		for (int i = 0; i < n; i++) {
	        int count = 0;
	        for (int j = 0; j < n; j++) {
	            count += graph[i][j];
	        }
	        pq.push(make_pair(count, i));
	
	        color[i] = -1;
	    }
	    
	    int max = -1;
	    while (!pq.empty()){
	    	
	    	pair<int, int> cur = pq.top();
	    	pq.pop();
	    	
	        for (int k = 0; k < n; k++) { // color
	            int check = 0;
	            for (int j = 0; j < n; j++) { // check neighbor
	                if(graph[cur.second][j] == 1 && color[j] == k){ // isConnected and isUsedColor  
	                    check = 1; 
	                    break;
	                }
	            }
	            if(check == 0) {
	                color[cur.second] = k;
	                break;
	            }
	        }
	        if(max < color[cur.second]) {
	            max = color[cur.second];
	        }
	    
		}
	    
	    if (max <= 2 - 1) cout << "BICOLORABLE." << endl;
	    else cout << "NOT BICOLORABLE." << endl;
	}
	return 0;
}
