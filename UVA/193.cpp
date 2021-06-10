#include<iostream>
#include<vector>
using namespace std;

vector<int> adjlist[105];
vector<int> vres;
int color[105];
int l, k, maxx;

bool check(int vtx){
	
	int len = adjlist[vtx].size();
	for (int i = 0; i < len; i++){
		if (color[adjlist[vtx][i]] == 1) return false; 
	}
	return true;
}

void generateAns(int vtx, vector<int> temp){
 	if (vtx == l + 1){
 	
		int count = 0;
		for (int i = 1; i <= l; i++){
			count += color[i];
		}
		
		if (count > maxx){
			maxx = count;
			vres = temp;
		}
		return;
	}
	for (int i = 0; i < 2; i++){
		//1 black, 0 white
		if (i == 1) temp.push_back(vtx);
		color[vtx] = i;
		
		if (i == 0 || check(vtx)){
			generateAns(vtx + 1, temp);
		}
		
		color[vtx] = -1;
		if (i == 1) temp.pop_back();
		
	}
}

int main(){
	int n;
	cin >> n;
	while (n--){
		
		vres.clear();
		for (int i = 0; i < 105; i++) {
			adjlist[i].clear();
			color[i] = -1;
		}
		
		cin >> l >> k;
		while (k--){
			int a, b;
			cin >> a >> b;
			adjlist[a].push_back(b);
			adjlist[b].push_back(a);
		}
		
		maxx = 0;
		vector<int> temp;
		generateAns(1, temp);
		
		cout << maxx << endl;
		for (int i = 0; i < vres.size(); i++){
			cout << vres[i];
			if (i != vres.size() - 1) cout << " ";
		}
		cout << endl;
		
	}
	return 0;
}
