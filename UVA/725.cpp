#include <stdio.h>

int main (){
	int n;
	int first = 1;
	while (scanf("%d", &n) && n != 0){
		if (!first) puts("");
		int ans = 0;
		for (int fghij = 1234; fghij <= 98765 / n; fghij++){
			int abcde = fghij * n;
			int temp = abcde;
			int used = (fghij < 10000);
			while (temp){
				used |= (1 << (temp % 10));
				temp /= 10;
			}
			temp = fghij;
			while (temp){
				used |= (1 << (temp % 10));
				temp /= 10;
			}
			if (used == (1 << 10) - 1){
				ans = 1;
				printf("%.5d / %.5d = %d\n", abcde, fghij, n);
			}
		}
		if (!ans) printf("There are no solutions for %d.\n", n);
		first = 0;
	}
	return 0;
}
