#include <stdio.h>

int main (){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	printf("%s\n", (m < n || k < n) ? "No" : "Yes");
	return 0;
}
