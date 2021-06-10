#include <cstdio>
using namespace std;

int main (){
	int n,x;
	scanf("%d %d",&n,&x);
	int s[n],q[n];
	for (int a=0; a<n; a++)
		scanf("%d",&s[a]);
	for (int b=0; b<n; b++)
		scanf("%d",&q[b]);
	bool ever=false;
	for (int c=0; c<n; c++){
		bool ever2=false;
		for (int d=c-x; d<=c+x; d++){
			if ((d<0)||(d>=n))
				continue;
			if ((s[c]==q[d])&&(!ever)){
				printf("%d",c+1);
				ever = true;
			} else if ((s[c]==q[d])&&(!ever2)){
				printf (" %d",c+1);
				ever2 = true;
			}
		}
	}
	printf("\n");
	return 0;
}
