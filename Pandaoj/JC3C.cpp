#include <stdio.h>

int main () {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		int tempa = 0, tempb = 0;
		while (a > 0){
			tempa += a % 10;
			a /= 10;
		}
		while (b > 0){
			tempb += b % 10;
			b /= 10;
		}
		printf("Case #%d: %d\n", i, tempa * tempb);
	}
	return 0;
}
