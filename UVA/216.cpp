#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

vector< pair<int, int> > coord;
pair<int, int> backtrack[10][1<<10];
double memo[10][1<<10];
int before;

double calculateDist(pair<int, int> a, pair<int, int> b){
	return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

double tsp(int idx, int mask){
	
	if (memo[idx][mask] >= 0) return memo[idx][mask];
	
	if (mask == (1 << coord.size()) - 1) return 0.0;
	
	double ans = (double)(1 << 30);
	for (int i = 0; i < coord.size(); i++){
		if (i == idx) continue;
		if (!(mask&(1<<i))){
			double temp = tsp(i, mask|(1 << i)) + calculateDist(coord[i], coord[idx]) + 16.0;
			if (temp < ans){
				ans = temp;
				backtrack[idx][mask].first = i;
				backtrack[idx][mask].second = mask|(1 << i);
			}
		}
	}
	
	return memo[idx][mask] = ans;
}

void printBacktrack(int idx, int mask){
	if (backtrack[idx][mask].first == idx){
		printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", 
		coord[before].first, coord[before].second, coord[idx].first, coord[idx].second, calculateDist(coord[before], coord[idx]) + 16.0);
		return;
	}
	printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", 
		coord[before].first, coord[before].second, coord[idx].first, coord[idx].second, calculateDist(coord[before], coord[idx]) + 16.0);
	before = idx;
	printBacktrack(backtrack[idx][mask].first, backtrack[idx][mask].second);
}

int main (){
	int tc;
	int cases = 1;
	while (cin >> tc){
		if (tc == 0) break;
		coord.clear();
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < (1<<10); j++){
				backtrack[i][j].first = backtrack[i][j].second = i;
				memo[i][j] = -1.0;
			}
		}
			
		
		while (tc--){
			int x, y;
			cin >> x >> y;
			coord.push_back(make_pair(x, y));
		}
		double res = (double)(1 << 30);
		int actualres = 0;
		for (int i = 0; i < coord.size(); i++){
			double temp = tsp(i, 0|(1<<i));
			if (temp < res){
				res = temp;
				actualres = i;
			}
		}
		printf("**********************************************************\n");
		printf("Network #%d\n", cases++);
		before = actualres;
		printBacktrack(backtrack[actualres][0|1<<actualres].first, backtrack[actualres][0|1<<actualres].second);
		printf("Number of feet of cable required is %.2lf.\n", res);
	}
	return 0;
}
