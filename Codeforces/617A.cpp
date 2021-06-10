#include <stdio.h>

int main () {
	int n;
	scanf("%d", &n);
	int ans = n / 5;
	if (n % 5 != 0){
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}
