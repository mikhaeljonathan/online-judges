#include <stdio.h>
#include <string.h>

int max ( int a, int b ){
	if (a > b){
		return a;
	}
	return b;
}

int min (int a, int b){
	if (a < b){
		return a;
	}
	return b;
}

int main (){
	int n;
	scanf("%d", &n);
	getchar();
	char key[n + 1];
	gets(key);
	char x[n + 1];
	gets(x);
	
	long long res = 0;
	for (int i = 0; i < strlen(key); i++){
		int maximum = max(key[i] - '0', x[i] - '0');
		int minimum = min(key[i] - '0', x[i] - '0');
		int temp1 = maximum - minimum;
		int temp2 = 10 - maximum + minimum;
		res += min(temp1, temp2);
	}
	
	printf("%lld\n", res);
	return 0;
}
