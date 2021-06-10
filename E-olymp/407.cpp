#include <stdio.h>

int main (){
	int t;
	scanf("%d", &t);
	while (t--){
		int n;
		scanf("%d", &n);
		if (n % 3 == 0) puts("GCV");
		else if (n % 3 == 1) puts("VGC");
		else puts("CVG");
	}
	return 0;
}
