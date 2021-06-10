#include <cstdio>
#include <algorithm>
using namespace std;
long long memo[10005];

long long f(long long coins[], int n) {
	if (memo[n]!='\0')
		return memo[n];
	if (n<=0)
		return 0;
	else {
		long long temp1 = f(coins,n-1);
		long long temp2 = coins[n] + f(coins,n-2);
		memo[n] = max(temp1,temp2);
		return max(temp1,temp2);
	}
}

int main () {
	int t;
	scanf("%d",&t);
	for (int tc=0; tc<t; tc++){
		int n;
		scanf("%d",&n);
		long long coins[n+1];
		for (int a=1; a<=n; a++){
			scanf("%lld",&coins[a]);
		}
		printf("Case %d: %lld\n",tc+1,f(coins,n));
		for (int b=0; b<10005; b++){
			memo[b]='\0';
		}
	}
	return 0;
}
