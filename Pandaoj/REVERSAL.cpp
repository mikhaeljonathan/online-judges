#include <cstdio>
using namespace std;

int main (){
	int n;
	scanf("%d",&n);
	int y[n];
	for (int a=0; a<n; a++){
		scanf("%d",&y[a]);
	}
	for (int b=n-1; b>=0; b--){
		printf("%d",y[b]);
		if (b!=0)
			printf(" ");
	}
	return 0;
}
