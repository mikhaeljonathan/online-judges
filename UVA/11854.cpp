#include <stdio.h>

int main () {
	int a, b ,c;
	scanf("%d %d %d", &a, &b, &c);
	while (a != 0){
		if (a * a + b * b == c * c || b * b + c * c == a * a || a * a + c * c == b * b){
			puts("right");
		} else {
			puts("wrong");
		}
		scanf("%d %d %d", &a, &b, &c);
	}
	return 0;
}
