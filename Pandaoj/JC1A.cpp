#include <cstdio>
using namespace std;

int main (){
	int t;
	scanf("%d",&t);
	for (int tc=1; tc<=t; tc++){
		int n,x;
		scanf("%d %d",&n,&x);
		int res=0;
		int x2=x;
		while (x<n+x2){
			res++;
			x+=x2;
		}
		printf("Kasus #%d: %d\n",tc,res);
	}
	return 0;
}
