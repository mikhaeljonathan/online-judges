#include <stdio.h>

int main () {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++){
		long long a, b;
		scanf("%lld %lld", &a, &b);
		if (a < b){
			puts("<");
		} else if (a > b){
			puts(">");
		} else {
			puts("=");
		}
	}
	return 0;
}
