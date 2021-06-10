#include <stdio.h>

int min (int a, int b){
	if (a < b){
		return a;
	}
	return b;
}

int main () {
	int k2, k3, k5, k6;
	scanf("%d %d %d %d", &k2, &k3, &k5, &k6);
	
	long long res = 0;
	long long multiplier = min(k2, min(k5, k6));
	res += multiplier * 256;
	
	k2 -= multiplier;
	
	multiplier = min(k2, k3);
	res += multiplier * 32;
	
	printf("%lld\n", res);
	return 0;
}
