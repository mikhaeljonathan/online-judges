#include <stdio.h>

int main (){
	int n;
	int res = -1;
	scanf("%d", &n);
	int curr = 0;
	while (n--){
		int a, b;
		scanf("%d %d", &a, &b);
		curr -= a;
		curr += b;
		if (curr > res) res = curr;
	}
	printf("%d\n", res);
	return 0;
}
