#include <stdio.h>

int main () {
	int n;
	scanf("%d", &n);
	if (n % 10 == n / 100){
		puts("Yes");
	} else {
		puts("No");
	}
	return 0;
}
