#include <stdio.h>
#include <math.h>

int main (){
	int t;
	scanf("%d", &t);
	while (t--){
		int n, m;
		scanf("%d %d", &n, &m);
		n -= 2;
		m -= 2;
		int res1 = ceil(n / 3.0);
		int res2 = ceil(m / 3.0);
		int res = res1 * res2;
		printf("%d\n", res);
	}
	return 0;
}
