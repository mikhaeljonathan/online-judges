#include <cstdio>
using namespace std;

int main (){
	int n;
	scanf("%d",&n);
	int s[n];
	for (int a=0; a<n; a++){
		scanf("%d",&s[a]);
	}
	int m;
	scanf("%d",&m);
	int q[m];
	for (int b=0; b<m; b++){
		scanf("%d",&q[b]);
	}
	bool ever[n];
	for (int e=0; e<n; e++)
		ever[e]=false;
	for (int c=0; c<n; c++){
		for (int d=0; d<m; d++){
			if (s[c]==q[d])
				ever[c]=true;	
		}
	}
	int trig=0;
	for (int f=0; f<n; f++){
		if ((!ever[f])&&(trig==0)){
			printf("%d",s[f]);
			trig++;
		}
		else if (!ever[f])
			printf(" %d",s[f]);
	}
	printf("\n");
	return 0;
}
