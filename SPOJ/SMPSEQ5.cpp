#include <cstdio>
#include <algorithm>
using namespace std;

int main (){
	int n,m;
	scanf("%d",&n);
	int s[n];
	for (int a=0; a<n; a++){
		scanf("%d",&s[a]);
	}
	scanf("%d",&m);
	int q[m];
	for (int b=0; b<m; b++){
		scanf("%d",&q[b]);
	}
	sort(s,s+n);
	sort(q,q+m);
	int trig=0;
	for (int d=0; d<min(m,n); d++){
		if ((s[d]==q[d])&&(trig!=0))
			printf(" %d",d+1);
		else if (s[d]==q[d]){
			printf("%d",d+1);
			trig++;
		}
	}
	printf("\n");
	return 0;
}
