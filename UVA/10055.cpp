#include <stdio.h>

int main () {
	long long n, m;
	while (scanf("%lld %lld", &n, &m) != EOF){
		long long ans = n - m;
		if (ans < 0){
			ans *= -1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
