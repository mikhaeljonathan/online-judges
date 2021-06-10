#include <stdio.h>

int main (){
	int n;
	scanf("%d", &n);
	double ans;
	int count = 0;
	while (n--){
		int x;
		scanf("%d", &x);
		ans += x / 100.0;
		count++;
	}
	printf("%lf\n", ans / count * 100);
	return 0;
}
