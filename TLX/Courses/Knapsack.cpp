#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector< pair<int, int> > v;
pair<int, int> memo[105][2005];
int backtrack[105];
int n, k;

pair<int, int> ks(int idx, int w){
	
	if (idx == -1){
		return make_pair(0, 0);	
	}	
	
	if (memo[idx][w].first != -1){
		return memo[idx][w];
	}
	
	pair<int, int> ret = ks(idx - 1, w);
	backtrack[idx + 1] = backtrack[idx];
	
	if (w < v[idx].first){
		
		return memo[idx][w] = ret;
	}
	
	pair<int, int> temp = ks(idx - 1, w - v[idx].first);
	pair<int, int> ret2 = make_pair(temp.first + v[idx].second, temp.second + v[idx].first);
	
	cout << idx << " " << w << endl;
	cout << "ret " << ret.first << " " << ret.second << endl;
	cout << "ret2 " << ret2.first << " " << ret2.second << endl;
	cout << endl;
	
	if (ret2.first > ret.first){
		
		backtrack[idx + 1] = idx;
		
		ret = ret2;
		
	} else if (ret2.first == ret.first){
		if (ret2.second < ret.second){
			
			backtrack[idx + 1] = idx;
			
			ret = ret2;
			
		}
	}
	
	return memo[idx][w] = ret;
}

void printres(int idx){
	if (backtrack[idx] == -1) return;
	cout << idx << endl;
	printres(backtrack[idx]);
}

int main (){
	
	for (int i = 0; i < 105; i++){
		for (int j = 0; j < 2005; j++){
			memo[i][j].first = memo[i][j].second = -1;
		}
		backtrack[i] = -1;
	}
		
	
	cin >> n >> k;
	
	while (k--){
		int w, h;
		cin >> w >> h;
		v.push_back(make_pair(w, h));
	}
	
	pair<int, int> res = ks(v.size() - 1, n);
	
	cout << "deb " << res.first << " " << res.second << endl;
	
	cout << "backtrack" << endl;
	for (int i = 0; i <= v.size(); i++){
		cout << backtrack[i] << " ";
	}
	cout << endl;
	
	printres(v.size());
	
	return 0;
}
