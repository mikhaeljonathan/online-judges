#include <stdio.h>

long long nozero (long long n){
	long long temp = 0;
	while (n > 0){
		if (n % 10 != 0){
			temp += n % 10;
			temp *= 10;
		}
		n /= 10;
	}
	temp /= 10;
	
	//reverse back
	long long res = 0;
	while (temp > 0){
		res += temp % 10;
		res *= 10;
		temp /= 10;
	}
	res /= 10;
	
	return res;
}

int main () {
	long long a, b;
	scanf("%lld %lld", &a, &b);
	if (nozero(a) + nozero(b) == nozero(a + b)){
		puts("YES");
	} else {
		puts("NO");
	}
	return 0;
}
