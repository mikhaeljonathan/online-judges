#include <stdio.h>

int main (){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		long long res;
		long long temp = n * n;
		if (temp % 2 == 1){
			res = (temp + 1) / 2;
			res *= temp;
		} else {
			res = temp / 2;
			res *= (temp + 1);
		}
		res /= n;
		printf("%lld\n", res);
	}
	return 0;
}
