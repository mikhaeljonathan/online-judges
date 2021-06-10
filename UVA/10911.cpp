#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

vector< pair<int, int> > coord;
double memo[1<<20];

double calculateDist(pair<int, int> a, pair<int, int> b){
	return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

double dp(int mask){
	
	if (memo[mask] >= 0) return memo[mask];
	
	if (mask == (1 << coord.size()) - 1) return 0.0;
	
	double ret = (double)(1 << 30);
	for (int i = 0; i < coord.size(); i++){
		if (!(mask&(1 << i))){
			for (int j = i + 1; j < coord.size(); j++){
				if (!(mask&(1 << j))){
					int mask1 = (mask|(1 << i));
					ret = min(ret, dp(mask1|(1 << j)) + calculateDist(coord[i], coord[j]));
				}
			}
		}
	}
	
	return memo[mask] = ret;
}

int main (){
	int n;
	int cases = 1;
	while (cin >> n){
		if (n == 0) break;
		
		coord.clear();
		for (int i = 0; i < (1<<20); i++) memo[i] = -1.0;
		
		n *= 2;
		while(n--) {
			string name;
			int x, y;
			cin >> name >> x >> y;
			coord.push_back(make_pair(x, y));
		}
		
		printf("Case %d: %.2lf\n", cases++, dp(0));
	}
	return 0;
}
