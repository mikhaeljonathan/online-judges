#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int memo[105][105];

int sum(int i, int j){
	int ret = 0;
	for (int idx = i; idx <= j; idx++){
		ret += v[idx];
		ret %= 100;
	}
	ret %= 100;
	return ret;
}

int dp(int i, int j){
	
	if (i >= j) return 0;
	
	if (memo[i][j] != -1) return memo[i][j];
	
	int ret = (1<<30);
	for (int k = i; k < j; k++){
		ret = min(ret, dp(i, k) + dp(k + 1, j) + sum(i, k) * sum(k + 1, j));
	}
	
	return memo[i][j] = ret;
}

int main (){
	int n;
	while (cin >> n){
		
		v.clear();
		for (int i = 0; i < 105; i++)
			for (int j = 0; j < 105; j++)
				memo[i][j] = -1;
		
		while (n--){
			int x;
			cin >> x;
			v.push_back(x);
		}
		
		int ans = dp(0, v.size() - 1);
		cout << ans << endl;
	}
	return 0;
}
