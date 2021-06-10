#include <cstdio>
using namespace std;

int main (){
	int n,totaln=0;
	scanf("%d",&n);
	int s[n];
	for (int a=0; a<n; a++){
		scanf("%d",&s[a]);
		totaln+=s[a];
	}
	int m, totalm=0;
	scanf("%d",&m);
	int q[m];
	for (int b=0; b<m; b++){
		scanf("%d",&q[b]);
		totalm+=q[b];
	}
	bool first=true;
	if (totalm<totaln){
		for (int c=0; c<n; c++){
			if (first){
				printf("%d",s[c]);
				first=false;
			} else
				printf(" %d",s[c]);
		}
	} else {
		for (int d=0; d<m; d++){
			if (first){
				printf("%d",q[d]);
				first=false;
			} else
				printf(" %d",q[d]);
		}
	}
	printf("\n");
	return 0;
}
