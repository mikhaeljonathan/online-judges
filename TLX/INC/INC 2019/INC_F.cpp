#include <stdio.h>
int main (){
	int n, k;
	scanf("%d %d", &n, &k);
	int res = 0;
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		res += num;
	}
	printf("%s\n", (res % 2 == 0) ? "Preston" : "John");
	return 0;
}
