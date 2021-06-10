#include <stdio.h>

int main (){
	int n, x;
	scanf("%d %d", &n, &x);
	int l[n], r[n];
	for (int i = 0; i < n; i++) scanf("%d %d", &l[i], &r[i]);
	int start = 1;
	int res = 0;
	for (int i = 0; i < n; i++){
		while (start + x <= l[i]) start += x;
			
		res += r[i] - start + 1;
		start = r[i] + 1;
		
		
	}
	printf("%d\n", res);
	return 0;
}
