#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Node{
	public:
		int idx;
		char map[15][15];
};

class PqNode{
	public:
		int idx;
		int dist;
		int par;
};

int n, m, k, w;
bool visited[1005];
int dist[1005];
vector<Node> v;
vector< pair<int, int> > ansv;

bool operator<(PqNode const &a, PqNode const &b){
	return (a.dist > b.dist);
}

PqNode addNew(int idx, int dist, int par){
	PqNode newPq;
	newPq.idx = idx;
	newPq.dist = dist;
	newPq.par = par;
	return newPq;
}

pair<int, int> newPair(int a, int b){
	pair<int, int> ret;
	ret.first = a;
	ret.second = b;
	return ret;
}

int getDist(int a, int b){
	int ret = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			if (v.at(a).map[i][j] == v.at(b).map[i][j]) continue;
			ret++;
		}
	
	ret *= w;
	return ret;
}

void prim(int begin){
	for (int i = 0; i < k; i++){
		visited[i] = false;
		dist[i] = 1 << 30;
	}
	dist[begin] = n * m;
	
	priority_queue<PqNode> pq;
	pq.push(addNew(begin, dist[begin], -1));
	
	while (!pq.empty()){
		PqNode top = pq.top();
		pq.pop();
		int curvtx = top.idx;
		
		if (visited[curvtx]) continue;
		visited[curvtx] = true;
		ansv.push_back(newPair(top.idx + 1, top.par + 1));
		
		for (int i = 0; i < k; i++){
			if (i == curvtx) continue;
			if (visited[i]) continue;
			
			int temp1 = n * m;
			int temp2 = getDist(curvtx, i);
			
			int temp = (temp1 < temp2) ? temp1 : temp2;
			
			if (temp < dist[i]){
				dist[i] = temp;
				if (temp == temp1) pq.push(addNew(i, dist[i], -1)); //whole new
				else pq.push(addNew(i, dist[i], curvtx)); //relax from a vertex
			}
		}
	}
}

int main (){
	cin >> n >> m >> k >> w;
	for (int i = 0; i < k; i++){
		Node newnode;
		for (int j = 0; j < n; j++)
			cin >> newnode.map[j];
		newnode.idx = i;
		v.push_back(newnode);
	}
	
	prim(0);
	int ans = 0;
	for (int i = 0; i < k; i++) 
		ans += dist[i];

	cout << ans <<endl;
	for (int i = 0; i < ansv.size(); i++)
		cout << ansv.at(i).first << " " << ansv.at(i).second << endl;
		
	return 0;
}
