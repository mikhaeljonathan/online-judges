#include <stdio.h>

int main () {
	int a, b ,c;
	scanf("%d %d %d", &a, &b, &c);
	if (c - b == b - a){
		puts("YES");
	} else {
		puts("NO");
	}
	return 0;
}
