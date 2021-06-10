#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

vector< pair<int, int> > v;
int totalmoney;
int totalitems;
int memo[105][1100][25];

int dp(int idx, int money, int items){
	if (idx < 0) return 0;
	
	if (memo[idx][money][items] != -1) return memo[idx][money][items];
	
	int ret = dp(idx - 1, money, items);
	
	if (ceil((double) (money + v[idx].first) * 1.1L) <= totalmoney && items + 1 <= totalitems){
		ret = max(ret, dp(idx - 1, money + v[idx].first, items + 1) + v[idx].second);
	}
	
	if (ceil((double) (money + 2 * v[idx].first) * 1.1L) <= totalmoney && items + 2 <= totalitems){
		ret = max(ret, dp(idx - 1, money + 2 * v[idx].first, items + 2) + 2 * v[idx].second);
	}
	
	return memo[idx][money][items] = ret;
}

int main (){
	int n, x, t, k;
	while (true){
		cin >> n >> x >> t >> k;
		if (n == 0 && x == 0 && t == 0 && k == 0) break;
		v.clear();
		for (int i = 0; i < 105; i++)
			for (int j = 0; j < 1100; j++)
				for (int l = 0; l < 25; l++)
					memo[i][j][l] = -1;
					
		while (k--){
			int price;
			cin >> price;
			int favour = 0;
			for (int i = 0; i <= n; i++){
				int temp;
				cin >> temp;
				favour += temp;
			}
			v.push_back(make_pair(price, favour));
		}
		totalitems = 2 * (n + 1);
		totalmoney = x * (n + 1);
		double res = (double)dp(v.size() - 1, t * (n + 1), 0);
		res /= (double)(n + 1);
		printf("%.2lf\n", res);
	}
	return 0;
}
