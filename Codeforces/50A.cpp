#include <stdio.h>

int max (int a, int b){
	if (a > b){
		return a;
	}
	return b;
}

int f(int m, int n){
	int temp = m;
	temp *= (n / 2);
	if (n % 2 == 1){
		temp += (m / 2);
	}
	return temp;
}

int main () {
	int m, n;
	scanf("%d %d", &m, &n);
	int res = max(f(m, n), f(n, m));
	printf("%d\n", res);	
	return 0;
}
