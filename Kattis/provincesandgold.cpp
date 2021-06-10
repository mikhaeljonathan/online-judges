#include <stdio.h>

int main () {
	int g, s, c;
	scanf("%d %d %d", &g, &s, &c);
	int total = 3 * g + 2 * s + c;
	
	if (total >= 8){
		printf("Province or ");
	} else if (total >= 5){
		printf("Duchy or ");
	} else if (total >= 2){
		printf("Estate or ");
	}
	
	if (total >= 6){
		puts("Gold");
	} else if (total >= 3){
		puts("Silver");
	} else {
		puts("Copper");
	}
	return 0;
}
