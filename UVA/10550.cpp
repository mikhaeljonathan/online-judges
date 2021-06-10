#include <stdio.h>

int main (){
	int dial, a, b, c;
	while (scanf("%d %d %d %d", &dial, &a, &b, &c)){
		if (a == 0 && b == 0 && c == 0) break;
		//step1
		int res = 720;
		printf("%d\n", res);
		
		//step2
		if (a < dial){
			res += ((40 - dial) + a) * 9;
		} else {
			res += (a - dial) * 9;
		}
		dial = a;
		printf("%d\n", res);
		
		//step3
		res += 360;
		printf("%d\n", res);
		
		//step4
		if (b > dial){
			res += (dial + (40 - b)) * 9;
		} else {
			res += (dial - b) * 9;
		}
		dial = b;
		printf("%d\n", res);
		
		//step5
		if (c < dial){
			res += ((40 - dial) + c) * 9;
		} else {
			res += (c - dial) * 9;
		}
		dial = c;
		printf("%d\n", res);
		
		printf("%d\n", res);
	}
	return 0;
}
