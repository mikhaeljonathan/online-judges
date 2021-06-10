#include <stdio.h>

int max (int a, int b){
	return (a < b) ? b : a;
}

int min (int a, int b){
	return (a < b) ? a : b;
}

int main (){
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d %d\n", min(a, b), (max(a, b) - min(a, b)) / 2);
	return 0;
}
