#include <cstdio>
#include <algorithm>
using namespace std;

int main (){
	int t;
	scanf("%d",&t);
	while (t--){
		int h,w;
		scanf("%d %d",&h,&w);
		int m[h][w+2];
		for (int a=0; a<h; a++){
			m[a][0]=0;
			m[a][w+1]=0;
		}
		for (int b=0; b<h; b++)
			for (int c=1; c<w+1; c++)
				scanf("%d",&m[b][c]);
		
		for (int d=1; d<h; d++){
			for (int e=1; e<w+1; e++){
				m[d][e]+=max(max(m[d-1][e-1],m[d-1][e]),max(m[d-1][e],m[d-1][e+1]));
			}
		}
		
		
		long res=m[h-1][1];
		for (int f=2; f<w+1; f++)
			if (res<m[h-1][f])
				res=m[h-1][f];
		printf("%ld\n",res);
	}
	return 0;
}
