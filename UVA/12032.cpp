#include <bits/stdc++.h>
using namespace std;

bool enough(vector<int> v, int x){
	for (int i = 0; i < v.size(); i++){
		int diff = v[i] - v[i - 1];
		
		if (diff > x) return false;
		
		if (diff == x) x--;
	}
	return true;
}

int main (){
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++){
		vector<int> v;
		int n;
		cin >> n;
		while (n--){
			int r;
			cin >> r;
			v.push_back(r);
		}
		
		int l = 0;
		int r = 10e7;
		int ans;
		while (l <= r){
			int mid = (l + r) / 2;
			if (enough(v, mid)){
				ans = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		
		cout << "Case " << i << ": " << ans << endl;
	}
	return 0;
}
