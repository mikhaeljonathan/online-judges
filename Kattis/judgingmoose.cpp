#include <stdio.h>

int main () {
	int l, r;
	scanf("%d %d", &l, &r);
	if (l == 0 && r == 0){
		puts("Not a moose");
	} else if (l == r){
		printf("Even %d\n", l * 2);
	} else {
		int max = (l > r) ? l : r;
		max *= 2;
		printf("Odd %d\n", max);
	}
	return 0;
}
