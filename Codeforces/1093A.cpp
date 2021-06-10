#include <stdio.h>
#include <math.h>

int main (){
	int t;
	scanf("%d", &t);
	while (t--){
		int x;
		scanf("%d", &x);
		double res = ceil((double)x / 7.0);
		int finalres = res;
		printf("%d\n", finalres);
	}
	return 0;
}
