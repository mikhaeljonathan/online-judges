#include <stdio.h>

int main (){
	int n;
	scanf("%d", &n);
	int min = 105;
	long long res = 0;
	
	while (n--){
		int a, p;
		scanf("%d %d", &a, &p);
		if (p < min) min = p;
		res += a * min;
	}
	
	printf("%lld\n", res);
	return 0;
}
