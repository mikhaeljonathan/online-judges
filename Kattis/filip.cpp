#include<stdio.h>

int main () {
	int a, b;
	scanf("%d %d", &a, &b);
	int aa, ab, ac, ba, bb, bc;
	
	ac = a % 10;
	a /= 10;
	ab = a % 10;
	a /= 10;
	aa = a;
	
	bc = b % 10;
	b /= 10;
	bb = b % 10;
	b /= 10;
	ba = b;
	
	a = ac * 100 + ab * 10 + aa;
	b = bc * 100 + bb * 10 + ba;
	
	if (a > b){
		printf("%d\n", a);
	} else {
		printf("%d\n", b);
	}
	
	return 0;
}
