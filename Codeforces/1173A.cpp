#include <stdio.h>

int main (){
	int x, y, z;
	scanf("%d %d %d", &x, &y, &z);
	if (x > y + z) printf("+\n");
	else if (y > x + z) printf("-\n");
	else if (x == y && z == 0) printf("0");
	else printf("?\n");
	return 0;
}
