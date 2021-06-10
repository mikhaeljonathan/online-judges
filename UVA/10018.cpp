#include <stdio.h>

long long rev(long long p){
	long long ans = 0;
	while (p > 0){
		ans += p % 10;
		ans *= 10;
		p /= 10;
	}
	ans /= 10;
	return ans;
}

int main (){
	int n;
	scanf("%d", &n);
	while (n--){
		long long p;
		scanf("%lld", &p);
		int it = 0;
		do {
			p += rev(p);
			it++;
		} while (rev(p) != p);
		printf("%d %lld\n", it, p);
	}
	return 0;
}
