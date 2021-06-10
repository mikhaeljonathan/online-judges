#include <stdio.h>

long long pow(int a, int b){
	if (b == 0) return 1;
	return a * pow(a, b - 1);
}

int main () {
	int n, b;
	scanf("%d %d", &n, &b);
	long long x = 0;
	while (n--){
		int num;
		scanf("%d", &num);
		x += num * pow(b, n);
	}
	int m;
	scanf("%d %d", &m, &b);
	long long y = 0;
	while (m--){
		int num;
		scanf("%d", &num);
		y += num * pow(b, m);
	}

	if (x == y){
		puts("=");
	} else if (x > y){
		puts(">");
	} else if (y > x){
		puts("<");
	}
	return 0;
}
