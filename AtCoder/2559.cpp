#include <stdio.h>

int main () {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if ((c >= a) && (c <= b)){
		puts("Yes");
	} else {
		puts("No");
	}
	return 0;
}
