#include <stdio.h>

int main (){
	int n;
	scanf("%d", &n);
	int temp[n + 1];
	for (int i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);
		temp[x] = i;
	}
	for (int i = 1; i <= n; i++){
		printf("%d", temp[i]);
		if (i != n) printf(" ");
	}
	puts("");
	return 0;
}
