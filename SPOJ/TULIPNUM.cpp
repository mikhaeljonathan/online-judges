#include <cstdio>
using namespace std;

int main (){
	int t;
	scanf("%d",&t);
	for (int tc=0; tc<t; tc++){
		long n,q;
		scanf("%ld %ld",&n,&q);
		int x;
		scanf("%d",&x);
		int memo[n+1];
		memo[0]=0;
		memo[1]=1;
		for (int a=2; a<=n; a++){
			int y;
			scanf("%d",&y);
			if (x==y){
				memo[a] = memo[a-1];
			} else {
				memo[a] = memo[a-1]+1;
			}	
			x=y;
		}
		printf("Case %d:\n",tc+1);
		for (int b=0; b<q; b++){
			long i,j;
			scanf("%ld %ld",&i,&j);
			if (memo[i]==memo[i-1])
				printf("%d",memo[j]-memo[i-1]+1);
			else
				printf("%d",memo[j]-memo[i-1]);
			printf("\n");
		}
	}
	return 0;
}
