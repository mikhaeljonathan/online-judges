#include <cstdio>
#include <algorithm>
using namespace std;

int main (){
	int n,m;
	scanf("%d %d",&n,&m);
	int buses[n][m+2];
	for (int a=0; a<n; a++)
		for (int b=1; b<=m; b++)
			scanf("%d",&buses[a][b]);
			
	for (int c=0; c<n; c++){
		buses[c][0]=105;
		buses[c][m+1]=105;
	}
	
	for (int d=1; d<n; d++)
		for (int e=1; e<m+1; e++)
			buses[d][e]+=min(min(buses[d-1][e-1],buses[d-1][e]),min(buses[d-1][e],buses[d-1][e+1]));
			
	long long res=buses[n-1][1];
	for (int f=2; f<=m; f++)
		if (res>buses[n-1][f])
			res=buses[n-1][f];
	printf("%lld\n",res);
		
	
	return 0;
}
