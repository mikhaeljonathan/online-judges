#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node{
	public:
		int val;
		int x;
		int y;
};

Node makeNode(int val, int x, int y){
	Node ret;
	ret.val = val;
	ret.x = x;
	ret.y = y;
	return ret;
}

bool sortNode(Node const& a, Node const& b){
	return a.val > b.val;
}

int f(vector<Node>& vn){
	
	int vnsize = vn.size();
	
	for (int i = 0; i < vnsize; i++){
		if (i != vnsize - 1 && vn[i].val != vn[i + 1].val) continue;

		int valnow, xnow, ynow;
		
		valnow = vn[i].val, xnow = vn[i].x, ynow = vn[i].y;
		for (int j = i + 1; j < vnsize; j++){
			if (vn[j].val != valnow) continue;
			if (vn[j].x >= xnow && vn[j].y >= ynow) return valnow;
		}
	}
	
	return -1;
	
}

int main(){
	int n;
	cin >> n;
	vector<Node> vn;
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			int temp;
			cin >> temp;
			vn.push_back(makeNode(temp, i, j));
		}
	}
		
	sort(vn.begin(), vn.end(), sortNode);
	cout << f(vn) << endl;
	
	return 0;
}
