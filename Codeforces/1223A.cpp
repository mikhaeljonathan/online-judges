#include <stdio.h>

int main (){
	int q;
	scanf("%d", &q);
	while (q--){
		int n;
		scanf("%d", &n);
		if (n == 2) printf("2\n");
		else printf("%d\n", (n % 2) ? 1 : 0);
	}
	return 0;
}
