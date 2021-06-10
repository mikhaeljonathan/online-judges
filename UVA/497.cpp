#include <stdio.h>
#include <string.h>
#include <vector>
#define SIZE 100000
using namespace std;

int backtrack[SIZE];
int memo[SIZE];

int lis(vector<int> v, int idx){
	if (memo[idx] != -1) return memo[idx];
	
	int res = 0;
	for (int i = 0; i < idx; i++){
		if (v[i] < v[idx]) {
			int temp = lis(v, i);
			if (res < temp){
				res = temp;
				backtrack[idx] = i;
			}
		}
	}
	
	return memo[idx] = res + 1;
}

void printBacktrack(vector<int>v, int idx){
	if (idx == -1) return;
	printBacktrack(v, backtrack[idx]);
	printf("%d\n", v[idx]);
}

int main (){
	int tc;
	scanf("%d", &tc);
	getchar();
	getchar();
	while (tc--){
		vector<int> v;
		char in[50];
		for (int i = 0; i < SIZE; i++){
			backtrack[i] = -1;
			memo[i] = -1;
		} 
		while (gets(in)){
			int len = strlen(in);
			if (len == 0) break;
			int x;
			sscanf(in, "%d", &x);
			v.push_back(x);
		}
		int ans = 0;
		int lastindex = -1;
		for (int i = 0; i < v.size(); i++){
			int temp = lis(v, i);
			if (ans < temp){
				ans = temp;
				lastindex = i;
			}
		}
		printf("Max hits: %d\n", ans);
		printBacktrack(v, lastindex);
		if (tc != 0) printf("\n");
	}
}
