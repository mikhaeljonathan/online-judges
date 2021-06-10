#include <stdio.h>

long long pow(int a, int b){
	if (b == 0) return 1;
	else {
		return a * pow(a, b - 1);
	}
}

int main (){
	int n;
	long long res = 0;
	scanf("%d", &n);
	while (n--){
		int num;
		scanf("%d", &num);
		res += pow(num / 10, num % 10);
	}
	printf("%lld\n", res);
	return 0;
}
