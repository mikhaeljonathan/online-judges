#include <stdio.h>
int min(int a, int b){
	return (a<b)? a : b;
}
int main (){
	int n;
	scanf("%d", &n);
	int odd = 0;
	int even = 0;
	for (int i = 0; i < n; i++){
		int num;
		scanf("%d", &num);
		if (num % 2 == 0) even++;
		else odd++;
	}
	int res;
	if (odd <= even) res = odd;
	else res = even + (odd - even)/2;
	printf("%d\n", res);
	return 0;
}
