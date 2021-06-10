#include <stdio.h>
#include <math.h>

int main (){
	int x1, y1, r1, x2, y2, r2;
	scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
	int distcenter = pow(x1 - x2, 2) + pow(y1 - y2, 2);
	int distr1 = pow(r1 - r2, 2);
	int distr2 = pow(r1 + r2, 2);
	if (distr1 <= distcenter && distcenter <= distr2) puts("bersentuhan");
	else puts("tidak bersentuhan");
	return 0;
}
