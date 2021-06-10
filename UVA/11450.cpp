#include<iostream>
#include<vector>
using namespace std;

vector< vector<int> > v;
int table[25][250];
int m;

int dp(int idx, int capacity){
	
	if (idx < 0) return (m - capacity);
	
	if (table[idx][capacity] != -1) return table[idx][capacity];
	
	int res = 0;
	for (int i = 0; i < v[idx].size(); i++){
		if (capacity >= v[idx][i]){
			res = max(res, dp(idx - 1, capacity - v[idx][i]));
		}
	}
	
	return table[idx][capacity] = res;
}

int main (){
	int n;
	cin >> n;
	while (n--){
		for (int i = 0; i < 25; i++) 
			for (int j = 0; j < 250; j++)
				table[i][j] = -1;
		v.clear();
		int c;
		cin >> m >> c;
		while (c--){
			int k;
			cin >> k;
			vector<int> temp;
			while (k--){
				int price;
				cin >> price;
				temp.push_back(price);
			}
			v.push_back(temp);
		}
		int res = dp(v.size() - 1, m);
		if (res == 0) cout << "no solution" << endl;
		else cout << res << endl;
	}
	return 0;
}
