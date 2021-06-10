#include <stdio.h>

int m;

int memo[1005];

int dp(int x){
	if (x <= 2) return memo[x] = 2;
	
	if (memo[x] != -1) return memo[x];
	
	int res = dp(x - 1) + dp(x - 2);
	if (res >= m) res -= m;
	return memo[x] = res;
}

int main (){
	int t;
	scanf("%d", &t);
	while (t--){
		int n;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < 1005; i++) memo[i] = -1;
		printf("%d\n", dp(n) % m);
	}
	return 0;
}
