#include <stdio.h>

int main(){
	int n, p, q;
	int count[105];
	for (int i = 0; i < 105; i++) count[i] = 0;
	
	scanf("%d", &n);
	
	scanf("%d", &p);
	for (int i = 0; i < p; i++){
		int temp;
		scanf("%d", &temp);
		count[temp]++;
	}
	
	scanf("%d", &q);
	for (int i = 0; i < q; i++){
		int temp;
		scanf("%d", &temp);
		count[temp]++;
	}
	
	
	int bingo = 1;
	for (int i = 1; i <= n; i++){
		if (count[i] == 0) {
			bingo = 0;
			break;
		}
	}
	printf("%s", (bingo == 1) ? "I become the guy." : "Oh, my keyboard!");
	return 0;
}
