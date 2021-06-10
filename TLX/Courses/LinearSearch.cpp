#include <stdio.h>

int main (){
	int n, d;
	scanf("%d %d", &n, &d);
	int m[n];
	for (int i = 0; i < n; i++) scanf("%d", &m[i]);
	int res = -1;
	for (int i = 0; i < n; i++) {
		if (m[i] == d) {
			res = i;
			break;
		}
	}
	printf("%d\n", res);
	return 0;
}
