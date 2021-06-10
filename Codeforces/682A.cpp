#include <stdio.h>

int min (int a, int b){
	if (a < b) return a;
	return b;
}

int max (int a, int b){
	if (a < b) return b;
	return a;
}

int main (){
	int n, m;
	scanf("%d %d", &n, &m);
	long long res = 0;	
	for (int i = 1; i <= min(n, m); i++){
		res += (i + max(n, m)) / 5;
		res -= i / 5;
	}
	printf("%lld\n", res);
	return 0;
}
