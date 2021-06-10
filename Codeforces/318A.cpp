#include <stdio.h>

int main (){
	long long n, k;
	scanf("%lld %lld", &n, &k);
	int index;
	if (n % 2 == 0){
		if (k > n / 2){
			k -= n / 2;
			k *= 2;
		} else {
			k *= 2;
			k--;
		}
		printf("%lld\n", k);
	} else {
		if (k > n / 2 + 1){
			k -= n / 2 + 1;
			k *= 2;
		} else {
			k *= 2;
			k--;
		}
		printf("%lld\n", k);
	}
}
