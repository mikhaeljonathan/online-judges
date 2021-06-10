#include <stdio.h>

int min(int a, int b){
	if (a < b) return a;
	return b;
}

int main (){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	long long res = c * 2;
	res += (a == b) ? a * 2 : min(a, b) * 2 + 1;
	printf("%lld\n", res);
	return 0;
}
