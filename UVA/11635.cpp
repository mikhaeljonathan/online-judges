#include <iostream>
#include <vector>
#include <queue>
#define SIZE 100005
using namespace std;

class Node{
	public:
		int vtx;
		int cost;
};

int n;
bool hotel[SIZE];
vector<Node> adjlist[SIZE];
bool visitedBfs[SIZE];
int dist[SIZE];
bool visitedDij[SIZE];

bool operator<(Node a, Node b){
	return (a.cost > b.cost);
}

void dijkstra(int begin){
	for (int i = 1; i <= n; i++){
		visitedDij[i] = false;
		dist[i] = 1 << 30;
	}
	dist[begin] = 0;
	priority_queue<Node> pq;
	
	Node node;
	node.vtx = begin;
	node.cost = dist[begin];
	pq.push(node);
	
	while(pq.size() > 0){
		Node top = pq.top();
		pq.pop();
		
		int curvtx = top.vtx;
		
		if (visitedDij[curvtx]) continue;
		visitedDij[curvtx] = true;
		
		for (int i = 0; i < adjlist[curvtx].size(); i++){
			if (visitedDij[adjlist[curvtx].at(i).vtx]) continue;
			if (dist[curvtx] + adjlist[curvtx].at(i).cost < dist[adjlist[curvtx].at(i).vtx]){
				dist[adjlist[curvtx].at(i).vtx] = dist[curvtx] + adjlist[curvtx].at(i).cost;
				
				Node node;
				node.vtx = adjlist[curvtx].at(i).vtx;
				node.cost = dist[adjlist[curvtx].at(i).vtx];
				pq.push(node);
			}
		}
	}
}

int bfs(){
	for (int i = 1; i <= n; i++) visitedBfs[i] = false;
	queue<int> q;
	q.push(1);
	
	for (int moves = 0; q.size() > 0; moves++){
		int curSize = q.size();
		for (int _ = 0; _ < curSize; _++){
			int curvtx = q.front();
			q.pop();
			
			if (curvtx == n) return moves;
			
			if (visitedBfs[curvtx]) continue;
			visitedBfs[curvtx] = true;
			
			dijkstra(curvtx);
			
			for (int i = 1; i <= n; i++){
				if (!hotel[i] && i != n) continue;
				if (dist[i] > 600) continue;
				q.push(i);
			}
		}
	}
	
	return 0;
}

int main (){
	while (cin >> n){
		if (n == 0) break;
		
		for (int i = 0; i < SIZE; i++){
			hotel[i] = false;
			while (adjlist[i].size() > 0) adjlist[i].pop_back();
		}
		
		int h;
		cin >> h;
		while(h--) {
			int c;
			cin >> c;
			hotel[c] = true;
		}
		
		int m;
		cin >> m;
		while (m--){
			int a, b, t;
			cin >> a >> b >> t;
			Node temp;
			temp.vtx = a;
			temp.cost = t;
			adjlist[b].push_back(temp);
			
			temp.vtx = b;
			adjlist[a].push_back(temp);
		}
		
		cout << bfs() - 1 << endl;
	}
	
	return 0;
}
