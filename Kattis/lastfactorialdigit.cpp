#include <stdio.h>

int f(int n){
	if (n == 1) return 1;
	return ((n % 10) * (f(n - 1) % 10)) % 10;
}

int main (){
	int t;
	scanf("%d", &t);
	while (t--){
		int n;
		scanf("%d", &n);
		printf("%d\n", f(n));
	}
	return 0;
}
