#include <stdio.h>
#include <math.h>

int main (){
	int n;
	scanf("%d", &n);
	while (n--){
		int l, w, h;
		scanf("%d %d %d", &l, &w, &h);
		int res = (h * w + h * l) * 2;
		printf("%d\n", (int) ceil((double) res / 16));
	}
	return 0;
}
