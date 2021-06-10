#include <stdio.h>

int main (){
	int lucky[12] = {4, 7, 47, 74, 444, 447, 474, 477, 744, 747, 774, 777};
	int n;
	scanf("%d", &n);
	bool almostlucky = false;
	for (int i = 0; i < 12; i++) if (n % lucky[i] == 0) almostlucky = true;
	printf("%s\n", (almostlucky) ? "YES" : "NO"); 
	return 0;
}
