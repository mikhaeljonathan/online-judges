#include <stdio.h>

int main () {
	long long n;
	scanf("%lld", &n);
	while (n != 0){
		while (n > 9){
			long long temp = n;
			long long total = 0;
			while (temp > 0){
				total += temp % 10;
				temp /= 10;
			}
			n = total;
		}
		printf("%lld\n", n);
		scanf("%lld", &n);
	}
	return 0;
}
