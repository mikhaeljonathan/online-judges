#include <stdio.h>

int main (){
	int n;
	scanf("%d", &n);
	int x, y, z;
	x = y = z = 0;
	while (n--){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		x += a;
		y += b;
		z += c;
	}
	printf("%s\n", (x == 0 && y == 0 && z == 0) ? "YES" : "NO");
	return 0;
}
