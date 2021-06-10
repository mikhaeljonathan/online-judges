#include <stdio.h>

int abs(int x){
	if (x < 0) return -x;
	return x;
}

int main (){
	int a, b;
	scanf("%d %d", &a, &b);
	int win, draw, lose;
	win = draw = lose = 0;
	for (int i = 1; i <= 6; i++){
		if (abs(a - i) < abs(b - i)) win++;
		else if (abs(a - i) > abs(b - i)) lose++;
		else draw++;
	}
	printf("%d %d %d\n", win, draw, lose);
	return 0;
}
