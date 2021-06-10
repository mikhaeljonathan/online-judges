#include <stdio.h>

int main () {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++){
		int n;
		scanf("%d", &n);
		long long ans = n;
		ans *= n;
		ans *= n;
		ans *= (n - 1);
		ans += n*n;
		ans -= n;
		ans += 1;

		printf("Kasus #%d: %lld\n", i, ans);
	}
	return 0;
}
