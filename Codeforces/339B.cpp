#include <stdio.h>

int main () {
	long long n, m;
	scanf("%lld %lld", &n, &m);
	long long res = 0;
	long long now = 1;
	while (m--){
		long long a;
		scanf("%lld", &a);
		if (a < now){
			res += n - now + a;
			now = a;
		} else {
			res += a - now;
			now = a;
		}
	}
	printf("%lld\n", res);
	return 0;
}
