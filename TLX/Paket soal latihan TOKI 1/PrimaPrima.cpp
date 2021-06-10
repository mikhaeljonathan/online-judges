#include <stdio.h>

int digit(int x){
	int res = 0;
	while (x > 0){
		x /= 10;
		res++;
	}
	return res;
}

int power(int x, int y){
	if (y == 0) return 1;
	return x * power(x, y - 1);
}

int combine(int x, int y){
	int res = x * power(10, digit(y));
	return res + y;
}

bool isPrime(int x){
	
	if (x == 1) return false;
	if (x == 2) return true;
	if (x % 2 == 0) return false;
	
	for (int i = 3; i * i <= x; i++){
		if (x % i == 0) return false;
	}
	
	return true;
}

int main(){
	int m, n;
	scanf("%d %d", &m, &n);
	bool ada = false;
	for (int i = m; i < n; i++){
		for (int j = m; j < n; j++){
			if (!isPrime(i)) continue;
			if (!isPrime(j)) continue;
			if (isPrime(combine(i, j))){
				ada = true;
				printf("%d %d\n", i, j);
			}
		}
	}
	if (!ada) printf("TIDAK ADA\n");
	return 0;
}
