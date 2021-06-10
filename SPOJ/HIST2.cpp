#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int memo[17][1<<17];
int counter[17][1<<17];

int tsp(int idx, int mask){
	
	if (mask == ((1 << v.size()) - 1)) {
		counter[idx][mask] = 1;
		return memo[idx][mask] = v[idx];
	}
	
	if (memo[idx][mask] != -1) return memo[idx][mask];
	
	int ans = 0;
	for (int i = 0; i < v.size(); i++){
		if (i == idx) continue;
		if (!(mask&(1<<i))){
			int temp = tsp(i, mask|(1<<i)) + abs(v[idx] - v[i]);
			if (ans < temp){
				ans = temp;
				counter[idx][mask] = counter[i][mask|(1<<i)];
			} else if (ans == temp){
				counter[idx][mask] += counter[i][mask|(1<<i)];
			}
		}
	}
	
	return memo[idx][mask] = ans;
}

int main (){
	int n;
	while (cin >> n){
		if (n == 0) break;
		
		v.clear();
		for (int i = 0; i < 17; i++){
			for (int j = 0; j < (1 << 17); j++){
				memo[i][j] = -1;
				counter[i][j] = 0;
			}
		}
		
		v.push_back(0);	
		while (n--){
			int x;
			cin >> x;
			v.push_back(x);
		}
		int res = tsp(0, 0|(1<<0));
		
		cout << res + (v.size() - 1) * 2 << " " << counter[0][0|(1<<0)] << endl;
	}
	return 0;
}
