#include <stdio.h>

int main (){
	char card[6][5];
	scanf("%s", card[0]);
	scanf("%s %s %s %s %s", card[1], card[2], card[3], card[4], card[5]);
	bool yes = false;
	for (int i = 1; i <= 5; i++) if (card[0][0] == card[i][0] || card[0][1] == card[i][1]) yes = true;
	printf("%s\n", yes ? "YES" : "NO");
	return 0;
}
