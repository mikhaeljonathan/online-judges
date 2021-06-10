#include <stdio.h>
#include <math.h>

int main (){
	int t;
	scanf("%d", &t);
	while (t--){
		long long n;
		scanf("%lld", &n);
		long long prev = -1;
		long long i = 1;
		long long res = 0;
		while (i * i <= n){
			res += n / i;
			if (prev != -1) res += (prev - (n / i)) * (i - 1);
			prev = n / i;
			i++;
		}
		i--;
		res += (i * (prev - i));
		printf("%lld\n", res);
	}
	return 0;
}
