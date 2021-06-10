#include <stdio.h>

int main () {
	int r;
	scanf("%d", &r);
	if (r < 1200){
		puts("ABC");
	} else if (r < 2800){
		puts("ARC");
	} else {
		puts("AGC");
	}
	return 0;
}
