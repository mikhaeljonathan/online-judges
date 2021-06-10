#include <stdio.h>

int main (){
	int n;
	scanf("%d", &n);
	getchar();
	int key[300];
	for (int i = 0; i < 300; i++) key[i] = 0;
	while (n--){
		char s[25];
		gets(s);
		key[s[0]]++;
	}
	long long res = 0;
	for (char i = 'a'; i <= 'z'; i++){
		int temp = key[i] / 2;
		if (key[i] % 2 == 0) res += temp * (temp - 1);
		else res += temp * temp; //   n(n-1)/2 + (n+1)(n)/2 equivalent to n^2
	}
	printf("%lld\n", res);
	return 0;
}
