#include <stdio.h>

int min (int a, int b){
	if (a < b){
		return a;
	}
	return b;
}

int f(int n, int k, int num){
	if (n == 0){
		return num;
	} else {
		int a = f(n - 1, k, num * 2);
		int b = f(n - 1, k, num + k);
		return min(a, b);
	}
}

int main () {
	int n, k;
	scanf("%d %d", &n, &k);
	int res = f(n, k, 1);
	printf("%d\n", res);
	return 0;
}
