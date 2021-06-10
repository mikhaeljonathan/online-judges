#include <stdio.h>

int main (){
	int q;
	scanf("%d", &q);
	while (q--){
		long long a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		a += b + c;
		a /= 2;
		printf("%lld\n", a);
	}
	return 0;
}
