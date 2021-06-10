#include <stdio.h>

int main (){
	int n;
	scanf("%d", &n);
	int ans = 0;
	int temp = 0;
	while (n--){
		int x;
		scanf("%d", &x);
		if (x != temp) ans++;
		temp = x;
	}
	printf("%d\n", ans);
	return 0;
}
